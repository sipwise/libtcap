/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#ifndef	_CNInfo_H_
#define	_CNInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* CNInfo */
typedef OCTET_STRING_t	 CNInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CNInfo;
asn_struct_free_f CNInfo_free;
asn_struct_print_f CNInfo_print;
asn_constr_check_f CNInfo_constraint;
ber_type_decoder_f CNInfo_decode_ber;
der_type_encoder_f CNInfo_encode_der;
xer_type_decoder_f CNInfo_decode_xer;
xer_type_encoder_f CNInfo_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _CNInfo_H_ */
#include <asn_internal.h>
