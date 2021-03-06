
#pragma once

#define ENABLEUSBCONNECTION
#undef ENABLETCPCONNECTION

#include "IHostIO.h"
#include "HostIO_USB.h"
#include "HostIO_TCP.h"
#include "CameraID.h"

class HostConnection
{
public:

	HostConnection(void);
	~HostConnection(void);

	int			ListDevices(std::vector<CameraID> & vID, CameraID::ConnProto_t protocol);
	IHostIO*	GetConnection(CameraID id);
	IHostIO*	GetConnection(CameraID::ConnProto_t protocol);
	bool		ImplementsProtocol(CameraID::ConnProto_t protocol);

	int			Open( CameraID );	 // Opens device by serial number
    int			Close();			 // Closes opened device
public:
	IHostIO *	m_HostIO;
private:
	HostIO_USB	m_HostIO_USB;
	HostIO_TCP	m_HostIO_TCP;
	int			m_iStatus;
};


