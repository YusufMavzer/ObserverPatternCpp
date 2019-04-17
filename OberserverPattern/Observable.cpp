#include "pch.h"
#include "Observable.h"

Observable::Observable() : m_EventHandlers()
{
}

void Observable::operator+=(EventHandler * handler)
{
	m_EventHandlers.push_back(std::make_unique<EventHandler*>(handler));
}

void Observable::operator-=(EventHandler * handler)
{
	std::string sender(handler->GetOwner());
	int index = -1;
	auto size = m_EventHandlers.size();
	for (size_t i = 0; i < size; i++) {
		if ((*m_EventHandlers[i])->GetOwner() == sender) {
			index = i;
		}
	}
	if (index == -1) return;
	m_EventHandlers.erase(m_EventHandlers.begin()+index);
}

void Observable::operator~()
{
	m_EventHandlers.clear();
}

void Observable::Observe(std::string sender)
{
	auto size = m_EventHandlers.size();
	for (size_t i = 0; i < size; i++) {
		if ((*m_EventHandlers[i])->GetOwner() == sender) {
			(*m_EventHandlers[i])->OnChanged();
			//break;
		}
	}
}
