/*******************************************************************************

Copyright (c) 1998 Microsoft Corporation.  All rights reserved.

File Name:

    object.cpp

Description:

    Fundamental base class.

*******************************************************************************/

#include "d3dlocus.h"

//******************************************************************************
// CObject
//******************************************************************************

//******************************************************************************
CObject::CObject() {

    m_uRef = 1;
}

//******************************************************************************
CObject::~CObject() {

    m_uRef = 0;
}

//******************************************************************************
ULONG CObject::AddRef() {

    return ++m_uRef;
}

//******************************************************************************
ULONG CObject::Release() {

    UINT uRef = --m_uRef;
    if (uRef == 0) {
        delete this;
    }
    return uRef;
}

//******************************************************************************
ULONG CObject::RefCount() {

    return m_uRef;
}
