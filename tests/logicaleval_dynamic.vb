Class MainClass
    Shared Function LeftTest() As Boolean
        Console.Write("Введите значение для Left (True/False): ")
        Dim input As Integer = Cint(Console.ReadLine())
        Dim result As Boolean = input
        Console.WriteLine("Left = " & result & " evaluated")
        Return result
    End Function

    Shared Function RightTest() As Boolean
        Console.Write("Введите значение для Right (True/False): ")
        Dim input As Integer = Cint(Console.ReadLine())
        Dim result As Boolean = input
        Console.WriteLine("Right = " & result & " evaluated")
        Return result
    End Function

    Shared Sub Main()
        ' Testing True OrElse False
        Console.WriteLine("Testing: True OrElse False")
        Dim x = LeftTest() OrElse RightTest()

        ' Testing False OrElse False
        Console.WriteLine("Testing: False OrElse False")
        Dim y = LeftTest() OrElse RightTest()

        ' Testing False AndAlso False
        Console.WriteLine("Testing: False AndAlso False")
        Dim z = LeftTest() AndAlso RightTest()

        ' Testing True AndAlso False
        Console.WriteLine("Testing: True AndAlso False")
        Dim a = LeftTest() AndAlso RightTest()

        ' Testing True Or False
        Console.WriteLine("Testing: True Or False")
        Dim b = LeftTest() Or RightTest()

        ' Testing False Or False
        Console.WriteLine("Testing: False Or False")
        Dim c = LeftTest() Or RightTest()

        ' Testing False And False
        Console.WriteLine("Testing: False And False")
        Dim d = LeftTest() And RightTest()

        ' Testing True And False
        Console.WriteLine("Testing: True And False")
        Dim e = LeftTest() And RightTest()
    End Sub
End Class
