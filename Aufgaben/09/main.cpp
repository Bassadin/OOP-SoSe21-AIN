//
// Created by basti on 18.05.2021.
//

#include <iostream>
#include <cassert>
#include <regex>
#include <fstream>

namespace task_09 {
    std::string extract_airline(const std::string &text) {

        //https://www.fluentcpp.com/2020/02/28/c-regex-101-simple-code-for-simple-cases-with-regexes/
        const std::regex regex(R"(\"([A-Z]{2})\")");
        std::smatch matches;

        if (!std::regex_search(text, matches, regex)) //Return false if not found
            return "";

        return matches[1]; //Return second element in matches (capture group)
    }

    std::unique_ptr<std::map<std::string, int>> create_frequencies(const std::string &filename) {
        auto resultMap = std::make_unique<std::map<std::string, int>>();

        std::ifstream inputFileStream(filename, std::ifstream::in);
        assert(inputFileStream.is_open());
        std::string line;
        inputFileStream >> line; //Skip over first line

        int counter = 0;

        while (inputFileStream >> line) {
            auto extractedAirlineString = extract_airline(line);

            //https://www.techiedelight.com/increment-map-value-associated-with-key-cpp/#:~:text=Given%20an%20ordered%20or%20an,the%20key%20is%20not%20found.

            auto foundMapEntry = resultMap->find(extractedAirlineString);

            if (foundMapEntry != resultMap->end()) {
                foundMapEntry->second++;
            } else {
                resultMap->insert(std::make_pair(extractedAirlineString, 1));
            }

            std::cout << "Iteration: " << counter << std::endl;
            counter++;
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

        std::string filename = "Aufgaben/09/flights.csv";
        auto airlines = create_frequencies(filename);
        assert(airlines->at("AA") == 32729);
        int size = airlines->size();
        assert(size == 18);

        std::cout << " --- Task 2 Test passed --- " << std::endl;
    }
}

int main() {
    std::cout << "starting..." << std::endl;

    task_09::test_task_01();
    task_09::test_task_02();

    std::cout << "terminating..." << std::endl;
    return 0;
}