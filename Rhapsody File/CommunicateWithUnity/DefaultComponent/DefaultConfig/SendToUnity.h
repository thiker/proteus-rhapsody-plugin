/*********************************************************************
	Rhapsody	: 8.2 
	Login		: 20175127
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: SendToUnity
//!	Generated Date	: Tue, 14, May 2019  
	File Path	: DefaultComponent\DefaultConfig\SendToUnity.h
*********************************************************************/

#ifndef SendToUnity_H
#define SendToUnity_H

//## auto_generated
#include <oxf.h>
//## auto_generated
#include "winsock2.h"
//## auto_generated
#include "stdio.h"
//## auto_generated
#include "windows.h"
//## auto_generated
#include "iostream"
//## auto_generated
#include <omreactive.h>
//## auto_generated
#include <state.h>
//## auto_generated
#include <event.h>
//## dependency string
#include <string.h>
//## auto_generated
#include <aom.h>
//## auto_generated
#include "Ws2tcpip.h"
//## auto_generated
#include "Default.h"
//## auto_generated
#include <omthread.h>
//#[ ignore
#define OMAnim_Default_SendToUnity_setHvac_bool_bool_ARGS_DECLARATION bool p_hvac_bool;

#define OMAnim_Default_SendToUnity_setIntensity_float_ARGS_DECLARATION float p_intensity;

#define OMAnim_Default_SendToUnity_setTemperature_float_ARGS_DECLARATION float p_temperature;
//#]

//## package Default

//## class SendToUnity
class SendToUnity : public OMThread, public OMReactive {
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedSendToUnity;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    ////    Operations    ////
    
    ////    Additional operations    ////
    
    ////    Attributes    ////
    
    //## auto_generated
    virtual bool startBehavior(void);

protected :

    //## auto_generated
    void initStatechart(void);

public :

    //## operation callMain()
    virtual int callMain(void);
    
    //## auto_generated
    const OMString getDisplayValue(void) const;
    
    //## auto_generated
    void setDisplayValue(const OMString p_displayValue);
    
    //## auto_generated
    const char getRecvbuf(const Rhp_int32_t iterI1) const;
    
    //## auto_generated
    void setRecvbuf(const Rhp_int32_t iterI1, const char p_recvbuf);
    
    //## auto_generated
    const int getRecvbuflen(void) const;
    
    //## auto_generated
    void setRecvbuflen(const int p_recvbuflen);
    
    //## auto_generated
    const int getSendbuflen(void) const;
    
    //## auto_generated
    void setSendbuflen(const int p_sendbuflen);
    
    //## auto_generated
    const char* getServerName(void) const;
    
    //## auto_generated
    void setServerName(char* const p_serverName);
    
    //## auto_generated
    const char getSndmsgbuf(const Rhp_int32_t iterI1) const;
    
    //## auto_generated
    void setSndmsgbuf(const Rhp_int32_t iterI1, const char p_sndmsgbuf);
    
    //## auto_generated
    const int getSockfd(void) const;
    
    //## auto_generated
    void setSockfd(const int p_sockfd);
    
    //## auto_generated
    const char getTemp(void) const;
    
    //## auto_generated
    void setTemp(const char p_temp);
    
    //## auto_generated
    const WSADATA getWs(void) const;
    
    //## auto_generated
    void setWs(const WSADATA p_ws);
    
    //## auto_generated
    virtual bool cancelTimeout(const IOxfTimeout* arg);

protected :

    //## auto_generated
    void cancelTimeouts(void);

private :

    SOCKET connectSocketForTest1;		//## attribute connectSocketForTest1
    
    OMString displayValue;		//## attribute displayValue
    
    int iResultTest1;		//## attribute iResultTest1
    
    int iSendResultTest1;		//## attribute iSendResultTest1
    
    SOCKET listenSocketForTest1;		//## attribute listenSocketForTest1
    
    int portTest1;		//## attribute portTest1
    
