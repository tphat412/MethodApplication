#pragma once

#include "MethodModel.h"
#include "MethodType.h"

#include <unordered_map>
#include <memory>

class MethodController
{
public:

    ~MethodController();

    void CreateModel(MethodType type);

    PublisherIf* GetPublisher(MethodType type);

    const std::vector<std::string>& GetOptions(MethodType type);

    std::string GetSelected(MethodType type);

    void SelectMethod(MethodType type, const std::string& method);

private:

    std::unordered_map<MethodType, MethodModel*> m_models;
};