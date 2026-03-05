#pragma once

#include "PublisherIf.h"
#include <vector>
#include <string>

class MethodModel : public PublisherIf
{
public:

    void SetOptions(const std::vector<std::string>& options);

    const std::vector<std::string>& GetOptions() const;

    void SetSelected(const std::string& method);

    const std::string& GetSelected() const;

    void AddSubscriber(SubscriberIf* sub) override;

    void RemoveSubscriber(SubscriberIf* sub) override;

    void Notify() override;

private:

    std::vector<std::string> m_options;
    std::string m_selected;
    std::vector<SubscriberIf*> m_subscribers;
};