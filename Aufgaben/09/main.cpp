//
// Created by basti on 18.05.2021.
//

#include <iostream>
#include <cassert>
#include <regex>
#include <fstream>
#include <chrono>

namespace task_09 {
    //RegEx seems to be extremely slow
    /*std::string extract_airline(const std::string &text) {

        //https://www.fluentcpp.com/2020/02/28/c-regex-101-simple-code-for-simple-cases-with-regexes/
        const std::regex regex(R"(,\"([A-Z0-9]{2})\")");
        std::smatch matches;

        if (!std::regex_search(text, matches, regex)) //Return false if not found
            return "";

        return matches[2]; //Return second element in matches (2nd capture group)
    }*/

    //Non-Regex Variant
    std::string extract_airline(const std::string &row) {
        auto indexOfFirstParentheses = row.find('"', 20);
        auto indexOfLastParentheses = row.find('"', indexOfFirstParentheses + 1);
        return row.substr(indexOfFirstParentheses + 1, indexOfLastParentheses - indexOfFirstParentheses - 1);
    }

    std::unique_ptr<std::map<std::string, int>> create_frequencies(const std::string &filename) {
        auto resultMap = std::make_unique<std::map<std::string, int>>();

        std::ifstream inputFileStream(filename, std::ifstream::in);
        assert(inputFileStream.is_open());
        std::string line;
        std::getline(inputFileStream, line); //Skip over first line

        int currentLineCounter = 1;

        //while (inputFileStream >> line) {
        while (std::getline(inputFileStream, line)) {
            auto extractedAirlineString = extract_airline(line);

            if (extractedAirlineString != "") {
                //https://www.techiedelight.com/increment-map-value-associated-with-key-cpp/#:~:text=Given%20an%20ordered%20or%20an,the%20key%20is%20not%20found.
                auto foundMapEntry = resultMap->find(extractedAirlineString);
                if (foundMapEntry != resultMap->end()) {
                    foundMapEntry->second++;
                } else {
                    resultMap->insert(std::make_pair(extractedAirlineString, 1));
                }
            }

            if (currentLineCounter % 10000 == 0) {
                std::cout << "Current line: " << currentLineCounter << std::endl;
            }
            currentLineCounter++;
        }

        inputFileStream.close();

        return resultMap;
    }

    void test_task_01() {
        std::string exampleString1 = R"(2013,1,1,542,540,2,923,850,33,"AA",1141,"N619AA","JFK","MIA",160,1089,5,40,2013-01-01 05:00:00)";
        std::cout << extract_airline(exampleString1) << std::endl;
        assert(extract_airline(exampleString1) == "AA");

        std::string exampleString2 = R"(2013,1,1,542,540,2,923,850,33,"BC",1141,"N619AA","JFK","MIA",160,1089,5,40,2013-01-01 05:00:00)";
        assert(extract_airline(exampleString2) == "BC");

        std::string exampleString3 = R"(2013,1,1,542,540,2,923,850,33,"ZE",1141,"N619AA","JFK","MIA",160,1089,5,40,2013-01-01 05:00:00)";
        assert(extract_airline(exampleString3) == "ZE");
        std::cout << " --- Task 1 Test passed --- " << std::endl;
    }

    template<typename T, typename U>
    std::string map_to_string(std::map<T, U> &m) {
        std::string output = "";
        std::string convrt = "";
        std::string result = "";

        for (auto it = m.cbegin(); it != m.cend(); it++) {

            convrt = std::to_string(it->second);
            output += (it->first) + ":" + (convrt) + ", ";
        }

        result = output.substr(0, output.size() - 2);

        return result;
    }

    void test_task_02() {

        std::string filename = "Aufgaben/09/flights.csv";
        auto airlines = create_frequencies(filename);

        std::cout << map_to_string(*airlines) << std::endl;

        assert(airlines->at("AA") == 32729);
        int size = airlines->size();
        std::cout << "map size: " << size << std::endl;
        //assert(size == 18);

        std::cout << " --- Task 2 Test passed --- " << std::endl;
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "starting..." << std::endl;

    task_09::test_task_01();
    task_09::test_task_02();

    std::cout << "terminating..." << std::endl;

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by function: "
              << duration.count() / 1000 << " milliseconds" << std::endl;

    return 0;
}