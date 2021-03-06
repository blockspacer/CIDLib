//
// FILE NAME: CIDKernel_Environment_Linux.Cpp
//
// AUTHOR: Will Mason
//
// CREATED: 12/09/1998
//
// COPYRIGHT: Charmed Quark Systems, Ltd - 2019
//
//  This software is copyrighted by 'Charmed Quark Systems, Ltd' and 
//  the author (Dean Roddey.) It is licensed under the MIT Open Source 
//  license:
//
//  https://opensource.org/licenses/MIT
//
// DESCRIPTION:
//
//  This file privdes the Linux specific implemention of the
//  TKrnlEnvironment namespace.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//


// ---------------------------------------------------------------------------
//  Facility specific includes
// ---------------------------------------------------------------------------
#include    "CIDKernel_.hpp"


// ---------------------------------------------------------------------------
//  Local const data
//
//  m_c4Modulus
//      The modulus used in the hashing of the key strings. This is passed
//      along to the hash map object.
// ---------------------------------------------------------------------------
static const tCIDLib::TCard4    m_c4Modulus = 23;



// ---------------------------------------------------------------------------
//  TCIDKrnlModule: Private, non-virtual methods
// ---------------------------------------------------------------------------
tCIDLib::TBoolean
TCIDKrnlModule::bInitTermEnvironment(const tCIDLib::EInitTerm eInitTerm)
{
    if (eInitTerm == tCIDLib::EInitTerm::Initialize)
    {
        // Allocate our critical section and our hash map objects.
        TKrnlEnvironment::s_pkcrsAccess = new TKrnlCritSec;
        TKrnlEnvironment::s_pkhshmEnv = new TKrnlHashMap(m_c4Modulus);

        //
        //  Now load up the environment with all of the environment
        //  strings that are set.
        //
        tCIDLib::TZStr512   szTmp;

        for (tCIDLib::TCard4 c4Count = 0; environ[c4Count]; c4Count++)
        {
            // Make a copy of the current element
            TRawStr::pszConvert(environ[c4Count], szTmp, c4MaxBufChars(szTmp));

            //
            //  We need to find the two parts of the string and pull
            //  it into its key and value sections.
            //
            tCIDLib::TCh* pszSplit = TRawStr::pszFindLastChar
            (
                szTmp
                , kCIDLib::chEquals
            );

            // This is bad, and should not be able to happen
            if (!pszSplit)
            {
                TKrnlError::SetLastKrnlError(kKrnlErrs::errcInit_InvalidEnvironment);
                return kCIDLib::False;
            }

            // Put a null at the split to create two strings
            *pszSplit = kCIDLib::chNull;

            // Uppercase the key
            TRawStr::pszUpperCase(szTmp);

            // And add them now to the hash map
            if (!TKrnlEnvironment::s_pkhshmEnv->bAdd(szTmp, pszSplit+1))
                return kCIDLib::False;
        }
    }
     else
    {
        // Delete our critical section and our hash map objects.
        delete TKrnlEnvironment::s_pkcrsAccess;
        delete TKrnlEnvironment::s_pkhshmEnv;
    }
    return kCIDLib::True;
}


// ---------------------------------------------------------------------------
//  TCIDKrnlModule: Public, static methods
// ---------------------------------------------------------------------------
tCIDLib::TBoolean
TKrnlEnvironment::bAddToExePath(const   tCIDLib::TCh* const pszToAdd
                                , const tCIDLib::EStartEnd  eWhere)
{
    TKrnlError::SetLastHostError(kKrnlErrs::errcGen_NotSupported);
    return kCIDLib::False;
}


tCIDLib::TBoolean
TKrnlEnvironment::bAddToLibPath(const   tCIDLib::TCh* const pszToAdd
                                , const tCIDLib::EStartEnd  eWhere)
{
    TKrnlError::SetLastHostError(kKrnlErrs::errcGen_NotSupported);
    return kCIDLib::False;    
}


tCIDLib::TBoolean
TKrnlEnvironment::bFindExePath(         tCIDLib::TCh* const pszToFill
                                , const tCIDLib::TCard4     c4MaxChars)
{
    TKrnlError::SetLastHostError(kKrnlErrs::errcGen_NotSupported);
    return kCIDLib::False;
}


tCIDLib::TBoolean
TKrnlEnvironment::bFindLibPath(         tCIDLib::TCh* const pszToFill
                                , const tCIDLib::TCard4     c4MaxChars)
{
    TKrnlError::SetLastHostError(kKrnlErrs::errcGen_NotSupported);
    return kCIDLib::False;
}


tCIDLib::TBoolean
TKrnlEnvironment::bFindTempPath(        tCIDLib::TCh* const pszToFill
                                , const tCIDLib::TCard4     c4MaxChars)
{
    TKrnlError::SetLastHostError(kKrnlErrs::errcGen_NotSupported);
    return kCIDLib::False;
}


// ---------------------------------------------------------------------------
//  TKrnlEnvironment: Private, static methods
// ---------------------------------------------------------------------------
tCIDLib::TBoolean
TKrnlEnvironment::bSetSysVar(const  tCIDLib::TCh* const pszKey
                            , const tCIDLib::TCh* const pszNewValue)
{
    // Build up the string
    const tCIDLib::TCard4 c4BufLen(TRawStr::c4StrLen(pszKey) + TRawStr::c4StrLen(pszNewValue));
    tCIDLib::TCh* apszBuf = nullptr;
    apszBuf = new tCIDLib::TCh[c4BufLen + 1];
    TArrayJanitor<tCIDLib::TCh> janBuf(apszBuf);
    TRawStr::CopyCatStr(apszBuf, c4BufLen, pszKey, L"=", pszNewValue);

    tCIDLib::TSCh* pszShortBuf = TRawStr::pszConvert(apszBuf);
    TArrayJanitor<tCIDLib::TSCh> janShortBuf(pszShortBuf);

    if (::putenv(pszShortBuf))
    {
        TKrnlError::SetLastHostError(errno);
        return kCIDLib::False;
    }
    return kCIDLib::True;
}

