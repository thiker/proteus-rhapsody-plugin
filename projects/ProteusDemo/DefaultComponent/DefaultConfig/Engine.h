/*********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Engine
//!	Generated Date	: Sun, 28, May 2023  
	File Path	: DefaultComponent\DefaultConfig\Engine.h
*********************************************************************/

#ifndef Engine_H
#define Engine_H

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
//## link itsCar
class Car;

//## package Default

//## class Engine
class Engine : public OMReactive {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedEngine;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    Engine(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~Engine();
    
    ////    Additional operations    ////
    
    //## auto_generated
    Car* getItsCar() const;
    
    //## auto_generated
    void setItsCar(Car* p_Car);
    
    //## auto_generated
    virtual bool startBehavior();

protected :

    //## auto_generated
    void initStatechart();
    
    //## auto_generated
    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    Car* itsCar;		//## link itsCar
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsCar(Car* p_Car);
    
    //## auto_generated
    void _setItsCar(Car* p_Car);
    
    //## auto_generated
    void _clearItsCar();
    
    // rootState:
    //## statechart_method
    inline bool rootState_IN() const;
    
    //## statechart_method
    virtual void rootState_entDef();
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent();
    
    // Running:
    //## statechart_method
    inline bool Running_IN() const;
    
    // Idle:
    //## statechart_method
    inline bool Idle_IN() const;
    
    ////    Framework    ////

protected :

//#[ ignore
    enum Engine_Enum {
        OMNonState = 0,
        Running = 1,
        Idle = 2
    };
    
    int rootState_subState;
    
    int rootState_active;
//#]
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedEngine : virtual public AOMInstance {
    DECLARE_REACTIVE_META(Engine, OMAnimatedEngine)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
    
    //## statechart_method
    void rootState_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Running_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Idle_serializeStates(AOMSState* aomsState) const;
};
//#]
#endif // _OMINSTRUMENT

inline bool Engine::rootState_IN() const {
    return true;
}

inline bool Engine::Running_IN() const {
    return rootState_subState == Running;
}

inline bool Engine::Idle_IN() const {
    return rootState_subState == Idle;
}

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Engine.h
*********************************************************************/
