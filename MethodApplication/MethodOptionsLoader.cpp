#include "pch.h"
#include "MethodOptionsLoader.h"
#include <afxwin.h>


std::vector<std::string> MethodOptionsLoader::LoadOptions(UINT resourceId)
{
    CString str;
    str.LoadString(resourceId);

    std::vector<std::string> options;

    int curPos = 0;
    CString token = str.Tokenize(L";", curPos);

    while (token != L"")
    {
        token.Trim(); // remove spaces

        options.push_back(std::string(CT2A(token)));

        token = str.Tokenize(L";", curPos);
    }

    return options;
}
