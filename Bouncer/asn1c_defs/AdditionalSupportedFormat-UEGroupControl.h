/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "defs/E2SM-RC-R003-v03.00.asn1"
 * 	`asn1c -fcompound-names -findirect-choice -fincludes-quoted -fno-include-deps -gen-PER -no-gen-OER -no-gen-example`
 */

#ifndef	_AdditionalSupportedFormat_UEGroupControl_H_
#define	_AdditionalSupportedFormat_UEGroupControl_H_


#include "asn_application.h"

/* Including external dependencies */
#include "RIC-Format-Type.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* AdditionalSupportedFormat-UEGroupControl */
typedef struct AdditionalSupportedFormat_UEGroupControl {
	RIC_Format_Type_t	 ric_ControlHeaderFormat_Type;
	RIC_Format_Type_t	 ric_ControlMessageFormat_Type;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AdditionalSupportedFormat_UEGroupControl_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AdditionalSupportedFormat_UEGroupControl;
extern asn_SEQUENCE_specifics_t asn_SPC_AdditionalSupportedFormat_UEGroupControl_specs_1;
extern asn_TYPE_member_t asn_MBR_AdditionalSupportedFormat_UEGroupControl_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _AdditionalSupportedFormat_UEGroupControl_H_ */
#include "asn_internal.h"
