/*
# ==================================================================================
# Copyright (c) 2020 HCL Technologies Limited.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ==================================================================================
*/

/* Classes to handle E2 service model based on e2sm-Bouncer-v001.asn */

#include "e2sm_subscription.hpp"

#include "E2SM-RC-EventTrigger.h"
#include "E2SM-RC-EventTrigger-Format4.h"
#include "E2SM-RC-EventTrigger-Format4-Item.h"
#include "TriggerType-Choice-RRCstate.h"
#include "TriggerType-Choice-RRCstate-Item.h"
#include "RRC-State.h"
#include "E2SM-RC-ActionDefinition.h"
#include "E2SM-RC-ActionDefinition-Format1.h"
#include "E2SM-RC-ActionDefinition-Format1-Item.h"


 //initialize
 e2sm_subscription::e2sm_subscription(void){

	memset(&event_fmt1, 0, sizeof(E2SM_Bouncer_EventTriggerDefinition_Format1_t));

	memset(&actn_fmt1, 0, sizeof(E2SM_Bouncer_ActionDefinition_Format1_t));


	ran_param = 0;
	ran_param = (RANparameter_Item_t*)calloc(1, sizeof(RANparameter_Item_t));
	assert(ran_param != 0);

    event_trigger = 0;
    event_trigger = ( E2SM_Bouncer_EventTriggerDefinition_t *)calloc(1, sizeof( E2SM_Bouncer_EventTriggerDefinition_t));
    assert(event_trigger != 0);

    action_defn = 0;
    action_defn = (E2SM_Bouncer_ActionDefinition_t*)calloc(1, sizeof(E2SM_Bouncer_ActionDefinition_t));
    assert(action_defn !=0);

    errbuf_len = 128;
  };

 e2sm_subscription::~e2sm_subscription(void){

  mdclog_write(MDCLOG_DEBUG, "Freeing event trigger object memory");

  event_trigger->choice.eventDefinition_Format1 = 0;

  action_defn->choice.actionDefinition_Format1 = 0;

  free(ran_param);

  ASN_STRUCT_FREE(asn_DEF_E2SM_Bouncer_EventTriggerDefinition, event_trigger);
  ASN_STRUCT_FREE(asn_DEF_E2SM_Bouncer_ActionDefinition, action_defn);


};

bool e2sm_subscription::encode_event_trigger(unsigned char *buf, ssize_t *size, e2sm_subscription_helper &helper){

  ASN_STRUCT_RESET(asn_DEF_E2SM_Bouncer_EventTriggerDefinition, event_trigger);

  bool res;
  res = set_fields(event_trigger, helper);
  if (!res){

    return false;
  }

  int ret_constr = asn_check_constraints(&asn_DEF_E2SM_Bouncer_EventTriggerDefinition, event_trigger, errbuf, &errbuf_len);
  if(ret_constr){
    error_string.assign(&errbuf[0], errbuf_len);
    return false;
  }

  xer_fprint(stdout, &asn_DEF_E2SM_Bouncer_EventTriggerDefinition, event_trigger);

  asn_enc_rval_t retval = asn_encode_to_buffer(0, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2SM_Bouncer_EventTriggerDefinition, event_trigger, buf, *size);

  if(retval.encoded == -1){
    error_string.assign(strerror(errno));
    return false;
  }
  else if (retval.encoded > *size){
    std::stringstream ss;
    ss  <<"Error encoding event trigger definition. Reason =  encoded pdu size " << retval.encoded << " exceeds buffer size " << *size << std::endl;
    error_string = ss.str();
    return false;
  }
  else{
    *size = retval.encoded;
  }

  return true;
}

bool e2sm_subscription::encode_action_defn(unsigned char *buf, ssize_t *size, e2sm_subscription_helper &helper){

  bool res;
  res = set_fields(action_defn, helper);
  if (!res){
    return false;
  }


  int ret_constr = asn_check_constraints(&asn_DEF_E2SM_Bouncer_ActionDefinition, action_defn, errbuf, &errbuf_len);
  if(ret_constr){
    error_string.assign(&errbuf[0], errbuf_len);
    return false;
  }

  xer_fprint(stdout, &asn_DEF_E2SM_Bouncer_ActionDefinition, action_defn);

  asn_enc_rval_t retval = asn_encode_to_buffer(0, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2SM_Bouncer_ActionDefinition, action_defn, buf, *size);

  if(retval.encoded == -1){
    error_string.assign(strerror(errno));
    return false;
  }
  else if (retval.encoded > *size){
    std::stringstream ss;
    ss  <<"Error encoding action definition. Reason =  encoded pdu size " << retval.encoded << " exceeds buffer size " << *size << std::endl;
    error_string = ss.str();
    return false;
  }
  else{
    *size = retval.encoded;
  }

  return true;
}

