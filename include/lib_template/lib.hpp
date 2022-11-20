#pragma once

#include <string>

class Lib
{
public:
    [[nodiscard]] static std::string helloWorldMsg();
};

inline std::string Lib::helloWorldMsg() { return "Hello World!\n"; }
