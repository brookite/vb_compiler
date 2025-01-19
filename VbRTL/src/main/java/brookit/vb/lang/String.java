package brookit.vb.lang;

public class String extends Object {
    private java.lang.String _jvm;

    public String(java.lang.String str) {
        _jvm = str;
    }

    public String() {
        _jvm = "";
    }

    public ULong Length() {
        return new ULong(_jvm.length());
    }

    public String Format(Object[] fmt) {
        return new String(java.lang.String.format(this.toJvmString(), fmt));
    }

    public String Concat(String other) {
        return new String(this.toJvmString().concat(other.toJvmString()));
    }

    public Char Get(Integer number) {return new Char(_jvm.charAt((int) number.getInteger()));}

    @Override
    public java.lang.String toJvmString() {
        return _jvm;
    }

    @Override
    public Boolean equals(Object other) {
        return null;
    }
}
