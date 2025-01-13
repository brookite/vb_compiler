package brookit.vb.lang;

import java.lang.reflect.InvocationTargetException;
import java.util.Arrays;

public class CompilerUtils {
    public static Object[] redim(Object[] array, Number size) {
        if (array == null || size == null) {
            throw new IllegalArgumentException("Array and size must not be null");
        }

        int oldLength = array.length;
        long newSize = size.getInteger();
        if (newSize < 0) {
            throw new IllegalArgumentException("Size cannot be negative");
        }

        Object[] newArray = Arrays.copyOf(array, (int) newSize);
        for (int i = oldLength; i < newSize; i++) {
            if (Number.class.isAssignableFrom(array.getClass().getComponentType())) {
                try {
                    newArray[i] = (Object) array.getClass().getComponentType().getConstructor().newInstance();
                } catch (InstantiationException | IllegalAccessException | InvocationTargetException |
                         NoSuchMethodException e) {
                    throw new RuntimeException(e);
                }
            } else {
                newArray[i] = null;
            }
        }
        return newArray;
    }

    public static void erase(Object[] array) {
        if (array == null) {
            throw new IllegalArgumentException("Array must not be null");
        }

        if (Number.class.isAssignableFrom(array.getClass().getComponentType())) {
            try {
                Arrays.fill(array, array.getClass().getComponentType().getConstructor().newInstance());
            } catch (InstantiationException | IllegalAccessException | InvocationTargetException |
                     NoSuchMethodException e) {
                throw new RuntimeException(e);
            }
        } else {
            Arrays.fill(array, null);
        }

    }
}
