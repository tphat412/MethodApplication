#pragma once

#include "PublisherBase.h"
#include <vector>
#include <string>

class MethodModel : public PublisherBase
{
public:

    void SetOptions(const std::vector<std::string>& options);

    const std::vector<std::string>& GetOptions() const;

    void SetSelected(const std::string& method);

    const std::string& GetSelected() const;

private:
    std::vector<std::string> m_options;
    std::string m_selected;
};