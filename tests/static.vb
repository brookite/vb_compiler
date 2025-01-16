Class T
    Shared Dim k = 5
End class

Class Main
    Shared Function Secret() As Integer
        Return 21521
    End Function
    
    Shared Dim a = 12210
    
    Shared Sub Main()
        Console.WriteLine(a)
        a = 512
        Console.WriteLine(a)
        Console.WriteLine(T.k)
        T.k = 105
        Console.WriteLine(T.k)
        Console.WriteLine(Secret())
    End Sub
End Class 