/********************************************************************
	Rhapsody	: 9.0 
	Login		: thijskoenraadt
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Car
//!	Generated Date	: Tue, 6, Jun 2023  
	File Path	: DefaultComponent\DefaultConfig\Car.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "Car.h"
//## link itsEngine
#include "Engine.h"
//## link itsWheel
#include "Wheel.h"
//#[ ignore
#define Default_Car_Car_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class Car
Car::Car() {
    NOTIFY_CONSTRUCTOR(Car, Car(), 0, Default_Car_Car_SERIALIZE);
    itsEngine = NULL;
}

Car::~Car() {
    NOTIFY_DESTRUCTOR(~Car, true);
    cleanUpRelations();
}

Engine* Car::getItsEngine() const {
    return itsEngine;
}

void Car::setItsEngine(Engine* p_Engine) {
    if(p_Engine != NULL)
        {
            p_Engine->_setItsCar(this);
        }
    _setItsEngine(p_Engine);
}

OMIterator<Wheel*> Car::getItsWheel() const {
    OMIterator<Wheel*> iter(itsWheel);
    return iter;
}

void Car::addItsWheel(Wheel* p_Wheel) {
    if(p_Wheel != NULL)
        {
            p_Wheel->_setItsCar(this);
        }
    _addItsWheel(p_Wheel);
}

void Car::removeItsWheel(Wheel* p_Wheel) {
    if(p_Wheel != NULL)
        {
            p_Wheel->__setItsCar(NULL);
        }
    _removeItsWheel(p_Wheel);
}

void Car::clearItsWheel() {
    OMIterator<Wheel*> iter(itsWheel);
    while (*iter){
        (*iter)->_clearItsCar();
        iter++;
    }
    _clearItsWheel();
}

void Car::cleanUpRelations() {
    if(itsEngine != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsEngine");
            Car* p_Car = itsEngine->getItsCar();
            if(p_Car != NULL)
                {
                    itsEngine->__setItsCar(NULL);
                }
            itsEngine = NULL;
        }
    {
        OMIterator<Wheel*> iter(itsWheel);
        while (*iter){
            Car* p_Car = (*iter)->getItsCar();
            if(p_Car != NULL)
                {
                    (*iter)->__setItsCar(NULL);
                }
            iter++;
        }
        itsWheel.removeAll();
    }
}

void Car::__setItsEngine(Engine* p_Engine) {
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

void Car::_setItsEngine(Engine* p_Engine) {
    if(itsEngine != NULL)
        {
            itsEngine->__setItsCar(NULL);
        }
    __setItsEngine(p_Engine);
}

void Car::_clearItsEngine() {
    NOTIFY_RELATION_CLEARED("itsEngine");
    itsEngine = NULL;
}

void Car::_addItsWheel(Wheel* p_Wheel) {
    if(p_Wheel != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsWheel", p_Wheel, false, false);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsWheel");
        }
    itsWheel.add(p_Wheel);
}

void Car::_removeItsWheel(Wheel* p_Wheel) {
    NOTIFY_RELATION_ITEM_REMOVED("itsWheel", p_Wheel);
    itsWheel.remove(p_Wheel);
}

void Car::_clearItsWheel() {
    NOTIFY_RELATION_CLEARED("itsWheel");
    itsWheel.removeAll();
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedCar::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsWheel", false, false);
    {
        OMIterator<Wheel*> iter(myReal->itsWheel);
        while (*iter){
            aomsRelations->ADD_ITEM(*iter);
            iter++;
        }
    }
    aomsRelations->addRelation("itsEngine", false, true);
    if(myReal->itsEngine)
        {
            aomsRelations->ADD_ITEM(myReal->itsEngine);
        }
}
//#]

IMPLEMENT_META_P(Car, Default, Default, false, OMAnimatedCar)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Car.cpp
*********************************************************************/
