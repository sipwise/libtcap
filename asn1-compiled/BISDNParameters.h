/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#ifndef	_BISDNParameters_H_
#define	_BISDNParameters_H_


#include <asn_application.h>

/* Including external dependencies */
#include "AALParameters.h"
#include "AdditionalATMCellRate.h"
#include "AESACalledParty.h"
#include "AESACallingParty.h"
#include "AlternativeATMTrafficDescriptor.h"
#include "ATMCellRate.h"
#include "CDVTDescriptor.h"
#include "CumulativeTransitDelay.h"
#include "EndToEndTransitDelay.h"
#include "MinAcceptableATMTrafficDescriptor.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* BISDNParameters */
typedef struct BISDNParameters {
	AALParameters_t	*aALParameters	/* OPTIONAL */;
	AdditionalATMCellRate_t	*additionalATMCellRate	/* OPTIONAL */;
	AESACalledParty_t	*aESACalledParty	/* OPTIONAL */;
	AESACallingParty_t	*aESACallingParty	/* OPTIONAL */;
	AlternativeATMTrafficDescriptor_t	*alternativeATMTrafficDescriptor	/* OPTIONAL */;
	ATMCellRate_t	*aTMCellRate	/* OPTIONAL */;
	CDVTDescriptor_t	*cDVTDescriptor	/* OPTIONAL */;
	CumulativeTransitDelay_t	*cumulativeTransitDelay	/* OPTIONAL */;
	EndToEndTransitDelay_t	*endToEndTransitDelay	/* OPTIONAL */;
	MinAcceptableATMTrafficDescriptor_t	*minAcceptableATMTrafficDescriptor	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} BISDNParameters_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_BISDNParameters;

#ifdef __cplusplus
}
#endif

#endif	/* _BISDNParameters_H_ */
#include <asn_internal.h>
