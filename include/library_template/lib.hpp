#pragma once

#include <string>

#include "export.hpp"

class LIBRARY_TEMPLATE_EXPORT Lib
{
public:
    [[nodiscard]] static std::string helloWorldMsg();
};