/*********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: IProteusComms
//!	Generated Date	: Mon, 29, May 2023  
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
    
    //## operation SetCurrentState(OMString,OMString)
    virtual void SetCurrentState(OMString stateObjectId, const OMString& state) = 0;
    
    //## operation SetStateData(OMString,OMString,int)
    virtual void SetStateData(const OMString& stateObjectId, const OMString& key, int data) = 0;
    
    //## operation SetStateData(OMString,OMString,OMString,bool)
    virtual void SetStateData(const OMString& stateObjectId, const OMString& key, const OMString& data, bool useDataRaw = false) = 0;
    
    //## operation SetStateData(OMString,OMString,float)
    virtual void SetStateData(const OMString& stateObjectId, const OMString& key, float data) = 0;
    
    //## operation SetStateData(OMString,OMString,bool)
    virtual void SetStateData(const OMString& stateObjectId, const OMString& key, bool data) = 0;
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
