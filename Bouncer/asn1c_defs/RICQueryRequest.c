/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-PDU-Contents"
 * 	found in "defs/E2AP-R003-v03.00.asn1"
 * 	`asn1c -fcompound-names -findirect-choice -fincludes-quoted -fno-include-deps -gen-PER -no-gen-OER -no-gen-example`
 */

#include "RICQueryRequest.h"

asn_TYPE_member_t asn_MBR_RICQueryRequest_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RICQueryRequest, protocolIEs),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolIE_Container_2529P17,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"protocolIEs"
		},
};
static const ber_tlv_tag_t asn_DEF_RICQueryRequest_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_RICQueryRequest_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* protocolIEs */
};
asn_SEQUENCE_specifics_t asn_SPC_RICQueryRequest_specs_1 = {
	sizeof(struct RICQueryRequest),
	offsetof(struct RICQueryRequest, _asn_ctx),
	asn_MAP_RICQueryRequest_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_RICQueryRequest = {
	"RICQueryRequest",
	"RICQueryRequest",
	&asn_OP_SEQUENCE,
	asn_DEF_RICQueryRequest_tags_1,
	sizeof(asn_DEF_RICQueryRequest_tags_1)
		/sizeof(asn_DEF_RICQueryRequest_tags_1[0]), /* 1 */
	asn_DEF_RICQueryRequest_tags_1,	/* Same as above */
	sizeof(asn_DEF_RICQueryRequest_tags_1)
		/sizeof(asn_DEF_RICQueryRequest_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_RICQueryRequest_1,
	1,	/* Elements count */
	&asn_SPC_RICQueryRequest_specs_1	/* Additional specs */
};

