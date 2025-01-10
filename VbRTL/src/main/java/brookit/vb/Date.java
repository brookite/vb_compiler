package brookit.vb;

import java.time.LocalDateTime;
import java.time.ZoneId;
import java.time.ZoneOffset;

public class Date {
    public int year = 1970;
    public int month = 1;
    public int day = 1;

    public int hour = 0 ;
    public int minute = 0;
    public int second = 0;

    private void validate() {
        if (year < 0 || (month < 1 || month > 12) ||
                (day < 1 || day > 31) || (hour < 0 || hour > 23) ||
                (minute < 0 || minute > 59) || (second < 0 || second > 23)) {
            throw new IllegalArgumentException("Invalid date components");
        }
    }

    public Date(int year, int month, int day) {
        this.year = year;
        this.month = month;
        this.day = day;
    }

    public Date(int year, int month, int day, int hour, int minute, int second) {
        this.year = year;
        this.month = month;
        this.day = day;
        this.hour = hour;
        this.minute = minute;
        this.second = second;
    }

    public static Date fromTime(int hour, int minute, int second) {
        return new Date(1970, 1, 1, hour, minute, second);
    }

    public Long ToTimestamp() {
        return new Long(toJavaDate().toEpochSecond(ZoneOffset.UTC));
    }

    public static Date FromTimestamp(Long val) {
        return fromJavaDate(LocalDateTime.ofEpochSecond(val.getInteger(), 0, ZoneOffset.UTC));
    }

    private static Date fromJavaDate(LocalDateTime dt) {
        return new Date(dt.getYear(), dt.getMonthValue(), dt.getDayOfMonth(), dt.getHour(), dt.getMinute(), dt.getSecond());
    }

    private LocalDateTime toJavaDate() {
        return LocalDateTime.of(year, month, day, hour, minute, second);
    }

    public static Date Now() {
        return fromJavaDate(LocalDateTime.now());
    }
}
