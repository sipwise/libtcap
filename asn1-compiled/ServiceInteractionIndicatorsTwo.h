/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#ifndef	_ServiceInteractionIndicatorsTwo_H_
#define	_ServiceInteractionIndicatorsTwo_H_


#include <asn_application.h>

/* Including external dependencies */
#include "BothwayThroughConnectionInd.h"
#include "SuspendTimer.h"
#include "ConnectedNumberTreatmentInd.h"
#include <BOOLEAN.h>
#include <NULL.h>
#include "RedirectReason.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ForwardServiceInteractionInd;
struct BackwardServiceInteractionInd;

/* ServiceInteractionIndicatorsTwo */
typedef struct ServiceInteractionIndicatorsTwo {
	struct ForwardServiceInteractionInd	*forwardServiceInteractionInd	/* OPTIONAL */;
	struct BackwardServiceInteractionInd	*backwardServiceInteractionInd	/* OPTIONAL */;
	BothwayThroughConnectionInd_t	*bothwayThroughConnectionInd	/* OPTIONAL */;
	SuspendTimer_t	*suspendTimer	/* OPTIONAL */;
	ConnectedNumberTreatmentInd_t	*connectedNumberTreatmentInd	/* OPTIONAL */;
	BOOLEAN_t	*suppressCallDiversionNotification	/* OPTIONAL */;
	BOOLEAN_t	*suppressCallTransferNotification	/* OPTIONAL */;
	BOOLEAN_t	*allowCdINNoPresentationInd	/* OPTIONAL */;
	BOOLEAN_t	*userDialogueDurationInd	/* DEFAULT TRUE */;
	BOOLEAN_t	*overrideLineRestrictions	/* DEFAULT FALSE */;
	BOOLEAN_t	*suppressVPNAPP	/* DEFAULT FALSE */;
	BOOLEAN_t	*calledINNumberOverriding	/* OPTIONAL */;
	struct redirectServiceTreatmentInd {
		RedirectReason_t	*redirectReason	/* OPTIONAL */;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *redirectServiceTreatmentInd;
	NULL_t	*nonCUGCall	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ServiceInteractionIndicatorsTwo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ServiceInteractionIndicatorsTwo;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ForwardServiceInteractionInd.h"
#include "BackwardServiceInteractionInd.h"

#endif	/* _ServiceInteractionIndicatorsTwo_H_ */
#include <asn_internal.h>
