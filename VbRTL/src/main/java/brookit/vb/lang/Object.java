package brookit.vb.lang;

public abstract class Object {
    public java.lang.String toJvmString() {
        return super.toString();
    }

    public String ToString() {
        return new String(toJvmString());
    }

    public java.lang.String toString() {
        return ToString().toJvmString();
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
