/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#ifndef	_MiscCallInfo_H_
#define	_MiscCallInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum messageType {
	messageType_request	= 0,
	messageType_notification	= 1
} e_messageType;
typedef enum dpAssignment {
	dpAssignment_individualBased	= 0,
	dpAssignment_groupBased	= 1,
	dpAssignment_switchBased	= 2
} e_dpAssignment;

/* MiscCallInfo */
typedef struct MiscCallInfo {
	ENUMERATED_t	 messageType;
	ENUMERATED_t	*dpAssignment	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MiscCallInfo_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_messageType_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_dpAssignment_5;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_MiscCallInfo;

#ifdef __cplusplus
}
#endif

#endif	/* _MiscCallInfo_H_ */
#include <asn_internal.h>
