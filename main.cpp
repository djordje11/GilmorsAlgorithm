#include "term.h"
#include "domain.h"
#include <iostream>
#include <memory>
#include "pom.h"


int main()
{
    FiniteDomain<int> x{{1, 2}};
    Signature s;
    s.fun = {std::make_pair("c", 0), std::make_pair("b", 0), std::make_pair("f", 1), std::make_pair("g", 2)};

    Pom pom(std::make_shared<Signature>(s));


     Pom p(std::make_shared<Signature>(s));

    unsigned n;
    std::cin >> n;
    auto tuples = p.ground_terms(n);
    std::cout << tuples->size() << " size" << std::endl;

    std::for_each(tuples->begin(), tuples->end(), 
        [](TermPtr t)
        {
            t->print();
            std::cout << std::endl;
        });


    return 0;
}