package brookit.vb.lang;

import java.lang.String;

public class Boolean extends Number {
    boolean _src;

    public Boolean(Number n) {
        _src = n.getBoolean();
    }

    public Boolean() {
        _src = false;
    }

    public Boolean(long num) {
        _src = num != 0;
    }

    public Boolean(double num) {
        _src = num != 0;
    }

    public Boolean(boolean num) {
        _src = num;
    }

    public Boolean(char num) {
        _src = num != 0;
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
        return _src ? 1.0 : 0.0;
    }

    @Override
    public boolean getBoolean() {
        return _src;
    }

    @Override
    public long getInteger() {
        return _src ? 1 : 0;
    }

    @Override
    public String toJvmString() {
        return java.lang.Boolean.toString(_src);
    }
}
