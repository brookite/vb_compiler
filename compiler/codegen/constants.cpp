#include "constants.hpp"

bytearray_t* constant_utf8::toBytes()
{
    byte_writer writer;
    writer.addByte(TAG);
    writer.addUTF8(this->value);
    return writer.getByteArray();
}

bytearray_t* constant_class::toBytes()
{
    byte_writer writer;
    writer.addByte(TAG);
    writer.addInt16(this->number);
    return writer.getByteArray();
}

bytearray_t* constant_string::toBytes()
{
    byte_writer writer;
    writer.addByte(TAG);
    writer.addInt16(this->number);
    return writer.getByteArray();
}

bytearray_t* constant_nameandtype::toBytes()
{
    byte_writer writer;
    writer.addByte(TAG);
    writer.addInt16(this->name->number);
    writer.addInt16(this->type->number);
    return writer.getByteArray();
}

bytearray_t* constant_methodref::toBytes()
{
    byte_writer writer;
    writer.addByte(TAG);
    writer.addInt16(this->cls->number);
    writer.addInt16(this->nt->number);
    return writer.getByteArray();
}

bytearray_t* constant_fieldref::toBytes()
{
    byte_writer writer;
    writer.addByte(TAG);
    writer.addInt16(this->cls->number);
    writer.addInt16(this->nt->number);
    return writer.getByteArray();
}

bytearray_t* constant_int::toBytes()
{
    byte_writer writer;
    writer.addByte(TAG);
    writer.addInt32(this->value);
    return writer.getByteArray();
}

bytearray_t* constant_float::toBytes()
{
    byte_writer writer;
    writer.addByte(TAG);
    writer.addFloat(this->value);
    return writer.getByteArray();
}

bytearray_t* constant_long::toBytes()
{
    byte_writer writer;
    writer.addByte(TAG);
    writer.addInt64(this->value);
    return writer.getByteArray();
}

bytearray_t* constant_double::toBytes()
{
    byte_writer writer;
    writer.addByte(TAG);
    writer.addDouble(this->value);
    return writer.getByteArray();
}
