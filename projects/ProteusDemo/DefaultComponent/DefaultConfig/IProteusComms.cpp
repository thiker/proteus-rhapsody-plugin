/********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: IProteusComms
//!	Generated Date	: Mon, 29, May 2023  
	File Path	: DefaultComponent\DefaultConfig\IProteusComms.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "IProteusComms.h"
//#[ ignore
#define Proteus_IProteusComms_SetCurrentState_SERIALIZE \
    aomsmethod->addAttribute("stateObjectId", x2String(stateObjectId));\
    aomsmethod->addAttribute("state", x2String(state));
#define Proteus_IProteusComms_SetStateData_SERIALIZE \
    aomsmethod->addAttribute("stateObjectId", x2String(stateObjectId));\
    aomsmethod->addAttribute("key", x2String(key));\
    aomsmethod->addAttribute("data", x2String(data));
#define OM_Proteus_IProteusComms_SetStateData_1_SERIALIZE \
    aomsmethod->addAttribute("stateObjectId", x2String(stateObjectId));\
    aomsmethod->addAttribute("key", x2String(key));\
    aomsmethod->addAttribute("data", x2String(data));\
    aomsmethod->addAttribute("useDataRaw", x2String(useDataRaw));
#define OM_Proteus_IProteusComms_SetStateData_2_SERIALIZE \
    aomsmethod->addAttribute("stateObjectId", x2String(stateObjectId));\
    aomsmethod->addAttribute("key", x2String(key));\
    aomsmethod->addAttribute("data", x2String(data));
#define OM_Proteus_IProteusComms_SetStateData_3_SERIALIZE \
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
