#pragma once
#include <iostream>

class Animal
{
public:
	virtual void Eat() = 0; //виртуальный метод нужен для переопределения метода в наследнике

public:
	virtual void Run() = 0;

public:
	virtual void Roar() = 0;

public:
	virtual void Swim()
	{
		std::cout << "This animal not swiming today" << std::endl;
	}

};

