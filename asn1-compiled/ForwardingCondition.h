/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#ifndef	_ForwardingCondition_H_
#define	_ForwardingCondition_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ForwardingCondition {
	ForwardingCondition_busy	= 0,
	ForwardingCondition_noanswer	= 1,
	ForwardingCondition_any	= 2
} e_ForwardingCondition;

/* ForwardingCondition */
typedef ENUMERATED_t	 ForwardingCondition_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ForwardingCondition;
asn_struct_free_f ForwardingCondition_free;
asn_struct_print_f ForwardingCondition_print;
asn_constr_check_f ForwardingCondition_constraint;
ber_type_decoder_f ForwardingCondition_decode_ber;
der_type_encoder_f ForwardingCondition_encode_der;
xer_type_decoder_f ForwardingCondition_decode_xer;
xer_type_encoder_f ForwardingCondition_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _ForwardingCondition_H_ */
#include <asn_internal.h>