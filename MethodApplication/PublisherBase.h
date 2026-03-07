#pragma once

#include "PublisherIf.h"
#include <vector>
#include <memory>

class PublisherBase : public PublisherIf
{
public:
	virtual ~PublisherBase() = default;

	void AddSubscriber(SubscriberIf* sub) override;

	void RemoveSubscriber(SubscriberIf* sub) override;

	void Notify() override;

protected:
	std::vector<SubscriberIf*> m_subscribers;
};