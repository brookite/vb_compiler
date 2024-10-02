Public Class Form1

 Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click

 Dim charValue As Char

 'getting single character from textbox
 charValue = CChar(TextBox1.Text.Trim)

        'getting byte as ascii value of the character
        Dim asciiValue As Integer

 asciiValue = Convert.ToByte(charValue)

        'printing value

        MsgBox("ASCII value is: " & asciiValue)

    End Sub
End Class