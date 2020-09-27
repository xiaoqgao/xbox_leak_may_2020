/*

Copyright (c) 2000 Microsoft Corporation

Module Name:

    utils.h

Abstract:

    This module contains the helper functions used by the API tests

Author:

    Josh Poley (jpoley)

Environment:

    XBox

Revision History:
    04-21-2000  Created

Notes:

*/
#ifndef _UTILS_H_
#define _UTILS_H_

#include "stdafx.h"
#include <xlog.h>

namespace Nickname
    {
    bool CompareFirstNickname(WCHAR *nickname);
    bool RemoveNicknameFile(void);
    } // namespace Nickname
#endif // _UTILS_H_