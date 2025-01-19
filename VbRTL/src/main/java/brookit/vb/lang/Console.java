package brookit.vb.lang;

import java.lang.String;
import java.util.Arrays;
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

    public static void WriteLine(java.lang.Object o) {
        if (o == null) {
            System.out.println("Nothing");
        } else if (o instanceof Object obj) {
            System.out.println(obj.ToString().toString());
        } else if (o instanceof Object[] arr) {
            System.out.println(Arrays.toString(arr));
        } else {
            System.out.println(o.toString());
        }
    }

    public static void Write(java.lang.Object o) {
        if (o == null) {
            System.out.print("Nothing");
        } else if (o instanceof Object obj) {
            System.out.print(obj.ToString().toString());
        } else if (o instanceof Object[] arr){
            System.out.print(Arrays.toString(arr));
        } else {
            System.out.println(o.toString());
        }
    }

    public static brookit.vb.lang.String ReadLine() {
        try {
            return new brookit.vb.lang.String(scanner.nextLine());
        } catch (Exception e) {
            throw new RuntimeException("Error reading line: " + e.getMessage(), e);
        }
    }

    public static Long ReadInt() {
        try {
            return new Long(scanner.nextLong());
        } catch (Exception e) {
            throw new RuntimeException("Error reading integer: " + e.getMessage(), e);
        } finally {
            scanner.nextLine(); // Clear the buffer
        }
    }

    public static Double ReadDouble() {
        try {
            return new Double(scanner.nextDouble());
        } catch (Exception e) {
            throw new RuntimeException("Error reading double: " + e.getMessage(), e);
        } finally {
            scanner.nextLine(); // Clear the buffer
        }
    }

    public static Boolean ReadBoolean() {
        try {
            return new Boolean(scanner.nextBoolean());
        } catch (Exception e) {
            throw new RuntimeException("Error reading boolean: " + e.getMessage(), e);
        } finally {
            scanner.nextLine(); // Clear the buffer
        }
    }
}
