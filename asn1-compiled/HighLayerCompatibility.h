/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#ifndef	_HighLayerCompatibility_H_
#define	_HighLayerCompatibility_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* HighLayerCompatibility */
typedef OCTET_STRING_t	 HighLayerCompatibility_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_HighLayerCompatibility;
asn_struct_free_f HighLayerCompatibility_free;
asn_struct_print_f HighLayerCompatibility_print;
asn_constr_check_f HighLayerCompatibility_constraint;
ber_type_decoder_f HighLayerCompatibility_decode_ber;
der_type_encoder_f HighLayerCompatibility_encode_der;
xer_type_decoder_f HighLayerCompatibility_decode_xer;
xer_type_encoder_f HighLayerCompatibility_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _HighLayerCompatibility_H_ */
#include <asn_internal.h>
