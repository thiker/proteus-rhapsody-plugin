/*********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ProteusRhapsody
//!	Generated Date	: Sun, 28, May 2023  
	File Path	: DefaultComponent\DefaultConfig\ProteusRhapsody.h
*********************************************************************/

#ifndef ProteusRhapsody_H
#define ProteusRhapsody_H

//## auto_generated
#include <oxf\oxf.h>
//## auto_generated
#include <aom\aom.h>
//## auto_generated
#include "MQTTClient.h"
//## auto_generated
#include "Proteus.h"
//## auto_generated
#include <oxf\omthread.h>
//## auto_generated
#include <oxf\omreactive.h>
//## auto_generated
#include <oxf\state.h>
//## auto_generated
#include <oxf\event.h>
//## package Proteus

//## class ProteusRhapsody
class ProteusRhapsody : public OMReactive {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedProteusRhapsody;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    ProteusRhapsody(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~ProteusRhapsody();
    
    ////    Operations    ////
    
    //## operation Init()
    void Init();
    
    ////    Additional operations    ////
    
    //## auto_generated
    static const char* getADDRESS();
    
    //## auto_generated
    static const char* getCLIENTID();
    
    //## auto_generated
    static const int getQOS();
    
    //## auto_generated
    static const OMString getSTART_PAYLOAD();
    
    //## auto_generated
    static MQTTClient getClient();
    
    //## auto_generated
    static void setClient(MQTTClient p_client);
    
    //## auto_generated
    virtual bool startBehavior();

protected :

    //## auto_generated
    void initStatechart();
    
    ////    Attributes    ////
    
    static const char* ADDRESS;		//## attribute ADDRESS
    
    static const char* CLIENTID;		//## attribute CLIENTID
    
    static const int QOS;		//## attribute QOS
    
    static const OMString START_PAYLOAD;		//## attribute START_PAYLOAD
    
    static MQTTClient client;		//## attribute client
    
    ////    Framework operations    ////

public :

    // rootState:
    //## statechart_method
    inline bool rootState_IN() const;
    
    //## statechart_method
    virtual void rootState_entDef();
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent();
    
    // Default:
    //## statechart_method
    inline bool Default_IN() const;
    
    ////    Framework    ////

protected :

//#[ ignore
    enum ProteusRhapsody_Enum {
        OMNonState = 0,
        Default = 1
    };
    
    int rootState_subState;
    
    int rootState_active;
//#]
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedProteusRhapsody : virtual public AOMInstance {
    DECLARE_REACTIVE_META(ProteusRhapsody, OMAnimatedProteusRhapsody)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeAttributes(AOMSAttributes* aomsAttributes) const;
    
    //## statechart_method
    void rootState_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Default_serializeStates(AOMSState* aomsState) const;
};
//#]
#endif // _OMINSTRUMENT

inline bool ProteusRhapsody::rootState_IN() const {
    return true;
}

inline bool ProteusRhapsody::Default_IN() const {
    return rootState_subState == Default;
}

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\ProteusRhapsody.h
*********************************************************************/
