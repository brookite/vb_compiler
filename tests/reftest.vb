Class T
    Dim k = 5
End Class

Class Main
    Sub Main()
        Dim array As Integer() = {1, 2, 3, 4}
        Dim t as Integer = 5
        Dim k as String = "abb"
        Dim tt as T = new T()
        Console.WriteLine(array)
        Console.WriteLine(t)
        Console.WriteLine(tt.k)
        Console.WriteLine(k)
        RefTest(array, t, tt, k)
        Console.WriteLine("----")
        Console.WriteLine(array)
        Console.WriteLine(t)
        Console.WriteLine(tt.k)
        Console.WriteLine(k)
    End Sub
    
    Shared Sub RefTest(a as Integer(), t as Integer, tt as T, k as String)
        a(1) = 5
        a = {5, 6 ,7}
        t = 7
        k = "gfgfg"
        tt.k = 6
        tt = new T()
    End Sub
End Class