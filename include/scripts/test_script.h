#pragma once

#include <core/objectsManager.h>

class TestScript : public Object
{
public:
	void init() override;
	void update(double deltaTime) override;
};