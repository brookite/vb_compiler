package brookit.vb.lang;

import java.lang.reflect.InvocationTargetException;

public abstract class Number extends Object {
    public abstract int byteSize();

    public abstract boolean isUnsigned();

    public abstract boolean isInteger();

    public abstract double getFloat();

    public abstract boolean getBoolean();

    public abstract long getInteger();

    public Number inc() {
        try {
            if (!this.isInteger()) {
                double a = this.getFloat();
                double b = 1;
                double res = a + b;
                return this.getClass().getDeclaredConstructor(double.class).newInstance(res);
            } else {
                long a = this.getInteger();
                long b = 1;
                long res = a + b;
                return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number add(Number other) {
        try {
            if (!other.isInteger() || !this.isInteger()) {
                double a = this.getFloat();
                double b = other.getFloat();
                double res = a + b;
                return new Double(res);
            } else {
                long a = this.getInteger();
                long b = other.getInteger();
                long res = a + b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
                    }
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number sub(Number other) {
        try {
            if (!other.isInteger() || !this.isInteger()) {
                double a = this.getFloat();
                double b = other.getFloat();
                double res = a - b;
                return new Double(res);
            } else {
                long a = this.getInteger();
                long b = other.getInteger();
                long res = a - b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
                    }
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new RuntimeException(e);
        }
    }

    public Number mul(Number other) {
        try {
            if (!other.isInteger() || !this.isInteger()) {
                double a = this.getFloat();
                double b = other.getFloat();
                double res = a * b;
                return new Double(res);
            } else {
                long a = this.getInteger();
                long b = other.getInteger();
                long res = a * b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
                    }
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number div(Number other) {
        if (!other.isInteger() || !this.isInteger()) {
            double a = this.getFloat();
            double b = other.getFloat();
            double res = a / b;
            return new Double(res);
        } else {
            long a = this.getInteger();
            long b = other.getInteger();
            double res = ((double)a) / b;
            return new Double(res);
        }
    }

    public Number floorDiv(Number other) {
        try {
            if (!other.isInteger() || !this.isInteger()) {
                double a = this.getFloat();
                double b = other.getFloat();
                double res = a / b;
                return new Long(res);
            } else {
                long a = this.getInteger();
                long b = other.getInteger();
                long res = a / b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
                    }
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number exp(Number other) {
        try {
            if (!other.isInteger() || !this.isInteger()) {
                double a = this.getFloat();
                double b = other.getFloat();
                double res = java.lang.Math.pow(a, b);
                return new Double(res);
            } else {
                long a = this.getInteger();
                long b = other.getInteger();
                long res = (long) java.lang.Math.pow(a, b);
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
                    }
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number mod(Number other) {
        try {
            if (!other.isInteger() || !this.isInteger()) {
                double a = this.getFloat();
                double b = other.getFloat();
                double res = a % b;
                return new Double(res);
            } else {
                long a = this.getInteger();
                long b = other.getInteger();
                long res = a % b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
                    }
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number or(Number other) {
        try {
            long a = this.getInteger();
            long b = other.getInteger();
            long res = a | b;
            if (other.byteSize() > this.byteSize()) {
                return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
            } else if (other.byteSize() < this.byteSize()) {
                return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
            } else {
                if (other.isUnsigned()) {
                    return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
                } else {
                    return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number orElse(Number other) {
        try {
            boolean a = this.getBoolean();
            boolean b = other.getBoolean();
            boolean res = a || b;
            if (other.byteSize() > this.byteSize()) {
                return other.getClass().getDeclaredConstructor(boolean.class).newInstance(res);
            } else if (other.byteSize() < this.byteSize()) {
                return this.getClass().getDeclaredConstructor(boolean.class).newInstance(res);
            } else {
                if (other.isUnsigned()) {
                    return this.getClass().getDeclaredConstructor(boolean.class).newInstance(res);
                } else {
                    return other.getClass().getDeclaredConstructor(boolean.class).newInstance(res);
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number and(Number other) {
        try {
            long a = this.getInteger();
            long b = other.getInteger();
            long res = a & b;
            if (other.byteSize() > this.byteSize()) {
                return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
            } else if (other.byteSize() < this.byteSize()) {
                return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
            } else {
                if (other.isUnsigned()) {
                    return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
                } else {
                    return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number andAlso(Number other) {
        try {
            boolean a = this.getBoolean();
            boolean b = other.getBoolean();
            boolean res = a && b;
            if (other.byteSize() > this.byteSize()) {
                return other.getClass().getDeclaredConstructor(boolean.class).newInstance(res);
            } else if (other.byteSize() < this.byteSize()) {
                return this.getClass().getDeclaredConstructor(boolean.class).newInstance(res);
            } else {
                if (other.isUnsigned()) {
                    return this.getClass().getDeclaredConstructor(boolean.class).newInstance(res);
                } else {
                    return other.getClass().getDeclaredConstructor(boolean.class).newInstance(res);
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number unaryPlus() {
        try {
            if (!this.isInteger()) {
                double a = this.getFloat();
                double res = +a;
                return this.getClass().getDeclaredConstructor(double.class).newInstance(res);
            } else {
                long a = this.getInteger();
                long res = +a;
                return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number unaryMinus() {
        try {
            if (!this.isInteger()) {
                double a = this.getFloat();
                double res = -a;
                return this.getClass().getDeclaredConstructor(double.class).newInstance(res);
            } else {
                long a = this.getInteger();
                long res = -a;
                return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number not() {
        try {
            if (this instanceof Boolean) {
                boolean res = !(this.getBoolean());
                return this.getClass().getDeclaredConstructor(boolean.class).newInstance(res);
            } else {
                long res = ~(this.getInteger());
                return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number lshift(Number other) {
        try {
            long a = this.getInteger();
            long b = other.getInteger();
            long res = a << b;
            if (other.byteSize() > this.byteSize()) {
                return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
            } else if (other.byteSize() < this.byteSize()) {
                return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
            } else {
                if (other.isUnsigned()) {
                    return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
                } else {
                    return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number rshift(Number other) {
        try {
            long a = this.getInteger();
            long b = other.getInteger();
            long res = a >> b;
            if (other.byteSize() > this.byteSize()) {
                return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
            } else if (other.byteSize() < this.byteSize()) {
                return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
            } else {
                if (other.isUnsigned()) {
                    return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
                } else {
                    return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number lte(Number other) {
        if (!other.isInteger() || !this.isInteger()) {
            double a = this.getFloat();
            double b = other.getFloat();
            boolean res = a <= b;
            return new Boolean(res);
        } else {
            long a = this.getInteger();
            long b = other.getInteger();
            boolean res = a <= b;
            return new Boolean(res);
        }
    }

    public Number gte(Number other) {
        if (!other.isInteger() || !this.isInteger()) {
            double a = this.getFloat();
            double b = other.getFloat();
            boolean res = a >= b;
            return new Boolean(res);
        } else {
            long a = this.getInteger();
            long b = other.getInteger();
            boolean res = a >= b;
            return new Boolean(res);
        }
    }

    public Number lt(Number other) {
        if (!other.isInteger() || !this.isInteger()) {
            double a = this.getFloat();
            double b = other.getFloat();
            boolean res = a < b;
            return new Boolean(res);
        } else {
            long a = this.getInteger();
            long b = other.getInteger();
            boolean res = a < b;
            return new Boolean(res);
        }
    }

    public Number gt(Number other) {
        if (!other.isInteger() || !this.isInteger()) {
            double a = this.getFloat();
            double b = other.getFloat();
            boolean res = a > b;
            return new Boolean(res);
        } else {
            long a = this.getInteger();
            long b = other.getInteger();
            boolean res = a > b;
            return new Boolean(res);
        }
    }

    public Number xor(Number other) {
        try {
            long a = this.getInteger();
            long b = other.getInteger();
            long res = a ^ b;
            if (other.byteSize() > this.byteSize()) {
                return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
            } else if (other.byteSize() < this.byteSize()) {
                return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
            } else {
                if (other.isUnsigned()) {
                    return this.getClass().getDeclaredConstructor(long.class).newInstance(res);
                } else {
                    return other.getClass().getDeclaredConstructor(long.class).newInstance(res);
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Boolean equals(Object o) {
        if (!(o instanceof Number)) {
            return new Boolean(false);
        }
        Number other = (Number) o;
        if (!other.isInteger() || !this.isInteger()) {
            double a = this.getFloat();
            double b = other.getFloat();
            boolean res = a == b;
            return new Boolean(res);
        } else {
            long a = this.getInteger();
            long b = other.getInteger();
            boolean res = a == b;
            return new Boolean(res);
        }
    }
}
