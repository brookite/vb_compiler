#include "rtl.hpp"

struct_node* createDummyStructNode(rtl_class_record * record) {
	struct_node* strct = new struct_node();
	strct->record = record;
	strct->name = record->name;
	return strct;
}

std::string vbDescriptor(std::string className) {
	return "L" + rtl_class_record::vbPackage() + className + ";";
}

std::string jvmStdlibDescriptor(std::string className) {
	return "L" + rtl_class_record::jvmStdlibPackage() + className + ";";
}

rtl_class_record* initString() {
	rtl_class_record* rec = rtl_class_record::String;
	rec->parent = rtl_class_record::Object;

	rec->methods["Length"] = new method_record("Length", rec, rtl_class_record::ULong->type, false, {});
	rec->methods["Concat"] = new method_record("Concat", rec, rec->type, false, {new parameter_record("other", rec->type, nullptr)});
	rec->methods["Format"] = new method_record("Format", rec, rec->type, false, { new parameter_record("fmt", new jvm_array_type(rtl_class_record::Object->type), nullptr)});
	rec->methods["Get"] = new method_record("Get", rec, rtl_class_record::Char->type, false, {new parameter_record("index", rtl_class_record::Integer->type, nullptr)});
	rec->methods["Join"] = new method_record("Join", rec, rtl_class_record::String->type, true, { new parameter_record("delim", rtl_class_record::String->type, nullptr),
		new parameter_record("array", new jvm_array_type(rtl_class_record::Object->type), nullptr)});

	rec->node = createDummyStructNode(rec);
	return rec;
}

rtl_class_record* initObject() {
	rtl_class_record* rec = rtl_class_record::Object;
	rec->parent = nullptr;

	rec->methods["toJvmString"] = new method_record("toJvmString", rec, new jvm_type("String", jvmStdlibDescriptor("String")), false, {});
	rec->methods["ToString"] = new method_record("ToString", rec, rtl_class_record::String->type, false, {});
	rec->methods["equals"] = new method_record("equals", rec, rtl_class_record::Boolean->type, false, {new parameter_record("val", rec->type, nullptr)});
	rec->methods["notEquals"] = new method_record("notEquals", rec, rtl_class_record::Boolean->type, false, { new parameter_record("val", rec->type, nullptr) });
	rec->methods["is"] = new method_record("is", rec, rtl_class_record::Boolean->type, false, { new parameter_record("val", rec->type, nullptr) });
	rec->methods["isNot"] = new method_record("isNot", rec, rtl_class_record::Boolean->type, false, { new parameter_record("val", rec->type, nullptr) });
	
	rec->node = createDummyStructNode(rec);
	return rec;
}

