#pragma once
#include "record.hpp"
#include "types.hpp"

struct rtl_class_record : struct_record {
	static rtl_class_record* String;
	static rtl_class_record* Integer;
	static rtl_class_record* Number;
	static rtl_class_record* Long;
	static rtl_class_record* ULong;
	static rtl_class_record* UInteger;
	static rtl_class_record* Short;
	static rtl_class_record* UShort;
	static rtl_class_record* Byte;
	static rtl_class_record* SByte;
	static rtl_class_record* Console;
	static rtl_class_record* Object;
	static rtl_class_record* DateTime;
	static rtl_class_record* Char;
	static rtl_class_record* Single;
	static rtl_class_record* Double;
	static rtl_class_record* Boolean;
	static rtl_class_record* Math;
	static rtl_class_record* CompilerUtils;

	static std::string jvmStdlibPackage() { return "java/lang/"; }
	static std::string vbPackage() { return "brookit/vb/lang/"; }

	rtl_class_record() {}
	rtl_class_record(std::string name) { this->name = name; }

	std::string jvmDescriptor() {
		return "L" + vbPackage() + this->name + ";";
	}
};

struct rtl_type : struct_type {
	rtl_class_record* record;

	rtl_type(rtl_class_record* cls) : struct_type(cls), record(cls) {}

	virtual std::string jvmDescriptor() const {
		return record->jvmDescriptor();
	}

	virtual std::string readableName() const {
		return record->name;
	}

	virtual std::string qualifiedName() const {
		return rtl_class_record::vbPackage() + record->name;
	}
};

struct sized_rtl_type : rtl_type {
	virtual size_t byteSize() = 0;

	sized_rtl_type(rtl_class_record* rec) : rtl_type(rec) {}
};

struct int_rtl_type : sized_rtl_type {
	size_t byteSize() {
		if (readableName() == "UShort" || readableName() == "Short") {
			return 2;
		} else if (readableName() == "SByte" || readableName() == "Byte") {
			return 1;
		} else if (readableName() == "Integer" || readableName() == "UInteger") {
			return 4;
		} else if (readableName() == "Long" || readableName() == "ULong") {
			return 8;
		}
	}

	int_rtl_type(rtl_class_record* cls) : sized_rtl_type(cls) {}

	bool isUnsigned() {
		return readableName() == "UShort" || readableName() == "ULong" || readableName() == "UInteger" || readableName() == "Byte";
	}
};

struct float_rtl_type : sized_rtl_type {
	size_t byteSize() {
		return readableName() == "Double" ? 8 : 4;
	}

	float_rtl_type(rtl_class_record* cls) : sized_rtl_type(cls) {}
};

struct bool_rtl_type : sized_rtl_type {
	size_t byteSize() {
		return 1;
	}

	bool_rtl_type(rtl_class_record* cls) : sized_rtl_type(cls) {}
};

struct char_rtl_type : sized_rtl_type {
	size_t byteSize() {
		return 2;
	}

	char_rtl_type(rtl_class_record* cls) : sized_rtl_type(cls) {}
};

struct number_rtl_type : rtl_type {
	virtual std::string jvmDescriptor() const;

	virtual std::string readableName() const {
		return "Number";
	}

	virtual std::string qualifiedName() const {
		return rtl_class_record::vbPackage() + "Number";
	}

	number_rtl_type(rtl_class_record* record) : rtl_type(record) {}
};

void initRTL();