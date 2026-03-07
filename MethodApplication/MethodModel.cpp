#include "pch.h"
#include "MethodModel.h"
#include "SubscriberIf.h"


void MethodModel::SetOptions(const std::vector<std::string>& opts)
{
    m_options = opts;

    if (!m_options.empty())
        m_selected = m_options[0];

    Notify();
    return;
}

const std::vector<std::string>& MethodModel::GetOptions() const
{
    return m_options;
}

void MethodModel::SetSelected(const std::string& method)
{
    if (m_selected == method)
        return;

    m_selected = method;
    Notify();
    return;
}

const std::string& MethodModel::GetSelected() const
{
    return m_selected;
}