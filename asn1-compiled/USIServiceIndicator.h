/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#ifndef	_USIServiceIndicator_H_
#define	_USIServiceIndicator_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OBJECT_IDENTIFIER.h>
#include <OCTET_STRING.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum USIServiceIndicator_PR {
	USIServiceIndicator_PR_NOTHING,	/* No components present */
	USIServiceIndicator_PR_global,
	USIServiceIndicator_PR_local
} USIServiceIndicator_PR;

/* USIServiceIndicator */
typedef struct USIServiceIndicator {
	USIServiceIndicator_PR present;
	union USIServiceIndicator_u {
		OBJECT_IDENTIFIER_t	 global;
		OCTET_STRING_t	 local;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} USIServiceIndicator_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_USIServiceIndicator;

#ifdef __cplusplus
}
#endif

#endif	/* _USIServiceIndicator_H_ */
#include <asn_internal.h>