bool e2sm_subscription::encodeRCTriggerDefinitionFormat4(unsigned char *buffer, ssize_t *buflen) {
  std::stringstream ss;

  if (!buffer) {
    ss << "Invalid reference for buffer to enconde RC EventTriggerDefinition in fucntion " << __func__;
    error_string = ss.str();
    return false;
  }

  // E2SM_RC_EventTrigger_t *trigger = (E2SM_RC_EventTrigger_t *) calloc(1, sizeof(E2SM_RC_EventTrigger_t));
  // trigger->ric_eventTrigger_formats.present = E2SM_RC_EventTrigger__ric_eventTrigger_formats_PR_eventTrigger_Format4;
  // trigger->ric_eventTrigger_formats.choice.eventTrigger_Format4 = (E2SM_RC_EventTrigger_Format4_t *) calloc(1, sizeof(E2SM_RC_EventTrigger_Format4_t));
  // E2SM_RC_EventTrigger_Format4_t *fmt4 = trigger->ric_eventTrigger_formats.choice.eventTrigger_Format4;
  E2SM_RC_EventTrigger_Format4_t *fmt4 = (E2SM_RC_EventTrigger_Format4_t *) calloc(1, sizeof(E2SM_RC_EventTrigger_Format4_t));


  E2SM_RC_EventTrigger_Format4_Item_t *fmt4_item = (E2SM_RC_EventTrigger_Format4_Item_t *) calloc(1, sizeof(E2SM_RC_EventTrigger_Format4_Item_t));
  ASN_SEQUENCE_ADD(&fmt4->uEInfoChange_List.list, fmt4_item);

  fmt4_item->ric_eventTriggerCondition_ID = 1;
  fmt4_item->triggerType.present = TriggerType_Choice_PR_triggerType_Choice_RRCstate;
  fmt4_item->triggerType.choice.triggerType_Choice_RRCstate = (TriggerType_Choice_RRCstate_t *) calloc(1, sizeof(TriggerType_Choice_RRCstate));

  TriggerType_Choice_RRCstate_Item_t *rrc_connect = (TriggerType_Choice_RRCstate_Item_t *) calloc(1, sizeof(TriggerType_Choice_RRCstate_Item_t));
  rrc_connect->stateChangedTo = RRC_State_rrc_connected;
  ASN_SEQUENCE_ADD(&fmt4_item->triggerType.choice.triggerType_Choice_RRCstate->rrcState_List.list, rrc_connect);
  // rrc_connect->logicalOR = (LogicalOR_t *) calloc(1, sizeof(LogicalOR_t));
  // *rrc_connect->logicalOR = LogicalOR_true;

  TriggerType_Choice_RRCstate_Item_t *rrc_disconnect = (TriggerType_Choice_RRCstate_Item_t *) calloc(1, sizeof(TriggerType_Choice_RRCstate_Item_t));
  rrc_disconnect->stateChangedTo = RRC_State_rrc_inactive;
  ASN_SEQUENCE_ADD(&fmt4_item->triggerType.choice.triggerType_Choice_RRCstate->rrcState_List.list, rrc_disconnect);

  char errbuf[512] = {0,};
  size_t errlen = 512;

  // if (asn_check_constraints(&asn_DEF_E2SM_RC_EventTrigger, trigger, errbuf, &errlen) != 0) {
  //     ss << "Constraints for " << asn_DEF_E2SM_RC_EventTrigger.name << " did not met. Reason: " << errbuf;
  //     error_string = ss.str();
  // }
  if (asn_check_constraints(&asn_DEF_E2SM_RC_EventTrigger_Format4, fmt4, errbuf, &errlen) != 0) {
      ss << "Constraints for " << asn_DEF_E2SM_RC_EventTrigger.name << " did not met. Reason: " << errbuf;
      error_string = ss.str();
  }

  // if (mdclog_level_get() > MDCLOG_INFO) {
  //     asn_fprint(stderr, &asn_DEF_E2SM_RC_EventTrigger, trigger);
  // }
  if (mdclog_level_get() > MDCLOG_INFO) {
      asn_fprint(stderr, &asn_DEF_E2SM_RC_EventTrigger_Format4, fmt4);
  }

  asn_enc_rval_t rval;
  // rval = asn_encode_to_buffer(NULL, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2SM_RC_EventTrigger, trigger, buffer, *buflen);
  // if (rval.encoded == -1) {
  //     ss << "Serialization of " << asn_DEF_E2SM_RC_EventTrigger.name << " failed, type=" << rval.failed_type->name;
  //     error_string = ss.str();
  //     return false;
  // }
  // else if (rval.encoded > *buflen) {
  //     ss << "Buffer of size " << *buflen << " is too small for " << asn_DEF_E2SM_RC_EventTrigger.name << ", need " << rval.encoded;
  //     error_string = ss.str();
  //     return false;
  // }
  rval = asn_encode_to_buffer(NULL, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2SM_RC_EventTrigger_Format4, fmt4, buffer, *buflen);
  if (rval.encoded == -1) {
      ss << "Serialization of " << asn_DEF_E2SM_RC_EventTrigger.name << " failed, type=" << rval.failed_type->name;
      error_string = ss.str();
      return false;
  }
  else if (rval.encoded > *buflen) {
      ss << "Buffer of size " << *buflen << " is too small for " << asn_DEF_E2SM_RC_EventTrigger_Format4.name << ", need " << rval.encoded;
      error_string = ss.str();
      return false;
  }

  *buflen = rval.encoded;

  // ASN_STRUCT_FREE(asn_DEF_E2SM_RC_EventTrigger, trigger);
  ASN_STRUCT_FREE(asn_DEF_E2SM_RC_EventTrigger_Format4, fmt4);

  return true;
}

