/*********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Starter
//!	Generated Date	: Sun, 28, May 2023  
	File Path	: DefaultComponent\DefaultConfig\Starter.h
*********************************************************************/

#ifndef Starter_H
#define Starter_H

//## auto_generated
#include <oxf\oxf.h>
//## auto_generated
#include <aom\aom.h>
//## auto_generated
#include "MQTTClient.h"
//## auto_generated
#include "Default.h"
//## auto_generated
#include <oxf\omthread.h>
//## auto_generated
#include <oxf\omreactive.h>
//## auto_generated
#include <oxf\state.h>
//## auto_generated
#include <oxf\event.h>
//## link itsEngine
class Engine;

//## link itsStarterComponent
class StarterComponent;

//## link itsStarterComponent2
class StarterComponent2;

//## package Default

//## class Starter
class Starter : public OMReactive {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedStarter;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    Starter(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~Starter();
    
    ////    Additional operations    ////
    
    //## auto_generated
    Engine* getItsEngine() const;
    
    //## auto_generated
    void setItsEngine(Engine* p_Engine);
    
    //## auto_generated
    StarterComponent* getItsStarterComponent() const;
    
    //## auto_generated
    void setItsStarterComponent(StarterComponent* p_StarterComponent);
    
    //## auto_generated
    StarterComponent2* getItsStarterComponent2() const;
    
    //## auto_generated
    void setItsStarterComponent2(StarterComponent2* p_StarterComponent2);
    
    //## auto_generated
    virtual bool startBehavior();

protected :

    //## auto_generated
    void initStatechart();
    
    //## auto_generated
    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    Engine* itsEngine;		//## link itsEngine
    
    StarterComponent* itsStarterComponent;		//## link itsStarterComponent
    
    StarterComponent2* itsStarterComponent2;		//## link itsStarterComponent2
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsStarterComponent(StarterComponent* p_StarterComponent);
    
    //## auto_generated
    void _setItsStarterComponent(StarterComponent* p_StarterComponent);
    
    //## auto_generated
    void _clearItsStarterComponent();
    
    //## auto_generated
    void __setItsStarterComponent2(StarterComponent2* p_StarterComponent2);
    
    //## auto_generated
    void _setItsStarterComponent2(StarterComponent2* p_StarterComponent2);
    
    //## auto_generated
    void _clearItsStarterComponent2();
    
    // rootState:
    //## statechart_method
    inline bool rootState_IN() const;
    
    //## statechart_method
    virtual void rootState_entDef();
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent();
    
    // Stopped:
    //## statechart_method
    inline bool Stopped_IN() const;
    
    // Started:
    //## statechart_method
    inline bool Started_IN() const;
    
    ////    Framework    ////

protected :

//#[ ignore
    enum Starter_Enum {
        OMNonState = 0,
        Stopped = 1,
        Started = 2
    };
    
    int rootState_subState;
    
    int rootState_active;
//#]
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedStarter : virtual public AOMInstance {
    DECLARE_REACTIVE_META(Starter, OMAnimatedStarter)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
    
    //## statechart_method
    void rootState_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Stopped_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Started_serializeStates(AOMSState* aomsState) const;
};
//#]
#endif // _OMINSTRUMENT

inline bool Starter::rootState_IN() const {
    return true;
}

inline bool Starter::Stopped_IN() const {
    return rootState_subState == Stopped;
}

inline bool Starter::Started_IN() const {
    return rootState_subState == Started;
}

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Starter.h
*********************************************************************/
