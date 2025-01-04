#include "record.hpp"


struct constant_utf8 : public constant_record {
public:
	std::string value;
	constant_utf8(std::string str) : value(str) {};
	virtual bytearray_t* toBytes();
	virtual std::string printable();
	bool operator== (const constant_record& t) const {
		const constant_utf8 * other = dynamic_cast<const constant_utf8*>(&t);
		if (other != nullptr) {
			return value == other->value;
		}
		return false;
	}
private:
	static const byte_t TAG = 1;
};

struct constant_class : public constant_record {
public:
	constant_utf8* name;
	virtual bytearray_t* toBytes();
	virtual std::string printable();
	constant_class(constant_utf8* name) : name(name) {}
	bool operator== (const constant_record& t) const {
		const constant_class* other = dynamic_cast<const constant_class*>(&t);
		if (other != nullptr) {
			return *name == *other->name;
		}
		return false;
	}
private:
	static const byte_t TAG = 7;
};

struct constant_string : public constant_record {
public:
	constant_utf8* name;
	constant_string(constant_utf8* name) : name(name) {}
	virtual bytearray_t* toBytes();
	virtual std::string printable();
	bool operator== (const constant_record& t) const {
		const constant_string* other = dynamic_cast<const constant_string*>(&t);
		if (other != nullptr) {
			return *name == *other->name;
		}
		return false;
	}
private:
	static const byte_t TAG = 8;
};

struct constant_nameandtype : public constant_record {
public:
	constant_utf8* name;
	constant_utf8* type;
	constant_nameandtype(constant_utf8* name, constant_utf8* type) : name(name), type(type) {}
	virtual bytearray_t* toBytes();
	virtual std::string printable();

	bool operator== (const constant_record& t) const {
		const constant_nameandtype* other = dynamic_cast<const constant_nameandtype*>(&t);
		if (other != nullptr) {
			return *name == *other->name && *type == *other->type;
		}
		return false;
	}
private:
	static const byte_t TAG = 12;
};

struct constant_methodref : public constant_record {
public:
	constant_nameandtype * nt;
	constant_class* cls;
	constant_methodref(constant_nameandtype* nt, constant_class* cls) : nt(nt), cls(cls) {}
	virtual bytearray_t* toBytes();
	virtual std::string printable();
	bool operator== (const constant_record& t) const {
		const constant_methodref* other = dynamic_cast<const constant_methodref*>(&t);
		if (other != nullptr) {
			return *nt == *other->nt && *cls == *other->cls;
		}
		return false;
	}
private:
	static const byte_t TAG = 10;
};

struct constant_fieldref : public constant_record {
public:
	constant_nameandtype* nt;
	constant_class* cls;
	virtual bytearray_t* toBytes();
	virtual std::string printable();
	constant_fieldref(constant_nameandtype* nt, constant_class* cls) : nt(nt), cls(cls) {}
	bool operator== (const constant_record& t) const {
		const constant_fieldref* other = dynamic_cast<const constant_fieldref*>(&t);
		if (other != nullptr) {
			return *nt == *other->nt && *cls == *other->cls;
		}
		return false;
	}
private:
	static const byte_t TAG = 9;
};

struct constant_int : public constant_record {
public:
	int32_t value;
	virtual bytearray_t* toBytes();
	virtual std::string printable();
	constant_int(int32_t value) : value(value) {};
	bool operator== (const constant_record& t) const {
		const constant_int* other = dynamic_cast<const constant_int*>(&t);
		if (other != nullptr) {
			return value == other->value;
		}
		return false;
	}
private:
	static const byte_t TAG = 3;
};

struct constant_float : public constant_record {
public:
	float value;
	virtual bytearray_t* toBytes();
	virtual std::string printable();
	constant_float(float value) : value(value) {};
	bool operator== (const constant_record& t) const {
		const constant_float* other = dynamic_cast<const constant_float*>(&t);
		if (other != nullptr) {
			return value == other->value;
		}
		return false;
	}
private:
	static const byte_t TAG = 4;
};

struct constant_long : public constant_record {
public:
	int64_t value;
	virtual bytearray_t* toBytes();
	virtual std::string printable();
	constant_long(int64_t value) : value(value) {};
	bool operator== (const constant_record& t) const {
		const constant_long* other = dynamic_cast<const constant_long*>(&t);
		if (other != nullptr) {
			return value == other->value;
		}
		return false;
	}
private:
	static const byte_t TAG = 5;
};

struct constant_double : public constant_record {
public:
	double value;
	constant_double(double value) : value(value) {};
	virtual std::string printable();
	virtual bytearray_t* toBytes();
	bool operator== (const constant_record& t) const {
		const constant_double* other = dynamic_cast<const constant_double*>(&t);
		if (other != nullptr) {
			return value == other->value;
		}
		return false;
	}
private:
	static const byte_t TAG = 6;
};

