#pragma once

#include "messages.hpp"

class MDCallback {
    public:
        virtual bool OnTrade(Trade& trade) = 0;
        virtual bool OnQuote(Quote& quote) = 0;
};

