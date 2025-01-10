package brookit.vb;

import java.lang.String;

public class SByte extends Number {
    byte _src;

    public SByte(long num) {
        _src = (byte) num;
    }

    public SByte(double num) {
        _src = (byte) num;
    }

    public SByte(Number n) {
        _src = (byte) n.getInteger();
    }

    public SByte(boolean num) {
        _src = (byte) (num ? 1 : 0);
    }

    public SByte(char num) {
        _src = (byte) num;
    }

    @Override
    public int byteSize() {
        return 1;
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
