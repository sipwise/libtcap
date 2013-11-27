/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#ifndef	_OPERATION_H_
#define	_OPERATION_H_


#include <asn_application.h>

/* Including external dependencies */
#include <INTEGER.h>
#include <OBJECT_IDENTIFIER.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum OPERATION_PR {
	OPERATION_PR_NOTHING,	/* No components present */
	OPERATION_PR_localValue,
	OPERATION_PR_globalValue
} OPERATION_PR;

/* OPERATION */
typedef struct OPERATION {
	OPERATION_PR present;
	union OPERATION_u {
		INTEGER_t	 localValue;
		OBJECT_IDENTIFIER_t	 globalValue;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} OPERATION_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_OPERATION;

#ifdef __cplusplus
}
#endif

#endif	/* _OPERATION_H_ */
#include <asn_internal.h>
