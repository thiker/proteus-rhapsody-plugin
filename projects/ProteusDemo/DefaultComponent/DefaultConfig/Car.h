/*********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Car
//!	Generated Date	: Sat, 27, May 2023  
	File Path	: DefaultComponent\DefaultConfig\Car.h
*********************************************************************/

#ifndef Car_H
#define Car_H

//## auto_generated
#include <oxf\oxf.h>
//## auto_generated
#include <aom\aom.h>
//## auto_generated
#include "Default.h"
//## auto_generated
#include <oxf\omcollec.h>
//## link itsEngine
class Engine;

//## link itsWheel
class Wheel;

//## package Default

//## class Car
class Car {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedCar;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    Car();
    
    //## auto_generated
    ~Car();
    
    ////    Additional operations    ////
    
    //## auto_generated
    Engine* getItsEngine() const;
    
    //## auto_generated
    void setItsEngine(Engine* p_Engine);
    
    //## auto_generated
    OMIterator<Wheel*> getItsWheel() const;
    
    //## auto_generated
    void addItsWheel(Wheel* p_Wheel);
    
    //## auto_generated
    void removeItsWheel(Wheel* p_Wheel);
    
    //## auto_generated
    void clearItsWheel();

protected :

    //## auto_generated
    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    Engine* itsEngine;		//## link itsEngine
    
    OMCollection<Wheel*> itsWheel;		//## link itsWheel
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsEngine(Engine* p_Engine);
    
    //## auto_generated
    void _setItsEngine(Engine* p_Engine);
    
    //## auto_generated
    void _clearItsEngine();
    
    //## auto_generated
    void _addItsWheel(Wheel* p_Wheel);
    
    //## auto_generated
    void _removeItsWheel(Wheel* p_Wheel);
    
    //## auto_generated
    void _clearItsWheel();
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedCar : virtual public AOMInstance {
    DECLARE_META(Car, OMAnimatedCar)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Car.h
*********************************************************************/
