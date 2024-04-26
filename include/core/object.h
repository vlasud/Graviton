#pragma once

class Object
{
public:

    Object() = default;
    ~Object();

    virtual void init();
    virtual void update(double deltaTime);
};