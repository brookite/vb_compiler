package brookit.vb;

import java.lang.String;

public class Char extends Number {
    char _src;

    public Char(long num) {
        _src = (char) num;
    }

    public Char(double num) {
        _src = (char) num;
    }

    public Char(boolean num) {
        _src = (char) (num ? 1 : 0);
    }

    public Char(char num) {
        _src = (char) num;
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
        return java.lang.Character.toString(_src);
    }
}
