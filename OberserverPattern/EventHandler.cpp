#include "pch.h"
#include "EventHandler.h"

EventHandler::EventHandler(std::string owner, std::function<void()>* function) : owner(owner),function(function)
{

}

void EventHandler::OnChanged()
{
	if ((*function) != nullptr)
		(*function)();
}

std::string EventHandler::GetOwner()
{
	return this->owner;
}
