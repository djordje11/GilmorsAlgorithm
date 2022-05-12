#ifndef __TERM_H__
#define __TERM_H__

#include <string>
#include <utility>
#include <vector>
#include <variant>
#include <memory>

class Term;
using VarTerm = std::string;
using FuncTerm = std::pair<std::string, std::vector<Term>>;

using TermPtr = std::shared_ptr<Term>;
using TermList = std::vector<TermPtr>;
class Term
{
public:
   std::variant<VarTerm, FuncTerm> m_value; 
   Term(VarTerm v) : m_value(v) {} 
   Term(FuncTerm f) : m_value(f) {}
};





#endif // __TERM_H__