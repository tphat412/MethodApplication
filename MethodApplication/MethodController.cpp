#include "pch.h"
#include "MethodController.h"
#include "MethodOptionsLoader.h"

MethodController::~MethodController()
{
    for (auto& pair : m_models)
    {
        delete pair.second;
    }
    m_models.clear();
}

void MethodController::CreateModel(MethodType type)
{
    if (m_models.find(type) != m_models.end())
        return;

    m_models[type] = new MethodModel();
    m_models[type]->SetOptions(MethodOptionsLoader::LoadOptions(MethodTypeToOptionsStringID(type)));
}

PublisherIf* MethodController::GetPublisher(MethodType type)
{
    return m_models[type];
}

const std::vector<std::string>& MethodController::GetOptions(MethodType type)
{
    return m_models[type]->GetOptions();
}

std::string MethodController::GetSelected(MethodType type)
{
    return m_models[type]->GetSelected();
}

void MethodController::SelectMethod(MethodType type, const std::string& method)
{
    m_models[type]->SetSelected(method);
}