bool e2sm_subscription::encodeRCActionDefinitionFormat1(unsigned char *buffer, ssize_t *buflen) {
  std::stringstream ss;

  if (!buffer) {
    ss << "Invalid reference for buffer to enconde E2SM_RC_ActionDefinition in function " << __func__;
    error_string = ss.str();
    return false;
  }

  E2SM_RC_ActionDefinition_t *action = (E2SM_RC_ActionDefinition_t *) calloc(1, sizeof(E2SM_RC_ActionDefinition_t));
  action->ric_Style_Type = 4;
  action->ric_actionDefinition_formats.present = E2SM_RC_ActionDefinition__ric_actionDefinition_formats_PR_actionDefinition_Format1;
  action->ric_actionDefinition_formats.choice.actionDefinition_Format1 = (E2SM_RC_ActionDefinition_Format1_t *) calloc(1, sizeof(E2SM_RC_ActionDefinition_Format1_t));
  E2SM_RC_ActionDefinition_Format1_t *fmt1 = action->ric_actionDefinition_formats.choice.actionDefinition_Format1;

  E2SM_RC_ActionDefinition_Format1_Item_t *item1 = (E2SM_RC_ActionDefinition_Format1_Item_t *) calloc(1, sizeof(E2SM_RC_ActionDefinition_Format1_Item_t));
  item1->ranParameter_ID = 202; // "RRC State Changed To" as per 8.2.4 in E2SM-RC-R003-v03.00
  ASN_SEQUENCE_ADD(&fmt1->ranP_ToBeReported_List.list, item1);

  E2SM_RC_ActionDefinition_Format1_Item_t *item2 = (E2SM_RC_ActionDefinition_Format1_Item_t *) calloc(1, sizeof(E2SM_RC_ActionDefinition_Format1_Item_t));
  item2->ranParameter_ID = 12501; // RSRP as per 8.1.1.3 in E2SM-RC-R003-v03.00
  ASN_SEQUENCE_ADD(&fmt1->ranP_ToBeReported_List.list, item2);

  E2SM_RC_ActionDefinition_Format1_Item_t *item3 = (E2SM_RC_ActionDefinition_Format1_Item_t *) calloc(1, sizeof(E2SM_RC_ActionDefinition_Format1_Item_t));
  item3->ranParameter_ID = 12502; // RSRQ as per 8.1.1.3 in E2SM-RC-R003-v03.00
  ASN_SEQUENCE_ADD(&fmt1->ranP_ToBeReported_List.list, item3);

  E2SM_RC_ActionDefinition_Format1_Item_t *item4 = (E2SM_RC_ActionDefinition_Format1_Item_t *) calloc(1, sizeof(E2SM_RC_ActionDefinition_Format1_Item_t));
  item4->ranParameter_ID = 12503; // SINR as per 8.1.1.3 in E2SM-RC-R003-v03.00
  ASN_SEQUENCE_ADD(&fmt1->ranP_ToBeReported_List.list, item4);

  E2SM_RC_ActionDefinition_Format1_Item_t *item5 = (E2SM_RC_ActionDefinition_Format1_Item_t *) calloc(1, sizeof(E2SM_RC_ActionDefinition_Format1_Item_t));
  item5->ranParameter_ID = 17011; // Global gNB ID Structure as per 8.1.1.11 in E2SM-RC-R003-v03.00
  ASN_SEQUENCE_ADD(&fmt1->ranP_ToBeReported_List.list, item5);

  char errbuf[512] = {0,};
  size_t errlen = 512;

  if (asn_check_constraints(&asn_DEF_E2SM_RC_ActionDefinition, action, errbuf, &errlen) != 0) {
    ss << "Constraints for " << asn_DEF_E2SM_RC_ActionDefinition.name << " did not met. Reason: " << errbuf;
    error_string = ss.str();
  }

  if (mdclog_level_get() > MDCLOG_INFO) {
    asn_fprint(stderr, &asn_DEF_E2SM_RC_ActionDefinition, action);
  }

  asn_enc_rval_t rval;
  rval = asn_encode_to_buffer(nullptr, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2SM_RC_ActionDefinition, action, buffer, *buflen);
  if (rval.encoded == -1) {
    ss << "Serialization of " << asn_DEF_E2SM_RC_ActionDefinition.name << " failed, type=" << rval.failed_type->name;
    error_string = ss.str();
    return false;

  } else if (rval.encoded > *buflen) {
    ss << "Buffer of size " << *buflen << " is too small for " << asn_DEF_E2SM_RC_ActionDefinition.name << ", need " << rval.encoded;
    error_string = ss.str();
    return false;
  }

  *buflen = rval.encoded;


  ASN_STRUCT_FREE(asn_DEF_E2SM_RC_ActionDefinition, action);

  return true;
}

