#ifndef F129DE84_F183_4009_8673_FFA2C9690BF7
#define F129DE84_F183_4009_8673_FFA2C9690BF7

#include "formula.h"
#include <memory>

class NotFormula : public Formula
{
    FormulaPtr sub_formula;
public:
    NotFormula(FormulaPtr sub_f) : sub_formula(sub_f) {}
    void print() const override;
};


#endif /* F129DE84_F183_4009_8673_FFA2C9690BF7 */
