
#pragma once
#include "etl/string_view.h"

class SportsData {
    private:
        etl::string_view mUrl;
    public:
        SportsData();
        SportsData(etl::string_view aAPIEndpoint);
        void getData();
};