rtl_class_record* initNumber() {
	rtl_class_record* rec = rtl_class_record::Number;
	rec->parent = rtl_class_record::Object;

	rec->methods["add"] = new method_record("add", rec, rec->type, false, { new parameter_record("right", rec->type, nullptr) });
	rec->methods["inc"] = new method_record("inc", rec, rec->type, false, { });
	rec->methods["sub"] = new method_record("sub", rec, rec->type, false, { new parameter_record("right", rec->type, nullptr) });
	rec->methods["mul"] = new method_record("mul", rec, rec->type, false, { new parameter_record("right", rec->type, nullptr) });
	rec->methods["div"] = new method_record("div", rec, rec->type, false, { new parameter_record("right", rec->type, nullptr) });
	rec->methods["floorDiv"] = new method_record("floorDiv", rec, rec->type, false, { new parameter_record("right", rec->type, nullptr) });
	rec->methods["exp"] = new method_record("exp", rec, rec->type, false, { new parameter_record("right", rec->type, nullptr) });
	rec->methods["mod"] = new method_record("mod", rec, rec->type, false, { new parameter_record("right", rec->type, nullptr) });
	rec->methods["or"] = new method_record("or", rec, rec->type, false, { new parameter_record("right", rec->type, nullptr) });
	rec->methods["orElse"] = new method_record("orElse", rec, rec->type, false, { new parameter_record("right", rec->type, nullptr) });
	rec->methods["and"] = new method_record("and", rec, rec->type, false, { new parameter_record("right", rec->type, nullptr) });
	rec->methods["andAlso"] = new method_record("andAlso", rec, rec->type, false, { new parameter_record("right", rec->type, nullptr) });
	rec->methods["unaryPlus"] = new method_record("unaryPlus", rec, rec->type, false, { });
	rec->methods["unaryMinus"] = new method_record("unaryMinus", rec, rec->type, false, { });
	rec->methods["not"] = new method_record("not", rec, rec->type, false, { });
	rec->methods["lshift"] = new method_record("lshift", rec, rec->type, false, { new parameter_record("right", rec->type, nullptr) });
	rec->methods["rshift"] = new method_record("rshift", rec, rec->type, false, { new parameter_record("right", rec->type, nullptr) });
	rec->methods["lte"] = new method_record("lte", rec, rec->type, false, { new parameter_record("right", rec->type, nullptr) });
	rec->methods["lt"] = new method_record("lt", rec, rec->type, false, { new parameter_record("right", rec->type, nullptr) });
	rec->methods["gte"] = new method_record("gte", rec, rec->type, false, { new parameter_record("right", rec->type, nullptr) });
	rec->methods["gt"] = new method_record("gt", rec, rec->type, false, { new parameter_record("right", rec->type, nullptr) });
	rec->methods["xor"] = new method_record("xor", rec, rec->type, false, { new parameter_record("right", rec->type, nullptr) });

	rec->methods["getBoolean"] = new method_record("getBoolean", rec, new jvm_type("Boolean", "Z"), false, {});
	rec->methods["getDouble"] = new method_record("getDouble", rec, new jvm_type("Double", "D"), false, {});
	rec->methods["getInteger"] = new method_record("getInteger", rec, new jvm_type("Long", "J"), false, {});

	rec->node = createDummyStructNode(rec);
	return rec;
}

rtl_class_record* initBoolean() {
	rtl_class_record* rec = rtl_class_record::Boolean;
	rec->parent = rtl_class_record::Number;

	rec->methods["jvmValue"] = new method_record("jvmValue", rec, new jvm_type("Boolean", "Z"), false, {});
	rec->methods["numberValue"] = new method_record("numberValue", rec, rtl_class_record::Number->type, false, {});
	rec->methods["fromNumber"] = new method_record("fromNumber", rec, rec->type, true, {new parameter_record("val", rtl_class_record::Number->type, nullptr)});
	rec->methods["fromJvmType"] = new method_record("fromJvmType", rec, rec->type, true, {new parameter_record("val", new jvm_type("boolean", "Z"), nullptr)});
	
	rec->node = createDummyStructNode(rec);
	return rec;
}

rtl_class_record* initInteger() {
	rtl_class_record* rec = rtl_class_record::Integer;
	rec->type = new int_rtl_type(rec);
	rec->parent = rtl_class_record::Number;

	rec->methods["numberValue"] = new method_record("numberValue", rec, rtl_class_record::Number->type, false, {});
	rec->methods["fromNumber"] = new method_record("fromNumber", rec, rec->type, true, { new parameter_record("val", rtl_class_record::Number->type, nullptr) });
	rec->methods["fromJvmType"] = new method_record("fromJvmType", rec, rec->type, true, { new parameter_record("val", new jvm_type("int", "I"), nullptr) });
	
	rec->node = createDummyStructNode(rec);
	return rec;
}

rtl_class_record* initUInteger() {
	rtl_class_record* rec = rtl_class_record::UInteger;
	rec->type = new int_rtl_type(rec);
	rec->parent = rtl_class_record::Number;

	rec->methods["numberValue"] = new method_record("numberValue", rec, rtl_class_record::Number->type, false, {});
	rec->methods["fromNumber"] = new method_record("fromNumber", rec, rec->type, true, { new parameter_record("val", rtl_class_record::Number->type, nullptr) });
	rec->methods["fromJvmType"] = new method_record("fromJvmType", rec, rec->type, true, { new parameter_record("val", new jvm_type("int", "I"), nullptr) });
	
	rec->node = createDummyStructNode(rec);
	return rec;
}

