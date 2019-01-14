#pragma once
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>

std::vector<std::string> splitString(const std::string &str, char separator) {
    std::vector<std::string> splitResult;
    auto strBegin = str.begin();
    auto strEnd = str.cend();
    while(true) {
        auto it = find(strBegin, strEnd, separator);
        splitResult.push_back(std::string(strBegin, it));
        if(it == strEnd)
            break;
        else
            strBegin = it + 1;
    }
    return splitResult;
}

std::vector<std::string_view> splitStringView(std::string_view str, char separator) {
    std::vector<std::string_view> splitResult;
    size_t splitPosition;
    while(true) {
        splitPosition = str.find(separator);
        splitResult.push_back(str.substr(0, splitPosition));
        if(splitPosition == str.npos)
            break;
        else
            str.remove_prefix(splitPosition + 1);
    }

    return splitResult;
}

void exampleSplitString() {
    std::string s;
    char separator;
    std::getline(std::cin, s);
    std::cin.get(separator);
    for(const auto &str : splitString(s, separator))
        std::cout << str << "\n";
    for(const auto &str : splitStringView(s, separator))
        std::cout << str << "\n";
}
