/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-PDU-Contents"
 * 	found in "e2ap-v02.02.03.asn1"
 * 	`asn1c -fcompound-names -findirect-choice -fincludes-quoted -fno-include-deps -gen-PER -no-gen-example`
 */

#ifndef	_E2nodeComponentConfigAdditionAck_List_H_
#define	_E2nodeComponentConfigAdditionAck_List_H_


#include "asn_application.h"

/* Including external dependencies */
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolIE_SingleContainer;

/* E2nodeComponentConfigAdditionAck-List */
typedef struct E2nodeComponentConfigAdditionAck_List {
	A_SEQUENCE_OF(struct ProtocolIE_SingleContainer) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2nodeComponentConfigAdditionAck_List_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2nodeComponentConfigAdditionAck_List;

#ifdef __cplusplus
}
#endif

#endif	/* _E2nodeComponentConfigAdditionAck_List_H_ */
#include "asn_internal.h"