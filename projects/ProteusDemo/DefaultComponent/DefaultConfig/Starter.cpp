/********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Starter
//!	Generated Date	: Sat, 27, May 2023  
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
//#[ ignore
#define Default_Starter_Starter_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class Starter
Starter::Starter(IOxfActive* theActiveContext) {
    NOTIFY_REACTIVE_CONSTRUCTOR(Starter, Starter(), 0, Default_Starter_Starter_SERIALIZE);
    setActiveContext(theActiveContext, false);
    itsEngine = NULL;
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
