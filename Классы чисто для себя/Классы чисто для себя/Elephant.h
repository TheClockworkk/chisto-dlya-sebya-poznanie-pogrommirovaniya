#include <iostream>
#include"Animal.h"

class Elephant :public Animal
{
public:
	void Eat() override//��� ��������� ��������������� ������ � ���������� �� ������ � ��� ��� �� � ��� �� �� �������
	{//override ����� ��� ��������� ������ ��� ���������������
		std::cout << "Elephant eating" << std::endl;
	}

public:
	void Run() override
	{
		std::cout << "Elephant running" << std::endl;
	}

public:
	void Roar() override
	{
		std::cout << "Elephanton roaring" << std::endl;
	}

public:
	~Elephant()
	{
		std::cout << "Elephanton going sleep" << std::endl;
	}
};
