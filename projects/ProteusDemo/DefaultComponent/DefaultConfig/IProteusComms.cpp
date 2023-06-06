/********************************************************************
	Rhapsody	: 9.0 
	Login		: thijskoenraadt
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: IProteusComms
//!	Generated Date	: Tue, 6, Jun 2023  
	File Path	: DefaultComponent\DefaultConfig\IProteusComms.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "IProteusComms.h"
//#[ ignore
#define Proteus_IProteusComms_SetStateDataBool_SERIALIZE \
    aomsmethod->addAttribute("stateObjectId", x2String(stateObjectId));\
    aomsmethod->addAttribute("key", x2String(key));\
    aomsmethod->addAttribute("data", x2String(data));
#define Proteus_IProteusComms_SetStateDataNumber_SERIALIZE \
    aomsmethod->addAttribute("stateObjectId", x2String(stateObjectId));\
    aomsmethod->addAttribute("key", x2String(key));\
    aomsmethod->addAttribute("data", x2String(data));
#define OM_Proteus_IProteusComms_SetStateDataNumber_1_SERIALIZE \
    aomsmethod->addAttribute("stateObjectId", x2String(stateObjectId));\
    aomsmethod->addAttribute("key", x2String(key));\
    aomsmethod->addAttribute("data", x2String(data));
#define Proteus_IProteusComms_SetStateDataRaw_SERIALIZE \
    aomsmethod->addAttribute("stateObjectId", x2String(stateObjectId));\
    aomsmethod->addAttribute("key", x2String(key));\
    aomsmethod->addAttribute("data", x2String(data));
#define Proteus_IProteusComms_SetStateDataString_SERIALIZE \
    aomsmethod->addAttribute("stateObjectId", x2String(stateObjectId));\
    aomsmethod->addAttribute("key", x2String(key));\
    aomsmethod->addAttribute("data", x2String(data));
#define Proteus_IProteusComms_IProteusComms_SERIALIZE OM_NO_OP
//#]

//## package Proteus

//## class IProteusComms
IProteusComms::IProteusComms() {
    NOTIFY_CONSTRUCTOR(IProteusComms, IProteusComms(), 0, Proteus_IProteusComms_IProteusComms_SERIALIZE);
}

IProteusComms::~IProteusComms() {
    NOTIFY_DESTRUCTOR(~IProteusComms, true);
}

#ifdef _OMINSTRUMENT
IMPLEMENT_META_P(IProteusComms, Proteus, Proteus, false, OMAnimatedIProteusComms)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\IProteusComms.cpp
*********************************************************************/
