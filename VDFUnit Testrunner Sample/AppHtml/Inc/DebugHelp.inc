
<script Language="VBScript" RUNAT="Server">

Sub ShowPostGet
    Dim x, Nam
    response.write ("<hr /><strong>----DEBUG INFORMATION----</strong><br />")
    response.write ("content_length = " + request.servervariables("content_length")+"<br />")
    response.write ("request_method = " + request.servervariables("request_method")+"<br />")
    response.write "------------------------------------<br />"
    response.write "Form values<br />"
    if (request.form.count > 0) then
        For Each x In Request.Form
            set nam = Request.Form(x)
            response.write ("&nbsp;&nbsp;&nbsp;" + x +"= " +nam+"<br />")
        Next
    else
        response.write "&nbsp;&nbsp;&nbsp;NO form values<br />"
    end if
    response.write "------------------------------------<br />"
    response.write "Cookie values<br />"
    if (request.cookies.count > 0) then
        For Each x In Request.Cookies
            set nam = Request.Cookies(x)
            response.write("&nbsp;&nbsp;&nbsp;" + x +"= " +nam+"<br />")
        Next
    else
        response.write "&nbsp;&nbsp;&nbsp;NO cookie values<br />"
    end if
    response.write "------------------------------------<br />"
    response.write ("Querystring = " + request.querystring+"<br />")
    response.write "<strong>----END DEBUG INFORMATION----</strong><hr />"
End Sub
</script>

<%
If DebugMode = 0 then DebugMode = session ("debug")
If DebugMode <> 0 then ShowPostGet
%>