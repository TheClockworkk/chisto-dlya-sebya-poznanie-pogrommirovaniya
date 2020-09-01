#pragma once
#include <iostream>
#include"Animal.h"

class Turtle :public Animal
{
public:
	void Eat() override//��� ��������� ��������������� ������ � ���������� �� ������ � ��� ��� �� � ��� �� �� �������
	{//override ����� ��� ��������� ������ ��� ���������������
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
