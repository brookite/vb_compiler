#pragma once
#include <cstdint>
#include <string>
#include <map>
#include "../utils.hpp"
#include "../nodes.hpp"

struct constant_utf8;
struct constant_fieldref;
struct constant_methodref;
struct constant_class;
struct type;
struct struct_type;
struct semantic_context;

struct record {
	virtual ~record() = default;
	// interface
};

struct byte_record : public record {
	virtual bytearray_t toBytes() {
		return bytearray_t();
	}

	virtual bytearray_t toBytes(semantic_context * ctx) {
		return toBytes();
	}
};

struct var_record : record {
	std::string name;
	typed_value* valueNode;
	struct type* type;
	bool isConst = false;

	std::string jvmDescriptor();
};

struct localvar_record : var_record {
	method_record* owner;
	uint16_t number;

	localvar_record();
	localvar_record(std::string name, struct type* type, method_record* owner);
};

struct parameter_record : localvar_record {
	// �������� �������

	parameter_record() : localvar_record() {};
	parameter_record(std::string name, struct type* type, method_record* owner) : localvar_record(name, type, owner) {};
};

struct field_record : var_record {
	struct_record* owner = nullptr;
	field_node* node = nullptr;
	bool isStatic = false;

	field_record();
	field_record(std::string name, bool isStatic, struct type* type, struct_record* owner);
	virtual constant_fieldref* getConstantFor(struct_record* record, struct_type* trueOwner = nullptr);
};

struct method_record : byte_record {
public:
	std::string name;
	struct_record* owner = nullptr;
	procedure_node* node = nullptr;
	type* returnType = nullptr;

	bool isStatic;
	list<parameter_record*> args;
	std::map<std::string, localvar_record*> locals;
	std::map<uint16_t, localvar_record*> allLocals;

	method_record();
	method_record(std::string, struct_record* owner, type* retType, bool isStatic, list<parameter_record*> args);

	localvar_record* resolveLocal(std::string id);
	virtual constant_methodref* getConstantFor(struct_record* record, struct_type* trueOwner = nullptr);

	std::string jvmDescriptor();
	bytearray_t bytecode(semantic_context * ctx, Bytecode ** bytecode = nullptr);
	virtual bytearray_t toBytes(semantic_context * ctx);

	uint16_t localvarCounter = 0;
};

struct constant_record : public byte_record {
	uint16_t number = 0;
	virtual bool operator== (const constant_record& t) const = 0;
	virtual std::string printable() = 0;
};

struct struct_record : byte_record {
public:
	std::string name;
	struct_node* node = nullptr;
	struct_type* type = nullptr;
	struct_record* parent = nullptr;
	std::map<std::string, struct type*>* typeMap = nullptr;

	std::map<std::string, field_record*> fields;
	std::map<std::string, method_record*> methods;
	std::map<uint16_t, constant_record*> constant;

	struct_record();
	virtual constant_record* constantAt(uint16_t num);
	virtual constant_record* addConstant(constant_record* record);
	virtual constant_record* findConstant(constant_record* record);
	virtual constant_record* addConstantBy(field_record* record, struct_record* strct = nullptr);
	virtual constant_record* addConstantBy(struct_record* record);
	virtual constant_record* addConstantBy(method_record* record, struct_record * strct = nullptr);
	virtual constant_record* addConstantBy(struct type* type);
	virtual constant_record* addLiteralConstant(long long value);
	virtual constant_record* addLiteralConstant(double value);
	virtual constant_record* addLiteralConstant(float value);
	virtual constant_record* addLiteralConstant(std::string value);
	virtual constant_methodref* getConstructorConstant(list<std::string> descriptors, struct_record * dst);
	virtual constant_methodref* getStaticConstructorConstant(struct_record* dst);
	virtual constant_class* getConstantFor(struct_record* record);
	virtual void makeInit(semantic_context & context);

	virtual field_record * addField(field_node* node, semantic_context & context);
	virtual method_record * addMethod(procedure_node* procNode, semantic_context& context);
	virtual method_record * resolveMethod(std::string id);
	virtual field_record * resolveField(std::string id);
	virtual method_record* resolveStaticMethod(std::string id);
	virtual field_record* resolveStaticField(std::string id);
	virtual bytearray_t toBytes(semantic_context * context);
	constant_utf8* utf8ConstantOf(std::string name);

	bool isGeneric() const { return node->generics != nullptr && !node->generics->isEmpty(); };

	std::string jvmDescriptor() {
		return "Lbrookit/vb/code/" + this->name + ";";
	}

protected:
	uint16_t constantCounter = 1;
};

struct static_struct_record_wrapper : public struct_record {
public:
	method_record* resolveMethod(std::string id) {
		return resolveStaticMethod(id);
	}

	field_record* addField(field_node* node, semantic_context& context) { if (node->isStatic) { return source->addField(node, context); } return nullptr; }
	method_record* addMethod(procedure_node* procNode, semantic_context& context) { if (procNode->isStatic) { return source->addMethod(procNode, context); } return nullptr; }
	method_record* resolveStaticMethod(std::string id) { return source->resolveStaticMethod(id); }
	field_record* resolveStaticField(std::string id) { return source->resolveStaticField(id); }
	constant_record* constantAt(uint16_t num) { return source->constantAt(num); }
	constant_record* addConstant(constant_record* record) { return source->addConstant(record); }
	constant_record* findConstant(constant_record* record) { return source->findConstant(record); }
	constant_record* addConstantBy(field_record* record) { return source->addConstantBy(record); }
	constant_record* addConstantBy(method_record* record) { return source->addConstantBy(record); }
	constant_record* addConstantBy(struct type* type) { return source->addConstantBy(type); }
	constant_record* addLiteralConstant(long long value) { return source->addLiteralConstant(value); }
	constant_record* addLiteralConstant(double value) { return source->addLiteralConstant(value); }
	constant_record* addLiteralConstant(float value) { return source->addLiteralConstant(value); }
	constant_record* addLiteralConstant(std::string value) { return source->addLiteralConstant(value); }

	field_record* resolveField(std::string id) {
		return resolveStaticField(id);
	}

	static_struct_record_wrapper(struct_record* rec) : source(rec) {
		this->node = rec->node;
		this->parent = rec->parent;
		this->type = rec->type;
		this->typeMap = rec->typeMap;
	};
private:
	struct_record* source;
};

bytearray_t asBytes(std::map<uint16_t, constant_record*>*, uint16_t);
bytearray_t asBytes(std::map<std::string, field_record*>*);
bytearray_t asBytes(std::map<std::string, method_record*>*, semantic_context* ctx);
std::string printableConstant(std::string, std::map<uint16_t, constant_record*>);