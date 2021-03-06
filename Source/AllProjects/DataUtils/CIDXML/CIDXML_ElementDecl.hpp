//
// FILE NAME: CIDXML_ElementDecl.hpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 08/30/1999
//
// COPYRIGHT: Charmed Quark Systems, Ltd @ 2019
//
//  This software is copyrighted by 'Charmed Quark Systems, Ltd' and
//  the author (Dean Roddey.) It is licensed under the MIT Open Source
//  license:
//
//  https://opensource.org/licenses/MIT
//
// DESCRIPTION:
//
//  This is the header file for the CIDXML_ElementDecl.Cpp file, which
//  implements the TXMLElemDecl class. This class represents the basic
//  functionality of an element declaration. Different types of validators
//  will create variations for themselves. At this level, we just define
//  what is required for the parser core to do its work.
//
//  TAttrDefCursor is a small abstract class that represents a cursor for the
//  attr defs that belong to an element decl. Each type of validator defines
//  its own element decl derivative and its own attribute def derivative.
//  So this simple cursor class allows the core parser to be able to iterate
//  through the attribute defs of an element, no matter what type. It
//  implements the standard XML iterator mixin interface, as is normal for
//  any type of cursor or iterator.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//
#pragma once


#pragma CIDLIB_PACK(CIDLIBPACK)


// ---------------------------------------------------------------------------
//  CLASS: TAttrDefCursor
// PREFIX: adc
// ---------------------------------------------------------------------------
class CIDXMLEXP TAttrDefCursor
{
    public :
        // -------------------------------------------------------------------
        //  Public Destructor
        // -------------------------------------------------------------------
        TAttrDefCursor(const TAttrDefCursor&) = delete;
        TAttrDefCursor(TAttrDefCursor&&) = delete;

        virtual ~TAttrDefCursor() {}


        // -------------------------------------------------------------------
        //  Public operators
        // -------------------------------------------------------------------
        TAttrDefCursor& operator=(const TAttrDefCursor&) = delete;
        TAttrDefCursor& operator=(TAttrDefCursor&&) = delete;


        // -------------------------------------------------------------------
        //  Public, pure virtual methods
        // -------------------------------------------------------------------
        virtual tCIDLib::TBoolean bNext() = 0;

        virtual tCIDLib::TBoolean bReset() = 0;

        virtual const TXMLAttrDef& xadCur() const = 0;


    protected :
        // -------------------------------------------------------------------
        //  Hidden constructors and operators
        // -------------------------------------------------------------------
        TAttrDefCursor() {}
};


// ---------------------------------------------------------------------------
//  CLASS: TXMLElemDecl
// PREFIX: xdecl
// ---------------------------------------------------------------------------
class CIDXMLEXP TXMLElemDecl
{
    public  :
        // -------------------------------------------------------------------
        //  Public Destructor
        // -------------------------------------------------------------------
        TXMLElemDecl(const TXMLElemDecl&) = delete;
        TXMLElemDecl(TXMLElemDecl&&) = delete;

        virtual ~TXMLElemDecl() {}


        // -------------------------------------------------------------------
        //  Public operators
        // -------------------------------------------------------------------
        TXMLElemDecl& operator=(const TXMLElemDecl&) = delete;
        TXMLElemDecl& operator=(TXMLElemDecl&&) = delete;


        // -------------------------------------------------------------------
        //  Public, virtual methods
        // -------------------------------------------------------------------
        virtual TAttrDefCursor& adcThis() const = 0;

        virtual tCIDLib::TBoolean bClearAttrFlags() = 0;

        virtual tCIDXML::EElemTextTypes eTextType() const = 0;

        virtual tCIDLib::TVoid FormatCMTo
        (
                    TTextOutStream&         strmDest
            , const TXMLValidator&          xvalPools
        )   const = 0;

        virtual tCIDLib::TVoid FormatTo
        (
                    TTextOutStream&         strmDest
            , const TXMLValidator&          xvalPools
        )   const = 0;

        virtual TXMLAttrDef* pxadFindAttrDef
        (
            const   TString&                strName
        ) = 0;

        virtual const TXMLAttrDef* pxadFindAttrDef
        (
            const   TString&                strName
        )   const = 0;

        virtual TXMLAttrDef* pxadFindAttrDef
        (
            const   TString&                strName
            ,       tCIDLib::TBoolean&      bAdded
        ) = 0;

        virtual const TString& strFullName() const = 0;



        // -------------------------------------------------------------------
        //  Public, non-virtual methods
        // -------------------------------------------------------------------
        tCIDLib::TCard4 c4Id() const
        {
            return m_c4Id;
        }

        tCIDLib::TCard4 c4Id(const tCIDLib::TCard4 c4NewId)
        {
            m_c4Id = c4NewId;
            return m_c4Id;
        }

        tCIDXML::EElemReasons eCreateReason() const
        {
            return m_eCreateReason;
        }

        tCIDXML::EElemReasons eCreateReason(const tCIDXML::EElemReasons eReason)
        {
            m_eCreateReason = eReason;
            return m_eCreateReason;
        }


    protected :
        // -------------------------------------------------------------------
        //  Hidden constructors
        // -------------------------------------------------------------------
        TXMLElemDecl()  :

            m_c4Id(kCIDLib::c4MaxCard)
            , m_eCreateReason(tCIDXML::EElemReasons::Count)
        {
        }


    private :
        // -------------------------------------------------------------------
        //  Private data members
        //
        //  m_c4Id
        //      This the unique id (unique with the elements of a particular
        //      parse) assigned to this element by the pool it gets put into.
        //
        //  m_eCreateReason
        //      This is set to indicate why the element got into the elem
        //      pool.
        // -------------------------------------------------------------------
        tCIDLib::TCard4         m_c4Id;
        tCIDXML::EElemReasons   m_eCreateReason;
};

#pragma CIDLIB_POPPACK
