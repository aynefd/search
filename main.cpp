//
//  main.cpp
//  search
//
//  Created by Ayne Delgado on 2/8/15.
//  
//

#include <iostream>
#include <ctime>
#include "Search.h"
using namespace std;


//----------------------CONSTANTS----------------------
int const BIG = 10000;
int const GIANT = 1000000;
int const MY_SEED = 5;
int const FIND_ME = 100;
double const SEC_TO_MICRO=1000000;

int main()
{
    //Two searches declared, same size and seed
    
    Search binary(BIG,MY_SEED);
    Search sequential(BIG, MY_SEED);
    
    //One sorted random array for binary search and one random array for sequential search
    
    binary.init_sorted_array();
    sequential.init_array();
    
  
    //Testing iterative binary search. Should be the fastest
    
    clock_t start1 = clock();
    
    for(int i = 0; i<GIANT; i++)
    {
      binary.iterative_binary_find(FIND_ME);
    }
    
    clock_t end1 = clock();
    clock_t diff1 = end1-start1;
    
    
    //Testing recursive binary search. Should be second fastest
    
    clock_t start2 = clock();
    
    for(int i = 0; i<GIANT; i++)
    {
        binary.recursive_binary_find(FIND_ME);
    }
    
    clock_t end2 = clock();
    clock_t diff2 = end2-start2;
    
    
    //Testing sequential search. Should take longest
    
    clock_t start3 = clock();
    
    for(int i = 0; i<GIANT; i++)
    {
        sequential.sequential_find(FIND_ME);
    }
    
    clock_t end3 = clock();
    clock_t diff3 = end3-start3;
    

    //Calculate clocks to microseconds and output
    
    cout<<"The iterative binary search took "<<(((double)diff1)/CLOCKS_PER_SEC)*SEC_TO_MICRO<<" microseconds";
    cout<<endl;
    cout<<"The recursive binary search took "<<(((double)diff2)/CLOCKS_PER_SEC)*SEC_TO_MICRO<<" microseconds";
    cout<<endl;
    cout<<"The sequential search took "<<(((double)diff3)/CLOCKS_PER_SEC)*SEC_TO_MICRO<<" microseconds";
    cout<<endl;
    
    //system("PAUSE");
    return 0;

}

