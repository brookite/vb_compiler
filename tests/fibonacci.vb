Class FibonacciRecursive
    Shared Sub Main()
        ' Введите количество чисел в последовательности
        Console.Write("Введите количество чисел в последовательности Фибоначчи: ")
        Dim count As Integer = CInt(Console.ReadLine())

        Console.WriteLine("Последовательность Фибоначчи:")

        ' Вывод чисел последовательности
        For i As Integer = 0 To count - 1
            Console.Write(CStr(Fibonacci(i)) & " ")
        Next

    End Sub

    ' Рекурсивная функция для вычисления чисел Фибоначчи
    Shared Function Fibonacci(n As Integer) As Integer
        If n <= 1 Then
            Return n
        Else
            Return Fibonacci(n - 1) + Fibonacci(n - 2)
        End If
    End Function
End Class
