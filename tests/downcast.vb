Class Main
    Shared Sub Main()
        Dim a as A = new A()
        Dim b as B = new B()
        Console.WriteLine(a.t)
        Console.WriteLine(b.t)
        Test(b)
        Test2(a)
        Test2(b)
    End Sub
    
    Shared Sub Test(b as B)
        Console.WriteLine(b.t)
    End Sub
    
    Shared Sub Test2(b as A)
        Console.WriteLine(b.t)
    End Sub
End Class

Class A
    Dim t as Long = 231250
    Shared Dim m As String = "Hello"
End Class

Class B 
Inherits A
    Dim t as Long = 200141
    Shared Dim m As String = "Hello123"
End Class