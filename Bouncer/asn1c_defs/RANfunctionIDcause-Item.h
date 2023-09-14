/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-PDU-Contents"
 * 	found in "defs/E2AP-R003-v03.00.asn1"
 * 	`asn1c -fcompound-names -findirect-choice -fincludes-quoted -fno-include-deps -gen-PER -no-gen-OER -no-gen-example`
 */

#ifndef	_RANfunctionIDcause_Item_H_
#define	_RANfunctionIDcause_Item_H_


#include "asn_application.h"

/* Including external dependencies */
#include "RANfunctionID.h"
#include "Cause.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* RANfunctionIDcause-Item */
typedef struct RANfunctionIDcause_Item {
	RANfunctionID_t	 ranFunctionID;
	Cause_t	 cause;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANfunctionIDcause_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANfunctionIDcause_Item;

#ifdef __cplusplus
}
#endif

#endif	/* _RANfunctionIDcause_Item_H_ */
#include "asn_internal.h"
