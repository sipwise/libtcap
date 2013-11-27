/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "TCAPMessages"
 * 	found in "../asn1/tcap.asn"
 */

#ifndef	_ConnectArg_H_
#define	_ConnectArg_H_


#include <asn_application.h>

/* Including external dependencies */
#include "DestinationRoutingAddress.h"
#include "AlertingPattern.h"
#include "CorrelationID.h"
#include "CutAndPaste.h"
#include "ForwardingCondition.h"
#include "ISDNAccessRelatedInformation.h"
#include "OriginalCalledPartyID.h"
#include "ScfID.h"
#include "TravellingClassMark.h"
#include "Carrier.h"
#include "ServiceInteractionIndicators.h"
#include "CallingPartyNumber.h"
#include "CallingPartysCategory.h"
#include "RedirectingPartyID.h"
#include "RedirectionInformation.h"
#include "DisplayInformation.h"
#include "ForwardCallIndicators.h"
#include "ForwardGVNS.h"
#include "BackwardGVNS.h"
#include "ChargeNumber.h"
#include "CallSegmentID.h"
#include "SDSSinformation.h"
#include "CalledDirectoryNumber.h"
#include "CalledPartySubaddress.h"
#include "ConnectionIdentifier.h"
#include "GenericIdentifier.h"
#include "QoSParameter.h"
#include "CUG-Interlock.h"
#include <NULL.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RouteList;
struct GenericNumbers;
struct ServiceInteractionIndicatorsTwo;
struct Entry;
struct LegID;
struct BearerCapability;
struct BISDNParameters;
struct IPRelatedInformation;

/* ConnectArg */
typedef struct ConnectArg {
	DestinationRoutingAddress_t	 destinationRoutingAddress;
	AlertingPattern_t	*alertingPattern	/* OPTIONAL */;
	CorrelationID_t	*correlationID	/* OPTIONAL */;
	CutAndPaste_t	*cutAndPaste	/* OPTIONAL */;
	ForwardingCondition_t	*forwardingCondition	/* OPTIONAL */;
	ISDNAccessRelatedInformation_t	*iSDNAccessRelatedInformation	/* OPTIONAL */;
	OriginalCalledPartyID_t	*originalCalledPartyID	/* OPTIONAL */;
	struct RouteList	*routeList	/* OPTIONAL */;
	ScfID_t	*scfID	/* OPTIONAL */;
	TravellingClassMark_t	*travellingClassMark	/* OPTIONAL */;
	Carrier_t	*carrier	/* OPTIONAL */;
	ServiceInteractionIndicators_t	*serviceInteractionIndicators	/* OPTIONAL */;
	CallingPartyNumber_t	*callingPartyNumber	/* OPTIONAL */;
	CallingPartysCategory_t	*callingPartysCategory	/* OPTIONAL */;
	RedirectingPartyID_t	*redirectingPartyID	/* OPTIONAL */;
	RedirectionInformation_t	*redirectionInformation	/* OPTIONAL */;
	DisplayInformation_t	*displayInformation	/* OPTIONAL */;
	ForwardCallIndicators_t	*forwardCallIndicators	/* OPTIONAL */;
	struct GenericNumbers	*genericNumbers	/* OPTIONAL */;
	struct ServiceInteractionIndicatorsTwo	*serviceInteractionIndicatorsTwo	/* OPTIONAL */;
	struct Entry	*iNServiceCompatibilityResponse	/* OPTIONAL */;
	ForwardGVNS_t	*forwardGVNS	/* OPTIONAL */;
	BackwardGVNS_t	*backwardGVNS	/* OPTIONAL */;
	ChargeNumber_t	*chargeNumber	/* OPTIONAL */;
	CallSegmentID_t	*callSegmentID	/* OPTIONAL */;
	struct LegID	*legToBeCreated	/* OPTIONAL */;
	SDSSinformation_t	*sDSSinformation	/* OPTIONAL */;
	CalledDirectoryNumber_t	*calledDirectoryNumber	/* OPTIONAL */;
	struct BearerCapability	*bearerCapability	/* OPTIONAL */;
	CalledPartySubaddress_t	*calledPartySubaddress	/* OPTIONAL */;
	ConnectionIdentifier_t	*connectionIdentifier	/* OPTIONAL */;
	GenericIdentifier_t	*genericIdentifier	/* OPTIONAL */;
	QoSParameter_t	*qOSParameter	/* OPTIONAL */;
	struct BISDNParameters	*bISDNParameters	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	CUG_Interlock_t	*cug_Interlock	/* OPTIONAL */;
	NULL_t	*cug_OutgoingAccess	/* OPTIONAL */;
	struct IPRelatedInformation	*ipRelatedInformation	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ConnectArg_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ConnectArg;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RouteList.h"
#include "GenericNumbers.h"
#include "ServiceInteractionIndicatorsTwo.h"
#include "INServiceCompatibilityResponse.h"
#include "LegID.h"
#include "BearerCapability.h"
#include "BISDNParameters.h"
#include "IPRelatedInformation.h"

#endif	/* _ConnectArg_H_ */
#include <asn_internal.h>
