#ifndef FB2E5448_FA2A_4921_ADE6_160D85781EDC
#define FB2E5448_FA2A_4921_ADE6_160D85781EDC

#include "formula.h"


class TorF : public Formula
{
    bool m_value;
public:
    TorF(bool value) : m_value(value) {}
    void print() const override;
};








#endif /* FB2E5448_FA2A_4921_ADE6_160D85781EDC */
