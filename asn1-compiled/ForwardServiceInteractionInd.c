/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#include "ForwardServiceInteractionInd.h"

static int
memb_conferenceTreatmentIndicator_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
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
	
	if((size == 1)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_callDiversionTreatmentIndicator_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
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
	
	if((size == 1)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_callOfferingTreatmentIndicator_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
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
	
	if((size == 1)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_callWaitingTreatmentIndicator_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
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
	
	if((size == 1)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_holdTreatmentIndicator_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
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
	
	if((size == 1)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_ectTreatmentIndicator_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
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
	
	if((size == 1)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_TYPE_member_t asn_MBR_ForwardServiceInteractionInd_1[] = {
	{ ATF_POINTER, 6, offsetof(struct ForwardServiceInteractionInd, conferenceTreatmentIndicator),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		memb_conferenceTreatmentIndicator_constraint_1,
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"conferenceTreatmentIndicator"
		},
	{ ATF_POINTER, 5, offsetof(struct ForwardServiceInteractionInd, callDiversionTreatmentIndicator),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		memb_callDiversionTreatmentIndicator_constraint_1,
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"callDiversionTreatmentIndicator"
		},
	{ ATF_POINTER, 4, offsetof(struct ForwardServiceInteractionInd, callOfferingTreatmentIndicator),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		memb_callOfferingTreatmentIndicator_constraint_1,
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"callOfferingTreatmentIndicator"
		},
	{ ATF_POINTER, 3, offsetof(struct ForwardServiceInteractionInd, callWaitingTreatmentIndicator),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		memb_callWaitingTreatmentIndicator_constraint_1,
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"callWaitingTreatmentIndicator"
		},
	{ ATF_POINTER, 2, offsetof(struct ForwardServiceInteractionInd, holdTreatmentIndicator),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		memb_holdTreatmentIndicator_constraint_1,
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"holdTreatmentIndicator"
		},
	{ ATF_POINTER, 1, offsetof(struct ForwardServiceInteractionInd, ectTreatmentIndicator),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		memb_ectTreatmentIndicator_constraint_1,
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"ectTreatmentIndicator"
		},
};
static ber_tlv_tag_t asn_DEF_ForwardServiceInteractionInd_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_ForwardServiceInteractionInd_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 0, 0, 0 }, /* conferenceTreatmentIndicator at 327 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 1, 0, 0 }, /* callDiversionTreatmentIndicator at 331 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 2, 0, 0 }, /* callOfferingTreatmentIndicator at 335 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 3, 0, 0 }, /* callWaitingTreatmentIndicator at 344 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 4, 0, 0 }, /* holdTreatmentIndicator at 350 */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 5, 0, 0 } /* ectTreatmentIndicator at 354 */
};
static asn_SEQUENCE_specifics_t asn_SPC_ForwardServiceInteractionInd_specs_1 = {
	sizeof(struct ForwardServiceInteractionInd),
	offsetof(struct ForwardServiceInteractionInd, _asn_ctx),
	asn_MAP_ForwardServiceInteractionInd_tag2el_1,
	6,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	3,	/* Start extensions */
	7	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_ForwardServiceInteractionInd = {
	"ForwardServiceInteractionInd",
	"ForwardServiceInteractionInd",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_ForwardServiceInteractionInd_tags_1,
	sizeof(asn_DEF_ForwardServiceInteractionInd_tags_1)
		/sizeof(asn_DEF_ForwardServiceInteractionInd_tags_1[0]), /* 1 */
	asn_DEF_ForwardServiceInteractionInd_tags_1,	/* Same as above */
	sizeof(asn_DEF_ForwardServiceInteractionInd_tags_1)
		/sizeof(asn_DEF_ForwardServiceInteractionInd_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_ForwardServiceInteractionInd_1,
	6,	/* Elements count */
	&asn_SPC_ForwardServiceInteractionInd_specs_1	/* Additional specs */
};

