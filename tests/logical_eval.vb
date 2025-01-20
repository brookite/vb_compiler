class main
    Shared Function LeftFalseTest() As Boolean
        Console.WriteLine("left = false evaluated")
        return False
    End Function
    
    Shared Function RightFalseTest() As Boolean
        Console.WriteLine("right = false evaluated")
        return False
    End Function
    
     Shared Function LeftTrueTest() As Boolean
        Console.WriteLine("left = true evaluated")
        return True
    End Function
    
    Shared Function RightTrueTest() As Boolean
        Console.WriteLine("right = true evaluated")
        return True
    End Function

    Shared Sub Main()
        Console.WriteLine("Testing: True OrElse False")
        Dim x = LeftTrueTest() OrElse RightFalseTest()
        Console.WriteLine("Testing: False OrElse False")
        Dim y = LeftFalseTest() OrElse RightFalseTest()
        Console.WriteLine("Testing: False AndAlso False")
        Dim z = LeftFalseTest() AndAlso RightFalseTest() 
        Console.WriteLine("Testing: True AndAlso False")
        Dim a = LeftTrueTest() AndAlso RightFalseTest()
        Console.WriteLine("Testing: True Or False")
        Dim b = LeftTrueTest() Or RightFalseTest()
         Console.WriteLine("Testing: False Or False")
        Dim c = LeftFalseTest() Or RightFalseTest()
         Console.WriteLine("Testing: False And False")
        Dim d = LeftFalseTest() And RightFalseTest() 
         Console.WriteLine("Testing: True And False")
        Dim e = LeftTrueTest() And RightFalseTest()
    End Sub
end class