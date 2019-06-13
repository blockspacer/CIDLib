// ----------------------------------------------------------------------------
//  FILE: CIDOrbUC_CoreAdminServerBase.cpp
//  DATE: Wed, Apr 17 21:38:13 2019 -0400
//    ID: 2117FF72EE8BD81D-F320AE6BEB1B2F0C
//
//  This file was generated by the Charmed Quark CIDIDL compiler. Do not make
//  changes by hand, because they will be lost if the file is regenerated.
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------------
#include "CIDOrbUC_.hpp"

// ----------------------------------------------------------------------------
// Magic macros
// ----------------------------------------------------------------------------
RTTIDecls(TCIDCoreAdminServerBase,TOrbServerBase)


// ----------------------------------------------------------------------------
// Public, static data
// ----------------------------------------------------------------------------
const TString TCIDCoreAdminServerBase::strInterfaceId(L"2117FF72EE8BD81D-F320AE6BEB1B2F0C");
// ----------------------------------------------------------------------------
// TCIDCoreAdminServerBase: Destructor
// ----------------------------------------------------------------------------
TCIDCoreAdminServerBase::~TCIDCoreAdminServerBase()
{
}

// ----------------------------------------------------------------------------
// TCIDCoreAdminServerBase: Protected Constructors
// ----------------------------------------------------------------------------
TCIDCoreAdminServerBase::TCIDCoreAdminServerBase() :
    TOrbServerBase(strInterfaceId, L"TCIDCoreAdminClientProxy" )
{
}

TCIDCoreAdminServerBase::TCIDCoreAdminServerBase(const TOrbObjId& ooidThis) :
    TOrbServerBase(ooidThis)
{
}

// ----------------------------------------------------------------------------
// TCIDCoreAdminServerBase: Public, non-virtual methods
// ----------------------------------------------------------------------------
tCIDLib::TVoid TCIDCoreAdminServerBase::Dispatch(const TString& strMethodName, TOrbCmd& orbcToDispatch)
{
    if (strMethodName == L"AdminStop")
    {
        AdminStop
        (
        );
        orbcToDispatch.strmOut().Reset();
    }
     else if (strMethodName == L"bPollValuesInScope")
    {
        TString strParScope;
        orbcToDispatch.strmIn() >> strParScope;
        tCIDLib::TBoolean bDirectOnly;
        orbcToDispatch.strmIn() >> bDirectOnly;
        tCIDLib::TCard8 c8QueryStamp;
        orbcToDispatch.strmIn() >> c8QueryStamp;
        tCIDLib::TCard8 c8PollStamp;
        orbcToDispatch.strmIn() >> c8PollStamp;
        TFundVector<tCIDLib::TCard4> fcolIds;
        TFundVector<tCIDLib::TCard8> fcolValues;
        tCIDLib::TBoolean retVal = bPollValuesInScope
        (
            strParScope
          , bDirectOnly
          , c8QueryStamp
          , c8PollStamp
          , fcolIds
          , fcolValues
        );
        orbcToDispatch.strmOut().Reset();
        orbcToDispatch.strmOut() << retVal;
        orbcToDispatch.strmOut() << c8PollStamp;
        orbcToDispatch.strmOut() << fcolIds;
        orbcToDispatch.strmOut() << fcolValues;
    }
     else if (strMethodName == L"c4QueryStats")
    {
        TString strParScope;
        orbcToDispatch.strmIn() >> strParScope;
        TVector<TStatsCacheItemInfo> colItems;
        tCIDLib::TBoolean bDirectOnly;
        orbcToDispatch.strmIn() >> bDirectOnly;
        tCIDLib::TCard8 c8Stamp;
        orbcToDispatch.strmIn() >> c8Stamp;
        tCIDLib::TCard4 retVal = c4QueryStats
        (
            strParScope
          , colItems
          , bDirectOnly
          , c8Stamp
        );
        orbcToDispatch.strmOut().Reset();
        orbcToDispatch.strmOut() << retVal;
        orbcToDispatch.strmOut() << colItems;
        orbcToDispatch.strmOut() << c8Stamp;
    }
     else if (strMethodName == L"QueryBasicInfo")
    {
        TString strHostName;
        TString strProcName;
        tCIDLib::TCard4 c4CPUCount;
        TString strOSInfo;
        tCIDLib::TCard8 c8StartTime;
        QueryBasicInfo
        (
            strHostName
          , strProcName
          , c4CPUCount
          , strOSInfo
          , c8StartTime
        );
        orbcToDispatch.strmOut().Reset();
        orbcToDispatch.strmOut() << strHostName;
        orbcToDispatch.strmOut() << strProcName;
        orbcToDispatch.strmOut() << c4CPUCount;
        orbcToDispatch.strmOut() << strOSInfo;
        orbcToDispatch.strmOut() << c8StartTime;
    }
     else if (strMethodName == L"SetModLogLevel")
    {
        TString strModule;
        orbcToDispatch.strmIn() >> strModule;
        TString strLevel;
        orbcToDispatch.strmIn() >> strLevel;
        SetModLogLevel
        (
            strModule
          , strLevel
        );
        orbcToDispatch.strmOut().Reset();
    }
     else if (strMethodName == L"SetModLogTrace")
    {
        TString strModule;
        orbcToDispatch.strmIn() >> strModule;
        tCIDLib::TBoolean bState;
        orbcToDispatch.strmIn() >> bState;
        SetModLogTrace
        (
            strModule
          , bState
        );
        orbcToDispatch.strmOut().Reset();
    }
     else
    {
         TParent::Dispatch(strMethodName, orbcToDispatch);
    }
}

