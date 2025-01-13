#include "bytecode.hpp"
#include "types.hpp"
#include "constants.hpp"

Bytecode::Bytecode(semantic_context * context, method_record * method)
{
    writer = new byte_writer();
    this->method = method;
    this->context = context;
}

void Bytecode::writeSimple(Instruction instr)
{
    uint8_t instrCode = static_cast<std::underlying_type<Instruction>::type>(instr);
    writer->addByte(instrCode);
}

size_t Bytecode::currentOffset()
{
    return writer->offset();
}

bytearray_t Bytecode::ldc(uint8_t val)
{
    size_t start = currentOffset();
    writeSimple(Instruction::ldc);
    writer->addByte(val);
    return writer->getByteArray(start, currentOffset());
}

bytearray_t Bytecode::ldc_w(uint16_t val)
{
    size_t start = currentOffset();
    writeSimple(Instruction::ldc);
    writer->addInt16(val);
    return writer->getByteArray(start, currentOffset());
}

bytearray_t Bytecode::ldc2_w(uint16_t val)
{
    size_t start = currentOffset();
    writeSimple(Instruction::ldc2_w);
    writer->addInt16(val);
    return writer->getByteArray(start, currentOffset());
}

bytearray_t Bytecode::aload(uint16_t val)
{
    size_t start = currentOffset();
    if (val > UINT8_MAX) {
        writeSimple(Instruction::wide);
    }
    writeSimple(Instruction::aload);
    val > UINT8_MAX ? writer->addInt16(val) : writer->addByte((uint8_t) val);
    return writer->getByteArray(start, currentOffset());
}

bytearray_t Bytecode::astore(uint16_t val)
{
    size_t start = currentOffset();
    if (val > UINT8_MAX) {
        writeSimple(Instruction::wide);
    }
    writeSimple(Instruction::astore);
    val > UINT8_MAX ? writer->addInt16(val) : writer->addByte((uint8_t)val);
    return writer->getByteArray(start, currentOffset());
}

bytearray_t Bytecode::iload(uint16_t val)
{
    size_t start = currentOffset();
    writeSimple(Instruction::iload);
    writer->addByte(val);
    return writer->getByteArray(start, currentOffset());
}

bytearray_t Bytecode::istore(uint16_t val)
{
    size_t start = currentOffset();
    if (val > UINT8_MAX) {
        writeSimple(Instruction::wide);
    }
    writeSimple(Instruction::istore);
    val > UINT8_MAX ? writer->addInt16(val) : writer->addByte((uint8_t)val);
    return writer->getByteArray(start, currentOffset());
}

bytearray_t Bytecode::aaload()
{
    writeSimple(Instruction::aaload);
    return writer->getByteArray(currentOffset() - 1, currentOffset());
}

bytearray_t Bytecode::aastore()
{
    writeSimple(Instruction::aastore);
    return writer->getByteArray(currentOffset() - 1, currentOffset());
}

bytearray_t Bytecode::loadThis()
{
    return aload(0);
}

bytearray_t Bytecode::pop()
{
    writeSimple(Instruction::pop);
    return writer->getByteArray(currentOffset() - 1, currentOffset());
}

bytearray_t Bytecode::pop2()
{
    writeSimple(Instruction::pop2);
    return writer->getByteArray(currentOffset() - 1, currentOffset());
}

bytearray_t Bytecode::dup()
{
    writeSimple(Instruction::dup);
    return writer->getByteArray(currentOffset() - 1, currentOffset());
}

bytearray_t Bytecode::dup2()
{
    writeSimple(Instruction::dup2);
    return writer->getByteArray(currentOffset() - 1, currentOffset());
}

bytearray_t Bytecode::invokespecial(uint16_t val)
{
    size_t start = currentOffset();
    writeSimple(Instruction::invokespecial);
    writer->addInt16(val);
    return writer->getByteArray(start, currentOffset());
}

bytearray_t Bytecode::invokevirtual(uint16_t val)
{
    size_t start = currentOffset();
    writeSimple(Instruction::invokevirtual);
    writer->addInt16(val);
    return writer->getByteArray(start, currentOffset());
}

bytearray_t Bytecode::invokestatic(uint16_t val)
{
    size_t start = currentOffset();
    writeSimple(Instruction::invokestatic);
    writer->addInt16(val);
    return writer->getByteArray(start, currentOffset());
}

bytearray_t Bytecode::areturn()
{
    writeSimple(Instruction::areturn);
    return writer->getByteArray(currentOffset() - 1, currentOffset());
}

bytearray_t Bytecode::returnVoid()
{
    writeSimple(Instruction::_return);
    return writer->getByteArray(currentOffset() - 1, currentOffset());
}

bytearray_t Bytecode::getfield(uint16_t val)
{
    size_t start = currentOffset();
    writeSimple(Instruction::getfield);
    writer->addInt16(val);
    return writer->getByteArray(start, currentOffset());
}

bytearray_t Bytecode::putfield(uint16_t val)
{
    size_t start = currentOffset();
    writeSimple(Instruction::putfield);
    writer->addInt16(val);
    return writer->getByteArray(start, currentOffset());
}

bytearray_t Bytecode::getstatic(uint16_t val)
{
    size_t start = currentOffset();
    writeSimple(Instruction::getstatic);
    writer->addInt16(val);
    return writer->getByteArray(start, currentOffset());
}

bytearray_t Bytecode::putstatic(uint16_t val)
{
    size_t start = currentOffset();
    writeSimple(Instruction::putstatic);
    writer->addInt16(val);
    return writer->getByteArray(start, currentOffset());
}

bytearray_t Bytecode::instanceof(uint16_t val)
{
    size_t start = currentOffset();
    writeSimple(Instruction::instanceof);
    writer->addInt16(val);
    return writer->getByteArray(start, currentOffset());
}

