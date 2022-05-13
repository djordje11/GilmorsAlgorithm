#ifndef C3141E42_7039_4B50_81B1_AFB9964080E5
#define C3141E42_7039_4B50_81B1_AFB9964080E5

#include "formula.h"
#include <string>
#include <map>
#include <iostream>

enum class BinaryType
{
    AND,
    OR,
    IFF,
    IMP
};

template<BinaryType type>
class BinaryFormula : public Formula
{
    FormulaPtr left;
    FormulaPtr right;
    static std::map<BinaryType, std::string> operators;
public:
    BinaryFormula(FormulaPtr l, FormulaPtr r) : left(l), right(r) {}
    void print() const override;
    std::string get_type_as_string() const {return operators[type];}
    BinaryType get_type() const {return type;}
};

template<BinaryType type>
std::map<BinaryType, std::string> BinaryFormula<type>::operators = {
    std::make_pair(BinaryType::AND, "/\\"),
    std::make_pair(BinaryType::OR, "v"),
    std::make_pair(BinaryType::IFF, "<=>"),
    std::make_pair(BinaryType::IMP, "=>")
};


template<BinaryType type>
void BinaryFormula<type>::print() const
{
    std::cout << "(";
    left->print();
    std::cout << " " << get_type_as_string() << " ";
    right->print();
    std::cout << ")";
}








#endif /* C3141E42_7039_4B50_81B1_AFB9964080E5 */
