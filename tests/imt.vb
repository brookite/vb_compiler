Class BMI
        ' Функция для расчета индекса массы тела
        Shared Function CalculateBMI(weight As Double, height As Double) As Double
            ' Формула: BMI = weight (kg) / height^2 (m^2)
            Return weight / (height ^ 2)
        End Function

        ' Функция для определения категории по индексу массы тела
        Shared Function GetBMICategory(bmi As Double) As String
            If bmi < 16 Then
                Return "Выраженный дефицит массы тела"
            ElseIf bmi >= 16 AndAlso bmi < 17 Then
                Return "Умеренный дефицит массы тела"
            ElseIf bmi >= 17 AndAlso bmi < 18.5 Then
                Return "Небольшой дефицит массы тела"
            ElseIf bmi >= 18.5 AndAlso bmi < 25 Then
                Return "Норма"
            ElseIf bmi >= 25 AndAlso bmi < 30 Then
                Return "Избыточная масса тела"
            ElseIf bmi >= 30 AndAlso bmi < 35 Then
                Return "Ожирение I степени"
            ElseIf bmi >= 35 AndAlso bmi < 40 Then
                Return "Ожирение II степени"
            Else
                Return "Ожирение III степени (морбидное ожирение)"
            End If
        End Function
    End Class

Class BMICalculator
    Shared Sub Main()
        ' Ввод данных пользователя
        Console.WriteLine("Расчет индекса массы тела (BMI)")
        Console.Write("Введите ваш вес (в кг): ")
        Dim weight As Double = Console.ReadDouble()
        Console.Write("Введите ваш рост (в метрах): ")
        Dim height As Double = Console.ReadDouble()

        ' Расчет и вывод результата
        Dim bmi As Double = BMI.CalculateBMI(weight, height)
        Dim category As String = BMI.GetBMICategory(bmi)

        Console.WriteLine("Ваш BMI: " & bmi)
        Console.WriteLine("Категория: " & category)
    End Sub

End Class
