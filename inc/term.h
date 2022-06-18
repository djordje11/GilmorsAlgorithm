#ifndef __TERM_H__
#define __TERM_H__

#include <string>
#include <utility>
#include <vector>
#include <variant>
#include <memory>
#include "interpretation.h"

class Term;
using TermPtr = std::shared_ptr<Term>;
using TermList = std::vector<TermPtr>;
using VarTerm = std::string;
using FuncTerm = std::pair<std::string, std::vector<TermPtr>>;

class Term
{
public:
   std::variant<VarTerm, FuncTerm> m_value; 
   Term(VarTerm v) : m_value(v) {} 
   Term(FuncTerm f) : m_value(f) {}
   void print() const;
   bool isVar() const;
   bool isFun() const;
   unsigned narity() const;
};





#endif // __TERM_H__