#pragma once
#include "IEvent.h"
#include <functional>


class EventHandler : IEvent {

public:
	EventHandler(std::string owner, std::function<void()>* function);
	virtual void OnChanged() override;
	std::string GetOwner();
private:
	std::function<void()>* function;
	std::string owner;
};
