package brookit.vb;

import java.lang.String;
import java.util.Scanner;

public class Console extends Object {
    private static final Scanner scanner = new Scanner(System.in);

    @Override
    public String toJvmString() {
        return "IO object class";
    }

    @Override
    public Boolean equals(Object other) {
        return new Boolean(false);
    }

    public static void WriteLine(Object o) {
        System.out.println(o.toJvmString());
    }

    public static void Write(Object o) {
        System.out.print(o.toJvmString());
    }

    public static brookit.vb.String ReadLine() {
        try {
            return new brookit.vb.String(scanner.nextLine());
        } catch (Exception e) {
            throw new RuntimeException("Error reading line: " + e.getMessage(), e);
        }
    }

    public static brookit.vb.Long ReadInt() {
        try {
            return new brookit.vb.Long(scanner.nextLong());
        } catch (Exception e) {
            throw new RuntimeException("Error reading integer: " + e.getMessage(), e);
        } finally {
            scanner.nextLine(); // Clear the buffer
        }
    }

    public static brookit.vb.Double ReadDouble() {
        try {
            return new brookit.vb.Double(scanner.nextDouble());
        } catch (Exception e) {
            throw new RuntimeException("Error reading double: " + e.getMessage(), e);
        } finally {
            scanner.nextLine(); // Clear the buffer
        }
    }

    public static brookit.vb.Boolean ReadBoolean() {
        try {
            return new brookit.vb.Boolean(scanner.nextBoolean());
        } catch (Exception e) {
            throw new RuntimeException("Error reading boolean: " + e.getMessage(), e);
        } finally {
            scanner.nextLine(); // Clear the buffer
        }
    }
}
