Class PhysicsFormulas
        Shared Function KineticEnergy(mass As Double, velocity As Double) As Double
            ' Формула: E = 0.5 * m * v^2
            Return 0.5 * mass * (velocity ^ 2)
        End Function

        Shared Function OhmsLaw(voltage As Double, resistance As Double) As Double
            ' Формула: I = U / R
            Return voltage / resistance
        End Function

        Shared Function GravitationalForce(mass1 As Double, mass2 As Double, distance As Double) As Double
            ' Формула: F = G * (m1 * m2) / d^2
            Const G As Double = 6.67430E-11 
            ' Гравитационная постоянная
            Return G * (mass1 * mass2) / (distance ^ 2)
        End Function
End Class

    ' Логические формулы
Class LogicalOperations
        Shared Function ComplexOperation1(a As Integer, b As Integer) As Integer
            ' Сложная операция: (a AND b) OR ((a XOR b) << 2)
            Return (a And b) Or ((a Xor b) << 2)
        End Function

        Shared Function ComplexOperation2(a As Integer, b As Integer, c As Integer) As Integer
            ' Сложная операция: ((a OR b) AND c) XOR (b >> 1)
            Return ((a Or b) And c) Xor (b >> 1)
        End Function

        Shared Function ComplexOperation3(a As Integer, b As Integer, c As Integer) As Integer
            ' Сложная операция: (a AND (b XOR c)) OR ((c << 1) AND (a >> 2))
            Return (a And (b Xor c)) Or ((c << 1) And (a >> 2))
        End Function
End Class

Class PhysicsAndLogicFormulas
    Shared Sub Main()
        ' Примеры использования физических формул
        Console.WriteLine("Физические формулы:")
        Console.WriteLine("Кинетическая энергия (масса = 5 кг, скорость = 10 м/с): " &
                          PhysicsFormulas.KineticEnergy(5, 10) & " Дж")
        Console.WriteLine("Сила тока (напряжение = 12 В, сопротивление = 4 Ом): " &
                          PhysicsFormulas.OhmsLaw(12, 4) & " А")
        Console.WriteLine("Сила тяжести (масса1 = 5 кг, масса2 = 10 кг, расстояние = 2 м): " &
                          PhysicsFormulas.GravitationalForce(5, 10, 2) & " Н")

        ' Примеры использования сложных логических операций
        Console.WriteLine("Сложные логические операции:")
        Dim a As Integer = 5
        Dim b As Integer = 3
        Dim c As Integer = 7
        
        Dim k as Boolean = LogicalOperations.ComplexOperation1(a, b)
        Dim m as Boolean = LogicalOperations.ComplexOperation2(a, b, c)
        Dim n as Boolean = LogicalOperations.ComplexOperation3(a, b, c)
        Console.WriteLine(k)
        Console.WriteLine(m)
        Console.WriteLine(n)
    End Sub
End Class