rtl_class_record* initMath() {
	rtl_class_record* rec = rtl_class_record::Math;
	rec->type = new rtl_type(rec);
	rec->parent = rtl_class_record::Object;
	rec->allowLowercase = true;

	rec->methods["Sin"] = new method_record("Sin", rec, rtl_class_record::Double->type, true, { new parameter_record("a", rtl_class_record::Number->type, nullptr) });
	rec->methods["Cos"] = new method_record("Cos", rec, rtl_class_record::Double->type, true, { new parameter_record("a", rtl_class_record::Number->type, nullptr) });
	rec->methods["Abs"] = new method_record("Abs", rec, rtl_class_record::Double->type, true, { new parameter_record("a", rtl_class_record::Number->type, nullptr) });

	rec->methods["RandomInt"] = new method_record("RandomInt", rec, rtl_class_record::Long->type, true, {new parameter_record("val", 
		rtl_class_record::Long->type, nullptr)});
	rec->methods["Random"] = new method_record("Random", rec, rtl_class_record::Double->type, true, { });
	rec->methods["Min"] = new method_record("Min", rec, rtl_class_record::Number->type, true, { new parameter_record("a", rtl_class_record::Number->type, nullptr),
		new parameter_record("b", rtl_class_record::Number->type, nullptr) });
	rec->methods["Max"] = new method_record("Max", rec, rtl_class_record::Number->type, true, { new parameter_record("a", rtl_class_record::Number->type, nullptr),
		new parameter_record("b", rtl_class_record::Number->type, nullptr) });
	rec->methods["Pow"] = new method_record("Pow", rec, rtl_class_record::Double->type, true, { new parameter_record("a", rtl_class_record::Double->type, nullptr),
		new parameter_record("b", rtl_class_record::Double->type, nullptr) });

	rec->node = createDummyStructNode(rec);
	return rec;
}

rtl_class_record* initLong() {
	rtl_class_record* rec = rtl_class_record::Long;
	rec->name = "Long";
	rec->type = new int_rtl_type(rec);
	rec->parent = rtl_class_record::Number;

	rec->methods["numberValue"] = new method_record("numberValue", rec, rtl_class_record::Number->type, false, {});
	rec->methods["fromNumber"] = new method_record("fromNumber", rec, rec->type, true, { new parameter_record("val", rtl_class_record::Number->type, nullptr) });
	rec->methods["fromJvmType"] = new method_record("fromJvmType", rec, rec->type, true, { new parameter_record("val", new jvm_type("long", "L"), nullptr) });
	
	rec->node = createDummyStructNode(rec);
	return rec;
}


rtl_class_record* initULong() {
	rtl_class_record* rec = rtl_class_record::ULong;
	rec->type = new int_rtl_type(rec);
	rec->parent = rtl_class_record::Number;

	rec->methods["numberValue"] = new method_record("numberValue", rec, rtl_class_record::Number->type, false, {});
	rec->methods["fromNumber"] = new method_record("fromNumber", rec, rec->type, true, { new parameter_record("val", rtl_class_record::Number->type, nullptr) });
	rec->methods["fromJvmType"] = new method_record("fromJvmType", rec, rec->type, true, { new parameter_record("val", new jvm_type("long", "L"), nullptr) });
	
	rec->node = createDummyStructNode(rec);
	return rec;
}

rtl_class_record* initShort() {
	rtl_class_record* rec = rtl_class_record::Short;
	rec->type = new int_rtl_type(rec);
	rec->parent = rtl_class_record::Number;

	rec->methods["numberValue"] = new method_record("numberValue", rec, rtl_class_record::Number->type, false, {});
	rec->methods["fromNumber"] = new method_record("fromNumber", rec, rec->type, true, { new parameter_record("val", rtl_class_record::Number->type, nullptr) });
	rec->methods["fromJvmType"] = new method_record("fromJvmType", rec, rec->type, true, { new parameter_record("val", new jvm_type("short", "S"), nullptr) });
	
	rec->node = createDummyStructNode(rec);
	return rec;
}

