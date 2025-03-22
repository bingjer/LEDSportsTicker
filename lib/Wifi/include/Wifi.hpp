#include "IWifi.hpp"

namespace Wifi {
class Wifi : public IWifi {
    public:
    bool connect(const char* aSSID, const char* aPassword) override;
};
} // end Wifi