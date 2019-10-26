#include <iostream>
#include <gtest/gtest.h>
#include <memory>
#include <string>

#include "messages.hpp"
#include "parser.hpp"
#include "reader.hpp"

using namespace std;


//TODO: Here is your implementation of MDCallback
class MyCallback : public MDCallback {
    public:
        //begin your interface from MDCallback
        bool OnTrade(Trade& trade);
        bool OnQuote(Quote& quote);
    public:
        explicit MyCallback();
        virtual ~MyCallback();
        uint32_t getTradeCount();
        uint32_t getQuoteCount();
        uint32_t getSymbolCount();
        uint32_t getSymbolCount(string Symbol);
    private:
        uint32_t quoteCount;
        //TODO: Add some state in here to track your metrics.

};

bool MyCallback::OnTrade(Trade& trade){
    //TODO: IMPLEMENT ME
    return true;
}

//left as a hint to the applicant
bool MyCallback::OnQuote(Quote& quote){
    quoteCount++;
    return true;
}

/////////////////////IMPLEMENTATION///////////////////////////
uint32_t MyCallback::getSymbolCount(string symbol){
    //TODO: IMPLEMENT ME
    return 0;
}

uint32_t MyCallback::getSymbolCount(){
    //TODO: IMPLEMENT ME
    return 0;
}

uint32_t MyCallback::getTradeCount(){
    //TODO: IMPLEMENT ME
    return 0;
}

uint32_t MyCallback::getQuoteCount(){
    //left as a hint to the applicant
    return this->quoteCount;
}

MyCallback::~MyCallback(){
    //TODO: Clean up any resources
}
////////////////////////////////////////////////////////////////
MyCallback::MyCallback(): quoteCount(0)
{
    //TODO: Initialize your state
}


//BEGIN TESTS. YOU NEED TO MAKE SURE THESE WORK, We know that 
//the given imput file has the following properties.  If your 
//parser is correct, you will have...
//  12527 Trade Messages
//  12536 Quote Messages
//  2520 CMCSA Trades
//  2492 S Trades
//  2534 AAPL Trades
//  2554 GOOG Trades
//  2427 BA Trades
//  
class FilterTest : public ::testing::Test {
    protected:
        virtual void SetUp(){
            parser = unique_ptr<Parser>(new Parser("../data/data.in"));
        }
        virtual void TearDown() {
        }
    public:
        unique_ptr<Parser> parser;
};

TEST_F(FilterTest, CheckCounts){
    MyCallback cb;
    while(parser->GetMessagesInPacket(cb));
    EXPECT_EQ(12527, cb.getTradeCount());
    EXPECT_EQ(12536, cb.getQuoteCount());
}

TEST_F(FilterTest, CheckTotalSymbols){
    MyCallback cb;
    while(parser->GetMessagesInPacket(cb));
    EXPECT_EQ(5, cb.getSymbolCount());
}

TEST_F(FilterTest, CheckSymbolCounts){
    MyCallback cb;
    while(parser->GetMessagesInPacket(cb));
    EXPECT_EQ(2520, cb.getSymbolCount("CMCSA"));
    EXPECT_EQ(2492, cb.getSymbolCount("S"));
    EXPECT_EQ(2534, cb.getSymbolCount("AAPL"));
    EXPECT_EQ(2554, cb.getSymbolCount("GOOG"));
    EXPECT_EQ(2427, cb.getSymbolCount("BA"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
