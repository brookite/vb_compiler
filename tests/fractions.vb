Class Fraction
    Dim numerator As Double = 1
    Dim denominator As Double = 1
    
    Function floatValue() as Double
        Return numerator / denominator
    End Function
    
    Function Mul(other As Fraction) as Fraction
        Dim newFrac as Fraction = new Fraction()
        newFrac.numerator = numerator * other.numerator
        newFrac.denominator = Me.denominator * other.denominator
        return newFrac
    End Function
End Class

Class Vector2D
    Dim x As Double = 0
    Dim y As Double = 0
    
    Function Scalar(other As Vector2D) as Double
        Return Me.x * other.x + y + other.y
    End Function
    
End Class 


Class Vector3D 
Inherits Vector2D
    Dim z As Double = 0
    
    Function Scalar(other As Vector2D) as Double
        Return MyBase.Scalar(other) + z * CType(other, Vector3D).z
    End Function
    
End Class 


Class Main
    Shared Sub Main()
        If (True) Then
            Console.WriteLine("Vectors")
        End If
        
        Dim x as Fraction = new Fraction()
        x.numerator = 10
        x.denominator = 2
        Console.WriteLine(x.floatValue())
        Dim y as Fraction = new Fraction()
        x.numerator = 4542
        y.denominator = 122
        Console.WriteLine(x.Mul(y).floatValue())
        Dim z as Fraction = new Fraction()
        z.numerator = 4
        z.denominator = 5
        Console.WriteLine(z.Mul(x))
        
        Dim vec as Vector2D = new Vector2D()
        vec.x = 10
        vec.y = 10
        Console.WriteLine(vec.Scalar(vec))
        Dim vec2 As Vector3D = new Vector3D()
        vec2.x = 3
        vec2.y = 4
        Console.WriteLine(vec2.Scalar(vec2))
    End Sub
End Class 