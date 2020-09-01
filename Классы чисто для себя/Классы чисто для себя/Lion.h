#pragma once
#include <iostream>
#include"Animal.h"

class Lion :public Animal
{
public:
	void Eat() override//��� ��������� ��������������� ������ � ���������� �� ������ � ��� ��� �� � ��� �� �� �������
	{//override ����� ��� ��������� ������ ��� ���������������
		std::cout << "Lion eating" << std::endl; 
	}

public:
	void Run() override
	{
		std::cout << "Lion running" << std::endl;
	}

public:
	void Roar() override
	{
		std::cout << "Lion RRRRRRRRRRROARING" << std::endl;
	}

public:
	~Lion()
	{
		std::cout << "Lion going sleep" << std::endl;
	}
};

