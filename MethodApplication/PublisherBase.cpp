#include "pch.h"
#include "PublisherBase.h"


void PublisherBase::AddSubscriber(SubscriberIf* sub)
{
    auto it = std::find(m_subscribers.begin(), m_subscribers.end(), sub);

    if (it == m_subscribers.end())
    {
        m_subscribers.push_back(sub);
    }
}

void PublisherBase::RemoveSubscriber(SubscriberIf* sub)
{
    m_subscribers.erase(
        std::remove(m_subscribers.begin(),
            m_subscribers.end(),
            sub),
        m_subscribers.end());
}

void PublisherBase::Notify()
{
    for (auto subscriber : m_subscribers)
        subscriber->Update();
}