bool e2sm_subscription::set_fields(E2SM_Bouncer_EventTriggerDefinition_t * ref_event_trigger, e2sm_subscription_helper & helper){

 if(ref_event_trigger == 0){
    error_string = "Invalid reference for Event Trigger Definition set fields";
    return false;
  }

  ref_event_trigger->present = E2SM_Bouncer_EventTriggerDefinition_PR_eventDefinition_Format1;

  event_fmt1.triggerNature = helper.triger_nature;

  ref_event_trigger->choice.eventDefinition_Format1 = &event_fmt1;

  return true;
};

bool e2sm_subscription::set_fields(E2SM_Bouncer_ActionDefinition_t * ref_action_defn, e2sm_subscription_helper & helper){

 if(ref_action_defn == 0){
    error_string = "Invalid reference for Event Action Definition set fields";
    return false;
  }
  ref_action_defn->present = E2SM_Bouncer_ActionDefinition_PR_actionDefinition_Format1;


  ranparam_helper_t paramlst = helper.get_paramlist();

  for(RANParam_Helper item:paramlst){
	  ran_param->ranParameter_ID = item.getran_helper()._param_id;
	  ran_param->ranParameter_Name.buf = item.getran_helper()._param_name;
	  ran_param->ranParameter_Name.size = item.getran_helper()._param_name_len;
	  ran_param->ranParameter_Test = item.getran_helper()._param_test;
	  ran_param->ranParameter_Value.buf = item.getran_helper()._param_value;
	  ran_param->ranParameter_Value.size = item.getran_helper()._param_value_len;
	  ASN_SEQUENCE_ADD(&(actn_fmt1.ranParameter_List->list.array), ran_param);
  }


  ref_action_defn->choice.actionDefinition_Format1 = &actn_fmt1;


  return true;
};

