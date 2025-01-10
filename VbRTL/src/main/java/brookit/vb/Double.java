package brookit.vb;

import java.lang.String;

public class Double extends Number {
    double _src;

    public Double(double num) {
        _src = num;
    }

    public Double(long num) {
        _src = (double) num;
    }

    public Double(boolean num) {
        _src = num ? 1 : 0;
    }

    public Double(char num) {
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
