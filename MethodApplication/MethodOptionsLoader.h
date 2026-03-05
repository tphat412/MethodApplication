#pragma once

#include <windows.h>
#include <vector>
#include <string>

class MethodOptionsLoader
{
public:
    static std::vector<std::string> LoadOptions(UINT resourceId);
};