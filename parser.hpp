#pragma once

#include <string>
#include "messages.hpp"
#include "reader.hpp"

#include <fstream>

class Parser{
    public:
        explicit Parser(std::string infileStr);
        ~Parser();
        bool GetMessagesInPacket(MDCallback& callback);
    private:
        //Here you will need to save you state.
};
    
