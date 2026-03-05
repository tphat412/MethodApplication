#pragma once

class SubscriberIf
{
public:
    virtual ~SubscriberIf() = default;
    virtual void Update() = 0;
};