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

void MethodModel::AddSubscriber(SubscriberIf* sub)
{
    auto it = std::find(m_subscribers.begin(), m_subscribers.end(), sub);

    if (it == m_subscribers.end())
    {
        m_subscribers.push_back(sub);
    }
}

void MethodModel::RemoveSubscriber(SubscriberIf* sub)
{
    m_subscribers.erase(
        std::remove(m_subscribers.begin(),
            m_subscribers.end(),
            sub),
        m_subscribers.end());
}

void MethodModel::Notify()
{
    for (auto subscriber : m_subscribers)
        subscriber->Update();
}