Class LuhnAlgorithm
    ' Реализация собственной функции Mid
    Shared Function MyMid(str As String, startPos As Integer, length As Integer) As String
        Dim result As String = ""
        Dim strLength As Integer = GetLength(str)
        Dim endPos As Integer = startPos + length - 1

        If startPos < 1 OrElse startPos > strLength Then
            Return result ' Возврат пустой строки, если startPos вне диапазона
        End If

        For i As Integer = startPos To Math.Min(endPos, strLength)
            result &= CStr(str(i - 1))
        Next

        Return result
    End Function

    ' Функция для получения длины строки
    Shared Function GetLength(str As String) As Integer
        Return str.Length()
    End Function

    ' Преобразование символа в число
    Shared Function StrToInt(str as String) As Integer
        Return CInt(str)
    End Function

    ' Функция для извлечения только цифр из строки
    Shared Function FilterDigits(code As String) As String
        Dim result As String = ""
        For i As Integer = 1 To GetLength(code)
            Dim ch As Char = MyMid(code, i, 1)(0)
            If ch >= "0"c AndAlso ch <= "9"c Then
                result &= CStr(ch)
            End If
        Next
        Return result
    End Function

    ' Вычисление суммы Луна
    Shared Function LuhnSum(code As String) As Integer
        code = FilterDigits(code)
        Dim length As Integer = GetLength(code)
        Dim parity As Integer = length Mod 2
        Dim sum As Integer = 0

        For i As Integer = 1 To length
            Dim digit As Integer = StrToInt(MyMid(code, i, 1))

            If (i - 1) Mod 2 = parity Then
                digit *= 2
                If digit > 9 Then
                    digit -= 9
                End If
            End If

            sum += digit
        Next

        Return sum
    End Function

    ' Проверка валидности по алгоритму Луна
    Shared Function LuhnCheck(code As String) As Boolean
        Return LuhnSum(code) Mod 10 = 0
    End Function

    Shared Sub Main()
        ' Тестовые данные
        Dim code As String

        Console.WriteLine("Введите номер карты для проверки (алгоритм Луна): ")
        code = Console.ReadLine()

        If LuhnCheck(code) Then
            Console.WriteLine("Номер карты валиден!")
        Else
            Console.WriteLine("Номер карты НЕ валиден.")
        End If

    End Sub
End Class
