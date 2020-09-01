#include <iostream>
#include "Animal.h"
#include "Lion.h"
#include "Turtle.h"
#include "Elephant.h"
#include "Zoo.h"


int main()
{
    //Animal animal;
    //animal.Roar(); 

    //в Animal есть чисто виртуальные функции. Они не поволяют создавать экземпляр класса, но это
    //не относится к подклассу хехе. То есть таким образом мы можем просто не реализовывать каких-то
    //абстрактных животных и их действия, а делать по конкретитке всё

    Lion lion;
    Turtle turtle;
    Elephant elephant;

   // Animal* beast1 = &lion;
    
    //Animal* beast2 = &turtle;
   
    //Animal* beast3 = &elephant;
   
    Zoo zoo;

    zoo.action(&lion);
    std::cout << std::endl;

    zoo.action(&turtle);
    std::cout << std::endl;

    zoo.action(&elephant);
    std::cout << std::endl;
    //кароче, мы благодаря переопределению и полиморфизму благодаря ему можем сделать так, что
    //каким-то сторонним классом мы можем вызывать методы из разных классов, не парясь с отдельной
    //реализацией йоу
   
    return 0;
}
