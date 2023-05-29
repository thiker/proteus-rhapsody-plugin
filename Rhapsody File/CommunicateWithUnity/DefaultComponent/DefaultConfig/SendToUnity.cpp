/********************************************************************
	Rhapsody	: 8.2 
	Login		: 20175127
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: SendToUnity
//!	Generated Date	: Tue, 14, May 2019  
	File Path	: DefaultComponent\DefaultConfig\SendToUnity.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "SendToUnity.h"
//#[ ignore
#define Default_SendToUnity_SendToUnity_SERIALIZE OM_NO_OP

#define Default_SendToUnity_callMain_SERIALIZE OM_NO_OP

#define OMAnim_Default_SendToUnity_setHvac_bool_bool_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_hvac_bool)

#define OMAnim_Default_SendToUnity_setHvac_bool_bool_SERIALIZE_RET_VAL

#define OMAnim_Default_SendToUnity_setIntensity_float_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_intensity)

#define OMAnim_Default_SendToUnity_setIntensity_float_SERIALIZE_RET_VAL

#define OMAnim_Default_SendToUnity_setTemperature_float_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_temperature)

#define OMAnim_Default_SendToUnity_setTemperature_float_SERIALIZE_RET_VAL
//#]

//## package Default

//## class SendToUnity
bool SendToUnity::startBehavior(void) {
    bool done = false;
    done = OMReactive::startBehavior();
    if(done)
        {
            startDispatching();
        }
    return done;
}

void SendToUnity::initStatechart(void) {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    state_11_subState = OMNonState;
    state_11_active = OMNonState;
    state_11_timeout = NULL;
    state_10_subState = OMNonState;
    state_10_active = OMNonState;
    state_10_timeout = NULL;
}

int SendToUnity::callMain(void) {
    NOTIFY_OPERATION(callMain, callMain(), 0, Default_SendToUnity_callMain_SERIALIZE);
    //#[ operation callMain()
    #ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN 
    #define _WINSOCK_DEPRECATED_NO_WARNINGS
    #endif      
    
    #include <stdlib.h> 
    
    WSAStartup(0x0101,&ws);
    
    char out_string_for_test [1024];
    char out_string_for_test1 [1024];
    char out_string_for_test2 [1024];
    char out_string_for_intensity [1024];
    char out_string_for_temperature [1024];
    char out_string_for_hvac [1024];
    
    //TEST
    ZeroMemory(&address_test, sizeof(address_test));
    address_test.sin_family = AF_INET;
    address_test.sin_port = htons(portTest);
    address_test.sin_addr.s_addr=inet_addr(serverName);             
    
    //TEST1
    ZeroMemory(&address_test1, sizeof(address_test1));
    address_test1.sin_family = AF_INET;
    address_test1.sin_port = htons(portTest1);
    address_test1.sin_addr.s_addr=inet_addr(serverName);      
    
    //TEST2
    ZeroMemory(&address_test2, sizeof(address_test2));
    address_test2.sin_family = AF_INET;
    address_test2.sin_port = htons(portTest2);
    address_test2.sin_addr.s_addr=inet_addr(serverName);
    
    //LIGHT INTENSITY
    ZeroMemory(&address_intensity, sizeof(address_intensity));
    address_intensity.sin_family = AF_INET;
    address_intensity.sin_port = htons(portIntensity);
    address_intensity.sin_addr.s_addr=inet_addr(serverName);
    
    //TEMPERATURE
    ZeroMemory(&address_temperature, sizeof(address_temperature));
    address_temperature.sin_family = AF_INET;
    address_temperature.sin_port = htons(portTemperature);
    address_temperature.sin_addr.s_addr=inet_addr(serverName);
    
    //HVAC
    ZeroMemory(&address_hvac, sizeof(address_hvac));
    address_hvac.sin_family = AF_INET;
    address_hvac.sin_port = htons(portHVAC);
    address_hvac.sin_addr.s_addr=inet_addr(serverName);
                                      
    //INITIALIZE ALL SOCKETS
    listenSocketForTest = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    listenSocketForTest1 = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    listenSocketForTest2 = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    listenSocketForIntensity = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    listenSocketForTemperature = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    listenSocketForHVAC = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    
    //CONNECT ALL THE SOCKETS
    iResultTest = connect(listenSocketForTest,(SOCKADDR*)&address_test, sizeof(address_test));    
    iResultTest1 = connect(listenSocketForTest1,(SOCKADDR*)&address_test1, sizeof(address_test1));
    iResultTest2 = connect(listenSocketForTest2,(SOCKADDR*)&address_test2, sizeof(address_test2));
    iResultIntensity = connect(listenSocketForIntensity,(SOCKADDR*)&address_intensity, sizeof(address_intensity));
    iResultTemperature = connect(listenSocketForTemperature,(SOCKADDR*)&address_temperature, sizeof(address_temperature));
    iResultHVAC = connect(listenSocketForHVAC,(SOCKADDR*)&address_hvac, sizeof(address_hvac));
    
    //ASSIGN VALUES TO SEND 
    sprintf(out_string_for_test, "%f", test);
    sprintf(out_string_for_test1, "%f", test1);
    sprintf(out_string_for_test2, "%f", test2);
    sprintf(out_string_for_intensity, "%f", intensity);
    sprintf(out_string_for_temperature, "%f", temperature);  
    if(hvac_bool==true){
    	hvac = 1;
    }
    else{
    	hvac = 0;
    }
    sprintf(out_string_for_hvac, "%f", hvac);
    
    //SEND VALUE
    iSendResultTest = sendto(listenSocketForTest, (char *)&out_string_for_test ,sizeof(uint32_t), 0 ,(SOCKADDR *) & address_test, sizeof (address_test) );               
    iSendResultTest1 = sendto(listenSocketForTest1, (char *)&out_string_for_test1 ,sizeof(uint32_t), 0 ,(SOCKADDR *) & address_test1, sizeof (address_test1) );               
    iSendResultTest2 = sendto(listenSocketForTest2, (char *)&out_string_for_test2 ,sizeof(uint32_t), 0 ,(SOCKADDR *) & address_test2, sizeof (address_test2) );               
    iSendResultIntensity = sendto(listenSocketForIntensity, (char *)&out_string_for_intensity ,sizeof(uint32_t), 0 ,(SOCKADDR *) & address_intensity, sizeof (address_intensity) );               
    iSendResultTemperature = sendto(listenSocketForTemperature, (char *)&out_string_for_temperature ,sizeof(uint32_t), 0 ,(SOCKADDR *) & address_temperature, sizeof (address_temperature) );               
    iSendResultHVAC = sendto(listenSocketForHVAC, (char *)&out_string_for_hvac ,sizeof(uint32_t), 0 ,(SOCKADDR *) & address_hvac, sizeof (address_hvac) );               
    
    //SHOW SENT VALUES IN CONSOLE
    printf("Test value sent: %s \n",out_string_for_test);
    printf("Test1 value sent: %s \n",out_string_for_test1);
    printf("Test2 value sent: %s \n",out_string_for_test2);
    printf("Intensity value sent: %s \n",out_string_for_intensity);
    printf("Temperature value sent: %s \n",out_string_for_temperature);
    printf("HVAC Status value sent: %s \n",out_string_for_hvac);
    
    //RECIEVED VALUE OF TEST
    iResultTest = recv(listenSocketForTest, recvbuf, recvbuflen, 0);   
    printf("Test value recieved: %f\n",atof(recvbuf)); 
    //RECIEVED VALUE OF TEST1
    iResultTest1 = recv(listenSocketForTest1, recvbuf, recvbuflen, 0);   
    printf("Test1 value recieved: %f\n",atof(recvbuf)); 
    //RECIEVED VALUE OF TEST2
    iResultTest2 = recv(listenSocketForTest2, recvbuf, recvbuflen, 0);   
    test2check = atof(recvbuf);
    printf("Test2 value recieved: %f\n",test2check); 
    //RECIEVED VALUE OF INTENSITY
    iResultIntensity = recv(listenSocketForIntensity, recvbuf, recvbuflen, 0);   
    printf("Intensity value recieved: %f\n",atof(recvbuf)); 
    //RECIEVED VALUE OF TEMPERATURE
    iResultTemperature = recv(listenSocketForTemperature, recvbuf, recvbuflen, 0);   
    printf("Intensity value recieved: %f\n",atof(recvbuf)); 
    //RECIEVED VALUE OF HVAC
    iResultHVAC = recv(listenSocketForHVAC, recvbuf, recvbuflen, 0);   
    printf("Intensity value recieved: %f\n",atof(recvbuf)); 
    int hvactocheck = atof(recvbuf);
    if(hvactocheck==1){
    	hvac_text = "HVAC is ON";
    }
    else{
    	hvac_text = "HVAC is OFF";
    }
    //CLOSE ALL THE SOCKETS
    closesocket(listenSocketForTest);
    closesocket(listenSocketForTest1);
    closesocket(listenSocketForTest2);
    closesocket(listenSocketForIntensity);
    closesocket(listenSocketForTemperature);
    closesocket(listenSocketForHVAC);
    
    return 0;
    //#]
}

const OMString SendToUnity::getDisplayValue(void) const {
    return displayValue;
}

void SendToUnity::setDisplayValue(const OMString p_displayValue) {
    displayValue = p_displayValue;
}

const char SendToUnity::getRecvbuf(const Rhp_int32_t iterI1) const {
    return recvbuf[iterI1];
}

void SendToUnity::setRecvbuf(const Rhp_int32_t iterI1, const char p_recvbuf) {
    recvbuf[iterI1] = p_recvbuf;
}

const int SendToUnity::getRecvbuflen(void) const {
    return recvbuflen;
}

void SendToUnity::setRecvbuflen(const int p_recvbuflen) {
    recvbuflen = p_recvbuflen;
}

const int SendToUnity::getSendbuflen(void) const {
    return sendbuflen;
}

void SendToUnity::setSendbuflen(const int p_sendbuflen) {
    sendbuflen = p_sendbuflen;
}

const char* SendToUnity::getServerName(void) const {
    return serverName;
}

void SendToUnity::setServerName(char* const p_serverName) {
    serverName = p_serverName;
}

const char SendToUnity::getSndmsgbuf(const Rhp_int32_t iterI1) const {
    return sndmsgbuf[iterI1];
}

void SendToUnity::setSndmsgbuf(const Rhp_int32_t iterI1, const char p_sndmsgbuf) {
    sndmsgbuf[iterI1] = p_sndmsgbuf;
}

const int SendToUnity::getSockfd(void) const {
    return sockfd;
}

void SendToUnity::setSockfd(const int p_sockfd) {
    sockfd = p_sockfd;
}

const char SendToUnity::getTemp(void) const {
    return temp;
}

void SendToUnity::setTemp(const char p_temp) {
    temp = p_temp;
}

const WSADATA SendToUnity::getWs(void) const {
    return ws;
}

void SendToUnity::setWs(const WSADATA p_ws) {
    ws = p_ws;
}

bool SendToUnity::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
    if(state_11_timeout == arg)
        {
            state_11_timeout = NULL;
            res = true;
        }
    if(state_10_timeout == arg)
        {
            state_10_timeout = NULL;
            res = true;
        }
    return res;
}

void SendToUnity::cancelTimeouts(void) {
    cancel(state_11_timeout);
    cancel(state_10_timeout);
}

SendToUnity::SendToUnity(void) : OMThread(), OMReactive(), connectSocketForTest1(INVALID_SOCKET), displayValue(""), listenSocketForTest1(INVALID_SOCKET), portTest1(52052), recvbuflen(DEFAULT_BUFLEN), sendbuflen(DEFAULT_BUFLEN), serverName("127.0.0.1"), temp('c'), Int32(0), connectSocketForHVAC(INVALID_SOCKET), connectSocketForIntensity(INVALID_SOCKET), connectSocketForTemperature(INVALID_SOCKET), connectSocketForTest(INVALID_SOCKET), connectSocketForTest2(INVALID_SOCKET), filename(""), hvac(0), hvac_bool(0), hvac_text(""), intensity(0), listenSocketForHVAC(INVALID_SOCKET), listenSocketForIntensity(INVALID_SOCKET), listenSocketForTemperature(INVALID_SOCKET), listenSocketForTest(INVALID_SOCKET), listenSocketForTest2(INVALID_SOCKET), portHVAC(52057), portIntensity(52055), portTemperature(52056), portTest(52051), portTest2(52053), temperature(0), test(0), test1(10), test2(0) {
    NOTIFY_ACTIVE_CONSTRUCTOR(SendToUnity, SendToUnity(), 0, Default_SendToUnity_SendToUnity_SERIALIZE);
    setActiveContext(this, true);
    initStatechart();
}

SendToUnity::~SendToUnity(void) {
    NOTIFY_DESTRUCTOR(~SendToUnity, true);
    cancelTimeouts();
}

const int SendToUnity::getInt32(void) const {
    return Int32;
}

void SendToUnity::setInt32(const int p_Int32) {
    Int32 = p_Int32;
}

const SOCKADDR_IN SendToUnity::getAddress_hvac(void) const {
    return address_hvac;
}

void SendToUnity::setAddress_hvac(const SOCKADDR_IN p_address_hvac) {
    address_hvac = p_address_hvac;
}

const SOCKADDR_IN SendToUnity::getAddress_intensity(void) const {
    return address_intensity;
}

void SendToUnity::setAddress_intensity(const SOCKADDR_IN p_address_intensity) {
    address_intensity = p_address_intensity;
}

const SOCKADDR_IN SendToUnity::getAddress_temperature(void) const {
    return address_temperature;
}

void SendToUnity::setAddress_temperature(const SOCKADDR_IN p_address_temperature) {
    address_temperature = p_address_temperature;
}

const SOCKADDR_IN SendToUnity::getAddress_test(void) const {
    return address_test;
}

void SendToUnity::setAddress_test(const SOCKADDR_IN p_address_test) {
    address_test = p_address_test;
}

const SOCKADDR_IN SendToUnity::getAddress_test1(void) const {
    return address_test1;
}

void SendToUnity::setAddress_test1(const SOCKADDR_IN p_address_test1) {
    address_test1 = p_address_test1;
}

const SOCKADDR_IN SendToUnity::getAddress_test2(void) const {
    return address_test2;
}

void SendToUnity::setAddress_test2(const SOCKADDR_IN p_address_test2) {
    address_test2 = p_address_test2;
}

const SOCKET SendToUnity::getConnectSocketForHVAC(void) const {
    return connectSocketForHVAC;
}

void SendToUnity::setConnectSocketForHVAC(const SOCKET p_connectSocketForHVAC) {
    connectSocketForHVAC = p_connectSocketForHVAC;
}

const SOCKET SendToUnity::getConnectSocketForIntensity(void) const {
    return connectSocketForIntensity;
}

void SendToUnity::setConnectSocketForIntensity(const SOCKET p_connectSocketForIntensity) {
    connectSocketForIntensity = p_connectSocketForIntensity;
}

const SOCKET SendToUnity::getConnectSocketForTemperature(void) const {
    return connectSocketForTemperature;
}

void SendToUnity::setConnectSocketForTemperature(const SOCKET p_connectSocketForTemperature) {
    connectSocketForTemperature = p_connectSocketForTemperature;
}

const SOCKET SendToUnity::getConnectSocketForTest(void) const {
    return connectSocketForTest;
}

void SendToUnity::setConnectSocketForTest(const SOCKET p_connectSocketForTest) {
    connectSocketForTest = p_connectSocketForTest;
}

const SOCKET SendToUnity::getConnectSocketForTest1(void) const {
    return connectSocketForTest1;
}

void SendToUnity::setConnectSocketForTest1(const SOCKET p_connectSocketForTest1) {
    connectSocketForTest1 = p_connectSocketForTest1;
}

const SOCKET SendToUnity::getConnectSocketForTest2(void) const {
    return connectSocketForTest2;
}

void SendToUnity::setConnectSocketForTest2(const SOCKET p_connectSocketForTest2) {
    connectSocketForTest2 = p_connectSocketForTest2;
}

const OMString SendToUnity::getFilename(void) const {
    return filename;
}

void SendToUnity::setFilename(const OMString p_filename) {
    filename = p_filename;
}

const double SendToUnity::getFval(void) const {
    return fval;
}

void SendToUnity::setFval(const double p_fval) {
    fval = p_fval;
}

const float SendToUnity::getHvac(void) const {
    return hvac;
}

void SendToUnity::setHvac(const float p_hvac) {
    hvac = p_hvac;
}

const bool SendToUnity::getHvac_bool(void) const {
    return hvac_bool;
}

void SendToUnity::setHvac_bool(const bool p_hvac_bool) {
    hvac_bool = p_hvac_bool;
    NOTIFY_SET_OPERATION;
}

const OMString SendToUnity::getHvac_text(void) const {
    return hvac_text;
}

void SendToUnity::setHvac_text(const OMString p_hvac_text) {
    hvac_text = p_hvac_text;
    NOTIFY_SET_OPERATION;
}

const int SendToUnity::getIResultHVAC(void) const {
    return iResultHVAC;
}

void SendToUnity::setIResultHVAC(const int p_iResultHVAC) {
    iResultHVAC = p_iResultHVAC;
}

const int SendToUnity::getIResultIntensity(void) const {
    return iResultIntensity;
}

void SendToUnity::setIResultIntensity(const int p_iResultIntensity) {
    iResultIntensity = p_iResultIntensity;
}

const int SendToUnity::getIResultTemperature(void) const {
    return iResultTemperature;
}

void SendToUnity::setIResultTemperature(const int p_iResultTemperature) {
    iResultTemperature = p_iResultTemperature;
}

const int SendToUnity::getIResultTest(void) const {
    return iResultTest;
}

void SendToUnity::setIResultTest(const int p_iResultTest) {
    iResultTest = p_iResultTest;
}

const int SendToUnity::getIResultTest1(void) const {
    return iResultTest1;
}

void SendToUnity::setIResultTest1(const int p_iResultTest1) {
    iResultTest1 = p_iResultTest1;
}

const int SendToUnity::getIResultTest2(void) const {
    return iResultTest2;
}

void SendToUnity::setIResultTest2(const int p_iResultTest2) {
    iResultTest2 = p_iResultTest2;
}

const int SendToUnity::getISendResultHVAC(void) const {
    return iSendResultHVAC;
}

void SendToUnity::setISendResultHVAC(const int p_iSendResultHVAC) {
    iSendResultHVAC = p_iSendResultHVAC;
}

const int SendToUnity::getISendResultIntensity(void) const {
    return iSendResultIntensity;
}

void SendToUnity::setISendResultIntensity(const int p_iSendResultIntensity) {
    iSendResultIntensity = p_iSendResultIntensity;
}

const int SendToUnity::getISendResultTemperature(void) const {
    return iSendResultTemperature;
}

void SendToUnity::setISendResultTemperature(const int p_iSendResultTemperature) {
    iSendResultTemperature = p_iSendResultTemperature;
}

const int SendToUnity::getISendResultTest(void) const {
    return iSendResultTest;
}

void SendToUnity::setISendResultTest(const int p_iSendResultTest) {
    iSendResultTest = p_iSendResultTest;
}

const int SendToUnity::getISendResultTest1(void) const {
    return iSendResultTest1;
}

void SendToUnity::setISendResultTest1(const int p_iSendResultTest1) {
    iSendResultTest1 = p_iSendResultTest1;
}

const int SendToUnity::getISendResultTest2(void) const {
    return iSendResultTest2;
}

void SendToUnity::setISendResultTest2(const int p_iSendResultTest2) {
    iSendResultTest2 = p_iSendResultTest2;
}

const float SendToUnity::getIntensity(void) const {
    return intensity;
}

void SendToUnity::setIntensity(const float p_intensity) {
    intensity = p_intensity;
    NOTIFY_SET_OPERATION;
}

const SOCKET SendToUnity::getListenSocketForHVAC(void) const {
    return listenSocketForHVAC;
}

void SendToUnity::setListenSocketForHVAC(const SOCKET p_listenSocketForHVAC) {
    listenSocketForHVAC = p_listenSocketForHVAC;
}

const SOCKET SendToUnity::getListenSocketForIntensity(void) const {
    return listenSocketForIntensity;
}

void SendToUnity::setListenSocketForIntensity(const SOCKET p_listenSocketForIntensity) {
    listenSocketForIntensity = p_listenSocketForIntensity;
}

const SOCKET SendToUnity::getListenSocketForTemperature(void) const {
    return listenSocketForTemperature;
}

void SendToUnity::setListenSocketForTemperature(const SOCKET p_listenSocketForTemperature) {
    listenSocketForTemperature = p_listenSocketForTemperature;
}

const SOCKET SendToUnity::getListenSocketForTest(void) const {
    return listenSocketForTest;
}

void SendToUnity::setListenSocketForTest(const SOCKET p_listenSocketForTest) {
    listenSocketForTest = p_listenSocketForTest;
}

const SOCKET SendToUnity::getListenSocketForTest1(void) const {
    return listenSocketForTest1;
}

void SendToUnity::setListenSocketForTest1(const SOCKET p_listenSocketForTest1) {
    listenSocketForTest1 = p_listenSocketForTest1;
}

const SOCKET SendToUnity::getListenSocketForTest2(void) const {
    return listenSocketForTest2;
}

void SendToUnity::setListenSocketForTest2(const SOCKET p_listenSocketForTest2) {
    listenSocketForTest2 = p_listenSocketForTest2;
}

const int SendToUnity::getPortHVAC(void) const {
    return portHVAC;
}

void SendToUnity::setPortHVAC(const int p_portHVAC) {
    portHVAC = p_portHVAC;
}

const int SendToUnity::getPortIntensity(void) const {
    return portIntensity;
}

void SendToUnity::setPortIntensity(const int p_portIntensity) {
    portIntensity = p_portIntensity;
}

const int SendToUnity::getPortTemperature(void) const {
    return portTemperature;
}

void SendToUnity::setPortTemperature(const int p_portTemperature) {
    portTemperature = p_portTemperature;
}

const int SendToUnity::getPortTest(void) const {
    return portTest;
}

void SendToUnity::setPortTest(const int p_portTest) {
    portTest = p_portTest;
}

const int SendToUnity::getPortTest1(void) const {
    return portTest1;
}

void SendToUnity::setPortTest1(const int p_portTest1) {
    portTest1 = p_portTest1;
}

const int SendToUnity::getPortTest2(void) const {
    return portTest2;
}

void SendToUnity::setPortTest2(const int p_portTest2) {
    portTest2 = p_portTest2;
}

const float SendToUnity::getTemperature(void) const {
    return temperature;
}

void SendToUnity::setTemperature(const float p_temperature) {
    temperature = p_temperature;
    NOTIFY_SET_OPERATION;
}

const float SendToUnity::getTest(void) const {
    return test;
}

void SendToUnity::setTest(const float p_test) {
    test = p_test;
}

const float SendToUnity::getTest1(void) const {
    return test1;
}

void SendToUnity::setTest1(const float p_test1) {
    test1 = p_test1;
}

const float SendToUnity::getTest2(void) const {
    return test2;
}

void SendToUnity::setTest2(const float p_test2) {
    test2 = p_test2;
}

const float SendToUnity::getTest2check(void) const {
    return test2check;
}

void SendToUnity::setTest2check(const float p_test2check) {
    test2check = p_test2check;
    NOTIFY_SET_OPERATION;
}

const double SendToUnity::getUtof(void) const {
    return utof;
}

void SendToUnity::setUtof(const double p_utof) {
    utof = p_utof;
}

void SendToUnity::DispenseFuel_entDef(void) {
    NOTIFY_STATE_ENTERED("ROOT.DispenseFuel");
    rootState_subState = DispenseFuel;
    rootState_active = DispenseFuel;
    state_10_entDef();
    state_11_entDef();
}

void SendToUnity::DispenseFuel_exit(void) {
    switch (state_10_subState) {
        // State UpdateVariable
        case UpdateVariable:
        {
            cancel(state_10_timeout);
            NOTIFY_STATE_EXITED("ROOT.DispenseFuel.ROOT.DispenseFuel.state_10.UpdateVariable");
        }
        break;
        case accepttimeevent_25:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.DispenseFuel.ROOT.DispenseFuel.state_10.accepttimeevent_25");
        }
        break;
        default:
            break;
    }
    state_10_subState = OMNonState;
    NOTIFY_STATE_EXITED("ROOT.DispenseFuel.ROOT.DispenseFuel.state_10");
    state_11_exit();
    
    NOTIFY_STATE_EXITED("ROOT.DispenseFuel");
}

IOxfReactive::TakeEventStatus SendToUnity::DispenseFuel_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    IOxfReactive::TakeEventStatus omComponentStatus = eventNotConsumed;
    bool dispatchDone = false;
    {
        // State state_10
        omComponentStatus = state_10_processEvent();
        if(omComponentStatus != eventNotConsumed)
            {
                res = eventConsumed;
                if(IS_IN(DispenseFuel) == false)
                    {
                        dispatchDone = true;
                    }
            }
    }
    if(!dispatchDone)
        {
            // State state_11
            omComponentStatus = state_11_processEvent();
            if(omComponentStatus != eventNotConsumed)
                {
                    res = eventConsumed;
                }
        }
    
    return res;
}

void SendToUnity::state_11_entDef(void) {
    NOTIFY_STATE_ENTERED("ROOT.DispenseFuel.ROOT.DispenseFuel.state_11");
    NOTIFY_TRANSITION_STARTED("ROOT.DispenseFuel.0");
    NOTIFY_STATE_ENTERED("ROOT.DispenseFuel.ROOT.DispenseFuel.state_11.SendAndRecieve");
    state_11_subState = SendAndRecieve;
    state_11_active = SendAndRecieve;
    //#[ state DispenseFuel.DispenseFuel.state_11.SendAndRecieve.(Entry) 
    callMain();
                
     
    //#]
    state_11_timeout = scheduleTimeout(1000, "ROOT.DispenseFuel.ROOT.DispenseFuel.state_11.SendAndRecieve");
    NOTIFY_TRANSITION_TERMINATED("ROOT.DispenseFuel.0");
}

void SendToUnity::state_11_exit(void) {
    // State SendAndRecieve
    if(state_11_subState == SendAndRecieve)
        {
            cancel(state_11_timeout);
            NOTIFY_STATE_EXITED("ROOT.DispenseFuel.ROOT.DispenseFuel.state_11.SendAndRecieve");
        }
    state_11_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.DispenseFuel.ROOT.DispenseFuel.state_11");
}

IOxfReactive::TakeEventStatus SendToUnity::state_11_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    // State SendAndRecieve
    if(state_11_active == SendAndRecieve)
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == state_11_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.DispenseFuel.1");
                            cancel(state_11_timeout);
                            NOTIFY_STATE_EXITED("ROOT.DispenseFuel.ROOT.DispenseFuel.state_11.SendAndRecieve");
                            NOTIFY_STATE_ENTERED("ROOT.DispenseFuel.ROOT.DispenseFuel.state_11.SendAndRecieve");
                            state_11_subState = SendAndRecieve;
                            state_11_active = SendAndRecieve;
                            //#[ state DispenseFuel.DispenseFuel.state_11.SendAndRecieve.(Entry) 
                            callMain();
                                        
                             
                            //#]
                            state_11_timeout = scheduleTimeout(1000, "ROOT.DispenseFuel.ROOT.DispenseFuel.state_11.SendAndRecieve");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.DispenseFuel.1");
                            res = eventConsumed;
                        }
                }
            
            
        }
    return res;
}

void SendToUnity::state_10_entDef(void) {
    NOTIFY_STATE_ENTERED("ROOT.DispenseFuel.ROOT.DispenseFuel.state_10");
    NOTIFY_TRANSITION_STARTED("ROOT.DispenseFuel.2");
    NOTIFY_STATE_ENTERED("ROOT.DispenseFuel.ROOT.DispenseFuel.state_10.UpdateVariable");
    state_10_subState = UpdateVariable;
    state_10_active = UpdateVariable;
    //#[ state DispenseFuel.DispenseFuel.state_10.UpdateVariable.(Entry) 
    test++;  
    test1++;      
    test2++;
    //#]
    state_10_timeout = scheduleTimeout(5000, "ROOT.DispenseFuel.ROOT.DispenseFuel.state_10.UpdateVariable");
    NOTIFY_TRANSITION_TERMINATED("ROOT.DispenseFuel.2");
}

IOxfReactive::TakeEventStatus SendToUnity::state_10_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (state_10_active) {
        // State UpdateVariable
        case UpdateVariable:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == state_10_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.DispenseFuel.3");
                            cancel(state_10_timeout);
                            NOTIFY_STATE_EXITED("ROOT.DispenseFuel.ROOT.DispenseFuel.state_10.UpdateVariable");
                            NOTIFY_STATE_ENTERED("ROOT.DispenseFuel.ROOT.DispenseFuel.state_10.accepttimeevent_25");
                            pushNullTransition();
                            state_10_subState = accepttimeevent_25;
                            state_10_active = accepttimeevent_25;
                            NOTIFY_TRANSITION_TERMINATED("ROOT.DispenseFuel.3");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        case accepttimeevent_25:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    NOTIFY_TRANSITION_STARTED("ROOT.DispenseFuel.4");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.DispenseFuel.ROOT.DispenseFuel.state_10.accepttimeevent_25");
                    NOTIFY_STATE_ENTERED("ROOT.DispenseFuel.ROOT.DispenseFuel.state_10.UpdateVariable");
                    state_10_subState = UpdateVariable;
                    state_10_active = UpdateVariable;
                    //#[ state DispenseFuel.DispenseFuel.state_10.UpdateVariable.(Entry) 
                    test++;  
                    test1++;      
                    test2++;
                    //#]
                    state_10_timeout = scheduleTimeout(5000, "ROOT.DispenseFuel.ROOT.DispenseFuel.state_10.UpdateVariable");
                    NOTIFY_TRANSITION_TERMINATED("ROOT.DispenseFuel.4");
                    res = eventConsumed;
                }
            
            
        }
        break;
        default:
            break;
    }
    return res;
}

void SendToUnity::rootState_entDef(void) {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        DispenseFuel_entDef();
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

IOxfReactive::TakeEventStatus SendToUnity::rootState_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    // State DispenseFuel
    if(rootState_active == DispenseFuel)
        {
            res = DispenseFuel_processEvent();
        }
    return res;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedSendToUnity::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("sockfd", x2String(myReal->sockfd));
    aomsAttributes->addAttribute("iResultTest1", x2String(myReal->iResultTest1));
    aomsAttributes->addAttribute("portTest1", x2String(myReal->portTest1));
    aomsAttributes->addAttribute("ws", UNKNOWN2STRING(myReal->ws));
    aomsAttributes->addAttribute("serverName", x2String(myReal->serverName));
    aomsAttributes->addAttribute("listenSocketForTest1", UNKNOWN2STRING(myReal->listenSocketForTest1));
    aomsAttributes->addAttribute("connectSocketForTest1", UNKNOWN2STRING(myReal->connectSocketForTest1));
    aomsAttributes->addAttribute("recvbuf", array2String(DEFAULT_BUFLEN, myReal->recvbuf, sizeof(char), &x2String));
    aomsAttributes->addAttribute("recvbuflen", x2String(myReal->recvbuflen));
    aomsAttributes->addAttribute("sendbuflen", x2String(myReal->sendbuflen));
    aomsAttributes->addAttribute("iSendResultTest1", x2String(myReal->iSendResultTest1));
    aomsAttributes->addAttribute("displayValue", x2String(myReal->displayValue));
    aomsAttributes->addAttribute("sndmsgbuf", array2String(DEFAULT_BUFLEN+3, myReal->sndmsgbuf, sizeof(char), &x2String));
    aomsAttributes->addAttribute("temp", x2String(myReal->temp));
    aomsAttributes->addAttribute("Int32", x2String(myReal->Int32));
    aomsAttributes->addAttribute("test1", x2String(myReal->test1));
    aomsAttributes->addAttribute("address_test1", UNKNOWN2STRING(myReal->address_test1));
    aomsAttributes->addAttribute("utof", x2String(myReal->utof));
    aomsAttributes->addAttribute("fval", x2String(myReal->fval));
    aomsAttributes->addAttribute("filename", x2String(myReal->filename));
    aomsAttributes->addAttribute("test", x2String(myReal->test));
    aomsAttributes->addAttribute("portTest", x2String(myReal->portTest));
    aomsAttributes->addAttribute("listenSocketForTest", UNKNOWN2STRING(myReal->listenSocketForTest));
    aomsAttributes->addAttribute("iSendResultTest", x2String(myReal->iSendResultTest));
    aomsAttributes->addAttribute("iResultTest", x2String(myReal->iResultTest));
    aomsAttributes->addAttribute("address_test", UNKNOWN2STRING(myReal->address_test));
    aomsAttributes->addAttribute("connectSocketForTest", UNKNOWN2STRING(myReal->connectSocketForTest));
    aomsAttributes->addAttribute("address_test2", UNKNOWN2STRING(myReal->address_test2));
    aomsAttributes->addAttribute("connectSocketForTest2", UNKNOWN2STRING(myReal->connectSocketForTest2));
    aomsAttributes->addAttribute("iResultTest2", x2String(myReal->iResultTest2));
    aomsAttributes->addAttribute("iSendResultTest2", x2String(myReal->iSendResultTest2));
    aomsAttributes->addAttribute("listenSocketForTest2", UNKNOWN2STRING(myReal->listenSocketForTest2));
    aomsAttributes->addAttribute("portTest2", x2String(myReal->portTest2));
    aomsAttributes->addAttribute("test2", x2String(myReal->test2));
    aomsAttributes->addAttribute("test2check", x2String(myReal->test2check));
    aomsAttributes->addAttribute("address_intensity", UNKNOWN2STRING(myReal->address_intensity));
    aomsAttributes->addAttribute("connectSocketForIntensity", UNKNOWN2STRING(myReal->connectSocketForIntensity));
    aomsAttributes->addAttribute("iResultIntensity", x2String(myReal->iResultIntensity));
    aomsAttributes->addAttribute("iSendResultIntensity", x2String(myReal->iSendResultIntensity));
    aomsAttributes->addAttribute("listenSocketForIntensity", UNKNOWN2STRING(myReal->listenSocketForIntensity));
    aomsAttributes->addAttribute("portIntensity", x2String(myReal->portIntensity));
    aomsAttributes->addAttribute("intensity", x2String(myReal->intensity));
    aomsAttributes->addAttribute("address_hvac", UNKNOWN2STRING(myReal->address_hvac));
    aomsAttributes->addAttribute("address_temperature", UNKNOWN2STRING(myReal->address_temperature));
    aomsAttributes->addAttribute("connectSocketForHVAC", UNKNOWN2STRING(myReal->connectSocketForHVAC));
    aomsAttributes->addAttribute("connectSocketForTemperature", UNKNOWN2STRING(myReal->connectSocketForTemperature));
    aomsAttributes->addAttribute("iResultHVAC", x2String(myReal->iResultHVAC));
    aomsAttributes->addAttribute("iResultTemperature", x2String(myReal->iResultTemperature));
    aomsAttributes->addAttribute("iSendResultHVAC", x2String(myReal->iSendResultHVAC));
    aomsAttributes->addAttribute("iSendResultTemperature", x2String(myReal->iSendResultTemperature));
    aomsAttributes->addAttribute("listenSocketForHVAC", UNKNOWN2STRING(myReal->listenSocketForHVAC));
    aomsAttributes->addAttribute("listenSocketForTemperature", UNKNOWN2STRING(myReal->listenSocketForTemperature));
    aomsAttributes->addAttribute("portTemperature", x2String(myReal->portTemperature));
    aomsAttributes->addAttribute("portHVAC", x2String(myReal->portHVAC));
    aomsAttributes->addAttribute("temperature", x2String(myReal->temperature));
    aomsAttributes->addAttribute("hvac", x2String(myReal->hvac));
    aomsAttributes->addAttribute("hvac_text", x2String(myReal->hvac_text));
    aomsAttributes->addAttribute("hvac_bool", x2String(myReal->hvac_bool));
}

void OMAnimatedSendToUnity::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    if(myReal->rootState_subState == SendToUnity::DispenseFuel)
        {
            DispenseFuel_serializeStates(aomsState);
        }
}

void OMAnimatedSendToUnity::DispenseFuel_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.DispenseFuel");
    state_10_serializeStates(aomsState);
    state_11_serializeStates(aomsState);
}

void OMAnimatedSendToUnity::state_11_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.DispenseFuel.ROOT.DispenseFuel.state_11");
    if(myReal->state_11_subState == SendToUnity::SendAndRecieve)
        {
            SendAndRecieve_serializeStates(aomsState);
        }
}

void OMAnimatedSendToUnity::SendAndRecieve_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.DispenseFuel.ROOT.DispenseFuel.state_11.SendAndRecieve");
}

void OMAnimatedSendToUnity::state_10_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.DispenseFuel.ROOT.DispenseFuel.state_10");
    switch (myReal->state_10_subState) {
        case SendToUnity::UpdateVariable:
        {
            UpdateVariable_serializeStates(aomsState);
        }
        break;
        case SendToUnity::accepttimeevent_25:
        {
            accepttimeevent_25_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedSendToUnity::UpdateVariable_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.DispenseFuel.ROOT.DispenseFuel.state_10.UpdateVariable");
}

void OMAnimatedSendToUnity::accepttimeevent_25_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.DispenseFuel.ROOT.DispenseFuel.state_10.accepttimeevent_25");
}
//#]

IMPLEMENT_REACTIVE_META_P(SendToUnity, Default, Default, false, OMAnimatedSendToUnity)

IMPLEMENT_META_OP(OMAnimatedSendToUnity, Default_SendToUnity_setHvac_bool_bool, "setHvac_bool", FALSE, "setHvac_bool(bool)", 1)

IMPLEMENT_OP_CALL(Default_SendToUnity_setHvac_bool_bool, SendToUnity, setHvac_bool(p_hvac_bool), NO_OP())

IMPLEMENT_META_OP(OMAnimatedSendToUnity, Default_SendToUnity_setIntensity_float, "setIntensity", FALSE, "setIntensity(float)", 1)

IMPLEMENT_OP_CALL(Default_SendToUnity_setIntensity_float, SendToUnity, setIntensity(p_intensity), NO_OP())

IMPLEMENT_META_OP(OMAnimatedSendToUnity, Default_SendToUnity_setTemperature_float, "setTemperature", FALSE, "setTemperature(float)", 1)

IMPLEMENT_OP_CALL(Default_SendToUnity_setTemperature_float, SendToUnity, setTemperature(p_temperature), NO_OP())
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\SendToUnity.cpp
*********************************************************************/
