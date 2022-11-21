#include "time.h"
#include "Dice.h"
#include <cstdlib>

Dice::Dice()
{
}

Dice::~Dice()
{
}

Dice::Dice(int numberOfSides)
{
    srand (time(NULL));
    roll();
    m_numberOfSides = numberOfSides;
}

int Dice::roll(void)
{
    int result = (rand() % m_numberOfSides) + 1;
    return result;
}

