
#ifndef __formula__
#define __formula__

#include <memory>

class Formula
{
public:
    virtual void print() const = 0;
};

using FormulaPtr = std::shared_ptr<Formula>;

#endif