/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#ifndef	_ExternalPDU_H_
#define	_ExternalPDU_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OBJECT_IDENTIFIER.h>
#include "DialoguePDU.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ExternalPDU */
typedef struct ExternalPDU {
	OBJECT_IDENTIFIER_t	 oid;
	DialoguePDU_t	 dialog;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ExternalPDU_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ExternalPDU;

#ifdef __cplusplus
}
#endif

#endif	/* _ExternalPDU_H_ */
#include <asn_internal.h>
