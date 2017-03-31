/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#ifndef	_CCSS_H_
#define	_CCSS_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BOOLEAN.h>

#ifdef __cplusplus
extern "C" {
#endif

/* CCSS */
typedef BOOLEAN_t	 CCSS_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CCSS;
asn_struct_free_f CCSS_free;
asn_struct_print_f CCSS_print;
asn_constr_check_f CCSS_constraint;
ber_type_decoder_f CCSS_decode_ber;
der_type_encoder_f CCSS_encode_der;
xer_type_decoder_f CCSS_decode_xer;
xer_type_encoder_f CCSS_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _CCSS_H_ */
#include <asn_internal.h>