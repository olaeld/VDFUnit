<% response.expires = 0 %>
<html>
<head>
<title>Debug Toggle</title>
</head>
<body>
The Debug mode is currently
<%
 Bug = session ("debug")
 If Bug =0 then
    session ("debug") = 1
    response.write (" On")
 else
    session ("debug") = 0
    response.write (" Off")
 end if
%>
</body>
</html>
