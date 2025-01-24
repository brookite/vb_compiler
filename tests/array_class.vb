Class Array(Of T)
    Dim src(10) as T
    Dim ptr as Integer = 0

    Sub SetLength(size as ULong) 
        Console.Write("Extending to ")
        Console.WriteLine(size)
        Redim Preserve src(size)
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
    
    Function [Get](i as Integer) as T
        Return src(i)
    End Function
    
    Function Length() as Integer
        Return ptr
    End Function
    
    Function ToString() As String
        Dim res As String = "["
        For Each i As T In src
            If Not (i Is Nothing) Then
                res &= i.ToString()
                res &= ", "
            End If
        Next
        res &= "]"
        Return res
    End Function
End Class

Class Main
    Shared Sub Main()
        Dim arr as Array(Of ULong) = new Array(Of ULong)()
        arr.Add(10)
        arr.Add(16)
        Dim arr3 as Array(Of String) = new Array(Of String)()
        arr3.Add("Hello")
        arr3.Add("World")
        
        Dim arr2 as Array(Of Array(Of ULong)) = new Array(Of Array(Of ULong))()
        arr2.Add(new Array(Of ULong)())
        arr2.Add(new Array(Of ULong)())
        
        Console.WriteLine(arr.ToString())
        Console.WriteLine(arr2.ToString())
        Console.WriteLine(arr3.ToString())
    End Sub
End Class