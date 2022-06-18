#include "term.h"
#include <iostream>
#include "ar_std.h"

void Term::print() const
{
    if(m_value.index() == 0)
    {
        std::cout << std::get<VarTerm>(m_value);
    }
    else if(m_value.index() == 1)
    {
        const FuncTerm& ft = std::get<FuncTerm>(m_value);
        printInFunctionNotation(ft.first, ft.second);
    }
}

bool Term::isVar() const
{
    return m_value.index() == 0;
}
bool Term::isFun() const
{
    return m_value.index() == 1;
}


unsigned Term::narity() const
{
    return isVar() ? 0 : std::get<FuncTerm>(m_value).second.size();
}
