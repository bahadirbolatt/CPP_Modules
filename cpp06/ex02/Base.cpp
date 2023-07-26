#include "Base.hpp"

Base::~Base(){std::cout << "Base destructor called\n";}

A::~A(){std::cout << "A destructor called\n";}
B::~B(){std::cout << "B destructor called\n";}
C::~C(){std::cout << "C destructor called\n";}

Base * generate(void){
    srand((unsigned) time(NULL));
    int random = rand() % 3;
    switch(random){
        case 1:
            return new(A);
        case 0:
            return new(B);
        case 2:
            return new(C);
    }
    return NULL;
}

void identify(Base* p){
    if(dynamic_cast<A*>(p))
        std::cout << "this is definitely type A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "this is definitely type B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "this is definitely type C" << std::endl;
    else
        std::cout << "this is a definitely dynamic_cast error situtaion" << std::endl;
}

void identify(Base& p){
    try{
        A typeA;
        typeA = dynamic_cast<A&>(p);
        std::cout << "this class' type is A" << std::endl;
    }
    catch (const std::exception& e) {
		std::cout << "A : " << e.what() << std::endl;
	}
    try{
        B typeB;
        typeB = dynamic_cast<B&>(p);
        std::cout << "this class' type is B" << std::endl;
    }
    catch (const std::exception& e) {
		std::cout << "B : " << e.what() << std::endl;
	}
    try{
        C typeC;
        typeC = dynamic_cast<C&>(p);
        std::cout << "this class' type is C" << std::endl;
    }
    catch (const std::exception& e) {
		std::cout << "C : " << e.what() << std::endl;
	}
}