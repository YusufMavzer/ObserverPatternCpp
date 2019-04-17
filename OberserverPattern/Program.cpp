// OberserverPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Person.h"


int main()
{
	Person person = Person("Yusuf");
	person += new EventHandler(nameof(person.Name), new std::function<void()>([&]() {
		std::cout << "Adding another event to the same property.\n";
	}));

	person.ageChanged= new std::function<void()>([&]() {
		std::cout << " Overriding the person age function \n";
	});
	person.LastName = "Mavzer";
	person.Name = "Tayfun";
	person.LastName = "M.";
	person.Name = "Yusuf";
	person.Age = "24";



	std::cout << "End...\n";
}