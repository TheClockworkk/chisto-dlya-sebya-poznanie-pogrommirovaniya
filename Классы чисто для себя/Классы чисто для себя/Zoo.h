#pragma once
#include "Animal.h"

class Zoo
{
public:
	void action(Animal* animal)
	{
		animal->Roar();
		animal->Eat();
		animal->Run();
		animal->Swim();
	}

public:
	~Zoo()
	{
		std::cout << "Zoo closing" << std::endl;
	}
};

