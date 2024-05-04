#pragma once

#include <string>

namespace TimeLogger
{

    std::string getCurrentTime();

    void appendTimeToFile(const std::string &filePath);

}