bytearray_t Bytecode::checkcast(uint16_t val)
{
    size_t start = currentOffset();
    writeSimple(Instruction::checkcast);
    writer->addInt16(val);
    return writer->getByteArray(start, currentOffset());
}

bytearray_t Bytecode::jump(Instruction instr, int16_t offset)
{
    if (!isJump(instr)) {
        internal_error("Jump accept only jump opcodes");
    }
    size_t start = currentOffset();
    writeSimple(instr);
    writer->addInt16(offset);
    return writer->getByteArray(start, currentOffset());
}

uint32_t Bytecode::futureJump(Instruction instr)
{
    if (!isJump(instr)) {
        internal_error("Jump accept only jump opcodes");
    }
    writeSimple(instr);
    size_t currOffset = currentOffset();
    writer->addInt16(0);
    size_t endOffset = currentOffset();
    uint32_t num = ++futureCounter;
    _futures[num] = std::make_pair(currOffset, endOffset);
    return num;
}

void Bytecode::resolveFuture(uint32_t futureNum)
{
    if (!_futures.count(futureNum)) {
        internal_error("No such jump future");
    }
    std::pair<size_t, size_t> bounds = _futures[futureNum];
    int16_t offset = currentOffset() - bounds.first;
    writer->setBytes(bounds.first, bounds.second, &offset);
}

void Bytecode::makeWaypoint(void* target)
{
    _waypoints[target] = currentOffset();
}

size_t Bytecode::popWaypoint(void* target)
{
    size_t res = _waypoints[target];
    _waypoints.erase(target);
    return res;
}

size_t Bytecode::getWaypoint(void* target)
{
    return _waypoints[target];
}

bytearray_t Bytecode::bipush(int8_t val)
{
    size_t start = currentOffset();
    writeSimple(Instruction::bipush);
    writer->addByte(val);
    return writer->getByteArray(start, currentOffset());
}

bytearray_t Bytecode::sipush(int16_t val)
{
    size_t start = currentOffset();
    writeSimple(Instruction::sipush);
    writer->addInt16(val);
    return writer->getByteArray(start, currentOffset());
}

bytearray_t Bytecode::newArray(type* type)
{
    if (dynamic_cast<struct_type*>(type) != nullptr) {
        struct_type* structType = dynamic_cast<struct_type*>(type);
        size_t start = currentOffset();
        writeSimple(Instruction::anewarray);
        writer->addInt16(structType->record->getConstantFor(this->method->owner)->number);
        return writer->getByteArray(start, currentOffset());
    }
    else {
        internal_error("New array must be created with struct type");
    }
}

bytearray_t Bytecode::newObject(type* type)
{
    if (dynamic_cast<struct_type*>(type) != nullptr) {
        struct_type* structType = dynamic_cast<struct_type*>(type);
        size_t start = currentOffset();
        writeSimple(Instruction::_new);
        writer->addInt16(structType->record->getConstantFor(this->method->owner)->number);
        return writer->getByteArray(start, currentOffset());
    }
    else {
        internal_error("New array must be created with struct type");
    }
}

bytearray_t Bytecode::arrayLength()
{
    writeSimple(Instruction::arraylength);
    return writer->getByteArray(currentOffset() - 1, currentOffset());
}

bytearray_t Bytecode::constLoad(constant_record* constant)
{
    uint16_t num = constant->number;
    if (dynamic_cast<constant_double*>(constant) != nullptr || dynamic_cast<constant_long*>(constant) != nullptr) {
        return ldc2_w(num);
    }
    if (num <= UINT8_MAX) {
        return ldc((uint8_t)num);
    }
    else {
        return ldc_w(num);
    }
}

bytearray_t Bytecode::invokemethod(method_record* record, CallInfo type, struct_type * trueOwner)
{
    if (record == nullptr) {
        codegen_error("Record for invoke is null");
    }

    if (type == CallInfo::VIRTUAL) {
        return invokevirtual(record->getConstantFor(this->method->owner, trueOwner)->number);
    }
    else if (type == CallInfo::STATIC) {
        return invokestatic(record->getConstantFor(this->method->owner, trueOwner)->number);
    }
    else if (type == CallInfo::SPECIAL) {
        return invokespecial(record->getConstantFor(this->method->owner, trueOwner)->number);
    }
}

bytearray_t Bytecode::nullLoad()
{
    writeSimple(Instruction::aconst_null);
    return writer->getByteArray(currentOffset() - 1, currentOffset());
}

bytearray_t Bytecode::intLoad(int16_t val)
{
    size_t start = currentOffset();
    if (val == 0) {
        writeSimple(Instruction::iconst_0);
    }
    else if (val == 1) {
        writeSimple(Instruction::iconst_1);
    }
    else if (val == 2) {
        writeSimple(Instruction::iconst_2);
    }
    else if (val == 3) {
        writeSimple(Instruction::iconst_3);
    }
    else if (val == 4) {
        writeSimple(Instruction::iconst_4);
    }
    else if (val == 5) {
        writeSimple(Instruction::iconst_5);
    }
    else if (val == -1) {
        writeSimple(Instruction::iconst_m1);
    }
    else if (val < INT8_MIN || val > INT8_MAX) {
        bipush((int8_t)val);
    }
    else {
        sipush(val);
    }
    return writer->getByteArray(start, currentOffset());
}

bytearray_t Bytecode::boolLoad(bool val)
{
    size_t start = currentOffset();
    if (val) {
        writeSimple(Instruction::iconst_1);
    }
    else {
        writeSimple(Instruction::iconst_0);
    }
    return writer->getByteArray(start, currentOffset());
}

