// ----------------------------------------------------------------------------
//  FILE: CIDOrbUC_LogSrvClientProxy.hpp
//  DATE: Wed, Apr 17 21:38:13 2019 -0400
//    ID: 7F1112BEFF72CF9A-1A3600EA74289F30
//
//  This file was generated by the Charmed Quark CIDIDL compiler. Do not make
//  changes by hand, because they will be lost if the file is regenerated.
// ----------------------------------------------------------------------------
#pragma once

#pragma CIDLIB_PACK(CIDLIBPACK)

class CIDORBUCEXP TCIDLogSrvClientProxy : public TOrbClientBase
{
    public :
        // --------------------------------------------------------------------
        // Public, static data
        // --------------------------------------------------------------------
        static const TString strInterfaceId;
        static const TString strScope;
        static const TString strAdminBinding;
        static const TString strBinding;



        // --------------------------------------------------------------------
        // Public Constructors and Destructor
        // --------------------------------------------------------------------
        TCIDLogSrvClientProxy();
        TCIDLogSrvClientProxy(const TOrbObjId& ooidSrc, const TString& strNSBinding);
        TCIDLogSrvClientProxy(const TCIDLogSrvClientProxy&) = delete;
        ~TCIDLogSrvClientProxy();

        // --------------------------------------------------------------------
        // Public operators
        // --------------------------------------------------------------------
        TCIDLogSrvClientProxy& operator=(const TCIDLogSrvClientProxy&) = delete;

        // --------------------------------------------------------------------
        // Public, inherited methods
        // --------------------------------------------------------------------
        tCIDLib::TVoid SetObjId
        (
            const   TOrbObjId& ooidToSet
            , const TString& strNSBinding
            , const tCIDLib::TBoolean bCheck = kCIDLib::True
        )   override;

        // --------------------------------------------------------------------
        // Public, non-virtual methods
        // --------------------------------------------------------------------
        tCIDLib::TBoolean bGetLiveEvents
        (
            tCIDLib::TCard4& c4NextEventId
            , TVector<TLogEvent>& colToFill
        );

        tCIDLib::TCard4 c4QueryEvents
        (
            TVector<TLogEvent>& colToFill
            , const tCIDLib::TCard4 c4MaxToReturn
        );

        tCIDLib::TCard4 c4QueryEvents
        (
            TVector<TLogEvent>& colToFill
            , const tCIDLib::TCard4 c4Minutes
            , const tCIDLib::TCard4 c4MaxToReturn
        );

        tCIDLib::TCard4 c4QueryEvents
        (
            TVector<TLogEvent>& colToFill
            , const tCIDLib::TCard4 c4MaxToReturn
            , const TString& strHostExpr
            , const TString& strProcExpr
            , const TString& strFacExpr
            , const TString& strThreadExpr
            , const tCIDLib::TCard8 c8SevLevels
            , const tCIDLib::TCard8 c8ErrClasses
        );

        tCIDLib::TVoid DebugDump
        (
            tCIDLib::TCard4& c4BufSz_mbufData
            , THeapBuf& mbufData
        );

        tCIDLib::TVoid LogSingle
        (
            const TLogEvent& logevToSend
        );

        tCIDLib::TVoid LogMultiple
        (
            const TBag<TLogEvent>& colErrors
        );

        tCIDLib::TVoid RemoveAll();

    protected :
        // --------------------------------------------------------------------
        // Declare our friends
        // --------------------------------------------------------------------
        friend class TFacCIDOrb;

    private :
        // --------------------------------------------------------------------
        // Magic macros
        // --------------------------------------------------------------------
        RTTIDefs(TCIDLogSrvClientProxy,TOrbClientBase)
};

#pragma CIDLIB_POPPACK

inline tCIDLib::TVoid
TCIDLogSrvClientProxy::SetObjId(const  TOrbObjId& ooidToSet
              , const TString& strNSBinding
              , const tCIDLib::TBoolean bCheck)
{
    TParent::SetObjId(ooidToSet, strNSBinding, bCheck);
}

