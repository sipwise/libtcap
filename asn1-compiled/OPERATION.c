/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#include "OPERATION.h"

static asn_TYPE_member_t asn_MBR_OPERATION_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct OPERATION, choice.localValue),
		(ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
		0,
		&asn_DEF_INTEGER,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"localValue"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct OPERATION, choice.globalValue),
		(ASN_TAG_CLASS_UNIVERSAL | (6 << 2)),
		0,
		&asn_DEF_OBJECT_IDENTIFIER,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"globalValue"
		},
};
static asn_TYPE_tag2member_t asn_MAP_OPERATION_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 0, 0, 0 }, /* localValue at 188 */
    { (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)), 1, 0, 0 } /* globalValue at 189 */
};
static asn_CHOICE_specifics_t asn_SPC_OPERATION_specs_1 = {
	sizeof(struct OPERATION),
	offsetof(struct OPERATION, _asn_ctx),
	offsetof(struct OPERATION, present),
	sizeof(((struct OPERATION *)0)->present),
	asn_MAP_OPERATION_tag2el_1,
	2,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_OPERATION = {
	"OPERATION",
	"OPERATION",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	CHOICE_outmost_tag,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	0,	/* No PER visible constraints */
	asn_MBR_OPERATION_1,
	2,	/* Elements count */
	&asn_SPC_OPERATION_specs_1	/* Additional specs */
};