rtl_class_record* initUShort() {
	rtl_class_record* rec = rtl_class_record::UShort;
	rec->type = new int_rtl_type(rec);
	rec->parent = rtl_class_record::Number;

	rec->methods["numberValue"] = new method_record("numberValue", rec, rtl_class_record::Number->type, false, {});
	rec->methods["fromNumber"] = new method_record("fromNumber", rec, rec->type, true, { new parameter_record("val", rtl_class_record::Number->type, nullptr) });
	rec->methods["fromJvmType"] = new method_record("fromJvmType", rec, rec->type, true, { new parameter_record("val", new jvm_type("short", "S"), nullptr) });
	
	rec->node = createDummyStructNode(rec);
	return rec;
}

rtl_class_record* initByte() {
	rtl_class_record* rec = rtl_class_record::Byte;
	rec->type = new int_rtl_type(rec);
	rec->parent = rtl_class_record::Number;

	rec->methods["numberValue"] = new method_record("numberValue", rec, rtl_class_record::Number->type, false, {});
	rec->methods["fromNumber"] = new method_record("fromNumber", rec, rec->type, true, { new parameter_record("val", rtl_class_record::Number->type, nullptr) });
	rec->methods["fromJvmType"] = new method_record("fromJvmType", rec, rec->type, true, { new parameter_record("val", new jvm_type("byte", "B"), nullptr) });
	
	rec->node = createDummyStructNode(rec);
	return rec;
}

rtl_class_record* initSByte() {
	rtl_class_record* rec = rtl_class_record::SByte;
	rec->type = new int_rtl_type(rec);
	rec->parent = rtl_class_record::Number;

	rec->methods["numberValue"] = new method_record("numberValue", rec, rtl_class_record::Number->type, false, {});
	rec->methods["fromNumber"] = new method_record("fromNumber", rec, rec->type, true, { new parameter_record("val", rtl_class_record::Number->type, nullptr) });
	rec->methods["fromJvmType"] = new method_record("fromJvmType", rec, rec->type, true, { new parameter_record("val", new jvm_type("byte", "B"), nullptr) });
	
	rec->node = createDummyStructNode(rec);
	return rec;
}

rtl_class_record* initConsole() {
	rtl_class_record* rec = rtl_class_record::Console;
	rec->type = new rtl_type(rec);
	rec->parent = rtl_class_record::Object;
	rec->allowLowercase = true;

	rec->methods["WriteLine"] = new method_record("WriteLine", rec, new void_type(), true, { new parameter_record("val", new jvm_type("Object", "Ljava/lang/Object;"), nullptr)});
	rec->methods["Write"] = new method_record("Write", rec, new void_type(), true, {new parameter_record("val", new jvm_type("Object", "Ljava/lang/Object;"), nullptr)});
	rec->methods["ReadLine"] = new method_record("ReadLine", rec, rtl_class_record::String->type, true, {});
	rec->methods["ReadInt"] = new method_record("ReadInt", rec, rtl_class_record::Long->type, true, {});
	rec->methods["ReadDouble"] = new method_record("ReadDouble", rec, rtl_class_record::Double->type, true, {});
	rec->methods["ReadBoolean"] = new method_record("ReadBoolean", rec, rtl_class_record::Boolean->type, true, {});
	
	rec->node = createDummyStructNode(rec);
	return rec;
}

rtl_class_record* initSingle() {
	rtl_class_record* rec = rtl_class_record::Single;
	rec->type = new float_rtl_type(rec);
	rec->parent = rtl_class_record::Number;

	rec->methods["numberValue"] = new method_record("numberValue", rec, rtl_class_record::Number->type, false, {});
	rec->methods["fromNumber"] = new method_record("fromNumber", rec, rec->type, true, { new parameter_record("val", rtl_class_record::Number->type, nullptr) });
	rec->methods["fromJvmType"] = new method_record("fromJvmType", rec, rec->type, true, { new parameter_record("val", new jvm_type("float", "F"), nullptr) });
	
	rec->node = createDummyStructNode(rec);
	return rec;
}


