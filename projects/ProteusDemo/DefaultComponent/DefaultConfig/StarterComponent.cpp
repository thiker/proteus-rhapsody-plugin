/********************************************************************
	Rhapsody	: 9.0 
	Login		: thijskoenraadt
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: StarterComponent
//!	Generated Date	: Tue, 6, Jun 2023  
	File Path	: DefaultComponent\DefaultConfig\StarterComponent.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "StarterComponent.h"
//## link itsStarter
#include "Starter.h"
//#[ ignore
#define Default_StarterComponent_StarterComponent_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class StarterComponent
StarterComponent::StarterComponent() {
    NOTIFY_CONSTRUCTOR(StarterComponent, StarterComponent(), 0, Default_StarterComponent_StarterComponent_SERIALIZE);
    itsStarter = NULL;
}

StarterComponent::~StarterComponent() {
    NOTIFY_DESTRUCTOR(~StarterComponent, true);
    cleanUpRelations();
}

Starter* StarterComponent::getItsStarter() const {
    return itsStarter;
}

void StarterComponent::setItsStarter(Starter* p_Starter) {
    if(p_Starter != NULL)
        {
            p_Starter->_setItsStarterComponent(this);
        }
    _setItsStarter(p_Starter);
}

void StarterComponent::cleanUpRelations() {
    if(itsStarter != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsStarter");
            StarterComponent* p_StarterComponent = itsStarter->getItsStarterComponent();
            if(p_StarterComponent != NULL)
                {
                    itsStarter->__setItsStarterComponent(NULL);
                }
            itsStarter = NULL;
        }
}

void StarterComponent::__setItsStarter(Starter* p_Starter) {
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

void StarterComponent::_setItsStarter(Starter* p_Starter) {
    if(itsStarter != NULL)
        {
            itsStarter->__setItsStarterComponent(NULL);
        }
    __setItsStarter(p_Starter);
}

void StarterComponent::_clearItsStarter() {
    NOTIFY_RELATION_CLEARED("itsStarter");
    itsStarter = NULL;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedStarterComponent::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsStarter", false, true);
    if(myReal->itsStarter)
        {
            aomsRelations->ADD_ITEM(myReal->itsStarter);
        }
}
//#]

IMPLEMENT_META_P(StarterComponent, Default, Default, false, OMAnimatedStarterComponent)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\StarterComponent.cpp
*********************************************************************/
