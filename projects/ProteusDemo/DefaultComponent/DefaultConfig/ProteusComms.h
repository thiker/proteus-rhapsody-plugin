/*********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ProteusComms
//!	Generated Date	: Mon, 29, May 2023  
	File Path	: DefaultComponent\DefaultConfig\ProteusComms.h
*********************************************************************/

#ifndef ProteusComms_H
#define ProteusComms_H

//## auto_generated
#include <oxf\oxf.h>
//## auto_generated
#include <aom\aom.h>
//## auto_generated
#include "MQTTClient.h"
//## auto_generated
#include "Proteus.h"
//## class ProteusComms
#include "IProteusComms.h"
//## package Proteus

//## class ProteusComms
class ProteusComms : public IProteusComms {
public :

//#[ ignore
    //## package Proteus
    class pComms_C : public IProteusComms {
        ////    Constructors and destructors    ////
        
    public :
    
        //## auto_generated
        pComms_C();
        
        //## auto_generated
        virtual ~pComms_C();
        
        ////    Operations    ////
        
        //## auto_generated
        virtual void SetCurrentState(OMString stateObjectId, const OMString& state);
        
        //## auto_generated
        virtual void SetStateData(const OMString& stateObjectId, const OMString& key, int data);
        
        //## auto_generated
        virtual void SetStateData(const OMString& stateObjectId, const OMString& key, const OMString& data, bool useDataRaw = false);
        
        //## auto_generated
        virtual void SetStateData(const OMString& stateObjectId, const OMString& key, float data);
        
        //## auto_generated
        virtual void SetStateData(const OMString& stateObjectId, const OMString& key, bool data);
        
        //## auto_generated
        void connectProteusComms(ProteusComms* part);
        
        //## auto_generated
        IProteusComms* getItsIProteusComms();
        
        ////    Additional operations    ////
        
        //## auto_generated
        void setItsIProteusComms(IProteusComms* p_IProteusComms);
    
    protected :
    
        //## auto_generated
        void cleanUpRelations();
        
        ////    Attributes    ////
        
        int _p_;		//## attribute _p_
        
        ////    Relations and components    ////
        
        IProteusComms* itsIProteusComms;		//## link itsIProteusComms
    };
//#]

    ////    Friends    ////
    
#ifdef _OMINSTRUMENT
    friend class OMAnimatedProteusComms;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    ProteusComms();
    
    //## auto_generated
    virtual ~ProteusComms();
    
    ////    Operations    ////
    
    //## operation DestroyClient()
    void DestroyClient();
    
    //## operation Init()
    void Init();
    
    //## operation SendMqttMessage(OMString,OMString)
    void SendMqttMessage(const OMString& topic, const OMString& payload);
    
    //## operation SetStateData(OMString,OMString,int)
    virtual void SetStateData(const OMString& stateObjectId, const OMString& key, int data);
    
    //## operation SetStateData(OMString,OMString,float)
    virtual void SetStateData(const OMString& stateObjectId, const OMString& key, float data);
    
    //## operation SetStateData(OMString,OMString,OMString,bool)
    virtual void SetStateData(const OMString& stateObjectId, const OMString& key, const OMString& data, bool useDataRaw = false);
    
    //## operation SetStateData(OMString,OMString,bool)
    virtual void SetStateData(const OMString& stateObjectId, const OMString& key, bool data);
    
    ////    Additional operations    ////
    
    //## auto_generated
    pComms_C* getPComms() const;
    
    //## auto_generated
    pComms_C* get_pComms() const;
    
    //## auto_generated
    static char* getADDRESS();
    
    //## auto_generated
    static char* getCLIENTID();
    
    //## auto_generated
    static const int getQOS();
    
    //## auto_generated
    static const OMString getSTART_PAYLOAD();
    
    //## auto_generated
    const OMString getSTATE_UPDATE_TOPIC_PREFIX() const;
    
    //## auto_generated
    static MQTTClient getClient();
    
    //## auto_generated
    static void setClient(MQTTClient p_client);
    
    //## auto_generated
    bool getIsConnected() const;
    
    //## auto_generated
    void setIsConnected(bool p_isConnected);
    
    //## auto_generated
    OMString getPtResultEngineState() const;
    
    //## auto_generated
    void setPtResultEngineState(OMString p_ptResultEngineState);
    
    //## auto_generated
    OMString getPtResultStarterState() const;
    
    //## auto_generated
    void setPtResultStarterState(OMString p_ptResultStarterState);

protected :

    //## auto_generated
    void initRelations();
    
    ////    Attributes    ////
    
    static char* ADDRESS;		//## attribute ADDRESS
    
    static char* CLIENTID;		//## attribute CLIENTID
    
    static const int QOS;		//## attribute QOS
    
    static const OMString START_PAYLOAD;		//## attribute START_PAYLOAD
    
    const OMString STATE_UPDATE_TOPIC_PREFIX;		//## attribute STATE_UPDATE_TOPIC_PREFIX
    
    static MQTTClient client;		//## attribute client
    
    bool isConnected;		//## attribute isConnected
    
    OMString ptResultEngineState;		//## attribute ptResultEngineState
    
    OMString ptResultStarterState;		//## attribute ptResultStarterState
    
    ////    Relations and components    ////

public :

    //## operation SetCurrentState(OMString,OMString)
    virtual void SetCurrentState(OMString stateObjectId, const OMString& state);
    
    //## auto_generated
    static void setADDRESS(char* p_ADDRESS);
    
    //## auto_generated
    static void setCLIENTID(char* p_CLIENTID);

protected :

//#[ ignore
    pComms_C pComms;
//#]
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedProteusComms : public OMAnimatedIProteusComms {
    DECLARE_META(ProteusComms, OMAnimatedProteusComms)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeAttributes(AOMSAttributes* aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\ProteusComms.h
*********************************************************************/
