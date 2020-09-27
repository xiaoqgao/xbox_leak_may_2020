
/******************************************************************************\
*       This is a part of the Microsoft Source Code Samples. 
*       Copyright (C) 1993 Microsoft Corporation.
*       All rights reserved. 
*       This source code is only intended as a supplement to 
*       Microsoft Development Tools and/or WinHelp documentation.
*       See these sources for detailed information regarding the 
*       Microsoft samples programs.
\******************************************************************************/

/***************************************************************************
 *                                                                         *
 *  MODULE      : MpFind.c                                                 *
 *                                                                         *
 *  PURPOSE     : Code to do text searches in MultiPad.                    *
 *                                                                         *
 *  FUNCTIONS   : RealSlowCompare () - Compares subject string with target *
 *                                     string.                             *
 *                                                                         *
 *                Local_FindText ()          - Looks for the search string in the  *
 *                                     active window.                      *
 *                                                                         *
 *                FindPrev ()        - Find previous occurence of search   *
 *                                     string.                             *
 *                                                                         *
 *                FindNext ()        - Find next occurence of search string*
 *                                                                         *
 *                FindDlgProc ()     - Dialog function for Search/Find.    *
 *                                                                         *
 *                Find ()            - Invokes FindDlgProc ()              *
 *                                                                         *
 ***************************************************************************/
#include "multipad.h"

#undef HIWORD
#undef LOWORD

#define HIWORD(l) (((WORD*)&(l))[1])
#define LOWORD(l) (((WORD*)&(l))[0])

BOOL fCase         = FALSE;    /* Turn case sensitivity off */
CHAR szSearch[160] = "";       /* Initialize search string  */

//LPSTR WINAPI AnsiLower (LPSTR);

/****************************************************************************
 *                                                                          *
 *  FUNCTION   : RealSlowCompare ()                                         *
 *                                                                          *
 *  PURPOSE    : Compares subject string with the target string. This fn/   *
 *               is called repeatedly so that all substrings are compared,  *
 *               which makes it O(n ** 2), hence it's name.                 *
 *                                                                          *
 *  RETURNS    : TRUE  - If pSubject is identical to pTarget.               *
 *               FALSE - otherwise.                                         *
 *                                                                          *
 ****************************************************************************/

BOOL NEAR PASCAL RealSlowCompare (
        register PSTR pSubject,
        register PSTR pTarget)
{
    if (fCase){
        while (*pTarget)
            if (*pTarget++ != *pSubject++)
                return FALSE;
    }
    else{
        /* If case-insensitive, convert both subject and target to lowercase
         * before comparing.
         */
        AnsiLower ((LPSTR)pTarget);
        while (*pTarget)
            if (*pTarget++ != (CHAR)(DWORD)AnsiLower ((LPSTR)(DWORD)(BYTE)*pSubject++))
                return FALSE;
    }
    return TRUE;
}

/****************************************************************************
 *                                                                          *
 *  FUNCTION   : Local_FindText ()                                                  *
 *                                                                          *
 *  PURPOSE    : Finds the search string in the active window according to  *
 *               search direction (dch) specified ( -1 for reverse and 1 for*
 *               forward searches).                                         *
 *                                                                          *
 ****************************************************************************/
VOID NEAR PASCAL Local_FindText(register INT dch)
{
    register PSTR pText;
    HANDLE        hT;
    LONG          l;
    WORD          cch;
    INT           i;

    if (!*szSearch)
        return;

    /* Find the current selection range */
    l = (LONG)SendMessage(hwndActiveEdit, EM_GETSEL, 0, 0);

    /* Get the handle to the text buffer and lock it */
    hT    = (HANDLE)SendMessage (hwndActiveEdit, EM_GETHANDLE, 0, 0L);
    pText = LocalLock(hT);

    /* Get the length of the text */
    cch = (WORD)SendMessage (hwndActiveEdit, WM_GETTEXTLENGTH, 0, 0L);

    /* Start with the next char. in selected range ... */
    pText += LOWORD (l) + dch;

    /* Compute how many characters are before/after the current selection*/
    if (dch < 0)
        i = LOWORD (l);
    else
        i = cch - LOWORD (l) + 1 - lstrlen (szSearch);

    /* While there are uncompared substrings... */
    while ( i > 0){
        LOWORD(l)+=dch;

        /* Does this substring match? */
        if (RealSlowCompare(pText,szSearch)){

            /* Yes, unlock the buffer.*/
            LocalUnlock(hT);

            /* Select the located string */
            HIWORD(l) = LOWORD(l) + (WORD)lstrlen (szSearch);
            SendMessage(hwndActiveEdit, EM_SETSEL, GET_EM_SETSEL_MPS(LOWORD(l), HIWORD(l)));
            return;
        }
        i--;

        /* increment/decrement start position by 1 */
        pText += dch;
    }

    /* Not found... unlock buffer. */
    LocalUnlock (hT);

    /* Give a message */
    MPError (hwndFrame, MB_OK | MB_ICONEXCLAMATION, IDS_CANTFIND, (LPSTR)szSearch);

    return;
}

