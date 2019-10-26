#pragma once

#include <string>


//TODO: you will need to find some way to get the data into these classes.
// You can add to them, but the public getters need to remain as is.


/**
 * for this task you will probably *not* need to edit the Quote object.
 */
class Quote{
    public:
        int GetBidSize();
        int GetAskSize();
        float GetBidPrice();
        float GetAskPrice();
        std::string GetSymbol();
    private:
};

/**
 * We till expect to get some data out of this class to pass the unit tests.
 * You will likley have to make some changes here.
 */
class Trade{
    public:
        int GetLastSize() const;
        float GetLastPrice() const;
        std::string GetSymbol() const;

};


