package brookit.vb;

import java.lang.String;

public class Single extends Number {
    float _src;

    public Single(double num) {
        _src = (float) num;
    }

    public Single(long num) {
        _src = (float) num;
    }

    public Single(Number n) {
        _src = (float) n.getFloat();
    }

    public Single(boolean num) {
        _src = num ? 1 : 0;
    }

    public Single(char num) {
        _src = num;
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
        return false;
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
        return (long) _src;
    }

    @Override
    public String toJvmString() {
        return java.lang.Double.toString(getFloat());
    }
}
