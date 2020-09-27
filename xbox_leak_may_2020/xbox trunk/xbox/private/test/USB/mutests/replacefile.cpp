/*

Copyright (c) 2000 Microsoft Corporation

Module Name:

    ReplaceFile.cpp

Abstract:

    

Author:

    Josh Poley (jpoley)

Environment:

    XBox

Revision History:
    04-21-2000  Created

Notes:

*/

#include "stdafx.h"
#include "commontest.h"
#include "mutests.h"

/*

Routine Description:

    Tests the ReplaceFile API

Arguments:

    HANDLE hLog - handle to an XLOG object
    DWORD ThreadID - unique id of the thread - used to keep tests from 
        corrupting the same file

Return Value:

    

*/
DWORD MUTests::ReplaceFile_Test(HANDLE hLog, DWORD ThreadID)
    {
    /*
    BOOL ReplaceFile(
      LPCTSTR lpReplacedFileName,    // file name
      LPCTSTR lpReplacementFileName, // replacement file 
      LPCTSTR lpBackupFileName,      // optional backup file
      DWORD dwReplaceFlags,          // replace options
      LPVOID lpExclude,              // reserved
      LPVOID lpReserved              // reserved
    );
    */
    xSetFunctionName(hLog, "ReplaceFile");

    char lpFile1[80]; sprintf(lpFile1, "%ws:\\ReplaceFile_file1_%d.txt", BASE_DRIVE, ThreadID);
    char lpFile2[80]; sprintf(lpFile2, "%ws:\\ReplaceFile_file2_%d.txt", BASE_DRIVE, ThreadID);
    char lpFile3[80]; sprintf(lpFile3, "%ws:\\ReplaceFile_file3_%d.txt", BASE_DRIVE, ThreadID);
    char lpBigFile[80]; sprintf(lpBigFile, "%ws:\\ReplaceFile_bigfile_%d.txt", BASE_DRIVE, ThreadID);
    char lpFakeFile[80]; sprintf(lpFakeFile, "%ws:\\ReplaceFile_thisFileDoesNotExist_%d.bla", BASE_DRIVE, ThreadID);
    unsigned i;

    // initialize system state
    CreateFilledFile(lpFile1, KILOBYTE*16);
    CreateFilledFile(lpFile2, KILOBYTE*16);
    CreateFilledFile(lpBigFile, MEGABYTE*2);
    DeleteFile(lpFakeFile);
    DeleteFile(lpFile3);


    DWORD time = GetTickCount();


    //////////////////////////////////////////////////////////////////////////
    // Straight line successes
    //////////////////////////////////////////////////////////////////////////
    TESTCASE("valid valid nul")
        {
        if(ReplaceFile(lpFile1, lpFile2, lpNull, 0, NULL, NULL) == TRUE)
            TESTPASS(hLog, "ReplaceFile (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "ReplaceFile (ec: %ld)", GetLastError());

        if(!FileExists(lpFile2))
            TESTPASS(hLog, "Original file removed (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "Original file removed (ec: %ld)", GetLastError());
        } ENDTESTCASE_CLEAN({ CopyFile(lpFile1, lpFile2, FALSE); });
    TESTCASE("large valid valid nul")
        {
        if(ReplaceFile(lpFile1, lpBigFile, lpNull, 0, NULL, NULL) == TRUE)
            TESTPASS(hLog, "ReplaceFile (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "ReplaceFile (ec: %ld)", GetLastError());

        if(!FileExists(lpBigFile))
            TESTPASS(hLog, "Original file removed (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "Original file removed (ec: %ld)", GetLastError());
        } ENDTESTCASE_CLEAN({ CopyFile(lpFile1, lpBigFile, FALSE); });
    TESTCASE("valid valid backup")
        {
        if(ReplaceFile(lpFile1, lpFile2, lpFile3, 0, NULL, NULL) == TRUE)
            TESTPASS(hLog, "ReplaceFile (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "ReplaceFile (ec: %ld)", GetLastError());

        if(!FileExists(lpFile2))
            TESTPASS(hLog, "Original file removed (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "Original file removed (ec: %ld)", GetLastError());

        if(FileExists(lpFile3))
            TESTPASS(hLog, "Backup created (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "Backup created (ec: %ld)", GetLastError());
        } ENDTESTCASE_CLEAN({ CopyFile(lpFile1, lpFile2, FALSE); DeleteFile(lpFile3); });
    TESTCASE("large valid valid backup")
        {
        if(ReplaceFile(lpFile1, lpBigFile, lpFile3, 0, NULL, NULL) == TRUE)
            TESTPASS(hLog, "ReplaceFile (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "ReplaceFile (ec: %ld)", GetLastError());

        if(!FileExists(lpBigFile))
            TESTPASS(hLog, "Original file removed (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "Original file removed (ec: %ld)", GetLastError());

        if(FileExists(lpFile3))
            TESTPASS(hLog, "Backup created (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "Backup created (ec: %ld)", GetLastError());
        } ENDTESTCASE_CLEAN({ CopyFile(lpFile1, lpBigFile, FALSE); DeleteFile(lpFile3); });


    //////////////////////////////////////////////////////////////////////////
    // Straight line failures
    //////////////////////////////////////////////////////////////////////////
    TESTCASE("invalid valid nul")
        {
        if(ReplaceFile(lpFakeFile, lpFile2, lpNull, 0, NULL, NULL) == FALSE)
            TESTPASS(hLog, "ReplaceFile (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "ReplaceFile (ec: %ld)", GetLastError());

        if(FileExists(lpFile2))
            TESTPASS(hLog, "Original file remains (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "Original file remains (ec: %ld)", GetLastError());

        if(!FileExists(lpFakeFile))
            TESTPASS(hLog, "Invalid file created (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "Invalid file created (ec: %ld)", GetLastError());
        } ENDTESTCASE_CLEAN({ DeleteFile(lpFakeFile); });
    TESTCASE("valid invalid nul")
        {
        if(ReplaceFile(lpFile1, lpFakeFile, lpNull, 0, NULL, NULL) == FALSE)
            TESTPASS(hLog, "ReplaceFile (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "ReplaceFile (ec: %ld)", GetLastError());

        if(FileExists(lpFile1))
            TESTPASS(hLog, "Original file remains (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "Original file remains (ec: %ld)", GetLastError());

        if(!FileExists(lpFakeFile))
            TESTPASS(hLog, "Invalid file created (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "Invalid file created (ec: %ld)", GetLastError());
        } ENDTESTCASE_CLEAN({ DeleteFile(lpFakeFile); });
    TESTCASE("newfile valid null w/ extra params")
        {
        if(ReplaceFile(lpFile1, lpFile2, lpNull, 0, hBogus, hBogus) == FALSE)
            TESTPASS(hLog, "ReplaceFile (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "ReplaceFile (ec: %ld)", GetLastError());
        } ENDTESTCASE_CLEAN({ CopyFile(lpFile1, lpFile2, FALSE); });



    //////////////////////////////////////////////////////////////////////////
    // Performance
    //////////////////////////////////////////////////////////////////////////
    TESTCASE("Performance")
        {
        xLog(hLog, XLL_INFO, "Test took %lu milliseconds to run", GetTickCount()-time);
        } ENDTESTCASE;


    //////////////////////////////////////////////////////////////////////////
    // Cleanup
    //////////////////////////////////////////////////////////////////////////
    xSetFunctionName(hLog, "DeleteFile");
    TESTCASE("Removing lpFile1")
        {
        if(DeleteFile(lpFile1) == TRUE)
            TESTPASS(hLog, "(ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "(ec: %ld)", GetLastError());
        } ENDTESTCASE;
    TESTCASE("Removing lpFile2")
        {
        if(DeleteFile(lpFile2) == TRUE)
            TESTPASS(hLog, "(ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "(ec: %ld)", GetLastError());
        } ENDTESTCASE;
    TESTCASE("Removing lpBigFile")
        {
        if(DeleteFile(lpBigFile) == TRUE)
            TESTPASS(hLog, "(ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "(ec: %ld)", GetLastError());
        } ENDTESTCASE;


    return 0;
    }
