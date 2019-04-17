#include "pch.h"
#include "Person.h"
#include <iostream>

//Constructor
Person::Person(std::string name) : Observable(), m_Name(name)
{
	nameChanged = &(OnNameChanged());
	lastNameChanged = &(OnLastNameChanged());
	ageChanged = &(OnAgeChanged());

	//Assign events
	(*this) += new EventHandler(nameof(Name), nameChanged);
	(*this) += new EventHandler(nameof(LastName), lastNameChanged);
	(*this) += new EventHandler(nameof(Age), ageChanged);

}

//Event Methods
std::function<void()> Person::OnNameChanged()
{
	return [&]() {
		std::cout << "User has changed it's name to " << Name() << "\n";
	};
}
std::function<void()> Person::OnLastNameChanged()
{
	return [&]() {
		auto lastname = LastName();
		std::cout << "User has changed it's lastname to " << lastname << "\n";
	};
}
std::function<void()> Person::OnAgeChanged()
{
	return [&]() {
		std::cout << "User has changed it's age to " << nameof(Age) << "\n";
	};
}
