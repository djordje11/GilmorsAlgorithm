#ifndef B5C5BEBD_50B8_4096_A0DC_051954D20287
#define B5C5BEBD_50B8_4096_A0DC_051954D20287
#include <map>
#include "domain.h"
#include <memory>
#include <functional>

struct Signature
{
    std::map<std::string, unsigned> rel;
    std::map<std::string, unsigned> fun;
};

template <typename T>
using Valuation = std::map<std::string, T>;

template <typename T>
using Function = std::function<T(const std::vector<T>&)>;

template <typename T>
using Relation = std::function<bool(const std::vector<T>&)>;

template <typename T>
struct LStructure
{
    Signature signature;
    std::shared_ptr<Domain<T>> domain;
    std::map<std::string, Function<T>> functions;
    std::map<std::string, Relation<T>> relations;
};



#endif /* B5C5BEBD_50B8_4096_A0DC_051954D20287 */