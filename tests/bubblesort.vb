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
        Dim numbers() As Integer = {5, 2, 9, 1, 5, 6}

        Console.WriteLine("Исходный массив:")
        Console.WriteLine(numbers)

        BubbleSort.Sort(numbers)

        Console.WriteLine("Отсортированный массив:")
        Console.WriteLine(numbers)
    End Sub
End Class
