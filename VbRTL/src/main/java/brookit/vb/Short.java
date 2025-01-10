package brookit.vb;

import java.lang.String;

public class Short extends Number {
    short _src;

    public Short(long num) {
        _src = (short) num;
    }

    public Short(double num) {
        _src = (short) num;
    }

    public Short(boolean num) {
        _src = (short) (num ? 1 : 0);
    }

    public Short(char num) {
        _src = (short) num;
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
        return java.lang.Long.toString(getInteger());
    }
}
