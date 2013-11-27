/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#ifndef	_EndToEndTransitDelay_H_
#define	_EndToEndTransitDelay_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* EndToEndTransitDelay */
typedef OCTET_STRING_t	 EndToEndTransitDelay_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_EndToEndTransitDelay;
asn_struct_free_f EndToEndTransitDelay_free;
asn_struct_print_f EndToEndTransitDelay_print;
asn_constr_check_f EndToEndTransitDelay_constraint;
ber_type_decoder_f EndToEndTransitDelay_decode_ber;
der_type_encoder_f EndToEndTransitDelay_encode_der;
xer_type_decoder_f EndToEndTransitDelay_decode_xer;
xer_type_encoder_f EndToEndTransitDelay_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _EndToEndTransitDelay_H_ */
#include <asn_internal.h>
