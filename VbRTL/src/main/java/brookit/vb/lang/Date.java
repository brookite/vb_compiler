package brookit.vb.lang;

import java.lang.String;
import java.time.LocalDateTime;
import java.time.ZoneOffset;

public class Date {
    public Integer year;
    public Integer month;
    public Integer day;

    public Integer hour = new Integer(0) ;
    public Integer minute = new Integer(0);
    public Integer second = new Integer(0);

    private void validate() {
        if (year.getInteger() < 0 || (month.getInteger() < 1 || month.getInteger() > 12) ||
                (day.getInteger() < 1 || day.getInteger() > 31) || (hour.getInteger() < 0 || hour.getInteger() > 23) ||
                (minute.getInteger() < 0 || minute.getInteger() > 59) || (second.getInteger() < 0 || second.getInteger() > 59)) {
            throw new IllegalArgumentException("Invalid date components: " + String.join(",", new java.lang.String[] {year.toJvmString(), month.toJvmString(), day.toJvmString(),
                    hour.toJvmString(), minute.toJvmString(), second.toJvmString()}));
        }
    }

    public Date() {
        year = new Integer(1970);
        month = new Integer(1);
        day = new Integer(1);
    }

    public Date(int year, int month, int day) {
        this.year = new Integer(year);
        this.month = new Integer(month);
        this.day = new Integer(day);
        validate();
    }

    public Date(int year, int month, int day, int hour, int minute, int second) {
        this.year = new Integer(year);
        this.month = new Integer(month);
        this.day = new Integer(day);
        this.hour = new Integer(hour);
        this.minute = new Integer(minute);
        this.second = new Integer(second);
        validate();
    }

    public static Date fromTime(int hour, int minute, int second) {
        return new Date(1970, 1, 1, hour, minute, second);
    }

    public Long ToTimestamp() {
        validate();
        return new Long(toJavaDate().toEpochSecond(ZoneOffset.UTC));
    }

    public static Date OfTimestamp(Long val) {
        return fromJavaDate(LocalDateTime.ofEpochSecond(val.getInteger(), 0, ZoneOffset.UTC));
    }

    public static Date FromTimestamp(Long val) {
        return fromJavaDate(LocalDateTime.ofEpochSecond(val.getInteger(), 0, ZoneOffset.UTC));
    }

    private static Date fromJavaDate(LocalDateTime dt) {
        return new Date(dt.getYear(), dt.getMonthValue(), dt.getDayOfMonth(), dt.getHour(), dt.getMinute(), dt.getSecond());
    }

    private LocalDateTime toJavaDate() {
        validate();
        return LocalDateTime.of((int) year.getInteger(), (int) month.getInteger(),
                (int) day.getInteger(), (int) hour.getInteger(), (int) minute.getInteger(), (int) second.getInteger());
    }

    public static Date Now() {
        return fromJavaDate(LocalDateTime.now());
    }

    public brookit.vb.lang.String ToString() {
        return new brookit.vb.lang.String(toJavaDate().toString());
    }
}
