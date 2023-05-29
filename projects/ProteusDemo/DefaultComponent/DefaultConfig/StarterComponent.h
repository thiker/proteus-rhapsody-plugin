/*********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: StarterComponent
//!	Generated Date	: Mon, 29, May 2023  
	File Path	: DefaultComponent\DefaultConfig\StarterComponent.h
*********************************************************************/

#ifndef StarterComponent_H
#define StarterComponent_H

//## auto_generated
#include <oxf\oxf.h>
//## auto_generated
#include <aom\aom.h>
//## auto_generated
#include "MQTTClient.h"
//## auto_generated
#include "Default.h"
//## link itsStarter
class Starter;

//## package Default

//## class StarterComponent
class StarterComponent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedStarterComponent;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    StarterComponent();
    
    //## auto_generated
    ~StarterComponent();
    
    ////    Additional operations    ////
    
    //## auto_generated
    Starter* getItsStarter() const;
    
    //## auto_generated
    void setItsStarter(Starter* p_Starter);

protected :

    //## auto_generated
    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    Starter* itsStarter;		//## link itsStarter
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsStarter(Starter* p_Starter);
    
    //## auto_generated
    void _setItsStarter(Starter* p_Starter);
    
    //## auto_generated
    void _clearItsStarter();
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedStarterComponent : virtual public AOMInstance {
    DECLARE_META(StarterComponent, OMAnimatedStarterComponent)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\StarterComponent.h
*********************************************************************/
