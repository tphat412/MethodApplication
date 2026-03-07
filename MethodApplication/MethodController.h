#pragma once

#include "MethodModel.h"
#include "MethodType.h"

#include <unordered_map>
#include <memory>

class MethodController
{
public:
    void CreateModel(MethodType type);

    void AddSubscriber(MethodType type, SubscriberIf* subscriber);

    const std::vector<std::string>& GetOptions(MethodType type) const;

    const std::string& GetSelected(MethodType type) const;

    void SelectMethod(MethodType type, const std::string& method);

private:
    std::unordered_map<MethodType, MethodModel> m_models;
};