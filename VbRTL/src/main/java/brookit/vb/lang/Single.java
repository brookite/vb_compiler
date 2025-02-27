package brookit.vb.lang;

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

    public Single() {
        _src = 0;
    }

    public Single(brookit.vb.lang.String val) {
        _src = java.lang.Float.parseFloat(val.toJvmString());
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
        if (java.lang.Math.abs(getFloat() - getInteger()) == 0) {
            return java.lang.Long.toString(getInteger());
        }
        return java.lang.Double.toString(getFloat());
    }
}
