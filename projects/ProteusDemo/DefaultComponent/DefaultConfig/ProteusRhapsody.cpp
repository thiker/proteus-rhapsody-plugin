/********************************************************************
	Rhapsody	: 9.0 
	Login		: TK
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ProteusRhapsody
//!	Generated Date	: Sun, 28, May 2023  
	File Path	: DefaultComponent\DefaultConfig\ProteusRhapsody.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "ProteusRhapsody.h"
//#[ ignore
#define Proteus_ProteusRhapsody_ProteusRhapsody_SERIALIZE OM_NO_OP

#define Proteus_ProteusRhapsody_Init_SERIALIZE OM_NO_OP
//#]

//## package Proteus

//## class ProteusRhapsody
const char* ProteusRhapsody::ADDRESS("tcp://localhost:1883");

const char* ProteusRhapsody::CLIENTID("ProteusDemoClient");

const int ProteusRhapsody::QOS(1);

const OMString ProteusRhapsody::START_PAYLOAD("TestingPayload");

MQTTClient ProteusRhapsody::client;

ProteusRhapsody::ProteusRhapsody(IOxfActive* theActiveContext) {
    NOTIFY_REACTIVE_CONSTRUCTOR(ProteusRhapsody, ProteusRhapsody(), 0, Proteus_ProteusRhapsody_ProteusRhapsody_SERIALIZE);
    setActiveContext(theActiveContext, false);
    initStatechart();
}

ProteusRhapsody::~ProteusRhapsody() {
    NOTIFY_DESTRUCTOR(~ProteusRhapsody, true);
}

void ProteusRhapsody::Init() {
    NOTIFY_OPERATION(Init, Init(), 0, Proteus_ProteusRhapsody_Init_SERIALIZE);
    //#[ operation Init()
    #define TOPIC       "MQTT Examples"
    #define PAYLOAD     "2!"
    #define TIMEOUT     10000L
    
        MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
        MQTTClient_message pubmsg = MQTTClient_message_initializer;
        MQTTClient_deliveryToken token;
        int rc;
     
        if ((rc = MQTTClient_create(&client, ADDRESS, CLIENTID,
            MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTCLIENT_SUCCESS)
        {
             printf("Failed to create client, return code %d\n", rc);
             exit(EXIT_FAILURE);
        }
     
        conn_opts.keepAliveInterval = 20;
        conn_opts.cleansession = 1;
        if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
        {
            printf("Failed to connect, return code %d\n", rc);
            exit(EXIT_FAILURE);
        }
     
        pubmsg.payload = PAYLOAD;
        pubmsg.payloadlen = (int)strlen(PAYLOAD);
        pubmsg.qos = QOS;
        pubmsg.retained = 0;
        if ((rc = MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token)) != MQTTCLIENT_SUCCESS)
        {
             printf("Failed to publish message, return code %d\n", rc);
             exit(EXIT_FAILURE);
        }
     
        printf("Waiting for up to %d seconds for publication of %s\n"
                "on topic %s for client with ClientID: %s\n",
                (int)(TIMEOUT/1000), PAYLOAD, TOPIC, CLIENTID);
        rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
        printf("Message with delivery token %d delivered\n", token);
     
        if ((rc = MQTTClient_disconnect(client, 10000)) != MQTTCLIENT_SUCCESS)
            printf("Failed to disconnect, return code %d\n", rc);
        MQTTClient_destroy(&client);
    //#]
}

const char* ProteusRhapsody::getADDRESS() {
    return ADDRESS;
}

const char* ProteusRhapsody::getCLIENTID() {
    return CLIENTID;
}

const int ProteusRhapsody::getQOS() {
    return QOS;
}

const OMString ProteusRhapsody::getSTART_PAYLOAD() {
    return START_PAYLOAD;
}

MQTTClient ProteusRhapsody::getClient() {
    return client;
}

void ProteusRhapsody::setClient(MQTTClient p_client) {
    client = p_client;
}

bool ProteusRhapsody::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void ProteusRhapsody::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void ProteusRhapsody::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        NOTIFY_STATE_ENTERED("ROOT.Default");
        rootState_subState = Default;
        rootState_active = Default;
        //#[ state Default.(Entry) 
        Init();
        //#]
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

IOxfReactive::TakeEventStatus ProteusRhapsody::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    return res;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedProteusRhapsody::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("START_PAYLOAD", x2String(myReal->START_PAYLOAD));
    aomsAttributes->addAttribute("ADDRESS", x2String(myReal->ADDRESS));
    aomsAttributes->addAttribute("CLIENTID", x2String(myReal->CLIENTID));
    aomsAttributes->addAttribute("QOS", x2String(myReal->QOS));
    aomsAttributes->addAttribute("client", UNKNOWN2STRING(myReal->client));
}

void OMAnimatedProteusRhapsody::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    if(myReal->rootState_subState == ProteusRhapsody::Default)
        {
            Default_serializeStates(aomsState);
        }
}

void OMAnimatedProteusRhapsody::Default_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Default");
}
//#]

IMPLEMENT_REACTIVE_META_P(ProteusRhapsody, Proteus, Proteus, false, OMAnimatedProteusRhapsody)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\ProteusRhapsody.cpp
*********************************************************************/
