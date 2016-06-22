/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#ifndef	_EventTypeBCSM_H_
#define	_EventTypeBCSM_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum EventTypeBCSM {
	EventTypeBCSM_origAttemptAuthorized	= 1,
	EventTypeBCSM_collectedInfo	= 2,
	EventTypeBCSM_analysedInformation	= 3,
	EventTypeBCSM_routeSelectFailure	= 4,
	EventTypeBCSM_oCalledPartyBusy	= 5,
	EventTypeBCSM_oNoAnswer	= 6,
	EventTypeBCSM_oAnswer	= 7,
	EventTypeBCSM_oMidCall	= 8,
	EventTypeBCSM_oDisconnect	= 9,
	EventTypeBCSM_oAbandon	= 10,
	EventTypeBCSM_termAttemptAuthorized	= 12,
	EventTypeBCSM_tBusy	= 13,
	EventTypeBCSM_tNoAnswer	= 14,
	EventTypeBCSM_tAnswer	= 15,
	EventTypeBCSM_tMidCall	= 16,
	EventTypeBCSM_tDisconnect	= 17,
	EventTypeBCSM_tAbandon	= 18,
	EventTypeBCSM_oTermSeized	= 19,
	EventTypeBCSM_oSuspend	= 20,
	EventTypeBCSM_tSuspend	= 21,
	EventTypeBCSM_origAttempt	= 22,
	EventTypeBCSM_termAttempt	= 23,
	EventTypeBCSM_oReAnswer	= 24,
	EventTypeBCSM_tReAnswer	= 25,
	EventTypeBCSM_facilitySelectedAndAvailable	= 26,
	EventTypeBCSM_callAccepted	= 27,
	EventTypeBCSM_authorizeRouteFailure	= 28,
	EventTypeBCSM_originationAttemptDenied	= 29,
	EventTypeBCSM_terminationAttemptDenied	= 30,
	EventTypeBCSM_oModifyRequest	= 100,
	EventTypeBCSM_oModifyResult	= 101,
	EventTypeBCSM_tModifyRequest	= 102,
	EventTypeBCSM_tModifyResult	= 103
} e_EventTypeBCSM;

/* EventTypeBCSM */
typedef ENUMERATED_t	 EventTypeBCSM_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_EventTypeBCSM;
asn_struct_free_f EventTypeBCSM_free;
asn_struct_print_f EventTypeBCSM_print;
asn_constr_check_f EventTypeBCSM_constraint;
ber_type_decoder_f EventTypeBCSM_decode_ber;
der_type_encoder_f EventTypeBCSM_encode_der;
xer_type_decoder_f EventTypeBCSM_decode_xer;
xer_type_encoder_f EventTypeBCSM_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _EventTypeBCSM_H_ */
#include <asn_internal.h>