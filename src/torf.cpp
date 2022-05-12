#include "torf.h"
#include <iostream>

void TorF::print() const
{
    std::cout << m_value ? "T" : "F";
}