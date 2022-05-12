#include "atomformula.h"
#include "ar_std.h"

void AtomFormula::print() const
{
    printInFunctionNotation(atom_name, terms);
}