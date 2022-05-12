#ifndef BD6747A6_089B_478B_981B_6CDE5BDB8E1F
#define BD6747A6_089B_478B_981B_6CDE5BDB8E1F

#include "formula.h"
enum class QuantifierType
{
    Existential,
    Universal
};

template<QuantifierType type>
class QuantifierFormula : public Formula
{
    FormulaPtr sub_formula;
public:
    QuantifierFormula(FormulaPtr subformula) : sub_formula(subformula) {}
    void print() const override;
    std::string get_type_as_string() const{return type == QuantifierType::Existential ? "E" : "A";}
    QuantifierType get_type() const{return type;}
};

template<QuantifierType type>
void QuantifierFormula<type>::print() const
{
    std::cout << "(" << get_type_as_string();
    sub_formula->print();
    std::cout << ")";
}

#endif /* BD6747A6_089B_478B_981B_6CDE5BDB8E1F */
