
#pragma once
#include <string>

namespace Wifi {

    class IWifi {
        public:
        virtual bool connect(const char* aSSID, const char* aPassword) = 0;
    };
} // end Wifi