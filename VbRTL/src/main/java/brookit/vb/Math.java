package brookit.vb;

import java.lang.String;
import java.util.Random;

public class Math extends Object {
    public static Double Sin(Number type) {
        return new Double(java.lang.Math.sin(type.getFloat()));
    }

    public static Double Cos(Number type) {
        return new Double(java.lang.Math.cos(type.getFloat()));
    }

    public static Double Abs(Number type) {
        return new Double(java.lang.Math.abs(type.getFloat()));
    }

    public static Long RandomInt(Long max) {
        return new Long(new Random().nextLong(max.getInteger()));
    }

    public static Double Random() {
        return new Double(java.lang.Math.random());
    }

    public static Number Min(Number a, Number b) {
        if (a.lt(b).getBoolean()) {
            return a;
        }
        return b;
    }

    public static Number Max(Number a, Number b) {
        if (a.gt(b).getBoolean()) {
            return a;
        }
        return b;
    }

    @Override
    public String toJvmString() {
        return "Math class object";
    }

    @Override
    public Boolean equals(Object other) {
        return new Boolean(false);
    }
}
