Class BubbleSort
    Shared Sub Sort(array() As Integer)
        Dim n As Integer = array.Length
        Dim swapped As Boolean

        Do
            swapped = False
            For i As Integer = 0 To n - 2
                If array(i) > array(i + 1) Then
                    Dim temp As Integer = array(i)
                    array(i) = array(i + 1)
                    array(i + 1) = temp
                    swapped = True
                End If
            Next
        Loop While swapped
    End Sub
End Class

Class Program
    Shared Sub Main()
        Dim numbers() As Integer = new Integer() {}
        Dim count As Integer = 0

        Console.WriteLine("Введите числа (введите 0 для завершения ввода):")
        While True
            Dim input As String = Console.ReadLine()
            Dim number As Integer = CInt(input)
            If number = 0 Then
                Exit While
            End If
            ' Увеличиваем размер массива и добавляем число
            count += 1
            ReDim Preserve numbers(count - 1)
            numbers(count - 1) = number
        End While

        Console.WriteLine("Исходный массив:")
        For Each number As Integer In numbers
            Console.Write(CStr(number) & " ")
        Next
        Console.WriteLine("")

        BubbleSort.Sort(numbers)

        Console.WriteLine("Отсортированный массив:")
        For Each number As Integer In numbers
            Console.Write(CStr(number) & " ")
        Next
        Console.WriteLine("")
    End Sub
End Class
