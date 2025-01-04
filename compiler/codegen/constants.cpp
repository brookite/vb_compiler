#include "constants.hpp"

bytearray_t* constant_utf8::toBytes()
{
    byte_writer writer;
    writer.addByte(TAG);
    writer.addUTF8(this->value);
    return writer.getByteArray();
}

std::string constant_utf8::printable()
{
    return "[" + std::to_string(this->number) + "]" + "utf8: " + this->value;
}

bytearray_t* constant_class::toBytes()
{
    byte_writer writer;
    writer.addByte(TAG);
    writer.addInt16(this->number);
    return writer.getByteArray();
}

std::string constant_class::printable()
{
    return "[" + std::to_string(this->number) + "]" + "class" + "[" + std::to_string(this->name->number) + "]: " + this->name->value;
}

bytearray_t* constant_string::toBytes()
{
    byte_writer writer;
    writer.addByte(TAG);
    writer.addInt16(this->number);
    return writer.getByteArray();
}

std::string constant_string::printable()
{
    return "[" + std::to_string(this->number) + "]" + "string" + "[" + std::to_string(this->name->number) + "]: " + this->name->value;
}

bytearray_t* constant_nameandtype::toBytes()
{
    byte_writer writer;
    writer.addByte(TAG);
    writer.addInt16(this->name->number);
    writer.addInt16(this->type->number);
    return writer.getByteArray();
}

std::string constant_nameandtype::printable()
{
    return "[" + std::to_string(this->number) + "]" + "nameandtype: {\n\t" + this->name->printable() + "\n\t" + this->type->printable() + "\n}";
}

bytearray_t* constant_methodref::toBytes()
{
    byte_writer writer;
    writer.addByte(TAG);
    writer.addInt16(this->cls->number);
    writer.addInt16(this->nt->number);
    return writer.getByteArray();
}

std::string constant_methodref::printable()
{
    return "[" + std::to_string(this->number) + "]" + "methodref: {\n\t" + this->nt->printable() + "\n\t" + this->cls->printable() + "\n}";
}

bytearray_t* constant_fieldref::toBytes()
{
    byte_writer writer;
    writer.addByte(TAG);
    writer.addInt16(this->cls->number);
    writer.addInt16(this->nt->number);
    return writer.getByteArray();
}

std::string constant_fieldref::printable()
{
    return "[" + std::to_string(this->number) + "]" + "fieldref: {\n\t" + this->nt->printable() + "\n\t" + this->cls->printable() + "\n}";
}

bytearray_t* constant_int::toBytes()
{
    byte_writer writer;
    writer.addByte(TAG);
    writer.addInt32(this->value);
    return writer.getByteArray();
}

std::string constant_int::printable()
{
    return "[" + std::to_string(this->number) + "]" + "int:" + std::to_string(this->value);
}

bytearray_t* constant_float::toBytes()
{
    byte_writer writer;
    writer.addByte(TAG);
    writer.addFloat(this->value);
    return writer.getByteArray();
}

std::string constant_float::printable()
{
    return "[" + std::to_string(this->number) + "]" + "float:" + std::to_string(this->value);
}

bytearray_t* constant_long::toBytes()
{
    byte_writer writer;
    writer.addByte(TAG);
    writer.addInt64(this->value);
    return writer.getByteArray();
}

std::string constant_long::printable()
{
    return "[" + std::to_string(this->number) + "]" + "long:" + std::to_string(this->value);
}

std::string constant_double::printable()
{
    return "[" + std::to_string(this->number) + "]" + "double:" + std::to_string(this->value);
}

bytearray_t* constant_double::toBytes()
{
    byte_writer writer;
    writer.addByte(TAG);
    writer.addDouble(this->value);
    return writer.getByteArray();
}
