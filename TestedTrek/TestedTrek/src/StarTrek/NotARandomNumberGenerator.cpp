#include "NotARandomNumberGenerator.h"

using namespace StarTrek;

NotARandomNumberGenerator::NotARandomNumberGenerator(int always_generate_this_value)
    : m_value(always_generate_this_value)
{ }

int NotARandomNumberGenerator::generate(int)
{
    return m_value;
}
