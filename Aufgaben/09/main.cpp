//
// Created by basti on 18.05.2021.
//

#include <iostream>
#include <cassert>
#include <regex>
#include <fstream>

namespace task_09 {
    std::string extract_airline(const std::string& text) {

        const std::regex regex(R"(\"([A-Z]{2})\")");
        std::smatch matches;

        if (!std::regex_search(text, matches, regex)) //Return false if not found
            return "";

        return matches[1]; //Return second element in matches (capture group)
    }

    std::map<std::string, int> create_frequencies(const std::string& filename) {
        auto resultMap = std::map<std::string, int>();

        std::ifstream inputFileStream(filename);
        assert(inputFileStream.is_open());
        std::string line;
        while (inputFileStream >> line){
            std::cout<<line<<std::endl;
            //TODO
        }
        inputFileStream.close();

        return resultMap;
    }

    void test_task_01() {
        std::string exampleString1 = R"(2013,1,1,542,540,2,923,850,33,"AA",1141,"N619AA","JFK","MIA",160,1089,5,40,2013-01-01 05:00:00)";
        assert(extract_airline(exampleString1) == "AA");

        std::string exampleString2 = R"(2013,1,1,542,540,2,923,850,33,"BC",1141,"N619AA","JFK","MIA",160,1089,5,40,2013-01-01 05:00:00)";
        assert(extract_airline(exampleString2) == "BC");

        std::string exampleString3 = R"(2013,1,1,542,540,2,923,850,33,"ZE",1141,"N619AA","JFK","MIA",160,1089,5,40,2013-01-01 05:00:00)";
        assert(extract_airline(exampleString3) == "ZE");
        std::cout << " --- Task 1 Test passed --- " << std::endl;
    }

    void test_task_02() {

        std::string filename="flights.csv";
        auto airlines=create_frequencies(filename);
        assert(airlines["AA"]=32729);
        int size=airlines.size();
        assert(size==18);

        std::cout << " --- Task 2 Test passed --- " << std::endl;
    }
}

int main() {
    std::cout << "starting..." << std::endl;

    task_09::test_task_01();

    std::cout << "terminating..." << std::endl;
    return 0;
}