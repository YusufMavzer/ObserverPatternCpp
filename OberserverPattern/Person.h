#pragma once
#include <string>
#include "Observable.h"

class Person : public Observable {

public:
	Person(std::string name = "");

	std::function<void()>* nameChanged;
	std::function<void()>* lastNameChanged;
	std::function<void()>* ageChanged;

protected:
	virtual std::function<void()> OnNameChanged();
	virtual std::function<void()> OnLastNameChanged();
	virtual std::function<void()> OnAgeChanged();

private:
	std::string m_Name;
	std::string m_LastName;
	std::string m_Age;

public:
	PROPERTY<std::string> Name = PROPERTY<std::string>(
		[&]()-> std::string& {return m_Name;},
		[&](std::string newValue) { m_Name = newValue; Observe(nameof(Name)); }
	);

	PROPERTY<std::string> LastName = PROPERTY<std::string>(
		[&]()-> std::string& {return m_LastName;},
		[&](std::string newValue) {m_LastName = newValue; Observe(nameof(LastName));}
	);

	PROPERTY<std::string> Age = PROPERTY<std::string>(
		[&]()-> std::string& { return m_Age; },
		[&](std::string newValue) { m_Age = newValue; Observe(nameof(Age)); }
	);


	
};