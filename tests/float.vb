Class OperationsWithFloatAndInt
    Shared Sub Main()
        ' Объявление переменных
        Dim intNumber As Integer = 10
        Dim floatNumber As Single = 3.5F

        ' Арифметические операции
        Console.WriteLine("Арифметические операции:")
        Console.WriteLine("Сложение: " & CStr(intNumber) & " + " & CStr(floatNumber) & " = " & CStr(intNumber + floatNumber))
        Console.WriteLine("Вычитание: " & CStr(intNumber) & " - " & CStr(floatNumber) & " = " & CStr(intNumber - floatNumber))
        Console.WriteLine("Умножение: " & CStr(intNumber) & " * " & CStr(floatNumber) & " = " & CStr(intNumber * floatNumber))
        Console.WriteLine("Деление: " & CStr(intNumber) & " / " & CStr(floatNumber) & " = " & CStr(intNumber / floatNumber))
        
        Console.WriteLine("Арифметические операции:")
        Console.WriteLine("Сложение: " & CStr(intNumber) & " + " & CStr(intNumber) & " = " & CStr(intNumber + intNumber))
        Console.WriteLine("Вычитание: " & CStr(intNumber) & " - " & CStr(intNumber) & " = " & CStr(intNumber - intNumber))
        Console.WriteLine("Умножение: " & CStr(intNumber) & " * " & CStr(intNumber) & " = " & CStr(intNumber * intNumber))
        Console.WriteLine("Деление: " & CStr(intNumber) & " / " & CStr(intNumber + 5) & " = " & CStr(intNumber / (intNumber + 5)))
        
        Console.WriteLine("Арифметические операции:")
        Console.WriteLine("Сложение: " & CStr(floatNumber) & " + " & CStr(intNumber) & " = " & CStr(floatNumber + intNumber))
        Console.WriteLine("Вычитание: " & CStr(floatNumber) & " - " & CStr(intNumber) & " = " & CStr(floatNumber - intNumber))
        Console.WriteLine("Умножение: " & CStr(floatNumber) & " * " & CStr(intNumber) & " = " & CStr(floatNumber * intNumber))
        Console.WriteLine("Деление: " & CStr(floatNumber) & " / " & CStr(intNumber) & " = " & CStr(floatNumber / intNumber))
        
        Console.WriteLine("Арифметические операции:")
        Console.WriteLine("Сложение: " & CStr(floatNumber) & " + " & CStr(floatNumber) & " = " & CStr(floatNumber + floatNumber))
        Console.WriteLine("Вычитание: " & CStr(floatNumber) & " - " & CStr(floatNumber) & " = " & CStr(floatNumber - floatNumber))
        Console.WriteLine("Умножение: " & CStr(floatNumber) & " * " & CStr(floatNumber) & " = " & CStr(floatNumber * floatNumber))
        Console.WriteLine("Деление: " & CStr(floatNumber) & " / " & CStr(floatNumber) & " = " & CStr(floatNumber / floatNumber))

        ' Целочисленное деление
        Console.WriteLine("Целочисленное деление: " & CStr(intNumber) & " \ 3 = " & CStr(intNumber \ 3))

        ' Остаток от деления
        Console.WriteLine("Остаток от деления: " & CStr(intNumber) & " Mod 3 = " & CStr(intNumber Mod 3))

        ' Сравнение чисел
        Console.WriteLine("Сравнение чисел:")
        Console.WriteLine(CStr(intNumber) & " > " & CStr(floatNumber) & ": " & CStr(intNumber > floatNumber))
        Console.WriteLine(CStr(intNumber) & " < " & CStr(floatNumber) & ": " & CStr(intNumber < floatNumber))
        Console.WriteLine(CStr(intNumber) & " = " & CStr(floatNumber) & ": " & CStr(intNumber = floatNumber))
        
        ' Целочисленное деление
        Console.WriteLine("Целочисленное деление: " & CStr(floatNumber) & " \ 3 = " & CStr(floatNumber \ 3))

        ' Остаток от деления
        Console.WriteLine("Остаток от деления: " & CStr(floatNumber) & " Mod 3 = " & CStr(intNumber Mod 3))


        Console.WriteLine("Сравнение чисел:")
        Console.WriteLine(CStr(floatNumber) & " > " & CStr(floatNumber) & ": " & CStr(floatNumber > floatNumber))
        Console.WriteLine(CStr(floatNumber) & " < " & CStr(floatNumber) & ": " & CStr(floatNumber < floatNumber))
        Console.WriteLine(CStr(floatNumber) & " = " & CStr(floatNumber) & ": " & CStr(floatNumber = floatNumber))

        Console.WriteLine("Сравнение чисел:")
        Console.WriteLine(CStr(intNumber) & " > " & CStr(intNumber) & ": " & CStr(intNumber > intNumber))
        Console.WriteLine(CStr(intNumber) & " < " & CStr(intNumber) & ": " & CStr(intNumber < intNumber))
        Console.WriteLine(CStr(intNumber) & " = " & CStr(intNumber) & ": " & CStr(intNumber = intNumber))
        
        Console.WriteLine("Сравнение чисел:")
        Console.WriteLine(CStr(floatNumber) & " > " & CStr(intNumber) & ": " & CStr(floatNumber > intNumber))
        Console.WriteLine(CStr(floatNumber) & " < " & CStr(intNumber) & ": " & CStr(floatNumber < intNumber))
        Console.WriteLine(CStr(floatNumber) & " = " & CStr(intNumber) & ": " & CStr(floatNumber = intNumber))

        ' Побитовые операции
        Console.WriteLine("Побитовые операции:")
        Dim anotherInt As Integer = 3
        Console.WriteLine(CStr(intNumber) & " And " & CStr(anotherInt) & ": " & CStr(intNumber And anotherInt))
        Console.WriteLine(CStr(intNumber) & " Or " & CStr(anotherInt) & ": " & CStr(intNumber Or anotherInt))
        Console.WriteLine(CStr(intNumber) & " Xor " & CStr(anotherInt) & ": " & CStr(intNumber Xor anotherInt))
        Console.WriteLine("Not " & CStr(intNumber) & ": " & CStr(Not intNumber))
        Console.WriteLine(CStr(intNumber) & " << 1: " & CStr(intNumber << 1))
        Console.WriteLine(CStr(intNumber) & " >> 1: " & CStr(intNumber >> 1))
    End Sub
End Class
