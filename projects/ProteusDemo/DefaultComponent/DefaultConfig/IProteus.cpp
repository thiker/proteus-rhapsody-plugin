/********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: IProteus
//!	Generated Date	: Mon, 29, May 2023  
	File Path	: DefaultComponent\DefaultConfig\IProteus.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "IProteus.h"
//#[ ignore
#define Proteus_IProteus_StateChange_SERIALIZE \
    aomsmethod->addAttribute("GUID", x2String(GUID));\
    aomsmethod->addAttribute("State", x2String(State));
#define Proteus_IProteus_IProteus_SERIALIZE OM_NO_OP
//#]

//## package Proteus

//## class IProteus
IProteus::IProteus() {
    NOTIFY_CONSTRUCTOR(IProteus, IProteus(), 0, Proteus_IProteus_IProteus_SERIALIZE);
}

IProteus::~IProteus() {
    NOTIFY_DESTRUCTOR(~IProteus, true);
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedIProteus::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("GUID", x2String(myReal->GUID));
    aomsAttributes->addAttribute("State", x2String(myReal->State));
}
//#]

IMPLEMENT_META_P(IProteus, Proteus, Proteus, false, OMAnimatedIProteus)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\IProteus.cpp
*********************************************************************/
