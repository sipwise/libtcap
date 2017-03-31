/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#include "ChargeNumber.h"

int
ChargeNumber_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const LocationNumber_t *st = (const LocationNumber_t *)sptr;
	size_t size;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size;
	
	if((size >= 2 && size <= 10)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

/*
 * This type is implemented using LocationNumber,
 * so here we adjust the DEF accordingly.
 */
static void
ChargeNumber_1_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
	td->free_struct    = asn_DEF_LocationNumber.free_struct;
	td->print_struct   = asn_DEF_LocationNumber.print_struct;
	td->ber_decoder    = asn_DEF_LocationNumber.ber_decoder;
	td->der_encoder    = asn_DEF_LocationNumber.der_encoder;
	td->xer_decoder    = asn_DEF_LocationNumber.xer_decoder;
	td->xer_encoder    = asn_DEF_LocationNumber.xer_encoder;
	td->uper_decoder   = asn_DEF_LocationNumber.uper_decoder;
	td->uper_encoder   = asn_DEF_LocationNumber.uper_encoder;
	if(!td->per_constraints)
		td->per_constraints = asn_DEF_LocationNumber.per_constraints;
	td->elements       = asn_DEF_LocationNumber.elements;
	td->elements_count = asn_DEF_LocationNumber.elements_count;
	td->specifics      = asn_DEF_LocationNumber.specifics;
}

void
ChargeNumber_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	ChargeNumber_1_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

int
ChargeNumber_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	ChargeNumber_1_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

asn_dec_rval_t
ChargeNumber_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	ChargeNumber_1_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

asn_enc_rval_t
ChargeNumber_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	ChargeNumber_1_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

asn_dec_rval_t
ChargeNumber_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	ChargeNumber_1_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

asn_enc_rval_t
ChargeNumber_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	ChargeNumber_1_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static ber_tlv_tag_t asn_DEF_ChargeNumber_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (4 << 2))
};
asn_TYPE_descriptor_t asn_DEF_ChargeNumber = {
	"ChargeNumber",
	"ChargeNumber",
	ChargeNumber_free,
	ChargeNumber_print,
	ChargeNumber_constraint,
	ChargeNumber_decode_ber,
	ChargeNumber_encode_der,
	ChargeNumber_decode_xer,
	ChargeNumber_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_ChargeNumber_tags_1,
	sizeof(asn_DEF_ChargeNumber_tags_1)
		/sizeof(asn_DEF_ChargeNumber_tags_1[0]), /* 1 */
	asn_DEF_ChargeNumber_tags_1,	/* Same as above */
	sizeof(asn_DEF_ChargeNumber_tags_1)
		/sizeof(asn_DEF_ChargeNumber_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	0, 0,	/* No members */
	0	/* No specifics */
};
