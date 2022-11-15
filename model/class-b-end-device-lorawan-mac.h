#ifndef LORAWAN_CLASS_B_LORAWAN_END_DEVICE_MAC_H
#define LORAWAN_CLASS_B_LORAWAN_END_DEVICE_MAC_H
#include "ns3/lorawan-mac.h"                // Packet
#include "ns3/end-device-lorawan-mac.h"     // EndDeviceLorawanMac
#include "ns3/lora-frame-header.h"          // RxParamSetupReq
// #include "ns3/random-variable-stream.h"
#include "ns3/lora-device-address.h"
#include "ns3/class-a-end-device-lorawan-mac.h"

namespace ns3 {
    namespace lorawan {
        class ClassBEndDeviceLorawanMac : public ClassAEndDeviceLorawanMac{

        public:
            static TypeId GetTypeId (void);

            ClassBEndDeviceLorawanMac ();
            virtual ~ClassBEndDeviceLorawanMac ();

            void scheduleBeaconSlots(Time interval);
            void receiveBeacon();

        private:
            Time m_receiveDelay1;
            Time m_receiveDelay2;

            EventId m_closeFirstWindow;
            EventId m_closeSecondWindow;
            EventId m_secondReceiveWindow;
            EventId m_openBeaconSlot;

            double m_secondReceiveWindowFrequency;

            uint8_t m_secondReceiveWindowDataRate;
            uint8_t m_rx1DrOffset;


        };

    }
}


#endif //LORAWAN_CLASS_B_LORAWAN_END_DEVICE_MAC_H
