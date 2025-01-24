Class T
    Dim k = 5
End Class

Class Main
    Sub Main()
        Dim array As Integer() = {1, 2, 3, 4}
        Dim t as Integer = 5
        Dim tt as T = new T()
        Console.WriteLine(array)
        Console.WriteLine(t)
        Console.WriteLine(tt.k)
        RefTest(array, t, tt)
        Console.WriteLine(array)
        Console.WriteLine(t)
        Console.WriteLine(tt.k)
    End Sub
    
    Shared Sub RefTest(a as Integer(), t as Integer, tt as T)
        a(1) = 5
        a = {5, 6 ,7}
        t = 7
        tt.k = 6
        tt = new T()
    End Sub
End Class