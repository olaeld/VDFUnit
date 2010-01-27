Use Windows.pkg
Use DFClient.pkg
Use cRichEdit.pkg
Use cProgressBar.pkg
Use VDFUnit.pkg

Activate_View Activate_VDFUnitTestRunner_vw for VDFUnitTestRunner_vw
Object VDFUnitTestRunner_vw is a View

    Procedure ShowText String sText
        Send AppendTextLn to oOutputBox sText
    End_Procedure
    
    Set Border_Style to Border_None
    Set Size to 246 427
    Set Location to 0 0
    Set Label to "VDFUnit TestRunner"
    Set Maximize_Icon to False
    Set Minimize_Icon to False
    Set pbSizeToClientArea to False
    Set Sysmenu_Icon to False
    Set Caption_Bar to False
    Set View_Mode to Viewmode_Zoom
    
    Object oOutputBox is a cRichEdit
        Set Size to 110 400
        Set Location to 64 13
        Set Focus_Mode to NonFocusable
        
        Procedure SetRunningColor
            Set Color to clGray
        End_Procedure
        
        Procedure SetSuccessColor
            Set Color to clLime
        End_Procedure
        
        Procedure SetFailedColor
            Set Color to clRed
        End_Procedure
    End_Object

    Object oRunTestsButton is a Button
        Set Size to 30 200
        Set Location to 13 13
        Set Label to "Run tests!"
        Set Typeface to "verdana"
        Set FontSize to 20 10
    
        Procedure OnClick
            Send Execute to oTestFixtureRunner
        End_Procedure
    
    End_Object

End_Object

Use oVDFUnitTests.pkg

Object oTestFixtureCatalog is a cTestFixtureCatalog
    Set phTestFixtureNeighborhood to (Parent(Self))
    Send InitTestFixtureCatalog
    
    Procedure ListTestFixtures
        String sTestFixtureName
        Handle hTestFixture
        
        Send IteratorReset
        While (IteratorMoveNext(Self))
            Get CurrentTestFixture to hTestFixture
            Get ObjectName of hTestFixture to sTestFixtureName
            Send ShowText to VDFUnitTestRunner_vw sTestFixtureName
        Loop
    End_Procedure
End_Object

Object oTestFixtureRunner is a cTestFixtureRunner
    Procedure Execute
        Indicate Err False
        Handle hOutputBox
        Move (oOutputBox(VDFUnitTestRunner_vw(Self))) to hOutputBox
        Send SetRunningColor to hOutputBox
        Send RunTestFixtures to oTestFixtureRunner
        If (Err) Begin
            Send SetFailedColor to hOutputBox
        End
        Else Begin
            Send SetSuccessColor to hOutputBox
        End
    End_Procedure
    
    Set phTestFixtureCatalog to (oTestFixtureCatalog(Self))
End_Object

Procedure ListTestFixtures
    Send ListTestFixtures to oTestFixtureCatalog
End_Procedure

Procedure Execute
    Send Execute to oTestFixtureRunner
End_Procedure