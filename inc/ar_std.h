#ifndef A4F19B9F_5B02_4982_8719_F58C631F2378
#define A4F19B9F_5B02_4982_8719_F58C631F2378

#include <string>

template <typename Container>
void printInFunctionNotation(std::string func_name, Container args)
{
        std::cout << func_name << "(";
        for(auto it = args.begin(); it != args.end() - 1; ++it)
        {
                it->print();
                std::cout << ", ";
        }
        if(args.size() > 0)
            (args.end() - 1)->print();
        std::cout << ")";
}





#endif /* A4F19B9F_5B02_4982_8719_F58C631F2378 */