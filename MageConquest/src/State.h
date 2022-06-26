#pragma once
#include"pch.h"
class State
{
private:

public:
	State();
	virtual ~State();
	virtual void Render() = 0;
	virtual void Update(float& deltaTime) = 0;
};

