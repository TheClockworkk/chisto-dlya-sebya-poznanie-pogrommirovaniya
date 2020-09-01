#pragma once
#include <iostream>
#include"Animal.h"

class Turtle :public Animal
{
public:
	void Eat() override//для успешного переопределения метода в наследнике мы должны и тип тот же и имя то же бахнуть
	{//override нужен для выявления ошибок при переопределении
		std::cout << "Turtle eating" << std::endl;
	}

public:
	void Run() override
	{
		std::cout << "Turtle running" << std::endl;
	}

public:
	void Roar() override
	{
		std::cout << "Turtle roarink" << std::endl;
	}

public:
	void Swim() override
	{
		std::cout << "Turtle swimmink" << std::endl;
	}

public:
	~Turtle()
	{
		std::cout << "Turtle going sleep" << std::endl;
	}
};