/****************************************************************************
 *                                                                          *
 *  FUNCTION   : FindPrev ()                                                *
 *                                                                          *
 *  PURPOSE    : Finds the previous occurence of the search string. Calls   *
 *               Local_FindText () with a negative search direction.                *
 *                                                                          *
 ****************************************************************************/
VOID APIENTRY FindPrev()
{
    Local_FindText(-1);
}

/****************************************************************************
 *                                                                          *
 *  FUNCTION   : FindNext ()                                                *
 *                                                                          *
 *  PURPOSE    : Finds the next occurence of search string. Calls           *
 *               Local_FindText () with a positive search direction.                *
 *                                                                          *
 ****************************************************************************/
VOID APIENTRY FindNext()
{
    Local_FindText(1);
}

/****************************************************************************
 *                                                                          *
 *  FUNCTION   : FindDlgProc(hwnd, message, wParam, lParam)                 *
 *                                                                          *
 *  PURPOSE    : Dialog function for the Search/Find command. Prompts user  *
 *               for target string, case flag and search direction.         *
 *                                                                          *
 ****************************************************************************/
BOOL APIENTRY FindDlgProc(
        HWND hwnd,
        UINT msg,
        UINT wParam,
        LONG lParam)
{
    switch (msg){
        case WM_INITDIALOG:{

            /* Check/uncheck case button */
            CheckDlgButton (hwnd, (int)IDD_CASE, (WORD)fCase);

            /* Set default search string to most recently searched string */
            SetDlgItemText (hwnd, IDD_SEARCH, szSearch);

            /* Allow search only if target is nonempty */
            if (!lstrlen (szSearch)){
                EnableWindow (GetDlgItem (hwnd, IDOK), FALSE);
                EnableWindow (GetDlgItem (hwnd, IDD_PREV), FALSE);
            }
            break;
        }

        case WM_COMMAND:
        {

            /* Search forward by default (see IDOK below) */
            INT i = 1;

            switch (LOWORD(wParam)){
                /* if the search target becomes non-empty, enable searching */
                case IDD_SEARCH:
                    if (GET_WM_COMMAND_CMD(wParam, lParam) == EN_CHANGE){
                        if (!(WORD) SendDlgItemMessage (hwnd,
                                                        IDD_SEARCH,
                                                        WM_GETTEXTLENGTH,
                                                        0,
                                                        0L))
                            i = FALSE;
                        else
                            i = TRUE;
                        EnableWindow (GetDlgItem (hwnd, IDOK), i);
                        EnableWindow (GetDlgItem (hwnd, IDD_PREV), i);
                    }
                    break;

                case IDD_CASE:
                    /* Toggle state of case button */
                    CheckDlgButton (hwnd,
                                    (int)IDD_CASE,
                                    (WORD)!IsDlgButtonChecked (hwnd, (int)IDD_CASE));
                    break;

                case IDD_PREV:
                    /* Set direction to backwards */
                    i=-1;
                    /*** FALL THRU ***/

                case IDOK:
                    /* Save case selection */
                    fCase = IsDlgButtonChecked( hwnd, IDD_CASE);

                    /* Get search string */
                    GetDlgItemText (hwnd, IDD_SEARCH, szSearch, sizeof (szSearch));

                    /* Find the text */
                    Local_FindText (i);
                    /*** FALL THRU ***/

                /* End the dialog */
                case IDCANCEL:
                    EndDialog (hwnd, 0);
                    break;

                default:
                    return FALSE;
            }
            break;
        }
        default:
            return FALSE;
    }
    return TRUE;
        UNREFERENCED_PARAMETER(lParam);
}

/****************************************************************************
 *                                                                          *
 *  FUNCTION   : Find()                                                     *
 *                                                                          *
 *  PURPOSE    : Invokes the Search/Find dialog.                            *
 *                                                                          *
 ****************************************************************************/

VOID APIENTRY Find()
{
    DialogBox (hInst, IDD_FIND, hwndFrame, FindDlgProc);
}
