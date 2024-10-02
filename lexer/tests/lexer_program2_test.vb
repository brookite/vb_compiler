Public Class Form1

 Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click

 Dim strBuffer As String = Nothing

 strBuffer = TextBox1.Text.Trim

        'declare byte buffer based on strBuffer length

        Dim byteArray(strBuffer.Length())  As Byte

 byteArray = System.Text.Encoding.Unicode.GetBytes(strBuffer)

        'printing byte array in string
        Dim finalString As String = Nothing

        'why step 2 - in byteArray each character will take 2 bytes, 
        ' for example Byte value of A is: 65 0
        ' and we have to pick 65 only 
        For counter As Integer = 0 To byteArray.Length - 1 Step 2
 finalString = finalString & byteArray(counter).ToString(0) & " "
        Next

        MsgBox("Byte Array values are: " & finalString)

    End Sub
End Class