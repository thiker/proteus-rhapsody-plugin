/********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Wheel
//!	Generated Date	: Sat, 27, May 2023  
	File Path	: DefaultComponent\DefaultConfig\Wheel.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "Wheel.h"
//## link itsCar
#include "Car.h"
//#[ ignore
#define Default_Wheel_Wheel_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class Wheel
Wheel::Wheel() {
    NOTIFY_CONSTRUCTOR(Wheel, Wheel(), 0, Default_Wheel_Wheel_SERIALIZE);
    itsCar = NULL;
}

Wheel::~Wheel() {
    NOTIFY_DESTRUCTOR(~Wheel, true);
    cleanUpRelations();
}

Car* Wheel::getItsCar() const {
    return itsCar;
}

void Wheel::setItsCar(Car* p_Car) {
    if(p_Car != NULL)
        {
            p_Car->_addItsWheel(this);
        }
    _setItsCar(p_Car);
}

void Wheel::cleanUpRelations() {
    if(itsCar != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsCar");
            Car* current = itsCar;
            if(current != NULL)
                {
                    current->_removeItsWheel(this);
                }
            itsCar = NULL;
        }
}

void Wheel::__setItsCar(Car* p_Car) {
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

void Wheel::_setItsCar(Car* p_Car) {
    if(itsCar != NULL)
        {
            itsCar->_removeItsWheel(this);
        }
    __setItsCar(p_Car);
}

void Wheel::_clearItsCar() {
    NOTIFY_RELATION_CLEARED("itsCar");
    itsCar = NULL;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedWheel::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsCar", false, true);
    if(myReal->itsCar)
        {
            aomsRelations->ADD_ITEM(myReal->itsCar);
        }
}
//#]

IMPLEMENT_META_P(Wheel, Default, Default, false, OMAnimatedWheel)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Wheel.cpp
*********************************************************************/
