// #include <iostream>
// #include <fstream>
// #include "inc/func.hpp"
// #include <chrono>
// #include <ctime>

// namespace TimeLogger



//     void logStartTime(const std::string &filePath)
//     {
//         std::ofstream file(filePath, std::ios::app);
//         if (file.is_open())
//         {
//             int RunNumber = 0;
//             std::ifstream inputFile(filePath);
//             if (inputFile.is_open())
//             {
//                 std::string line;
//                 while (std::getline(inputFile, line))
//                 {
//                     RunNumber++;
//                 }
//                 inputFile.close();
//             }

//             file << RunNumber + 1 << " " << getCurrentTime();
//             file.close();
//         }
//         else
//         {
//             std::cout << "Unable to open file: " << filePath << std::endl;
//         }
//     }

//     std::string getCurrentTime() {}

//     void appendTimeToFile(const std::string &filePath)
//     {
//     }
// }
#include <func.hpp>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

namespace TimeLogger {

    std::string getCurrentTime() {
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        return std::ctime(&currentTime);
    }

    void logStartTime(const std::string& filePath) {
        std::ofstream file(filePath, std::ios::app);
        if (file.is_open()) {
            // Îïðåäåëÿåì òåêóùèé íîìåð çàïóñêà
            int currentRunNumber = 0;
            std::ifstream inputFile(filePath);
            if (inputFile.is_open()) {
                std::string line;
                while (std::getline(inputFile, line)) {
                    currentRunNumber++;
                }
                inputFile.close();
            }

            // Çàïèñûâàåì â ôàéë èíôîðìàöèþ î çàïóñêå
            file << currentRunNumber + 1 << " " << getCurrentTime();
            file.close();
        }
        else {
            std::cout << "Unable to open file: " << filePath << std::endl;
        }
    }

}