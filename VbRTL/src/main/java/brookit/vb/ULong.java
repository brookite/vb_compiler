package brookit.vb;

import java.lang.String;

public class ULong extends Number {
    long _src;

    public ULong(long num) {
        _src = (int) num;
    }

    public ULong(double num) {
        _src = (int) num;
    }

    public ULong(boolean num) {
        _src = num ? 1 : 0;
    }

    public ULong(char num) {
        _src = num;
    }

    @Override
    public int byteSize() {
        return 8;
    }

    public ULong(Number n) {
        _src = n.getInteger();
    }

    public ULong() {
        _src = 0;
    }

    @Override
    public boolean isUnsigned() {
        return true;
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
