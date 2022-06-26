#include "pom.h"
#include <iostream>
#include "term.h"
#include <utility>

Pom::Pom(std::shared_ptr<Signature> signature) : m_signature(signature), m_functions_by_narity{{0, std::vector<std::string>()}}
{
    for(auto it = m_signature->fun.cbegin(); it != m_signature->fun.cend(); it++)
    {
        auto jt = m_functions_by_narity.find(it->second);
        if(jt == m_functions_by_narity.end())
            m_functions_by_narity[it->second] = {it->first};
        else
            m_functions_by_narity[it->second].push_back(it->first);
    }
}


void Pom::ispisi() const
{
    for(auto it = m_functions_by_narity.cbegin(); it != m_functions_by_narity.cend(); ++it)
    {
        std::cout << it->first << " : ";
        std::for_each(it->second.cbegin(), it->second.cend(), [](std::string fun){std::cout << fun << " ";});
        std::cout << std::endl;
    }
}



std::shared_ptr<TermList> Pom::ground_terms(unsigned n)
{
    std::shared_ptr<TermList> result = std::make_shared<TermList>();
    if(n == 0)
    {
       auto result = std::make_shared<TermList>(); 
       auto it = m_functions_by_narity.find(0);
       if(it != m_functions_by_narity.end())
            std::for_each(it->second.begin(), it->second.end(),
                [&result](std::string func)
                {
                    result->push_back(std::make_shared<Term>(func));
                }
            );
        return result;
    }
    else 
    {
        for(auto it = ++(m_functions_by_narity.begin()); it != m_functions_by_narity.end(); ++it)
        {
            std::for_each(it->second.begin(), it->second.end(),
                [n,this, &it, &result](std::string func)
                {
                    std::vector<TermList> list = ground_tuples(n-1, it->first);
                    std::transform(list.cbegin(), list.cend(), std::back_inserter(*result),
                        [&func](TermList l)
                        {
                            return std::make_shared<Term>(FuncTerm{func, l});
                        }
                    );
                }
            );
        }
    }
    return result;
}


std::vector<TermList> Pom::ground_tuples(unsigned n, unsigned m)
{
    if(m == 0)
        return n == 0 ? std::vector<TermList>{{}} : std::vector<TermList>{}; 
    std::vector<TermList> result;
    for(unsigned i = 0; i <= n; ++i)
    {
        auto terms = ground_terms(i);
        auto tuples = ground_tuples(n-i, m-1);


        std::for_each(terms->begin(), terms->end(), 
            [&result, &tuples](TermPtr ptr)
            {
                std::transform(tuples.begin(), tuples.end(), std::back_inserter(result), 
                    [&ptr](TermList t){
                       t.push_back(ptr);
                       return t;
                    });
            });
    }
    return result;
}