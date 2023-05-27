/*********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Default
//!	Generated Date	: Sat, 27, May 2023  
	File Path	: DefaultComponent\DefaultConfig\Default.h
*********************************************************************/

#ifndef Default_H
#define Default_H

//## auto_generated
#include <oxf\oxf.h>
//## auto_generated
#include <aom\aom.h>
//## auto_generated
#include <oxf\event.h>
//## classInstance itsCar
class Car;

//## classInstance itsEngine
class Engine;

//## classInstance itsStarter
class Starter;

//## classInstance itsWheel
class Wheel;

//#[ ignore
#define evRun_Default_id 18601

#define evIdle_Default_id 18602

#define evStart_Default_id 18603

#define evStop_Default_id 18604
//#]

//## package Default


//## classInstance itsCar
extern Car itsCar;

//## classInstance itsEngine
extern Engine itsEngine;

//## classInstance itsStarter
extern Starter itsStarter;

//## classInstance itsWheel
extern Wheel itsWheel;

//## auto_generated
void Default_initRelations();

//## auto_generated
bool Default_startBehavior();

//#[ ignore
class Default_OMInitializer {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    Default_OMInitializer();
    
    //## auto_generated
    ~Default_OMInitializer();
};
//#]

//## event evRun()
class evRun : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevRun;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evRun();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevRun : virtual public AOMEvent {
    DECLARE_META_EVENT(evRun)
};
//#]
#endif // _OMINSTRUMENT

//## event evIdle()
class evIdle : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevIdle;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evIdle();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevIdle : virtual public AOMEvent {
    DECLARE_META_EVENT(evIdle)
};
//#]
#endif // _OMINSTRUMENT

//## event evStart()
class evStart : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevStart;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evStart();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevStart : virtual public AOMEvent {
    DECLARE_META_EVENT(evStart)
};
//#]
#endif // _OMINSTRUMENT

//## event evStop()
class evStop : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevStop;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evStop();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevStop : virtual public AOMEvent {
    DECLARE_META_EVENT(evStop)
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Default.h
*********************************************************************/