    char recvbuf[DEFAULT_BUFLEN];		//## attribute recvbuf
    
    int recvbuflen;		//## attribute recvbuflen
    
    int sendbuflen;		//## attribute sendbuflen
    
    char* serverName;		//## attribute serverName
    
    char sndmsgbuf[DEFAULT_BUFLEN+3];		//## attribute sndmsgbuf
    
    int sockfd;		//## attribute sockfd
    
    char temp;		//## attribute temp
    
    WSADATA ws;		//## attribute ws

public :

    //## auto_generated
    SendToUnity(void);
    
    //## auto_generated
    virtual ~SendToUnity(void);
    
    //## auto_generated
    const int getInt32(void) const;
    
    //## auto_generated
    void setInt32(const int p_Int32);
    
    //## auto_generated
    const SOCKADDR_IN getAddress_hvac(void) const;
    
    //## auto_generated
    void setAddress_hvac(const SOCKADDR_IN p_address_hvac);
    
    //## auto_generated
    const SOCKADDR_IN getAddress_intensity(void) const;
    
    //## auto_generated
    void setAddress_intensity(const SOCKADDR_IN p_address_intensity);
    
    //## auto_generated
    const SOCKADDR_IN getAddress_temperature(void) const;
    
    //## auto_generated
    void setAddress_temperature(const SOCKADDR_IN p_address_temperature);
    
    //## auto_generated
    const SOCKADDR_IN getAddress_test(void) const;
    
    //## auto_generated
    void setAddress_test(const SOCKADDR_IN p_address_test);
    
    //## auto_generated
    const SOCKADDR_IN getAddress_test1(void) const;
    
    //## auto_generated
    void setAddress_test1(const SOCKADDR_IN p_address_test1);
    
    //## auto_generated
    const SOCKADDR_IN getAddress_test2(void) const;
    
    //## auto_generated
    void setAddress_test2(const SOCKADDR_IN p_address_test2);
    
    //## auto_generated
    const SOCKET getConnectSocketForHVAC(void) const;
    
    //## auto_generated
    void setConnectSocketForHVAC(const SOCKET p_connectSocketForHVAC);
    
    //## auto_generated
    const SOCKET getConnectSocketForIntensity(void) const;
    
    //## auto_generated
    void setConnectSocketForIntensity(const SOCKET p_connectSocketForIntensity);
    
    //## auto_generated
    const SOCKET getConnectSocketForTemperature(void) const;
    
    //## auto_generated
    void setConnectSocketForTemperature(const SOCKET p_connectSocketForTemperature);
    
    //## auto_generated
    const SOCKET getConnectSocketForTest(void) const;
    
    //## auto_generated
    void setConnectSocketForTest(const SOCKET p_connectSocketForTest);
    
    //## auto_generated
    const SOCKET getConnectSocketForTest1(void) const;
    
    //## auto_generated
    void setConnectSocketForTest1(const SOCKET p_connectSocketForTest1);
    
    //## auto_generated
    const SOCKET getConnectSocketForTest2(void) const;
    
    //## auto_generated
    void setConnectSocketForTest2(const SOCKET p_connectSocketForTest2);
    
    //## auto_generated
    const OMString getFilename(void) const;
    
    //## auto_generated
    void setFilename(const OMString p_filename);
    
    //## auto_generated
    const double getFval(void) const;
    
    //## auto_generated
    void setFval(const double p_fval);
    
    //## auto_generated
    const float getHvac(void) const;
    
    //## auto_generated
    void setHvac(const float p_hvac);
    
    //## auto_generated
    const bool getHvac_bool(void) const;
    
    //## auto_generated
    void setHvac_bool(const bool p_hvac_bool);
    
    //## auto_generated
    const OMString getHvac_text(void) const;
    
    //## auto_generated
    void setHvac_text(const OMString p_hvac_text);
    
    //## auto_generated
    const int getIResultHVAC(void) const;
    
