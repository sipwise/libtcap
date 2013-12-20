/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#include "USIServiceIndicator.h"

static int
memb_local_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size;
	
	if((size <= 255)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_TYPE_member_t asn_MBR_USIServiceIndicator_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct USIServiceIndicator, choice.global),
		(ASN_TAG_CLASS_UNIVERSAL | (6 << 2)),
		0,
		&asn_DEF_OBJECT_IDENTIFIER,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"global"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct USIServiceIndicator, choice.local),
		(ASN_TAG_CLASS_UNIVERSAL | (4 << 2)),
		0,
		&asn_DEF_OCTET_STRING,
		memb_local_constraint_1,
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"local"
		},
};
static asn_TYPE_tag2member_t asn_MAP_USIServiceIndicator_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)), 1, 0, 0 }, /* local at 716 */
    { (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)), 0, 0, 0 } /* global at 714 */
};
static asn_CHOICE_specifics_t asn_SPC_USIServiceIndicator_specs_1 = {
	sizeof(struct USIServiceIndicator),
	offsetof(struct USIServiceIndicator, _asn_ctx),
	offsetof(struct USIServiceIndicator, present),
	sizeof(((struct USIServiceIndicator *)0)->present),
	asn_MAP_USIServiceIndicator_tag2el_1,
	2,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_USIServiceIndicator = {
	"USIServiceIndicator",
	"USIServiceIndicator",
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
	asn_MBR_USIServiceIndicator_1,
	2,	/* Elements count */
	&asn_SPC_USIServiceIndicator_specs_1	/* Additional specs */
};

