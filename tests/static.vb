Class Main
    Shared Function Secret() As Integer
        Return 21521
    End Function
    
    Shared Dim a = 12210
    
    Shared Sub Main()
        Console.WriteLine(a)
        Console.WriteLine(Secret())
    End Sub
End Class 