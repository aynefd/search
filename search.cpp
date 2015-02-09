#include "Search.h"


int Search::getSize() const
{
    return aSize;
}
void Search::init_array()
{
    for(unsigned i = 0; i< aSize; i++)
    {
        array[i]=rand();
    }
}
