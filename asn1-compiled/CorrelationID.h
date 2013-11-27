/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#ifndef	_CorrelationID_H_
#define	_CorrelationID_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Digits.h"

#ifdef __cplusplus
extern "C" {
#endif

/* CorrelationID */
typedef Digits_t	 CorrelationID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CorrelationID;
asn_struct_free_f CorrelationID_free;
asn_struct_print_f CorrelationID_print;
asn_constr_check_f CorrelationID_constraint;
ber_type_decoder_f CorrelationID_decode_ber;
der_type_encoder_f CorrelationID_encode_der;
xer_type_decoder_f CorrelationID_decode_xer;
xer_type_encoder_f CorrelationID_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _CorrelationID_H_ */
#include <asn_internal.h>
