/********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Engine
//!	Generated Date	: Sat, 27, May 2023  
	File Path	: DefaultComponent\DefaultConfig\Engine.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "Engine.h"
//## link itsCar
#include "Car.h"
//#[ ignore
#define Default_Engine_Engine_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class Engine
Engine::Engine(IOxfActive* theActiveContext) {
    NOTIFY_REACTIVE_CONSTRUCTOR(Engine, Engine(), 0, Default_Engine_Engine_SERIALIZE);
    setActiveContext(theActiveContext, false);
    itsCar = NULL;
    initStatechart();
}

Engine::~Engine() {
    NOTIFY_DESTRUCTOR(~Engine, true);
    cleanUpRelations();
}

Car* Engine::getItsCar() const {
    return itsCar;
}

void Engine::setItsCar(Car* p_Car) {
    if(p_Car != NULL)
        {
            p_Car->_setItsEngine(this);
        }
    _setItsCar(p_Car);
}

bool Engine::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void Engine::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void Engine::cleanUpRelations() {
    if(itsCar != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsCar");
            Engine* p_Engine = itsCar->getItsEngine();
            if(p_Engine != NULL)
                {
                    itsCar->__setItsEngine(NULL);
                }
            itsCar = NULL;
        }
}

void Engine::__setItsCar(Car* p_Car) {
    itsCar = p_Car;
    if(p_Car != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsCar", p_Car, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsCar");
        }
}

void Engine::_setItsCar(Car* p_Car) {
    if(itsCar != NULL)
        {
            itsCar->__setItsEngine(NULL);
        }
    __setItsCar(p_Car);
}

void Engine::_clearItsCar() {
    NOTIFY_RELATION_CLEARED("itsCar");
    itsCar = NULL;
}

void Engine::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("2");
        NOTIFY_STATE_ENTERED("ROOT.Idle");
        rootState_subState = Idle;
        rootState_active = Idle;
        NOTIFY_TRANSITION_TERMINATED("2");
    }
}

IOxfReactive::TakeEventStatus Engine::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        // State Idle
        case Idle:
        {
            if(IS_EVENT_TYPE_OF(evRun_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("0");
                    NOTIFY_STATE_EXITED("ROOT.Idle");
                    NOTIFY_STATE_ENTERED("ROOT.Running");
                    rootState_subState = Running;
                    rootState_active = Running;
                    NOTIFY_TRANSITION_TERMINATED("0");
                    res = eventConsumed;
                }
            
        }
        break;
        // State Running
        case Running:
        {
            if(IS_EVENT_TYPE_OF(evIdle_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("1");
                    NOTIFY_STATE_EXITED("ROOT.Running");
                    NOTIFY_STATE_ENTERED("ROOT.Idle");
                    rootState_subState = Idle;
                    rootState_active = Idle;
                    NOTIFY_TRANSITION_TERMINATED("1");
                    res = eventConsumed;
                }
            
        }
        break;
        default:
            break;
    }
    return res;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedEngine::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsCar", false, true);
    if(myReal->itsCar)
        {
            aomsRelations->ADD_ITEM(myReal->itsCar);
        }
}

void OMAnimatedEngine::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case Engine::Idle:
        {
            Idle_serializeStates(aomsState);
        }
        break;
        case Engine::Running:
        {
            Running_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedEngine::Running_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Running");
}

void OMAnimatedEngine::Idle_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Idle");
}
//#]

IMPLEMENT_REACTIVE_META_P(Engine, Default, Default, false, OMAnimatedEngine)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Engine.cpp
*********************************************************************/
