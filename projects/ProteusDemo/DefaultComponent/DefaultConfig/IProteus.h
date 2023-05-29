/*********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: IProteus
//!	Generated Date	: Mon, 29, May 2023  
	File Path	: DefaultComponent\DefaultConfig\IProteus.h
*********************************************************************/

#ifndef IProteus_H
#define IProteus_H

//## auto_generated
#include <oxf\oxf.h>
//## auto_generated
#include <aom\aom.h>
//## auto_generated
#include "MQTTClient.h"
//## auto_generated
#include "Proteus.h"
//## package Proteus

//## class IProteus
class IProteus {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedIProteus;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    IProteus();
    
    //## auto_generated
    virtual ~IProteus() = 0;
    
    ////    Operations    ////
    
    //## operation StateChange(OMString,OMString)
    virtual void StateChange(const OMString& GUID, const OMString& State) = 0;
    
    ////    Additional operations    ////
    
    //## auto_generated
    virtual OMString getGUID() const = 0;
    
    //## auto_generated
    virtual void setGUID(OMString p_GUID) = 0;
    
    //## auto_generated
    virtual OMString getState() const = 0;
    
    //## auto_generated
    virtual void setState(OMString p_State) = 0;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedIProteus : virtual public AOMInstance {
    DECLARE_META(IProteus, OMAnimatedIProteus)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeAttributes(AOMSAttributes* aomsAttributes) const;
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\IProteus.h
*********************************************************************/
