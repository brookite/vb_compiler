Class Main
    Shared Sub Main()
        Console.Write("Input integer: ")
        Dim s as Integer = CInt(Console.ReadLine())
        Console.WriteLine(If(s > 0, "Positive", "Negative"))
    End Sub
End Class