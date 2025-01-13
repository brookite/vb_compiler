package brookit.vb.lang;

import java.lang.String;

public class Byte extends Number {
    byte _src;

    public Byte(Number n) {
        _src = (byte) n.getInteger();
    }

    public Byte() {
        _src = 0;
    }

    public Byte(long num) {
        _src = (byte) num;
    }

    public Byte(double num) {
        _src = (byte) num;
    }

    public Byte(boolean num) {
        _src = (byte) (num ? 1 : 0);
    }

    public Byte(char num) {
        _src = (byte) num;
    }

    @Override
    public int byteSize() {
        return 1;
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