    //## auto_generated
    void setIResultHVAC(const int p_iResultHVAC);
    
    //## auto_generated
    const int getIResultIntensity(void) const;
    
    //## auto_generated
    void setIResultIntensity(const int p_iResultIntensity);
    
    //## auto_generated
    const int getIResultTemperature(void) const;
    
    //## auto_generated
    void setIResultTemperature(const int p_iResultTemperature);
    
    //## auto_generated
    const int getIResultTest(void) const;
    
    //## auto_generated
    void setIResultTest(const int p_iResultTest);
    
    //## auto_generated
    const int getIResultTest1(void) const;
    
    //## auto_generated
    void setIResultTest1(const int p_iResultTest1);
    
    //## auto_generated
    const int getIResultTest2(void) const;
    
    //## auto_generated
    void setIResultTest2(const int p_iResultTest2);
    
    //## auto_generated
    const int getISendResultHVAC(void) const;
    
    //## auto_generated
    void setISendResultHVAC(const int p_iSendResultHVAC);
    
    //## auto_generated
    const int getISendResultIntensity(void) const;
    
    //## auto_generated
    void setISendResultIntensity(const int p_iSendResultIntensity);
    
    //## auto_generated
    const int getISendResultTemperature(void) const;
    
    //## auto_generated
    void setISendResultTemperature(const int p_iSendResultTemperature);
    
    //## auto_generated
    const int getISendResultTest(void) const;
    
    //## auto_generated
    void setISendResultTest(const int p_iSendResultTest);
    
    //## auto_generated
    const int getISendResultTest1(void) const;
    
    //## auto_generated
    void setISendResultTest1(const int p_iSendResultTest1);
    
    //## auto_generated
    const int getISendResultTest2(void) const;
    
    //## auto_generated
    void setISendResultTest2(const int p_iSendResultTest2);
    
    //## auto_generated
    const float getIntensity(void) const;
    
    //## auto_generated
    void setIntensity(const float p_intensity);
    
    //## auto_generated
    const SOCKET getListenSocketForHVAC(void) const;
    
    //## auto_generated
    void setListenSocketForHVAC(const SOCKET p_listenSocketForHVAC);
    
    //## auto_generated
    const SOCKET getListenSocketForIntensity(void) const;
    
    //## auto_generated
    void setListenSocketForIntensity(const SOCKET p_listenSocketForIntensity);
    
    //## auto_generated
    const SOCKET getListenSocketForTemperature(void) const;
    
    //## auto_generated
    void setListenSocketForTemperature(const SOCKET p_listenSocketForTemperature);
    
    //## auto_generated
    const SOCKET getListenSocketForTest(void) const;
    
    //## auto_generated
    void setListenSocketForTest(const SOCKET p_listenSocketForTest);
    
    //## auto_generated
    const SOCKET getListenSocketForTest1(void) const;
    
    //## auto_generated
    void setListenSocketForTest1(const SOCKET p_listenSocketForTest1);
    
    //## auto_generated
    const SOCKET getListenSocketForTest2(void) const;
    
    //## auto_generated
    void setListenSocketForTest2(const SOCKET p_listenSocketForTest2);
    
    //## auto_generated
    const int getPortHVAC(void) const;
    
    //## auto_generated
    void setPortHVAC(const int p_portHVAC);
    
    //## auto_generated
    const int getPortIntensity(void) const;
    
    //## auto_generated
    void setPortIntensity(const int p_portIntensity);
    
    //## auto_generated
    const int getPortTemperature(void) const;
    
    //## auto_generated
    void setPortTemperature(const int p_portTemperature);
    
    //## auto_generated
    const int getPortTest(void) const;
    
    //## auto_generated
    void setPortTest(const int p_portTest);
    
    //## auto_generated
    const int getPortTest1(void) const;
    
    //## auto_generated
    void setPortTest1(const int p_portTest1);
    
    //## auto_generated
    const int getPortTest2(void) const;
    
