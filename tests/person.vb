Class Person
    Dim firstName As String = Nothing
    Dim lastName As String = Nothing
    
    Function Greet() As String
        return "Hello, " & firstName & " " & lastName
    End Function
End Class

Class Student 
Inherits Person
    Dim course As Short = 4
End Class

Class Professor 
Inherits Person
    Dim degree As String = Nothing

    Function Greet() As String
        return "Hello, professor " & firstName & " " & lastName
    End Function
    
    Function GreetDefault() As String
        return MyBase.Greet()
    End Function
End Class

Class Main
    Shared Sub Main()
        Dim x As Student = new Student()
        x.firstName = "Dmitry"
        x.lastName = "Shashkov"
        Dim y As Professor = new Professor()
        y.firstName = "Mr."
        y.lastName = "Professor"
        Dim z As Person = x
        Console.WriteLine(CType(y, Person).Greet())
        Console.WriteLine(CType(x, Person).Greet())
        Console.WriteLine(CType(z, Student).Greet())
        Console.WriteLine(y.GreetDefault())
    End Sub
End Class 