#pragma once

#include <vector>
#include "SubscriberIf.h"

class PublisherIf
{
public:
    virtual ~PublisherIf() = default;
    virtual void AddSubscriber(SubscriberIf* sub) = 0;
    virtual void RemoveSubscriber(SubscriberIf* sub) = 0;
    virtual void Notify() = 0;
};