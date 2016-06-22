/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#ifndef	_AlternativeIdentity_H_
#define	_AlternativeIdentity_H_


#include <asn_application.h>

/* Including external dependencies */
#include <IA5String.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum AlternativeIdentity_PR {
	AlternativeIdentity_PR_NOTHING,	/* No components present */
	AlternativeIdentity_PR_url
} AlternativeIdentity_PR;

/* AlternativeIdentity */
typedef struct AlternativeIdentity {
	AlternativeIdentity_PR present;
	union AlternativeIdentity_u {
		IA5String_t	 url;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AlternativeIdentity_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AlternativeIdentity;

#ifdef __cplusplus
}
#endif

#endif	/* _AlternativeIdentity_H_ */
#include <asn_internal.h>