/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#ifndef	_InitialDPArg_H_
#define	_InitialDPArg_H_


#include <asn_application.h>

/* Including external dependencies */
#include "ServiceKey.h"
#include "CalledPartyNumber.h"
#include "CallingPartyNumber.h"
#include "CallingPartyBusinessGroupID.h"
#include "CallingPartysCategory.h"
#include "CallingPartySubaddress.h"
#include "CGEncountered.h"
#include "IPSSPCapabilities.h"
#include "IPAvailable.h"
#include "LocationNumber.h"
#include "OriginalCalledPartyID.h"
#include "ServiceProfileIdentifier.h"
#include "TerminalType.h"
#include "TriggerType.h"
#include "HighLayerCompatibility.h"
#include "ServiceInteractionIndicators.h"
#include "AdditionalCallingPartyNumber.h"
#include "ForwardCallIndicators.h"
#include "EventTypeBCSM.h"
#include "RedirectingPartyID.h"
#include "RedirectionInformation.h"
#include "Cause.h"
#include "ComponentType.h"
#include "ComponentCorrelationID.h"
#include "ISDNAccessRelatedInformation.h"
#include "ForwardGVNS.h"
#include "CSAID.h"
#include "USIInformation.h"
#include "Carrier.h"
#include "CCSS.h"
#include "VPNIndicator.h"
#include "CNInfo.h"
#include "CallReference.h"
#include "RouteingNumber.h"
#include "CallingGeodeticLocation.h"
#include "CalledPartySubaddress.h"
#include "ConnectionIdentifier.h"
#include "GenericIdentifier.h"
#include "QoSParameter.h"
#include "GlobalCallReference.h"
#include "CUG-Index.h"
#include "CUG-Interlock.h"
#include <NULL.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct MiscCallInfo;
struct BearerCapability;
struct Component;
struct INServiceCompatibilityIndication;
struct GenericNumbers;
struct ServiceInteractionIndicatorsTwo;
struct USIServiceIndicator;
struct BISDNParameters;
struct IPRelatedInformation;

/* InitialDPArg */
typedef struct InitialDPArg {
	ServiceKey_t	*serviceKey	/* OPTIONAL */;
	CalledPartyNumber_t	*dialledDigits	/* OPTIONAL */;
	CalledPartyNumber_t	*calledPartyNumber	/* OPTIONAL */;
	CallingPartyNumber_t	*callingPartyNumber	/* OPTIONAL */;
	CallingPartyBusinessGroupID_t	*callingPartyBusinessGroupID	/* OPTIONAL */;
	CallingPartysCategory_t	*callingPartysCategory	/* OPTIONAL */;
	CallingPartySubaddress_t	*callingPartySubaddress	/* OPTIONAL */;
	CGEncountered_t	*cGEncountered	/* OPTIONAL */;
	IPSSPCapabilities_t	*iPSSPCapabilities	/* OPTIONAL */;
	IPAvailable_t	*iPAvailable	/* OPTIONAL */;
	LocationNumber_t	*locationNumber	/* OPTIONAL */;
	struct MiscCallInfo	*miscCallInfo	/* OPTIONAL */;
	OriginalCalledPartyID_t	*originalCalledPartyID	/* OPTIONAL */;
	ServiceProfileIdentifier_t	*serviceProfileIdentifier	/* OPTIONAL */;
	TerminalType_t	*terminalType	/* OPTIONAL */;
	TriggerType_t	*triggerType	/* OPTIONAL */;
	HighLayerCompatibility_t	*highLayerCompatibility	/* OPTIONAL */;
	ServiceInteractionIndicators_t	*serviceInteractionIndicators	/* OPTIONAL */;
	AdditionalCallingPartyNumber_t	*additionalCallingPartyNumber	/* OPTIONAL */;
	ForwardCallIndicators_t	*forwardCallIndicators	/* OPTIONAL */;
	struct BearerCapability	*bearerCapability	/* OPTIONAL */;
	EventTypeBCSM_t	*eventTypeBCSM	/* OPTIONAL */;
	RedirectingPartyID_t	*redirectingPartyID	/* OPTIONAL */;
	RedirectionInformation_t	*redirectionInformation	/* OPTIONAL */;
	Cause_t	*cause	/* OPTIONAL */;
	ComponentType_t	*componentType	/* OPTIONAL */;
	struct Component	*component	/* OPTIONAL */;
	ComponentCorrelationID_t	*componentCorrelationID	/* OPTIONAL */;
	ISDNAccessRelatedInformation_t	*iSDNAccessRelatedInformation	/* OPTIONAL */;
	struct INServiceCompatibilityIndication	*iNServiceCompatibilityIndication	/* OPTIONAL */;
	struct GenericNumbers	*genericNumbers	/* OPTIONAL */;
	struct ServiceInteractionIndicatorsTwo	*serviceInteractionIndicatorsTwo	/* OPTIONAL */;
	ForwardGVNS_t	*forwardGVNS	/* OPTIONAL */;
	CSAID_t	*createdCallSegmentAssociation	/* OPTIONAL */;
	struct USIServiceIndicator	*uSIServiceIndicator	/* OPTIONAL */;
	USIInformation_t	*uSIInformation	/* OPTIONAL */;
	Carrier_t	*carrier	/* OPTIONAL */;
	CCSS_t	*cCSS	/* OPTIONAL */;
	VPNIndicator_t	*vPNIndicator	/* OPTIONAL */;
	CNInfo_t	*cNInfo	/* OPTIONAL */;
	CallReference_t	*callReference	/* OPTIONAL */;
	RouteingNumber_t	*routeingNumber	/* OPTIONAL */;
	CallingGeodeticLocation_t	*callingGeodeticLocation	/* OPTIONAL */;
	CalledPartySubaddress_t	*calledPartySubaddress	/* OPTIONAL */;
	ConnectionIdentifier_t	*connectionIdentifier	/* OPTIONAL */;
	GenericIdentifier_t	*genericIdentifier	/* OPTIONAL */;
	QoSParameter_t	*qOSParameter	/* OPTIONAL */;
	struct BISDNParameters	*bISDNParameters	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	GlobalCallReference_t	*globalCallReference	/* OPTIONAL */;
	CUG_Index_t	*cug_Index	/* OPTIONAL */;
	CUG_Interlock_t	*cug_Interlock	/* OPTIONAL */;
	NULL_t	*cug_OutgoingAccess	/* OPTIONAL */;
	struct IPRelatedInformation	*ipRelatedInformation	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} InitialDPArg_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_InitialDPArg;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "MiscCallInfo.h"
#include "BearerCapability.h"
#include "Component.h"
#include "INServiceCompatibilityIndication.h"
#include "GenericNumbers.h"
#include "ServiceInteractionIndicatorsTwo.h"
#include "USIServiceIndicator.h"
#include "BISDNParameters.h"
#include "IPRelatedInformation.h"

#endif	/* _InitialDPArg_H_ */
#include <asn_internal.h>