<script LANGUAGE="VBSCRIPT" RunAt="Server">

' constants for Find modes
    Const LT   =  0
    Const LE   =  1
    Const EQ   =  2
    Const GE   =  3
    Const GT   =  4
    Const NEXT_RECORD  = 5
    Const FIRST_RECORD = 6
    Const LAST_RECORD  = 7

' Const constants for ddValue for "01" interface
' Const all values for DDValue
' reserve 0-99 for DD field information values

    Const DDCRNTVALUE     = 0
    Const DDDESC          = 1
    Const DDLONGLABEL     = 2
    Const DDSHORTLABEL    = 3
    Const DDTAGLABEL      = 4
    Const DDSTHELP        = 5
    Const DDOPT           = 6

    Const DDVALNUM        = 7
    Const DDVALDATA       = 8
    Const DDVALDESC       = 9

' reserve 100-199 = HTML specfic "helper"
' return values

    Const DDSEL             = 103
    Const DDCHCK            = 104
    Const DDOPTION          = 105
    Const DDREADONLY        = 106
    Const DDRECS            = 107
    Const DDTITLE           = 108
    Const DDFIELDERROR      = 109
    Const DDSHORTFIELDERROR = 110
    Const DDROWIDS          = 111

' reserve 200-299 = HTML control
    Const DDFORM          = 200
    Const DDEDIT          = 201
    Const DDRADIO         = 202
    Const DDCOMBO         = 203
    Const DDPARENTCOMBO   = 204
    Const DDAUTO          = 205
</script>
