/********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Starter
//!	Generated Date	: Sun, 28, May 2023  
	File Path	: DefaultComponent\DefaultConfig\Starter.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "Starter.h"
//## link itsEngine
#include "Engine.h"
//## link itsStarterComponent
#include "StarterComponent.h"
//## link itsStarterComponent2
#include "StarterComponent2.h"
//#[ ignore
#define Default_Starter_Starter_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class Starter
Starter::Starter(IOxfActive* theActiveContext) {
    NOTIFY_REACTIVE_CONSTRUCTOR(Starter, Starter(), 0, Default_Starter_Starter_SERIALIZE);
    setActiveContext(theActiveContext, false);
    itsEngine = NULL;
    itsStarterComponent = NULL;
    itsStarterComponent2 = NULL;
    initStatechart();
}

Starter::~Starter() {
    NOTIFY_DESTRUCTOR(~Starter, true);
    cleanUpRelations();
}

Engine* Starter::getItsEngine() const {
    return itsEngine;
}

void Starter::setItsEngine(Engine* p_Engine) {
    itsEngine = p_Engine;
    if(p_Engine != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsEngine", p_Engine, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsEngine");
        }
}

StarterComponent* Starter::getItsStarterComponent() const {
    return itsStarterComponent;
}

void Starter::setItsStarterComponent(StarterComponent* p_StarterComponent) {
    if(p_StarterComponent != NULL)
        {
            p_StarterComponent->_setItsStarter(this);
        }
    _setItsStarterComponent(p_StarterComponent);
}

StarterComponent2* Starter::getItsStarterComponent2() const {
    return itsStarterComponent2;
}

void Starter::setItsStarterComponent2(StarterComponent2* p_StarterComponent2) {
    if(p_StarterComponent2 != NULL)
        {
            p_StarterComponent2->_setItsStarter(this);
        }
    _setItsStarterComponent2(p_StarterComponent2);
}

bool Starter::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void Starter::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void Starter::cleanUpRelations() {
    if(itsEngine != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsEngine");
            itsEngine = NULL;
        }
    if(itsStarterComponent != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsStarterComponent");
            Starter* p_Starter = itsStarterComponent->getItsStarter();
            if(p_Starter != NULL)
                {
                    itsStarterComponent->__setItsStarter(NULL);
                }
            itsStarterComponent = NULL;
        }
    if(itsStarterComponent2 != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsStarterComponent2");
            Starter* p_Starter = itsStarterComponent2->getItsStarter();
            if(p_Starter != NULL)
                {
                    itsStarterComponent2->__setItsStarter(NULL);
                }
            itsStarterComponent2 = NULL;
        }
}

void Starter::__setItsStarterComponent(StarterComponent* p_StarterComponent) {
    itsStarterComponent = p_StarterComponent;
    if(p_StarterComponent != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsStarterComponent", p_StarterComponent, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsStarterComponent");
        }
}

void Starter::_setItsStarterComponent(StarterComponent* p_StarterComponent) {
    if(itsStarterComponent != NULL)
        {
            itsStarterComponent->__setItsStarter(NULL);
        }
    __setItsStarterComponent(p_StarterComponent);
}

void Starter::_clearItsStarterComponent() {
    NOTIFY_RELATION_CLEARED("itsStarterComponent");
    itsStarterComponent = NULL;
}

void Starter::__setItsStarterComponent2(StarterComponent2* p_StarterComponent2) {
    itsStarterComponent2 = p_StarterComponent2;
    if(p_StarterComponent2 != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsStarterComponent2", p_StarterComponent2, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsStarterComponent2");
        }
}

void Starter::_setItsStarterComponent2(StarterComponent2* p_StarterComponent2) {
    if(itsStarterComponent2 != NULL)
        {
            itsStarterComponent2->__setItsStarter(NULL);
        }
    __setItsStarterComponent2(p_StarterComponent2);
}

void Starter::_clearItsStarterComponent2() {
    NOTIFY_RELATION_CLEARED("itsStarterComponent2");
    itsStarterComponent2 = NULL;
}

void Starter::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        NOTIFY_STATE_ENTERED("ROOT.Stopped");
        rootState_subState = Stopped;
        rootState_active = Stopped;
        //#[ state Stopped.(Entry) 
        itsEngine->GEN(evIdle());
        //#]
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

IOxfReactive::TakeEventStatus Starter::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        // State Stopped
        case Stopped:
        {
            if(IS_EVENT_TYPE_OF(evStart_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("1");
                    NOTIFY_STATE_EXITED("ROOT.Stopped");
                    NOTIFY_STATE_ENTERED("ROOT.Started");
                    rootState_subState = Started;
                    rootState_active = Started;
                    //#[ state Started.(Entry) 
                    itsEngine->GEN(evRun);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("1");
                    res = eventConsumed;
                }
            
        }
        break;
        // State Started
        case Started:
        {
            if(IS_EVENT_TYPE_OF(evStop_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("2");
                    NOTIFY_STATE_EXITED("ROOT.Started");
                    NOTIFY_STATE_ENTERED("ROOT.Stopped");
                    rootState_subState = Stopped;
                    rootState_active = Stopped;
                    //#[ state Stopped.(Entry) 
                    itsEngine->GEN(evIdle());
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("2");
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
void OMAnimatedStarter::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsEngine", false, true);
    if(myReal->itsEngine)
        {
            aomsRelations->ADD_ITEM(myReal->itsEngine);
        }
    aomsRelations->addRelation("itsStarterComponent2", false, true);
    if(myReal->itsStarterComponent2)
        {
            aomsRelations->ADD_ITEM(myReal->itsStarterComponent2);
        }
    aomsRelations->addRelation("itsStarterComponent", false, true);
    if(myReal->itsStarterComponent)
        {
            aomsRelations->ADD_ITEM(myReal->itsStarterComponent);
        }
}

void OMAnimatedStarter::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case Starter::Stopped:
        {
            Stopped_serializeStates(aomsState);
        }
        break;
        case Starter::Started:
        {
            Started_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedStarter::Stopped_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Stopped");
}

void OMAnimatedStarter::Started_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Started");
}
//#]

IMPLEMENT_REACTIVE_META_P(Starter, Default, Default, false, OMAnimatedStarter)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Starter.cpp
*********************************************************************/
