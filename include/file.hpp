#ifndef __FILE_HPP
#define __ FILE_HPP

#include <iostream>
#include <string>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>

class file
{
public:
    file();
    ~file();
    Json::Value json(std::string);
    auto csv();

private:
    std::string path;

};



#endif