/*********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Starter
//!	Generated Date	: Sat, 27, May 2023  
	File Path	: DefaultComponent\DefaultConfig\Starter.h
*********************************************************************/

#ifndef Starter_H
#define Starter_H

//## auto_generated
#include <oxf\oxf.h>
//## auto_generated
#include <aom\aom.h>
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
    virtual bool startBehavior();

protected :

    //## auto_generated
    void initStatechart();
    
    //## auto_generated
    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    Engine* itsEngine;		//## link itsEngine
    
    ////    Framework operations    ////

public :

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
