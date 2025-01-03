class Main
    Shared Sub Main()
        x("Hello", 1)
        y({1, 2, 3}, 10)
        y(10, 15)
    End Sub
    
    Shared Function x(x as Integer, y as Single) As Integer
        Return 10L
    End Function
    
    Shared Function y(x as Integer(), y as Single) As String
        Return 10L
    End Function
End Class