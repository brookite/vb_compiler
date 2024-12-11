Class Main
    Shared Sub Main()
        m = CBool(5)
        m = CType(5, String)
        m = If(a, b, c)
        m = If(c, d)
        m = New MyObj
        m = New MyObj(Of h)(10, 5) {"lol"}
        m = New MyObj(Of t)
        m = New MyObj()
        m = New MyObj(1, 3, 4)
        m = New MyObj(3) {1, 3, 4}
    End Sub
End Class