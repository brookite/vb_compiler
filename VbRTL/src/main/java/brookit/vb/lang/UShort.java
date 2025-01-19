package brookit.vb.lang;

import java.lang.String;

public class UShort extends Number {
    short _src;

    public UShort(long num) {
        _src = (short) num;
    }

    public UShort(Number n) {
        _src = (short) n.getInteger();
    }

    public UShort(double num) {
        _src = (short) num;
    }

    public UShort(boolean num) {
        _src = (short) (num ? 1 : 0);
    }

    public UShort(char num) {
        _src = (short) num;
    }

    public UShort() {
        _src = 0;
    }

    public UShort(brookit.vb.lang.String val) {
        _src = java.lang.Short.parseShort(val.toJvmString());
    }

    @Override
    public int byteSize() {
        return 2;
    }

    @Override
    public boolean isUnsigned() {
        return false;
    }

    @Override
    public boolean isInteger() {
        return true;
    }

    @Override
    public double getFloat() {
        return _src;
    }

    @Override
    public boolean getBoolean() {
        return _src != 0;
    }

    @Override
    public long getInteger() {
        return _src;
    }

    @Override
    public String toJvmString() {
        return java.lang.Long.toUnsignedString(getInteger());
    }
}