    //## auto_generated
    void setPortTest2(const int p_portTest2);
    
    //## auto_generated
    const float getTemperature(void) const;
    
    //## auto_generated
    void setTemperature(const float p_temperature);
    
    //## auto_generated
    const float getTest(void) const;
    
    //## auto_generated
    void setTest(const float p_test);
    
    //## auto_generated
    const float getTest1(void) const;
    
    //## auto_generated
    void setTest1(const float p_test1);
    
    //## auto_generated
    const float getTest2(void) const;
    
    //## auto_generated
    void setTest2(const float p_test2);
    
    //## auto_generated
    const float getTest2check(void) const;
    
    //## auto_generated
    void setTest2check(const float p_test2check);
    
    //## auto_generated
    const double getUtof(void) const;
    
    //## auto_generated
    void setUtof(const double p_utof);

private :

    int Int32;		//## attribute Int32
    
    SOCKADDR_IN address_hvac;		//## attribute address_hvac
    
    SOCKADDR_IN address_intensity;		//## attribute address_intensity
    
    SOCKADDR_IN address_temperature;		//## attribute address_temperature
    
    SOCKADDR_IN address_test;		//## attribute address_test
    
    SOCKADDR_IN address_test1;		//## attribute address_test1
    
    SOCKADDR_IN address_test2;		//## attribute address_test2
    
    SOCKET connectSocketForHVAC;		//## attribute connectSocketForHVAC
    
    SOCKET connectSocketForIntensity;		//## attribute connectSocketForIntensity
    
    SOCKET connectSocketForTemperature;		//## attribute connectSocketForTemperature
    
    SOCKET connectSocketForTest;		//## attribute connectSocketForTest
    
    SOCKET connectSocketForTest2;		//## attribute connectSocketForTest2
    
    OMString filename;		//## attribute filename
    
    double fval;		//## attribute fval
    
    float hvac;		//## attribute hvac
    
    bool hvac_bool;		//## attribute hvac_bool
    
    OMString hvac_text;		//## attribute hvac_text
    
    int iResultHVAC;		//## attribute iResultHVAC
    
    int iResultIntensity;		//## attribute iResultIntensity
    
    int iResultTemperature;		//## attribute iResultTemperature
    
    int iResultTest;		//## attribute iResultTest
    
    int iResultTest2;		//## attribute iResultTest2
    
    int iSendResultHVAC;		//## attribute iSendResultHVAC
    
    int iSendResultIntensity;		//## attribute iSendResultIntensity
    
    int iSendResultTemperature;		//## attribute iSendResultTemperature
    
    int iSendResultTest;		//## attribute iSendResultTest
    
    int iSendResultTest2;		//## attribute iSendResultTest2
    
    float intensity;		//## attribute intensity
    
    SOCKET listenSocketForHVAC;		//## attribute listenSocketForHVAC
    
    SOCKET listenSocketForIntensity;		//## attribute listenSocketForIntensity
    
    SOCKET listenSocketForTemperature;		//## attribute listenSocketForTemperature
    
    SOCKET listenSocketForTest;		//## attribute listenSocketForTest
    
    SOCKET listenSocketForTest2;		//## attribute listenSocketForTest2
    
    int portHVAC;		//## attribute portHVAC
    
    int portIntensity;		//## attribute portIntensity
    
    int portTemperature;		//## attribute portTemperature
    
    int portTest;		//## attribute portTest
    
    int portTest2;		//## attribute portTest2
    
    float temperature;		//## attribute temperature
    
    float test;		//## attribute test
    
    float test1;		//## attribute test1
    
    float test2;		//## attribute test2
    
    float test2check;		//## attribute test2check
    
    double utof;		//## attribute utof

public :

    // rootState:
    //## statechart_method
    inline RhpBoolean rootState_IN(void) const;
    
    // DispenseFuel:
    //## statechart_method
    inline RhpBoolean DispenseFuel_IN(void) const;
    
