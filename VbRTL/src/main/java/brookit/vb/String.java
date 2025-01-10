package brookit.vb;

public class String extends Object {
    private java.lang.String _jvm;

    public String(java.lang.String str) {
        _jvm = str;
    }

    public ULong Length() {
        return new ULong(_jvm.length());
    }

    public String Format(Object[] fmt) {
        return new String(java.lang.String.format(this.toJvmString(), fmt));
    }

    public String concat(String other) {
        return new String(other.toJvmString().concat(other.toJvmString()));
    }

    @Override
    public java.lang.String toJvmString() {
        return _jvm;
    }

    @Override
    public Boolean equals(Object other) {
        return null;
    }
}
