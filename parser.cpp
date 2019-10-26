
#include <iostream>
#include "parser.hpp"
#include <arpa/inet.h>


using namespace std;

/**
 * The Parser takes a string path to the data input file to parse.  You can 
 * assume it is formatted correctly, but extra points for being skeptical.
 */
Parser::Parser(std::string infileStr) {
    //Implement your constructor for this parser here.  You will have to iterate
    //the contents of the file passed in.
}

Parser::~Parser(){
    //Implement your destructor for this parser here.
}

/**
 *Here you will be called with a callback asking for the next message.  Make 
 * one call back to the to the correct method of the interface MDCallback.  
 */
bool Parser::GetMessagesInPacket(MDCallback& callback){
    //TODO: IMPLEMENT ME
    return false;
}


