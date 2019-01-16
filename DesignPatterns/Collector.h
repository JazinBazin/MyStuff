#pragma once
#include <vector>
#include <string>

class Collector {
public:
    Collector() :
        data(std::vector<std::string>()) {}

    void addData(const std::string &newData) {
        data.push_back(newData);
    }

private:
    std::vector<std::string> data;
};

class Filter {
public:
    void f(Collector &c) {
        c.addData("data from f()");
    }
    void g(Collector &c) {
        c.addData("data from g()");
    }
    void m(Collector &c) {
        c.addData("data from m()");
    }
};
