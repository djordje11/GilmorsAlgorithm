#include "term.h"
#include <iostream>


void Term::print() const
{
    if(m_value.index() == 0)
    {
        std::cout << std::get<VarTerm>(m_value);
    }
    else if(m_value.index() == 1)
    {
        const FuncTerm& ft = std::get<FuncTerm>(m_value);
        std::cout << ft.first << "(";
        for(auto it = ft.second.begin(); it != ft.second.end() - 1; ++it)
        {
                it->print();
                std::cout << ", ";
        }
        if(ft.second.size() > 0)
            (ft.second.end() - 1)->print();
        std::cout << ")";
    }
}