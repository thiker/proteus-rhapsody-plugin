/*********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Wheel
//!	Generated Date	: Mon, 29, May 2023  
	File Path	: DefaultComponent\DefaultConfig\Wheel.h
*********************************************************************/

#ifndef Wheel_H
#define Wheel_H

//## auto_generated
#include <oxf\oxf.h>
//## auto_generated
#include <aom\aom.h>
//## auto_generated
#include "MQTTClient.h"
//## auto_generated
#include "Default.h"
//## link itsCar
class Car;

//## package Default

//## class Wheel
class Wheel {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedWheel;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    Wheel();
    
    //## auto_generated
    ~Wheel();
    
    ////    Additional operations    ////
    
    //## auto_generated
    Car* getItsCar() const;
    
    //## auto_generated
    void setItsCar(Car* p_Car);

protected :

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
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedWheel : virtual public AOMInstance {
    DECLARE_META(Wheel, OMAnimatedWheel)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Wheel.h
*********************************************************************/
