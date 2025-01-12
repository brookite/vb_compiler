package brookit.vb;

import java.lang.String;

public class Integer extends Number {
    int _src;

    public Integer(long num) {
        _src = (int) num;
    }

    public Integer(Number n) {
        _src = (int) n.getInteger();
    }

    public Integer() {
        _src = 0;
    }

    public Integer(double num) {
        _src = (int) num;
    }

    public Integer(boolean num) {
        _src = (int) (num ? 1 : 0);
    }

    public Integer(char num) {
        _src = (int) num;
    }

    @Override
    public int byteSize() {
        return 4;
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
