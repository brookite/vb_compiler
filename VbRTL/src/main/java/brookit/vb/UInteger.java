package brookit.vb;

import java.lang.String;

public class UInteger extends Number {
    int _src;

    public UInteger(long num) {
        _src = (int) num;
    }

    public UInteger(Number n) {
        _src = (int) n.getInteger();
    }

    public UInteger() {
        _src = 0;
    }

    public UInteger(double num) {
        _src = (int) num;
    }

    public UInteger(boolean num) {
        _src = num ? 1 : 0;
    }

    public UInteger(char num) {
        _src = num;
    }

    @Override
    public int byteSize() {
        return 4;
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
