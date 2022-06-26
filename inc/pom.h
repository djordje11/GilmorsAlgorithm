#ifndef __POM_H__
#define __POM_H__

#include "interpretation.h"
#include "term.h"
#include <memory>
#include <string>
#include <vector>
#include <map>


class Pom 
{
public:
    std::shared_ptr<Signature> m_signature;
    std::map<unsigned, std::vector<std::string>> m_functions_by_narity;
public:
    Pom(std::shared_ptr<Signature> signature); 
    void ispisi()const;
    std::shared_ptr<TermList> ground_terms(unsigned n);
    std::vector<TermList> ground_tuples(unsigned n, unsigned m);
};
#endif // __POM_H__