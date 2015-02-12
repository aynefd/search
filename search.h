#include "Search.h"

Search::~Search()
{
    if(array!=nullptr)
    {
        delete[] array;
    }
    array = nullptr;
}
void Search::set_seed(int seed)
{
    srand(seed);
    
}
int Search::getSize() const
{
    return aSize;
}
void Search::init_array()
{
    assert(aSize>0);
    for(unsigned i = 0; i< aSize; i++)
    {
        array[i]=rand()/DIVIDER;
    }
}
void Search::init_sorted_array()
{
    assert(aSize>0);
    array[0]= rand() % SORT_DIVIDER; 
    for(unsigned i =0; i<aSize; i++)
    {
        array[i+1] = array[i] + rand() % SORT_DIVIDER;
    }
}
bool Search::sequential_find(int num)
{
    for(int i=0; i<aSize; i++)
    {
        if(array[i] == num)
            return true;
    }
    return false;


}
bool Search::iterative_binary_find(int num) 
{
    if(aSize==0)
        return false;
    int start = 0;
    int last = aSize;
    int mid = (aSize/ARRAY_DIVIDER) -1;
    while(start <=last)
    {
        if(array[mid]== num)
            return true;
        else if(num > array[mid])
        {
            start = mid+1;
            mid = start + ((last - start)/ARRAY_DIVIDER);
        }
        else if(num< array[mid])
        {
            last = mid-1;
            mid = start + ((last - start)/ARRAY_DIVIDER);
            
        }
    }
    return false;
    
    
}
bool Search::recursive_binary_find(int num)
{
    int first =0;
    return recursive_search_helper(num, first, aSize, array);
    
}
bool Search::recursive_search_helper(int num, int first, int size, int* theArray) //NEED CONSTS
{
    int mid;
    if(size==0)
        return false;
    else
    {
        mid=first + size/ARRAY_DIVIDER;
        if(num==theArray[mid])
            return true;
        else if(num<theArray[mid])
            return recursive_search_helper(num, first, size/ARRAY_DIVIDER, theArray);
        else
            return recursive_search_helper(num, mid+1, (size-1)/ARRAY_DIVIDER, theArray);
            
    }
}







