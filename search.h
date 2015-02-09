#pragma once

#include <iostream>
#include <fstream>
#include <random>
using namespace std;

class Search
{
public:
    bool sequential_find(int num);
    bool recursive_binary_find(int num);
    bool iterative_binary_find(int num);
    
    
    
    //Function to initialize the array with random numbers roughly the same size as the array
    void init_array();
    //Function to initialize the array with sorted random numbers
    void init_sorted_array();
    
    void set_seed(int seed);
    int getSize() const;
    
    // this is just for practice and debugging.
    friend ostream& operator<< (ostream& out, const Search& s)
    {
        // put the code in here.
    }
    
    Search(int size,int seed=0)
    {
        aSize=size;
        array = new int[aSize];
    }
    ~Search();
    
private:
    
    int aSize;
    int* array;
};

