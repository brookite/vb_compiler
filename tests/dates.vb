class DateTest
    Shared Sub Main()
        Dim t as Date = # 01-01-2026 00:00:00 #
        Dim now As Date = Date.Now()
        Dim timestamp As Long = (t.ToTimestamp() - now.ToTimestamp()) \ (24 * 60 * 60)
        Console.WriteLine("До нового года " & CStr(t.year) & " осталось " & CStr(timestamp) & " дней!")
        Console.WriteLine("Он будет " & CStr(t.day) & "." & CStr(t.month))
    End Sub
end class