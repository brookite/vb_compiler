Class Person
    Dim firstName As String = Nothing
    Dim lastName As String = Nothing
    
    Sub Greet() 
        Console.WriteLine("Person.Greet()")
    End Sub
End Class

Class Student 
Inherits Person
    Dim course As Short = 4
    
    Sub Greet()
        Console.WriteLine("Student.greet()")
    End Sub
End Class

Class Professor 
Inherits Person
    Dim degree As String = Nothing

    Sub Greet()
        MyBase.Greet()
        Console.WriteLine("Professor.greet()")
    End Sub
End Class

Class Main
    Shared Sub Main()
        Dim x As Student = new Student()
        x.firstName = "Dmitry"
        x.lastName = "Shashkov"
        Dim y As Professor = new Professor()
        y.firstName = "Mr."
        y.lastName = "Professor"
        Dim z As Person = new Person()
        
        Dim arr as Person = {z, x, y}
        For Each p as Person In arr
            p.Greet()
        Next
    End Sub
End Class 