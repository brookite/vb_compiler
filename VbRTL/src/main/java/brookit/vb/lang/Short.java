package brookit.vb.lang;

import java.lang.String;

public class Short extends Number {
    short _src;

    public Short(long num) {
        _src = (short) num;
    }

    public Short(double num) {
        _src = (short) num;
    }

    public Short(Number n) {
        _src = (short) n.getInteger();
    }

    public Short(boolean num) {
        _src = (short) (num ? 1 : 0);
    }

    public Short() {
        _src = 0;
    }

    public Short(brookit.vb.lang.String val) {
        _src = java.lang.Short.parseShort(val.toJvmString());
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
