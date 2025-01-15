Class Array(Of T)
    Dim src(10) as T
    Dim ptr as Integer = 0

    Sub SetLength(size as ULong) 
        Console.Write("Extending to ")
        Console.WriteLine(size)
        Redim src(size)
    End Sub
    
    Sub Add(val as T)
        If (ptr >= src.Length) Then
            Call SetLength(ptr + 16)
        End If
        src(ptr) = val
        ptr += 1
    End Sub
    
    Sub Clear()
        Erase src
    End Sub
    
    Function Get(i as Integer) as T
        Return src(i)
    End Function
    
    Function Length() as Integer
        Return ptr
    End Function
End Class

Class Main
    Shared Sub Main()
        Dim arr as Array(Of ULong) = new Array(Of ULong)()
        arr.Add(10)
        arr.Add(16)
        Console.WriteLine(arr.Get(0))
        Console.WriteLine(arr.Get(1))
        for cnt As Integer = 100 To 200
            If (cnt Mod 5 = 0) Then
                arr.Add(cnt * 105)
            ElseIf (cnt Mod 3 = 0) Then
                arr.Add(cnt / 10)
            Else
                arr.Add(cnt)
            End If
        Next
        
        Dim arr2 as Array(Of Array(Of ULong)) = new Array(Of Array(Of ULong))()
        arr2.Add(new Array(Of ULong)())
        arr2.Add(new Array(Of ULong)())
    End Sub
End Class