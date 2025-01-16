Class Main
    Shared Sub main()
        Const a(10) as Integer = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
        For Each i as Integer in a
            Console.WriteLine(i)
        Next
        Console.WriteLine("")
        For i as Integer = 5 to 100
            Console.Write(i)
            Console.Write(" ")
        Next
        Console.WriteLine("")
        For i as Integer = 5 to 100
            Console.Write(i)
            Console.Write(" ")
            if (i mod 35 = 0) Then 
                Exit For
            ElseIf (i mod 10 = 0) Then
                Continue For
            End If
        Next
        Console.WriteLine("")
        Dim i As Integer = 0
        While i < 15
            Console.WriteLine(i)
            If (i mod 10 = 0) Then
                Exit While
            End If
            i += 1
        End While
    End Sub
End Class 