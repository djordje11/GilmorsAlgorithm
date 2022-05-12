#ifndef B84AA876_E1A8_4F82_9431_0334DAFE2760
#define B84AA876_E1A8_4F82_9431_0334DAFE2760


#include "formula.h"
#include "term.h"
#include <string>

class AtomFormula : public Formula
{
    std::string atom_name;
    TermList terms;
public:
    AtomFormula(std::string name, TermList ts) : atom_name(name), terms(ts) {} 
    void print() const override;
};




#endif /* B84AA876_E1A8_4F82_9431_0334DAFE2760 */
