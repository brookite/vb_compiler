Class ShiftProgression
    Dim days As Integer() = New Integer(31) {}
    Dim dest_firstday As Date
    Dim dest_lastday As Date
    Dim d As Integer
    Dim first As Long

    Shared Function Create(d As Integer, [date] As Date, date_dest As Date) As ShiftProgression
        Dim m as ShiftProgression = new ShiftProgression()
        m.d = (d + 1) * 3600 * 24
        m.first = [date].ToTimestamp()
        m.dest_firstday = New Date()
        m.dest_firstday.year = date_dest.Year
        m.dest_firstday.month = date_dest.Month
        m.dest_firstday.day = 1
        m.dest_lastday = New Date()
        m.dest_lastday.year = date_dest.Year
        m.dest_lastday.month = date_dest.Month
        m.dest_lastday.day = DaysInMonth(date_dest.Year, date_dest.Month)
        return m
    End Function
    
    Shared Function DaysInMonth(year As Integer, month As Integer) As Integer
        If month = 1 OrElse month = 3 OrElse month = 5 OrElse month = 7 OrElse month = 8 OrElse month = 10 OrElse month = 12 Then
            Return 31
        ElseIf month = 4 OrElse month = 6 OrElse month = 9 OrElse month = 11 Then
            Return 30
        ElseIf month = 2 Then
            If (year Mod 4 = 0 AndAlso (year Mod 100 <> 0 OrElse year Mod 400 = 0)) Then
                Return 29
            Else
                Return 28
            End If
        End If
    End Function

    Function [Get](n As Long) As Long
        Return first + d * (n - 1)
    End Function

    Function Start() As ShiftProgression
        Dim k1 As Integer = CInt((dest_firstday.ToTimestamp() - first) / d) + 1
        Dim k2 As Integer = CInt((dest_lastday.ToTimestamp() - first) / d) + 1
        Dim j As Integer = 0

        For i As Long = k1 To k2
            Dim unix As Long = [Get](i)
            Dim dt As Date = Date.OfTimestamp(unix)

            If dt.Month = dest_firstday.Month Then
                days(j) = dt.Day
                j += 1
            End If
        Next

        FixArray()
        Return Me
    End Function

    Sub FixArray()
        Dim counter As Integer = days.Length

        For i As Integer = 0 To days.Length - 1
            If days(i) = 0 Then
                counter = i
                Exit For
            End If
        Next

        Redim Preserve days(counter - 1)
    End Sub

    Function GetArray() As Integer()
        Return days
    End Function
    
    Shared Sub Main()
        Console.Write("Enter destination month: ")
        Dim destMonth As Integer = CInt(Console.ReadLine())
        Console.Write("Enter destination year: ")
        Dim destYear As Integer = CInt(Console.ReadLine())

        Console.Write("Enter source day: ")
        Dim srcDay As Integer = CInt(Console.ReadLine())
        Console.Write("Enter source month: ")
        Dim srcMonth As Integer = CInt(Console.ReadLine())
        Console.Write("Enter source year: ")
        Dim srcYear As Integer = CInt(Console.ReadLine())

        Dim sourceDate As Date = New Date()
        sourceDate.year = srcYear
        sourceDate.month = srcMonth
        sourceDate.day = srcDay
        Dim destDate As Date = new Date()
        destDate.year = destYear
        destDate.month = destMonth
        destDate.day = 1

        Console.Write("Enter d: ")
        Dim d As Integer = CInt(Console.ReadLine())

        Dim progression As ShiftProgression = ShiftProgression.Create(d, sourceDate, destDate)
        progression.Start()

        Dim resultArray As Integer() = progression.GetArray()
        Console.WriteLine("Resulting days: " & String.Join(", ", resultArray))
    End Sub
End Class

