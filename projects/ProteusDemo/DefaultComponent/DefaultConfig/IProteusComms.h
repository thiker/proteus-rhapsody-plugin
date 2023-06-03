/*********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: IProteusComms
//!	Generated Date	: Sat, 3, Jun 2023  
	File Path	: DefaultComponent\DefaultConfig\IProteusComms.h
*********************************************************************/

#ifndef IProteusComms_H
#define IProteusComms_H

//## auto_generated
#include <oxf\oxf.h>
//## auto_generated
#include <aom\aom.h>
//## auto_generated
#include "MQTTClient.h"
//## auto_generated
#include "Proteus.h"
//## package Proteus

//## class IProteusComms
class IProteusComms {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedIProteusComms;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    IProteusComms();
    
    //## auto_generated
    virtual ~IProteusComms() = 0;
    
    ////    Operations    ////
    
    //## operation SetStateDataBool(OMString,OMString,bool)
    virtual void SetStateDataBool(const OMString& stateObjectId, const OMString& key, bool data) = 0;
    
    //## operation SetStateDataNumber(OMString,OMString,int)
    virtual void SetStateDataNumber(const OMString& stateObjectId, const OMString& key, int data) = 0;
    
    //## operation SetStateDataNumber(OMString,OMString,float)
    virtual void SetStateDataNumber(const OMString& stateObjectId, const OMString& key, float data) = 0;
    
    //## operation SetStateDataRaw(OMString,OMString,OMString)
    virtual void SetStateDataRaw(const OMString& stateObjectId, const OMString& key, const OMString& data) = 0;
    
    //## operation SetStateDataString(OMString,OMString,OMString)
    virtual void SetStateDataString(const OMString& stateObjectId, const OMString& key, const OMString& data) = 0;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedIProteusComms : virtual public AOMInstance {
    DECLARE_META(IProteusComms, OMAnimatedIProteusComms)
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\IProteusComms.h
*********************************************************************/