    //## statechart_method
    void DispenseFuel_entDef(void);
    
    //## statechart_method
    void DispenseFuel_exit(void);
    
    //## statechart_method
    IOxfReactive::TakeEventStatus DispenseFuel_processEvent(void);
    
    // state_11:
    //## statechart_method
    inline RhpBoolean state_11_IN(void) const;
    
    //## statechart_method
    void state_11_entDef(void);
    
    //## statechart_method
    void state_11_exit(void);
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_11_processEvent(void);
    
    // SendAndRecieve:
    //## statechart_method
    inline RhpBoolean SendAndRecieve_IN(void) const;
    
    // state_10:
    //## statechart_method
    inline RhpBoolean state_10_IN(void) const;
    
    //## statechart_method
    void state_10_entDef(void);
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_10_processEvent(void);
    
    // UpdateVariable:
    //## statechart_method
    inline RhpBoolean UpdateVariable_IN(void) const;
    
    // accepttimeevent_25:
    //## statechart_method
    inline RhpBoolean accepttimeevent_25_IN(void) const;

protected :

    //## statechart_method
    virtual void rootState_entDef(void);
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent(void);
    
//#[ ignore
    enum SendToUnity_Enum {
        OMNonState = 0,
        DispenseFuel = 1,
        state_11 = 2,
        SendAndRecieve = 3,
        state_10 = 4,
        UpdateVariable = 5,
        accepttimeevent_25 = 6
    };
//#]

private :

//#[ ignore
    SendToUnity_Enum rootState_subState;
    
    SendToUnity_Enum rootState_active;
    
    SendToUnity_Enum state_11_subState;
    
    SendToUnity_Enum state_11_active;
    
    IOxfTimeout* state_11_timeout;
    
    SendToUnity_Enum state_10_subState;
    
    SendToUnity_Enum state_10_active;
    
    IOxfTimeout* state_10_timeout;
//#]
};

#ifdef _OMINSTRUMENT
DECLARE_OPERATION_CLASS(Default_SendToUnity_setHvac_bool_bool)

DECLARE_OPERATION_CLASS(Default_SendToUnity_setIntensity_float)

DECLARE_OPERATION_CLASS(Default_SendToUnity_setTemperature_float)

//#[ ignore
class OMAnimatedSendToUnity : virtual public AOMInstance {
    DECLARE_REACTIVE_META(SendToUnity, OMAnimatedSendToUnity)
    
    DECLARE_META_OP(Default_SendToUnity_setHvac_bool_bool)
    
    DECLARE_META_OP(Default_SendToUnity_setIntensity_float)
    
    DECLARE_META_OP(Default_SendToUnity_setTemperature_float)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeAttributes(AOMSAttributes* aomsAttributes) const;
    
    //## statechart_method
    void rootState_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void DispenseFuel_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_11_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void SendAndRecieve_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_10_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void UpdateVariable_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void accepttimeevent_25_serializeStates(AOMSState* aomsState) const;
};
//#]
#endif // _OMINSTRUMENT

inline RhpBoolean SendToUnity::rootState_IN(void) const {
    return true;
}

inline RhpBoolean SendToUnity::DispenseFuel_IN(void) const {
    return rootState_subState == DispenseFuel;
}

inline RhpBoolean SendToUnity::state_11_IN(void) const {
    return DispenseFuel_IN();
}

inline RhpBoolean SendToUnity::SendAndRecieve_IN(void) const {
    return state_11_subState == SendAndRecieve;
}

inline RhpBoolean SendToUnity::state_10_IN(void) const {
    return DispenseFuel_IN();
}

inline RhpBoolean SendToUnity::UpdateVariable_IN(void) const {
    return state_10_subState == UpdateVariable;
}

inline RhpBoolean SendToUnity::accepttimeevent_25_IN(void) const {
    return state_10_subState == accepttimeevent_25;
}

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\SendToUnity.h
*********************************************************************/
