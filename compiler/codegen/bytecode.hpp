#include "../utils.hpp"
#include <unordered_set>
#include "constants.hpp"

enum class CallInfo : uint8_t {
    VIRTUAL,
    STATIC,
    SPECIAL,
    INTERFACE
};

enum class Instruction : uint8_t {
    ldc = 0x12,
    ldc_w = 0x13,
    ldc2_w = 0x14,

    invokespecial = 0xb7,
    invokestatic = 0xb8,
    invokevirtual = 0xb6,
    invokeinterface = 0xb9,

    aload = 0x19,
    astore = 0x3a,
    aaload = 0x32,
    aastore = 0x53,
    istore = 0x36,
    iload = 0x15,
    getfield = 0xb4,
    getstatic = 0xb2,
    putfield = 0xb5,
    putstatic = 0xb3,

    _return = 0xb1,
    areturn = 0xb0,

    _new = 0xbb,
    anewarray = 0xbd,
    arraylength = 0xbe,
    dup = 0x59,
    dup2 = 0x5c,

    iconst_m1 = 0x2,
    iconst_0 = 0x3,
    iconst_1 = 0x4,
    iconst_2 = 0x5,
    iconst_3 = 0x6,
    iconst_4 = 0x7,
    iconst_5 = 0x8,
    bipush = 0x10,
    sipush = 0x11,
    aconst_null = 0x1,

    if_icmpeq = 0x9f,
    if_icmpne = 0xa0,
    if_icmplt = 0xa1,
    if_icmpge = 0xa2,
    if_icmpgt = 0xa3,
    if_icmple = 0xa4,

    dcmpg = 0x98,
    dcmpl = 0x97,

    if_acmpeq = 0xa5,
    if_acmpne = 0xa6,

    ifnonnull = 0xc7,
    ifnull = 0xc6,

    ifeq = 0x99,
    ifne = 0x9a,
    iflt = 0x9b,
    ifge = 0x9c,
    ifgt = 0x9d,
    ifle = 0x9e,

    _goto = 0xa7,

    pop = 0x57,
    pop2 = 0x58,

    iadd = 0x60,
    isub = 0x64,
    imul = 0x68,
    ineg = 0x74,
    iinc = 0x84,

    i2d = 0x87,

    dadd = 0x63,
    dsub = 0x67,
    dmul = 0x6b,
    ddiv = 0x6f,
    dneg = 0x77,

    checkcast = 0xc0,
    instanceof = 0xc1,
    wide=0xc4
};

inline bool isJump(Instruction instruction) {
    static const std::unordered_set<Instruction> jumpInstructions = {
        Instruction::if_icmpeq, Instruction::if_icmpne, Instruction::if_icmplt, Instruction::if_icmpge, Instruction::if_icmpgt, Instruction::if_icmple,
        Instruction::_goto,
        Instruction::ifeq, Instruction::ifne, Instruction::iflt, Instruction::ifge, Instruction::ifgt, Instruction::ifle,
        Instruction::if_acmpeq, Instruction::if_acmpne,
        Instruction::ifnull, Instruction::ifnonnull
    };
    return jumpInstructions.find(instruction) != jumpInstructions.end();
}

struct Bytecode {
	byte_writer* writer;
    method_record* method;
    semantic_context* context;

    std::map<uint32_t, std::pair<size_t, size_t>> _futures;
    std::map<void*, size_t> _waypoints;
    uint32_t futureCounter = 0;

    stmt_node* lastWhile = nullptr;
    stmt_node* lastFor = nullptr;
    stmt_node* lastDo = nullptr;


    Bytecode();
    void writeSimple(Instruction instr);
    size_t currentOffset();

    bytearray_t ldc(uint8_t);
    bytearray_t ldc_w(uint16_t);
    bytearray_t ldc2_w(uint16_t);
    bytearray_t aload(uint16_t);
    bytearray_t astore(uint16_t);
    bytearray_t iload(uint16_t);
    bytearray_t istore(uint16_t);
    bytearray_t aaload();
    bytearray_t aastore();
    bytearray_t loadThis();
    bytearray_t pop();
    bytearray_t pop2();
    bytearray_t dup();
    bytearray_t dup2();

    bytearray_t invokespecial(uint16_t);
    bytearray_t invokevirtual(uint16_t);
    bytearray_t invokestatic(uint16_t);
    bytearray_t areturn();
    bytearray_t returnVoid();
    bytearray_t getfield(uint16_t);
    bytearray_t putfield(uint16_t);
    bytearray_t getstatic(uint16_t);
    bytearray_t putstatic(uint16_t);
    bytearray_t instanceof(uint16_t);
    bytearray_t checkcast(uint16_t);

    bytearray_t jump(Instruction instr, int16_t offset);
    uint32_t futureJump(Instruction instr);
    void resolveFuture(uint32_t futureNum);

    void makeWaypoint(void* target);
    size_t popWaypoint(void* target);
    size_t getWaypoint(void* target);

    bytearray_t bipush(int8_t);
    bytearray_t sipush(int16_t);

    bytearray_t newArray(type* type);
    bytearray_t newObject(type* type);
    bytearray_t arrayLength();


    bytearray_t constLoad(constant_record* constant);
    bytearray_t invokemethod(method_record* record, CallInfo type, struct_type* trueOwner = nullptr);
    bytearray_t nullLoad();
    bytearray_t intLoad(int16_t val);
    bytearray_t boolLoad(bool val);
};