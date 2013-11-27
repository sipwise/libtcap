/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#include "EventTypeBCSM.h"

int
EventTypeBCSM_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	/* Replace with underlying type checker */
	td->check_constraints = asn_DEF_ENUMERATED.check_constraints;
	return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using ENUMERATED,
 * so here we adjust the DEF accordingly.
 */
static void
EventTypeBCSM_1_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
	td->free_struct    = asn_DEF_ENUMERATED.free_struct;
	td->print_struct   = asn_DEF_ENUMERATED.print_struct;
	td->ber_decoder    = asn_DEF_ENUMERATED.ber_decoder;
	td->der_encoder    = asn_DEF_ENUMERATED.der_encoder;
	td->xer_decoder    = asn_DEF_ENUMERATED.xer_decoder;
	td->xer_encoder    = asn_DEF_ENUMERATED.xer_encoder;
	td->uper_decoder   = asn_DEF_ENUMERATED.uper_decoder;
	td->uper_encoder   = asn_DEF_ENUMERATED.uper_encoder;
	if(!td->per_constraints)
		td->per_constraints = asn_DEF_ENUMERATED.per_constraints;
	td->elements       = asn_DEF_ENUMERATED.elements;
	td->elements_count = asn_DEF_ENUMERATED.elements_count;
     /* td->specifics      = asn_DEF_ENUMERATED.specifics;	// Defined explicitly */
}

void
EventTypeBCSM_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	EventTypeBCSM_1_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

int
EventTypeBCSM_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	EventTypeBCSM_1_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

asn_dec_rval_t
EventTypeBCSM_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	EventTypeBCSM_1_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

asn_enc_rval_t
EventTypeBCSM_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	EventTypeBCSM_1_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

asn_dec_rval_t
EventTypeBCSM_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	EventTypeBCSM_1_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

asn_enc_rval_t
EventTypeBCSM_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	EventTypeBCSM_1_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_INTEGER_enum_map_t asn_MAP_EventTypeBCSM_value2enum_1[] = {
	{ 1,	21,	"origAttemptAuthorized" },
	{ 2,	13,	"collectedInfo" },
	{ 3,	19,	"analysedInformation" },
	{ 4,	18,	"routeSelectFailure" },
	{ 5,	16,	"oCalledPartyBusy" },
	{ 6,	9,	"oNoAnswer" },
	{ 7,	7,	"oAnswer" },
	{ 8,	8,	"oMidCall" },
	{ 9,	11,	"oDisconnect" },
	{ 10,	8,	"oAbandon" },
	{ 12,	21,	"termAttemptAuthorized" },
	{ 13,	5,	"tBusy" },
	{ 14,	9,	"tNoAnswer" },
	{ 15,	7,	"tAnswer" },
	{ 16,	8,	"tMidCall" },
	{ 17,	11,	"tDisconnect" },
	{ 18,	8,	"tAbandon" },
	{ 19,	11,	"oTermSeized" },
	{ 20,	8,	"oSuspend" },
	{ 21,	8,	"tSuspend" },
	{ 22,	11,	"origAttempt" },
	{ 23,	11,	"termAttempt" },
	{ 24,	9,	"oReAnswer" },
	{ 25,	9,	"tReAnswer" },
	{ 26,	28,	"facilitySelectedAndAvailable" },
	{ 27,	12,	"callAccepted" },
	{ 28,	21,	"authorizeRouteFailure" },
	{ 29,	24,	"originationAttemptDenied" },
	{ 30,	24,	"terminationAttemptDenied" },
	{ 100,	14,	"oModifyRequest" },
	{ 101,	13,	"oModifyResult" },
	{ 102,	14,	"tModifyRequest" },
	{ 103,	13,	"tModifyResult" }
};
static unsigned int asn_MAP_EventTypeBCSM_enum2value_1[] = {
	2,	/* analysedInformation(3) */
	26,	/* authorizeRouteFailure(28) */
	25,	/* callAccepted(27) */
	1,	/* collectedInfo(2) */
	24,	/* facilitySelectedAndAvailable(26) */
	9,	/* oAbandon(10) */
	6,	/* oAnswer(7) */
	4,	/* oCalledPartyBusy(5) */
	8,	/* oDisconnect(9) */
	7,	/* oMidCall(8) */
	29,	/* oModifyRequest(100) */
	30,	/* oModifyResult(101) */
	5,	/* oNoAnswer(6) */
	22,	/* oReAnswer(24) */
	18,	/* oSuspend(20) */
	17,	/* oTermSeized(19) */
	20,	/* origAttempt(22) */
	0,	/* origAttemptAuthorized(1) */
	27,	/* originationAttemptDenied(29) */
	3,	/* routeSelectFailure(4) */
	16,	/* tAbandon(18) */
	13,	/* tAnswer(15) */
	11,	/* tBusy(13) */
	15,	/* tDisconnect(17) */
	14,	/* tMidCall(16) */
	31,	/* tModifyRequest(102) */
	32,	/* tModifyResult(103) */
	12,	/* tNoAnswer(14) */
	23,	/* tReAnswer(25) */
	19,	/* tSuspend(21) */
	21,	/* termAttempt(23) */
	10,	/* termAttemptAuthorized(12) */
	28	/* terminationAttemptDenied(30) */
};
static asn_INTEGER_specifics_t asn_SPC_EventTypeBCSM_specs_1 = {
	asn_MAP_EventTypeBCSM_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_EventTypeBCSM_enum2value_1,	/* N => "tag"; sorted by N */
	33,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_EventTypeBCSM_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_EventTypeBCSM = {
	"EventTypeBCSM",
	"EventTypeBCSM",
	EventTypeBCSM_free,
	EventTypeBCSM_print,
	EventTypeBCSM_constraint,
	EventTypeBCSM_decode_ber,
	EventTypeBCSM_encode_der,
	EventTypeBCSM_decode_xer,
	EventTypeBCSM_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_EventTypeBCSM_tags_1,
	sizeof(asn_DEF_EventTypeBCSM_tags_1)
		/sizeof(asn_DEF_EventTypeBCSM_tags_1[0]), /* 1 */
	asn_DEF_EventTypeBCSM_tags_1,	/* Same as above */
	sizeof(asn_DEF_EventTypeBCSM_tags_1)
		/sizeof(asn_DEF_EventTypeBCSM_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	0, 0,	/* Defined elsewhere */
	&asn_SPC_EventTypeBCSM_specs_1	/* Additional specs */
};

