/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#ifndef	_CallingPartyBusinessGroupID_H_
#define	_CallingPartyBusinessGroupID_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* CallingPartyBusinessGroupID */
typedef OCTET_STRING_t	 CallingPartyBusinessGroupID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CallingPartyBusinessGroupID;
asn_struct_free_f CallingPartyBusinessGroupID_free;
asn_struct_print_f CallingPartyBusinessGroupID_print;
asn_constr_check_f CallingPartyBusinessGroupID_constraint;
ber_type_decoder_f CallingPartyBusinessGroupID_decode_ber;
der_type_encoder_f CallingPartyBusinessGroupID_encode_der;
xer_type_decoder_f CallingPartyBusinessGroupID_decode_xer;
xer_type_encoder_f CallingPartyBusinessGroupID_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _CallingPartyBusinessGroupID_H_ */
#include <asn_internal.h>
