#include "notformula.h"
#include <iostream>

void NotFormula::print() const
{
    std::cout << "(~";
    sub_formula->print();
    std::cout << ")";
}