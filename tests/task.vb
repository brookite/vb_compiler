Class Program
    Shared Sub Main()
        ' Условие задачи:
        ' Программа определяет, все ли сотрудники пришли на работу,
        ' и выводит список номеров сотрудников, пришедших на работу, 
        ' отсортированный по порядковому номеру.
        ' Если кто-то не пришёл, выводится его номер, иначе "Все пришли".

        ' Ввод количества сотрудников
        Console.WriteLine("Введите количество сотрудников (N):")
        Dim N As Integer = Console.ReadInt()
        If N < 1 Or N >= 40000 Then
            Console.WriteLine("Некорректное значение N. Завершение работы.")
            Return
        End If

        ' Ввод номеров сотрудников, пришедших на работу
        Console.WriteLine("Введите номера сотрудников, пришедших на работу (закончите ввод нулём):")
        Dim arrived(N - 1) As Boolean
        Dim input As Integer

        Do
            input = Console.ReadInt()
            If input = 0 Then 
                Exit Do
            ElseIf input > 0 AndAlso input <= N Then
                arrived(input - 1) = True ' Отмечаем сотрудника как пришедшего
            End If
        Loop

        ' Проверка на наличие прогульщиков
        Dim allPresent As Boolean = True
        For i As Integer = 0 To N - 1
            If Not arrived(i) Then
                allPresent = False
                Exit For
            End If
        Next

        ' Вывод результата
        If allPresent Then
            Console.WriteLine("Все пришли")
        Else
            Console.WriteLine("Список пришедших сотрудников:")
            For i As Integer = 0 To N - 1
                If arrived(i) Then
                    Console.Write((i + 1).ToString() & " ")
                End If
            Next
            Console.WriteLine("")
        End If
    End Sub
End Class