rtl_class_record* initDouble() {
	rtl_class_record* rec = rtl_class_record::Double;
	rec->type = new float_rtl_type(rec);
	rec->parent = rtl_class_record::Number;

	rec->methods["numberValue"] = new method_record("numberValue", rec, rtl_class_record::Number->type, false, {});
	rec->methods["fromNumber"] = new method_record("fromNumber", rec, rec->type, true, { new parameter_record("val", rtl_class_record::Number->type, nullptr) });
	rec->methods["fromJvmType"] = new method_record("fromJvmType", rec, rec->type, true, { new parameter_record("val", new jvm_type("double", "D"), nullptr) });
	
	rec->node = createDummyStructNode(rec);
	return rec;
}

rtl_class_record* initChar() {
	rtl_class_record* rec = rtl_class_record::Char;
	rec->type = new char_rtl_type(rec);
	rec->parent = rtl_class_record::Number;

	rec->methods["numberValue"] = new method_record("numberValue", rec, rtl_class_record::Number->type, false, {});
	rec->methods["fromNumber"] = new method_record("fromNumber", rec, rec->type, true, { new parameter_record("val", rtl_class_record::Number->type, nullptr) });
	rec->methods["fromJvmType"] = new method_record("fromJvmType", rec, rec->type, true, { new parameter_record("val", new jvm_type("char", "C"), nullptr) });

	rec->node = createDummyStructNode(rec);
	return rec;
}

rtl_class_record* initDatetime() {
	rtl_class_record* rec = rtl_class_record::DateTime;
	rec->type = new rtl_type(rec);
	rec->parent = rtl_class_record::Object;

	rec->fields["year"] = new field_record("year", false, rtl_class_record::Integer->type, rec);
	rec->fields["month"] = new field_record("month", false, rtl_class_record::Integer->type, rec);
	rec->fields["day"] = new field_record("day", false, rtl_class_record::Integer->type, rec);

	rec->fields["hour"] = new field_record("hour", false, rtl_class_record::Integer->type, rec);
	rec->fields["minute"] = new field_record("minute", false, rtl_class_record::Integer->type, rec);
	rec->fields["second"] = new field_record("second", false, rtl_class_record::Integer->type, rec);

	rec->methods["ToTimestamp"] = new method_record("ToTimestamp", rec, rtl_class_record::Long->type, false, {});
	rec->methods["OfTimestamp"] = new method_record("OfTimestamp", rec, rec->type, true, {new parameter_record("val", rtl_class_record::Long->type, nullptr)});
	rec->methods["FromTimestamp"] = new method_record("FromTimestamp", rec, rec->type, true, { new parameter_record("val", rtl_class_record::Long->type, nullptr) });
	rec->methods["Now"] = new method_record("Now", rec, rec->type, true, {});

	rec->node = createDummyStructNode(rec);
	return rec;
}

rtl_class_record* initUtils() {
	rtl_class_record* rec = rtl_class_record::CompilerUtils;
	rec->type = new rtl_type(rec);
	rec->parent = rtl_class_record::Object;
	rec->allowLowercase = true;

	rec->methods["erase"] = new method_record("erase", rec, new void_type(), true, { new parameter_record("array", new jvm_array_type(rtl_class_record::Object->type), nullptr) });
	rec->methods["redim"] = new method_record("redim", rec, new jvm_array_type(rtl_class_record::Object->type), true, { new parameter_record("array", new jvm_array_type(rtl_class_record::Object->type), nullptr),
		new parameter_record("length", rtl_class_record::Number->type, nullptr) });
	rec->methods["redimPreserve"] = new method_record("redimPreserve", rec, new jvm_array_type(rtl_class_record::Object->type), true, { new parameter_record("array", new jvm_array_type(rtl_class_record::Object->type), nullptr),
		new parameter_record("length", rtl_class_record::Number->type, nullptr) });

	rec->node = createDummyStructNode(rec);
	return rec;
}

