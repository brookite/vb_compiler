Class Main
    Shared Function BinaryFind(item As Integer, array() As Integer) As Integer
        Dim a As Integer = 0
        Dim b As Integer = array.Length

        While a < b - 1
            Dim m As Integer = (a + b) \ 2
            If item < array(m) Then
                b = m
            Else
                a = m
            End If
        End While

        If array(a) = item Then
            Return a
        Else
            Return -1
        End If
    End Function
    
    Shared Function GCD(a As Integer, b As Integer) As Integer
        While a <> 0 And b <> 0
            If a > b Then
                a = a Mod b
            Else
                b = b Mod a
            End If
        End While
        Return a + b
    End Function
    
    
    Shared Function Dels(x As Integer) As Integer()
        Dim divisors(0) As Integer
        Dim count As Integer = 0

        Dim k As Integer = 1
        While k * k <= x
            If x Mod k = 0 Then
                ReDim divisors(count + 1)
                divisors(count) = k
                count += 1
                If k <> x \ k Then
                    ReDim divisors(count + 1)
                    divisors(count) = x \ k
                    count += 1
                End If
            End If
            k += 1
        End While

        Return divisors
    End Function
    
    Shared Sub Main()
        Dim array() As Integer = {4, 2, 7, 1, 9, 3}
        Console.WriteLine(BinaryFind(1, array))
        Console.WriteLine(GCD(12, 8))
        Console.WriteLine(Dels(102))
    End Sub
End Class