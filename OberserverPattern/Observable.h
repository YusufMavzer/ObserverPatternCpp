#pragma once
#include "EventHandler.h"
#include "NameOf.h"
#include <vector>
#include <algorithm>
#include <tuple>
#include <iostream>


class Observable {

public:
	Observable();
	void operator+=(EventHandler* handler);
	void operator-=(EventHandler* handler);
	void operator~();
protected:
	void Observe(std::string sender);

private:
	std::vector<std::unique_ptr<EventHandler*>> m_EventHandlers;

};

