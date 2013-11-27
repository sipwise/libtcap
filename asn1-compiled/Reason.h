/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#ifndef	_Reason_H_
#define	_Reason_H_


#include <asn_application.h>

/* Including external dependencies */
#include "P-AbortCause.h"
#include "DialoguePortion.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Reason_PR {
	Reason_PR_NOTHING,	/* No components present */
	Reason_PR_p_abortCause,
	Reason_PR_u_abortCause
} Reason_PR;

/* Reason */
typedef struct Reason {
	Reason_PR present;
	union Reason_u {
		P_AbortCause_t	 p_abortCause;
		DialoguePortion_t	 u_abortCause;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Reason_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Reason;

#ifdef __cplusplus
}
#endif

#endif	/* _Reason_H_ */
#include <asn_internal.h>
