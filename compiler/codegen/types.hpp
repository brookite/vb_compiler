#pragma once
#include "../nodes.hpp"
#include "record.hpp"

struct semantic_context;

struct type {
	bool nullptrable = true;
	virtual std::string jvmDescriptor() const = 0;
	bool operator== (const type& t) const;
	bool isValueType() const;

	// Проверяет, что переданный в аргумент класс является потомком данного
	bool isAssignableFrom(type* t, semantic_context& context) const;
	virtual std::string readableName() const = 0;
};

struct jvm_type : public type {
	std::string name;
	std::string descriptor;

	jvm_type(std::string name, std::string descriptor) : name(name), descriptor(descriptor) {}

	virtual std::string jvmDescriptor() const {
		return descriptor;
	}

	virtual std::string readableName() const {
		return name;
	}
};


struct struct_type : public jvm_type {
	struct_record* record;

	struct_type(struct_record* record) : record(record), jvm_type(record->name, record->jvmDescriptor()) {}

	virtual std::string jvmDescriptor() const {
		return record->jvmDescriptor();
	}

	virtual std::string readableName() const {
		return record->name;
	}
};

struct jvm_array_type : public struct_type {
	type* valueType;

	jvm_array_type(type* valueType);

	virtual std::string jvmDescriptor() const {
		return "[" + valueType->jvmDescriptor();
	}

	virtual std::string readableName() const {
		return valueType->readableName() + "()";
	}
};

struct void_type : public type {
	virtual std::string jvmDescriptor() const {
		return "V";
	}

	std::string readableName() const {
		return "void";
	}
};

struct nullptr_reference : public type {
	virtual std::string jvmDescriptor() const {
		type_error("Unhandled nullptr type");
		return "";
	}

	std::string readableName() const {
		return "nullptr";
	}
};

struct unknown_type : public type {
	// for unknown collection type
	// needs to be replaced
	// context is needed
	virtual std::string jvmDescriptor() const {
		type_error("Unhandled unknown type");
		return "";
	}

	std::string readableName() const {
		return "?";
	}
};

type* inferType(expr_node* val, struct_record * context, method_record* methodContext, semantic_context& semanticContext);
type* inferType(type_node* type, semantic_context& context, std::map<std::string, struct type*>* typeMap);
size_t intSizeOf(long long value);
// учесть преобразование типа в expr
// учесть типы бинарных и логических операторов