#pragma once
#include <memory>
#include "WS_Lite.h"

namespace SL {
    namespace WS_LITE {
        struct WSocket;
    };
	namespace RAT {
        enum class PACKET_TYPES : unsigned int {
            INVALID,
            HTTP_MSG,
            MONITORINFO,
            SCREENIMAGEDIF,
            MOUSEPOS,
            MOUSEIMAGE,
            KEYEVENT,
            MOUSEEVENT,
            CLIPBOARDTEXTEVENT,
            //use LAST_PACKET_TYPE as the starting point of your custom packet types. Everything before this is used internally by the library
            LAST_PACKET_TYPE
        };
		class INetworkHandlers {
		public:
			virtual ~INetworkHandlers() {}

			virtual void onConnection(const WS_LITE::WSocket& socket) = 0;
			virtual void onMessage(const WS_LITE::WSocket&, const WS_LITE::WSMessage& msg) = 0;
			virtual void onDisconnection(const WS_LITE::WSocket&, unsigned short code, const std::string& msg) = 0;
		};
	}
}
