package brookit.vb.lang;

import java.lang.Double;
import java.lang.reflect.InvocationTargetException;

public abstract class Number extends Object {
    public abstract int byteSize();

    public abstract boolean isUnsigned();

    public abstract boolean isInteger();

    public abstract double getFloat();

    public abstract boolean getBoolean();

    public abstract long getInteger();

    public Number add(Number other) {
        try {
            if (!other.isInteger() || !this.isInteger()) {
                double a = this.getFloat();
                double b = other.getFloat();
                double res = a + b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    }
                }
            } else {
                long a = this.getInteger();
                long b = other.getInteger();
                long res = a + b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
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
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    }
                }
            } else {
                long a = this.getInteger();
                long b = other.getInteger();
                long res = a - b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                    }
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number mul(Number other) {
        try {
            if (!other.isInteger() || !this.isInteger()) {
                double a = this.getFloat();
                double b = other.getFloat();
                double res = a * b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    }
                }
            } else {
                long a = this.getInteger();
                long b = other.getInteger();
                long res = a * b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                    }
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number div(Number other) {
        try {
            if (!other.isInteger() || !this.isInteger()) {
                double a = this.getFloat();
                double b = other.getFloat();
                double res = a / b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    }
                }
            } else {
                long a = this.getInteger();
                long b = other.getInteger();
                long res = a / b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                    }
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number floorDiv(Number other) {
        try {
            if (!other.isInteger() || !this.isInteger()) {
                double a = this.getFloat();
                double b = other.getFloat();
                double res = a / b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    }
                }
            } else {
                long a = this.getInteger();
                long b = other.getInteger();
                long res = a / b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
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
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    }
                }
            } else {
                long a = this.getInteger();
                long b = other.getInteger();
                long res = (long) java.lang.Math.pow(a, b);
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
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
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    }
                }
            } else {
                long a = this.getInteger();
                long b = other.getInteger();
                long res = a % b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
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
                return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
            } else if (other.byteSize() < this.byteSize()) {
                return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
            } else {
                if (other.isUnsigned()) {
                    return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else {
                    return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
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
                return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
            } else if (other.byteSize() < this.byteSize()) {
                return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
            } else {
                if (other.isUnsigned()) {
                    return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else {
                    return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
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
                return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
            } else if (other.byteSize() < this.byteSize()) {
                return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
            } else {
                if (other.isUnsigned()) {
                    return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else {
                    return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
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
                return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
            } else if (other.byteSize() < this.byteSize()) {
                return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
            } else {
                if (other.isUnsigned()) {
                    return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else {
                    return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
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
                return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
            } else {
                long a = this.getInteger();
                long res = +a;
                return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
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
                return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
            } else {
                long a = this.getInteger();
                long res = -a;
                return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number not() {
        try {
            long a = this.getInteger();
            long res = ~a;
            return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
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
                return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
            } else if (other.byteSize() < this.byteSize()) {
                return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
            } else {
                if (other.isUnsigned()) {
                    return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else {
                    return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
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
                return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
            } else if (other.byteSize() < this.byteSize()) {
                return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
            } else {
                if (other.isUnsigned()) {
                    return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else {
                    return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number lte(Number other) {
        try {
            if (!other.isInteger() || !this.isInteger()) {
                double a = this.getFloat();
                double b = other.getFloat();
                boolean res = a <= b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    }
                }
            } else {
                long a = this.getInteger();
                long b = other.getInteger();
                boolean res = a <= b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                    }
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number gte(Number other) {
        try {
            if (!other.isInteger() || !this.isInteger()) {
                double a = this.getFloat();
                double b = other.getFloat();
                boolean res = a >= b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    }
                }
            } else {
                long a = this.getInteger();
                long b = other.getInteger();
                boolean res = a >= b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                    }
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number lt(Number other) {
        try {
            if (!other.isInteger() || !this.isInteger()) {
                double a = this.getFloat();
                double b = other.getFloat();
                boolean res = a < b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    }
                }
            } else {
                long a = this.getInteger();
                long b = other.getInteger();
                boolean res = a < b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                    }
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number gt(Number other) {
        try {
            if (!other.isInteger() || !this.isInteger()) {
                double a = this.getFloat();
                double b = other.getFloat();
                boolean res = a > b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Double.class).newInstance(res);
                    }
                }
            } else {
                long a = this.getInteger();
                long b = other.getInteger();
                boolean res = a > b;
                if (other.byteSize() > this.byteSize()) {
                    return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else if (other.byteSize() < this.byteSize()) {
                    return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else {
                    if (other.isUnsigned()) {
                        return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                    } else {
                        return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                    }
                }
            }
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new ArithmeticException(e.getMessage());
        }
    }

    public Number xor(Number other) {
        try {
            long a = this.getInteger();
            long b = other.getInteger();
            long res = a ^ b;
            if (other.byteSize() > this.byteSize()) {
                return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
            } else if (other.byteSize() < this.byteSize()) {
                return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
            } else {
                if (other.isUnsigned()) {
                    return this.getClass().getDeclaredConstructor(Long.class).newInstance(res);
                } else {
                    return other.getClass().getDeclaredConstructor(Long.class).newInstance(res);
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
