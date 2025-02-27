package brookit.vb.lang;

import java.lang.String;

public class Char extends Number {
    char _src;

    public Char(Number n) {
        _src = (char) n.getInteger();
    }

    public Char(long num) {
        _src = (char) num;
    }

    public Char() {
        _src = 0;
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

    public Char(brookit.vb.lang.String val) {
        if (val.toJvmString().isEmpty()) {
            throw new RuntimeException("String is empty to convert to char");
        }
        _src = val.toString().charAt(0);
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
