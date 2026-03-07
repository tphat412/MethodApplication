#include "pch.h"
#include "MethodController.h"
#include "MethodOptionsLoader.h"
#include <stdexcept>

void MethodController::CreateModel(MethodType type)
{
    if (m_models.find(type) != m_models.end())
        return;

    MethodModel model;
    model.SetOptions(MethodOptionsLoader::LoadOptions(MethodTypeToOptionsStringID(type)));
    m_models.emplace(type, model);
}

void MethodController::AddSubscriber(MethodType type, SubscriberIf* subscriber)
{
    return m_models.at(type).AddSubscriber(subscriber);
}

void MethodController::RemoveSubscriber(MethodType type, SubscriberIf* subscriber)
{
    return m_models.at(type).RemoveSubscriber(subscriber);
}

const std::vector<std::string>& MethodController::GetOptions(MethodType type) const
{
    return m_models.at(type).GetOptions();
}

const std::string& MethodController::GetSelected(MethodType type) const
{
    return m_models.at(type).GetSelected();
}

void MethodController::SelectMethod(MethodType type, const std::string& method)
{
    m_models.at(type).SetSelected(method);
}
