/********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ProteusComms
//!	Generated Date	: Sat, 3, Jun 2023  
	File Path	: DefaultComponent\DefaultConfig\ProteusComms.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "ProteusComms.h"
//## auto_generated
#include "string"
//#[ ignore
#define Proteus_ProteusComms_SendMqttMessage_SERIALIZE \
    aomsmethod->addAttribute("topic", x2String(topic));\
    aomsmethod->addAttribute("payload", x2String(payload));
#define Proteus_ProteusComms_SetStateDataBool_SERIALIZE \
    aomsmethod->addAttribute("stateObjectId", x2String(stateObjectId));\
    aomsmethod->addAttribute("key", x2String(key));\
    aomsmethod->addAttribute("data", x2String(data));
#define Proteus_ProteusComms_SetStateDataNumber_SERIALIZE \
    aomsmethod->addAttribute("stateObjectId", x2String(stateObjectId));\
    aomsmethod->addAttribute("key", x2String(key));\
    aomsmethod->addAttribute("data", x2String(data));
#define OM_Proteus_ProteusComms_SetStateDataNumber_1_SERIALIZE \
    aomsmethod->addAttribute("stateObjectId", x2String(stateObjectId));\
    aomsmethod->addAttribute("key", x2String(key));\
    aomsmethod->addAttribute("data", x2String(data));
#define Proteus_ProteusComms_SetStateDataRaw_SERIALIZE \
    aomsmethod->addAttribute("stateObjectId", x2String(stateObjectId));\
    aomsmethod->addAttribute("key", x2String(key));\
    aomsmethod->addAttribute("data", x2String(data));
#define Proteus_ProteusComms_SetStateDataString_SERIALIZE \
    aomsmethod->addAttribute("stateObjectId", x2String(stateObjectId));\
    aomsmethod->addAttribute("key", x2String(key));\
    aomsmethod->addAttribute("data", x2String(data));
#define Proteus_ProteusComms_ProteusComms_SERIALIZE OM_NO_OP

#define Proteus_ProteusComms_DestroyClient_SERIALIZE OM_NO_OP

#define Proteus_ProteusComms_Init_SERIALIZE OM_NO_OP
//#]

//## package Proteus

//## class ProteusComms
//#[ ignore
ProteusComms::pComms_C::pComms_C() : _p_(0) {
    itsIProteusComms = NULL;
}

ProteusComms::pComms_C::~pComms_C() {
    cleanUpRelations();
}

void ProteusComms::pComms_C::SetStateDataBool(const OMString& stateObjectId, const OMString& key, bool data) {
    
    if (itsIProteusComms != NULL) {
        itsIProteusComms->SetStateDataBool(stateObjectId,key,data);
    }
    
}

void ProteusComms::pComms_C::SetStateDataNumber(const OMString& stateObjectId, const OMString& key, int data) {
    
    if (itsIProteusComms != NULL) {
        itsIProteusComms->SetStateDataNumber(stateObjectId,key,data);
    }
    
}

void ProteusComms::pComms_C::SetStateDataNumber(const OMString& stateObjectId, const OMString& key, float data) {
    
    if (itsIProteusComms != NULL) {
        itsIProteusComms->SetStateDataNumber(stateObjectId,key,data);
    }
    
}

void ProteusComms::pComms_C::SetStateDataRaw(const OMString& stateObjectId, const OMString& key, const OMString& data) {
    
    if (itsIProteusComms != NULL) {
        itsIProteusComms->SetStateDataRaw(stateObjectId,key,data);
    }
    
}

void ProteusComms::pComms_C::SetStateDataString(const OMString& stateObjectId, const OMString& key, const OMString& data) {
    
    if (itsIProteusComms != NULL) {
        itsIProteusComms->SetStateDataString(stateObjectId,key,data);
    }
    
}

void ProteusComms::pComms_C::connectProteusComms(ProteusComms* part) {
    setItsIProteusComms(part);
    
}

IProteusComms* ProteusComms::pComms_C::getItsIProteusComms() {
    return this;
}

void ProteusComms::pComms_C::setItsIProteusComms(IProteusComms* p_IProteusComms) {
    itsIProteusComms = p_IProteusComms;
}

void ProteusComms::pComms_C::cleanUpRelations() {
    if(itsIProteusComms != NULL)
        {
            itsIProteusComms = NULL;
        }
}
//#]

char* ProteusComms::ADDRESS("tcp://localhost:1883");

char* ProteusComms::CLIENTID("ProteusDemoClient");

const int ProteusComms::QOS(1);

const OMString ProteusComms::START_PAYLOAD("TestingPayload");

MQTTClient ProteusComms::client;

ProteusComms::ProteusComms() : STATE_UPDATE_TOPIC_PREFIX("proteus/data/update/3dml/states/"), isConnected(false) {
    NOTIFY_CONSTRUCTOR(ProteusComms, ProteusComms(), 0, Proteus_ProteusComms_ProteusComms_SERIALIZE);
    initRelations();
}

ProteusComms::~ProteusComms() {
    NOTIFY_DESTRUCTOR(~ProteusComms, false);
}

void ProteusComms::DestroyClient() {
    NOTIFY_OPERATION(DestroyClient, DestroyClient(), 0, Proteus_ProteusComms_DestroyClient_SERIALIZE);
    //#[ operation DestroyClient()
    int rc;
    if ((rc = MQTTClient_disconnect(client, 10000)) != MQTTCLIENT_SUCCESS) {
        printf("Failed to disconnect, return code %d\n", rc);
    } else {
      isConnected = false;
    }
    
    MQTTClient_destroy(&client);
    //#]
}

bool ProteusComms::Init() {
    NOTIFY_OPERATION(Init, Init(), 0, Proteus_ProteusComms_Init_SERIALIZE);
    //#[ operation Init()
    #define TOPIC       "MQTT Examples"
    #define PAYLOAD     "2!"
    #define TIMEOUT     10000L
    
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    
    int rc;
     
    if ((rc = MQTTClient_create(&client, ADDRESS, CLIENTID,
        MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTCLIENT_SUCCESS)
    {
         printf("Failed to create client, return code %d\n", rc);
         return false;
    }
     
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        isConnected = false;
        printf("Failed to connect, return code %d\n", rc);
        return false;
    } else {
        isConnected = true;
        printf("Succesfully connected mqtt client");
    }
    
    return true;
    //#]
}

void ProteusComms::SendMqttMessage(const OMString& topic, const OMString& payload) {
    NOTIFY_OPERATION(SendMqttMessage, SendMqttMessage(const OMString&,const OMString&), 2, Proteus_ProteusComms_SendMqttMessage_SERIALIZE);
    //#[ operation SendMqttMessage(OMString,OMString)
    if (!isConnected) {
      std::cout << "Trying to send message but client is not connected. Running Init..." << std::endl;
      if (!Init()) {
        std::cout << "Tried Init but no success. Aborting.." << std::endl;
      	return;
      }
    }
    OMString topic_string = topic;
    OMString payload_string = payload;
    
    const char* c_const_topic = (const char*)(topic_string);
    const char* c_const_payload = (const char*)(payload_string);
    
    char* c_topic = const_cast<char*>(c_const_topic);
    char* c_payload = const_cast<char*>(c_const_payload);
    
    int rc;
    
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    
    pubmsg.payload = c_payload;
    pubmsg.payloadlen = (int)strlen(c_payload);
    pubmsg.qos = QOS;
    pubmsg.retained = 0;
    
    if ((rc = MQTTClient_publishMessage(client, c_topic, &pubmsg, &token)) != MQTTCLIENT_SUCCESS)
    {
         printf("Failed to publish message, return code %d\n", rc);
         exit(EXIT_FAILURE);
    }
     
    //printf("Waiting for up to %d seconds for publication of %s\n"
    //        "on topic %s for client with ClientID: %s\n",
    //        (int)(TIMEOUT/1000), c_payload , c_topic, CLIENTID);
    rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
    //printf("Message with delivery token %d delivered\n", token);
     
    //#]
}

void ProteusComms::SetStateDataNumber(const OMString& stateObjectId, const OMString& key, int data) {
    NOTIFY_OPERATION(SetStateDataNumber, SetStateDataNumber(const OMString&,const OMString&,int), 3, Proteus_ProteusComms_SetStateDataNumber_SERIALIZE);
    //#[ operation SetStateDataNumber(OMString,OMString,int)
    OMString topic = STATE_UPDATE_TOPIC_PREFIX + stateObjectId + "/" + key;
    OMString payload =  "{ \"StateId\":\"" + stateObjectId + "\", \"key\" : \""+ key +"\", \"value\": " + std::to_string(data).c_str()  + "}";
    SendMqttMessage(topic, payload);
    //#]
}

void ProteusComms::SetStateDataNumber(const OMString& stateObjectId, const OMString& key, float data) {
    NOTIFY_OPERATION(SetStateDataNumber, SetStateDataNumber(const OMString&,const OMString&,float), 3, OM_Proteus_ProteusComms_SetStateDataNumber_1_SERIALIZE);
    //#[ operation SetStateDataNumber(OMString,OMString,float)
    OMString topic = STATE_UPDATE_TOPIC_PREFIX + stateObjectId + "/" + key;
    OMString payload =  "{ \"StateId\":\"" + stateObjectId + "\", \"key\" : \""+ key +"\", \"value\": " + std::to_string(data).c_str()  + "}";
    SendMqttMessage(topic, payload);
    //#]
}

void ProteusComms::SetStateDataBool(const OMString& stateObjectId, const OMString& key, bool data) {
    NOTIFY_OPERATION(SetStateDataBool, SetStateDataBool(const OMString&,const OMString&,bool), 3, Proteus_ProteusComms_SetStateDataBool_SERIALIZE);
    //#[ operation SetStateDataBool(OMString,OMString,bool)
    OMString topic = STATE_UPDATE_TOPIC_PREFIX + stateObjectId + "/" + key;
    
    OMString boolString = "null";
    
    if (data) {
      boolString = "true";
    } else {
      boolString = "false";
    }
    
    OMString payload =  "{ \"StateId\":\"" + stateObjectId + "\", \"key\" : \""+ key +"\", \"value\": " + boolString  + "}";
    SendMqttMessage(topic, payload);
    //#]
}

ProteusComms::pComms_C* ProteusComms::getPComms() const {
    return (ProteusComms::pComms_C*) &pComms;
}

ProteusComms::pComms_C* ProteusComms::get_pComms() const {
    return (ProteusComms::pComms_C*) &pComms;
}

char* ProteusComms::getADDRESS() {
    return ADDRESS;
}

char* ProteusComms::getCLIENTID() {
    return CLIENTID;
}

const int ProteusComms::getQOS() {
    return QOS;
}

const OMString ProteusComms::getSTART_PAYLOAD() {
    return START_PAYLOAD;
}

const OMString ProteusComms::getSTATE_UPDATE_TOPIC_PREFIX() const {
    return STATE_UPDATE_TOPIC_PREFIX;
}

MQTTClient ProteusComms::getClient() {
    return client;
}

void ProteusComms::setClient(MQTTClient p_client) {
    client = p_client;
}

bool ProteusComms::getIsConnected() const {
    return isConnected;
}

void ProteusComms::setIsConnected(bool p_isConnected) {
    isConnected = p_isConnected;
}

OMString ProteusComms::getPtResultEngineState() const {
    return ptResultEngineState;
}

void ProteusComms::setPtResultEngineState(OMString p_ptResultEngineState) {
    ptResultEngineState = p_ptResultEngineState;
}

OMString ProteusComms::getPtResultStarterState() const {
    return ptResultStarterState;
}

void ProteusComms::setPtResultStarterState(OMString p_ptResultStarterState) {
    ptResultStarterState = p_ptResultStarterState;
}

void ProteusComms::initRelations() {
    if (get_pComms() != NULL) {
        get_pComms()->connectProteusComms(this);
    }
}

void ProteusComms::SetStateDataRaw(const OMString& stateObjectId, const OMString& key, const OMString& data) {
    NOTIFY_OPERATION(SetStateDataRaw, SetStateDataRaw(const OMString&,const OMString&,const OMString&), 3, Proteus_ProteusComms_SetStateDataRaw_SERIALIZE);
    //#[ operation SetStateDataRaw(OMString,OMString,OMString)
    OMString topic;
    OMString payload;
    
    topic = STATE_UPDATE_TOPIC_PREFIX + stateObjectId + "/" + key;
    payload =  "{ \"StateId\":\"" + stateObjectId + "\", \"key\" : \""+ key +"\", \"value\" : " + data + "}";
    
    SendMqttMessage(topic, payload);
    //#]
}

void ProteusComms::SetStateDataString(const OMString& stateObjectId, const OMString& key, const OMString& data) {
    NOTIFY_OPERATION(SetStateDataString, SetStateDataString(const OMString&,const OMString&,const OMString&), 3, Proteus_ProteusComms_SetStateDataString_SERIALIZE);
    //#[ operation SetStateDataString(OMString,OMString,OMString)
    OMString topic = STATE_UPDATE_TOPIC_PREFIX + stateObjectId + "/" + key;
    OMString payload =  "{ \"StateId\":\"" + stateObjectId + "\", \"key\" : \""+ key +"\", \"value\" : \"" + data + "\"}";
    SendMqttMessage(topic, payload);
    //#]
}

void ProteusComms::setADDRESS(char* p_ADDRESS) {
    ADDRESS = p_ADDRESS;
}

void ProteusComms::setCLIENTID(char* p_CLIENTID) {
    CLIENTID = p_CLIENTID;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedProteusComms::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("START_PAYLOAD", x2String(myReal->START_PAYLOAD));
    aomsAttributes->addAttribute("ADDRESS", x2String(myReal->ADDRESS));
    aomsAttributes->addAttribute("CLIENTID", x2String(myReal->CLIENTID));
    aomsAttributes->addAttribute("QOS", x2String(myReal->QOS));
    aomsAttributes->addAttribute("client", UNKNOWN2STRING(myReal->client));
    aomsAttributes->addAttribute("ptResultEngineState", x2String(myReal->ptResultEngineState));
    aomsAttributes->addAttribute("ptResultStarterState", x2String(myReal->ptResultStarterState));
    aomsAttributes->addAttribute("isConnected", x2String(myReal->isConnected));
    aomsAttributes->addAttribute("STATE_UPDATE_TOPIC_PREFIX", x2String(myReal->STATE_UPDATE_TOPIC_PREFIX));
    OMAnimatedIProteusComms::serializeAttributes(aomsAttributes);
}

void OMAnimatedProteusComms::serializeRelations(AOMSRelations* aomsRelations) const {
    OMAnimatedIProteusComms::serializeRelations(aomsRelations);
}
//#]

IMPLEMENT_META_S_P(ProteusComms, Proteus, false, IProteusComms, OMAnimatedIProteusComms, OMAnimatedProteusComms)

OMINIT_SUPERCLASS(IProteusComms, OMAnimatedIProteusComms)

OMREGISTER_CLASS
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\ProteusComms.cpp
*********************************************************************/
