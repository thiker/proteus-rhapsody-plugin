/********************************************************************
	Rhapsody	: 9.0 
	Login		: thijskoenraadt
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: StarterComponent2
//!	Generated Date	: Tue, 6, Jun 2023  
	File Path	: DefaultComponent\DefaultConfig\StarterComponent2.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "StarterComponent2.h"
//## link itsStarter
#include "Starter.h"
//#[ ignore
#define Default_StarterComponent2_StarterComponent2_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class StarterComponent2
StarterComponent2::StarterComponent2() {
    NOTIFY_CONSTRUCTOR(StarterComponent2, StarterComponent2(), 0, Default_StarterComponent2_StarterComponent2_SERIALIZE);
    itsStarter = NULL;
}

StarterComponent2::~StarterComponent2() {
    NOTIFY_DESTRUCTOR(~StarterComponent2, true);
    cleanUpRelations();
}

Starter* StarterComponent2::getItsStarter() const {
    return itsStarter;
}

void StarterComponent2::setItsStarter(Starter* p_Starter) {
    if(p_Starter != NULL)
        {
            p_Starter->_setItsStarterComponent2(this);
        }
    _setItsStarter(p_Starter);
}

void StarterComponent2::cleanUpRelations() {
    if(itsStarter != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsStarter");
            StarterComponent2* p_StarterComponent2 = itsStarter->getItsStarterComponent2();
            if(p_StarterComponent2 != NULL)
                {
                    itsStarter->__setItsStarterComponent2(NULL);
                }
            itsStarter = NULL;
        }
}

void StarterComponent2::__setItsStarter(Starter* p_Starter) {
    itsStarter = p_Starter;
    if(p_Starter != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsStarter", p_Starter, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsStarter");
        }
}

void StarterComponent2::_setItsStarter(Starter* p_Starter) {
    if(itsStarter != NULL)
        {
            itsStarter->__setItsStarterComponent2(NULL);
        }
    __setItsStarter(p_Starter);
}

void StarterComponent2::_clearItsStarter() {
    NOTIFY_RELATION_CLEARED("itsStarter");
    itsStarter = NULL;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedStarterComponent2::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsStarter", false, true);
    if(myReal->itsStarter)
        {
            aomsRelations->ADD_ITEM(myReal->itsStarter);
        }
}
//#]

IMPLEMENT_META_P(StarterComponent2, Default, Default, false, OMAnimatedStarterComponent2)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\StarterComponent2.cpp
*********************************************************************/
