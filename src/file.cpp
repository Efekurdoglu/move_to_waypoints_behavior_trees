#include "../include/file.hpp"

file::file()
{

}
file::~file()
{

}

Json::Value file::json(std::string path)
{
    // Using fstream to get the file pointer in "file"
    std::ifstream file(path);
    Json::Value actual_json;
    Json::Reader reader;

    // Using reader we are parsing the Json
    reader.parse(file, actual_json);
    return actual_json;
}
// auto file::csv();
