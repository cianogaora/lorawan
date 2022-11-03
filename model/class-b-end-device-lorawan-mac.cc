#include "ns3/class-b-end-device-lorawan-mac.h"
#include "ns3/end-device-lorawan-mac.h"
#include "ns3/end-device-lora-phy.h"
#include "ns3/log.h"
#include <algorithm>



using namespace ns3;
using namespace lorawan;
NS_LOG_COMPONENT_DEFINE ("ClassBEndDeviceLorawanMac");

NS_OBJECT_ENSURE_REGISTERED (ClassBEndDeviceLorawanMac);


TypeId
ClassBEndDeviceLorawanMac::GetTypeId (void)
{
static TypeId tid = TypeId ("ns3::ClassBEndDeviceLorawanMac")
  .SetParent<ClassAEndDeviceLorawanMac> ()
  .SetGroupName ("lorawan")
  .AddConstructor<ClassBEndDeviceLorawanMac> ();
return tid;
}

ClassBEndDeviceLorawanMac::ClassBEndDeviceLorawanMac () :
  // LoraWAN default
  m_receiveDelay1 (Seconds (1)),
  // LoraWAN default
  m_receiveDelay2 (Seconds (2)),
  m_rx1DrOffset (0)
{
  NS_LOG_FUNCTION (this);

  // Void the two receiveWindow events
  m_closeFirstWindow = EventId ();
  m_closeFirstWindow.Cancel ();
  m_closeSecondWindow = EventId ();
  m_closeSecondWindow.Cancel ();
  m_secondReceiveWindow = EventId ();
  m_secondReceiveWindow.Cancel ();
}

ClassBEndDeviceLorawanMac::~ClassBEndDeviceLorawanMac ()
{
  NS_LOG_FUNCTION_NOARGS ();
}

void ClassBEndDeviceLorawanMac::scheduleBeaconSlots(){
    
}

