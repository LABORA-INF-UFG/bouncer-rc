/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "defs/E2SM-RC-R003-v03.00.asn1"
 * 	`asn1c -fcompound-names -findirect-choice -fincludes-quoted -fno-include-deps -gen-PER -no-gen-OER -no-gen-example`
 */

#ifndef	_TriggerType_Choice_L2MACschChg_H_
#define	_TriggerType_Choice_L2MACschChg_H_


#include "asn_application.h"

/* Including external dependencies */
#include "L2MACschChgType-Choice.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* TriggerType-Choice-L2MACschChg */
typedef struct TriggerType_Choice_L2MACschChg {
	L2MACschChgType_Choice_t	 l2MACschChgType;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TriggerType_Choice_L2MACschChg_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TriggerType_Choice_L2MACschChg;
extern asn_SEQUENCE_specifics_t asn_SPC_TriggerType_Choice_L2MACschChg_specs_1;
extern asn_TYPE_member_t asn_MBR_TriggerType_Choice_L2MACschChg_1[1];

#ifdef __cplusplus
}
#endif

#endif	/* _TriggerType_Choice_L2MACschChg_H_ */
#include "asn_internal.h"
