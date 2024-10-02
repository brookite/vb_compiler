Module Program

    Sub Main()
        RunMethod("Hello")
        RunMethod("Hello", "world")
    End Sub

    Private Sub RunMethod(ByVal arg1 As String, Optional ByVal optionalArg As String = Nothing)
        If optionalArg Is Nothing Then
            Console.WriteLine($"{arg1}!")
        Else
            Console.WriteLine($"{arg1} {optionalArg}!")
        End If
    End Sub

End Module