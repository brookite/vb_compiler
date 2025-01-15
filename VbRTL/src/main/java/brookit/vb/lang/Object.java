package brookit.vb.lang;

public abstract class Object {
    public abstract java.lang.String toJvmString();

    public String ToString() {
        return new String(toJvmString());
    }

    public java.lang.String toString() {
        return toJvmString();
    }

    public abstract Boolean equals(Object other);

    public Boolean notEquals(Object other) {
        return new Boolean(equals(other).not().getBoolean());
    }

    public Boolean is(Object other) {
        return new Boolean(this == other);
    }

    public Boolean isNot(Object other) {
        return new Boolean(is(other).not().getBoolean());
    }
}
