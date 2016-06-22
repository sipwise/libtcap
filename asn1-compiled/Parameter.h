/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#ifndef	_Parameter_H_
#define	_Parameter_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ANY.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Parameter */
typedef ANY_t	 Parameter_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Parameter;
asn_struct_free_f Parameter_free;
asn_struct_print_f Parameter_print;
asn_constr_check_f Parameter_constraint;
ber_type_decoder_f Parameter_decode_ber;
der_type_encoder_f Parameter_encode_der;
xer_type_decoder_f Parameter_decode_xer;
xer_type_encoder_f Parameter_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _Parameter_H_ */
#include <asn_internal.h>