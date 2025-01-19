Class Main
    Shared Sub main()
        Dim a As Integer() = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
        Console.WriteLine(a)
        For Each t As Integer In a
            Console.WriteLine(t)
        Next
        Console.WriteLine("")
        For t As Integer = 5 To 100
            Console.Write(t)
            Console.Write(" ")
        Next
        Console.WriteLine("")
        For t As Integer = 5 To 100
            Console.Write(t)
            Console.Write(" ")
            If (t Mod 35 = 0) Then
                Exit For
            ElseIf (t Mod 10 = 0) Then
                Continue For
            End If
        Next
        Console.WriteLine("")
        Dim i As Integer = 0
        While i < 15
            Console.WriteLine(i)
            If (i Mod 11 = 0) Then
                Exit While
            End If
            i += 1
        End While
    End Sub
End Class