#pragma once

#include "PublisherIf.h"
#include <vector>
#include <memory>

class PublisherBase : public PublisherIf
{
public:
	virtual ~PublisherBase() = default;
protected:
	std::vector<SubscriberIf*> m_subscribers;
};