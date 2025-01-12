package brookit.vb;

import java.lang.String;

public class Long extends Number {
    long _src;

    public Long(long num) {
        _src = (int) num;
    }

    public Long(double num) {
        _src = (int) num;
    }

    public Long(Number n) {
        _src = n.getInteger();
    }

    public Long() {
        _src = 0;
    }

    public Long(boolean num) {
        _src = num ? 1 : 0;
    }

    public Long(char num) {
        _src = num;
    }

    @Override
    public int byteSize() {
        return 8;
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