rtl_class_record* rtl_class_record::Object = new rtl_class_record("Object");
rtl_class_record* rtl_class_record::Boolean = new rtl_class_record("Boolean");
rtl_class_record* rtl_class_record::String = new rtl_class_record("String");
rtl_class_record* rtl_class_record::Number = new rtl_class_record("<Number>");
rtl_class_record* rtl_class_record::Integer = new rtl_class_record("Integer");
rtl_class_record* rtl_class_record::Long = new rtl_class_record("Long");
rtl_class_record* rtl_class_record::ULong = new rtl_class_record("ULong");
rtl_class_record* rtl_class_record::UInteger = new rtl_class_record("UInteger");
rtl_class_record* rtl_class_record::Short = new rtl_class_record("Short");
rtl_class_record* rtl_class_record::UShort = new rtl_class_record("UShort");
rtl_class_record* rtl_class_record::Byte = new rtl_class_record("Byte");
rtl_class_record* rtl_class_record::SByte = new rtl_class_record("SByte");
rtl_class_record* rtl_class_record::Single = new rtl_class_record("Single");
rtl_class_record* rtl_class_record::Double = new rtl_class_record("Double");
rtl_class_record* rtl_class_record::Char = new rtl_class_record("Char");
rtl_class_record* rtl_class_record::Console = new rtl_class_record("Console");
rtl_class_record* rtl_class_record::DateTime = new rtl_class_record("Date");
rtl_class_record* rtl_class_record::Math = new rtl_class_record("Math");
rtl_class_record* rtl_class_record::CompilerUtils = new rtl_class_record("CompilerUtils");

void initRTL() {
	rtl_class_record::Number->type = new number_rtl_type(rtl_class_record::Number);
	rtl_class_record::Boolean->type = new bool_rtl_type(rtl_class_record::Boolean);
	rtl_class_record::String->type = new rtl_type(rtl_class_record::String);
	rtl_class_record::Object->type = new rtl_type(rtl_class_record::Object);

	rtl_class_record::Number = initNumber();
	rtl_class_record::Boolean = initBoolean();
	rtl_class_record::String = initString();
	rtl_class_record::Object = initObject();
	rtl_class_record::Integer = initInteger();
	rtl_class_record::Long = initLong();
	rtl_class_record::ULong = initULong();
	rtl_class_record::UInteger = initUInteger();
	rtl_class_record::Short = initShort();
	rtl_class_record::UShort = initUShort();
	rtl_class_record::Byte = initByte();
	rtl_class_record::SByte = initSByte();
	rtl_class_record::Single = initSingle();
	rtl_class_record::Double = initDouble();
	rtl_class_record::Char = initChar();
	rtl_class_record::Console = initConsole();
	rtl_class_record::DateTime = initDatetime();
	rtl_class_record::Math = initMath();
	rtl_class_record::CompilerUtils = initUtils();
}

std::string number_rtl_type::jvmDescriptor() const
{
	return vbDescriptor("Number");
}

method_record* rtl_class_record::resolveMethod(std::string id)
{
	for (auto& pair : methods) {
		std::string name = pair.first;
		toLower(&name);
		if (name == id) {
			return pair.second;
		}
	}
	return struct_record::resolveMethod(id);
}

field_record* rtl_class_record::resolveField(std::string id)
{
	for (auto& pair : fields) {
		std::string name = pair.first;
		toLower(&name);
		if (name == id) {
			return pair.second;
		}
	}
	return struct_record::resolveField(id);
}

method_record* rtl_class_record::resolveStaticMethod(std::string id)
{
	for (auto& pair : methods) {
		std::string name = pair.first;
		toLower(&name);
		if (name == id && pair.second->isStatic) {
			return pair.second;
		}
	}
	return struct_record::resolveMethod(id);
}

field_record* rtl_class_record::resolveStaticField(std::string id)
{
	for (auto& pair : fields) {
		std::string name = pair.first;
		toLower(&name);
		if (name == id && pair.second->isStatic) {
			return pair.second;
		}
	}
	return struct_record::resolveField(id);
}
