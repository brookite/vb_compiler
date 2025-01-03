Class A
End Class

Class B 
    Inherits A
End Class

Class Main
    Shared Sub Main()
        Dim x as Integer = 100
        Dim y as Long = 100L
        
        Dim s as Integer = CInt(x + y)
        Dim t as String = CStr(s)
        Dim m As Double = 7.0
        Dim mm As Short = m
        
        Dim a As B = new B()
        test2(new A())
        test2(CType(a, B))
        
    End Sub
    
    Shared Function test(x as Long) As Integer
        Return x / 12
    End Function
    
    Shared Sub test2(x as A)
    End Sub
End Class