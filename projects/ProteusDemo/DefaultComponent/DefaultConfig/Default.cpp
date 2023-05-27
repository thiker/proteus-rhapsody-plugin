/********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Default
//!	Generated Date	: Sat, 27, May 2023  
	File Path	: DefaultComponent\DefaultConfig\Default.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "Default.h"
//## classInstance itsCar
#include "Car.h"
//## classInstance itsEngine
#include "Engine.h"
//## classInstance itsStarter
#include "Starter.h"
//## classInstance itsWheel
#include "Wheel.h"
//#[ ignore
#define evRun_SERIALIZE OM_NO_OP

#define evRun_UNSERIALIZE OM_NO_OP

#define evRun_CONSTRUCTOR evRun()

#define evIdle_SERIALIZE OM_NO_OP

#define evIdle_UNSERIALIZE OM_NO_OP

#define evIdle_CONSTRUCTOR evIdle()

#define evStart_SERIALIZE OM_NO_OP

#define evStart_UNSERIALIZE OM_NO_OP

#define evStart_CONSTRUCTOR evStart()

#define evStop_SERIALIZE OM_NO_OP

#define evStop_UNSERIALIZE OM_NO_OP

#define evStop_CONSTRUCTOR evStop()
//#]

//## package Default


//## classInstance itsCar
Car itsCar;

//## classInstance itsEngine
Engine itsEngine;

//## classInstance itsStarter
Starter itsStarter;

//## classInstance itsWheel
Wheel itsWheel;

#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes* /* aomsAttributes */);

static void RenameGlobalInstances();

IMPLEMENT_META_PACKAGE(Default, Default)
#endif // _OMINSTRUMENT

void Default_initRelations() {
    {
        {
            itsStarter.setShouldDelete(false);
        }
        {
            itsEngine.setShouldDelete(false);
        }
    }
    itsStarter.setItsEngine(&itsEngine);
    itsEngine.setItsCar(&itsCar);
    itsWheel.setItsCar(&itsCar);
    
    #ifdef _OMINSTRUMENT
    RenameGlobalInstances();
    #endif // _OMINSTRUMENT
}

bool Default_startBehavior() {
    bool done = true;
    done &= itsEngine.startBehavior();
    done &= itsStarter.startBehavior();
    return done;
}

#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes* /* aomsAttributes */) {
}

static void RenameGlobalInstances() {
    OM_SET_INSTANCE_NAME(&itsStarter, Starter, "itsStarter", AOMNoMultiplicity);
    OM_SET_INSTANCE_NAME(&itsEngine, Engine, "itsEngine", AOMNoMultiplicity);
    OM_SET_INSTANCE_NAME(&itsCar, Car, "itsCar", AOMNoMultiplicity);
    OM_SET_INSTANCE_NAME(&itsWheel, Wheel, "itsWheel", AOMNoMultiplicity);
}
#endif // _OMINSTRUMENT

//#[ ignore
Default_OMInitializer::Default_OMInitializer() {
    Default_initRelations();
    Default_startBehavior();
}

Default_OMInitializer::~Default_OMInitializer() {
}
//#]

//## event evRun()
evRun::evRun() {
    NOTIFY_EVENT_CONSTRUCTOR(evRun)
    setId(evRun_Default_id);
}

bool evRun::isTypeOf(const short id) const {
    return (evRun_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evRun, Default, Default, evRun())

//## event evIdle()
evIdle::evIdle() {
    NOTIFY_EVENT_CONSTRUCTOR(evIdle)
    setId(evIdle_Default_id);
}

bool evIdle::isTypeOf(const short id) const {
    return (evIdle_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evIdle, Default, Default, evIdle())

//## event evStart()
evStart::evStart() {
    NOTIFY_EVENT_CONSTRUCTOR(evStart)
    setId(evStart_Default_id);
}

bool evStart::isTypeOf(const short id) const {
    return (evStart_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evStart, Default, Default, evStart())

//## event evStop()
evStop::evStop() {
    NOTIFY_EVENT_CONSTRUCTOR(evStop)
    setId(evStop_Default_id);
}

bool evStop::isTypeOf(const short id) const {
    return (evStop_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evStop, Default, Default, evStop())

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Default.cpp
*********************************************************************/
