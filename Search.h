//I Ayne Delgado have not used any code other than my own (or that in the textbook) for this project. 
//I also have not used any function or data-structure from the Standard-Template Library.
//I understand that any violation of this disclaimer will result in a 0 for the project.

//-------------------------Search header file---------------------------------------

#pragma once

#include <iostream>
#include <fstream>
#include <random>
#include <cassert>
using namespace std;
//-------------------------------------------CONSTANTS-------------------------------------

const int DIVIDER = 10000000;//Constant to make rand() numbers more managable
const int SORT_DIVIDER = 5;
const int ARRAY_DIVIDER =2;

class Search
{
public:
    //Sequential find function
    //Purpose: find a number in an array by checking each element from the beginning to the end
    //Parameters: number to find
    //Returns: a bool, if number was found or not
    //pre-conditions: a non empty Search array
    //post-conditions: true if found, false otherwise
    bool sequential_find(int num);
    
    //recursive binary find function
    //Purpose: use a binary search recursively to find an element in the array
    //Parameters: int, a number to find
    //Returns: a bool, if number was found or not
    //pre-conditions: a non empty Search array
    //post-conditions: true if found, false otherwise
    bool recursive_binary_find(int num);
    
    //iterative binary find function
    //Purpose: use a binary search with iteration to find an element in the array
    //Parameters: int, a number to find
    //Returns: a bool, if number was found or not
    //pre-conditions: a non empty Search array
    //post-conditions: true if found, false otherwise
    bool iterative_binary_find(int num);
    
    //init_array function
    //Purpose: initialize the array with random numbers roughly the same size as the array
    //Parameters: none
    //Returns: none
    //pre-conditions: array size not set to 0
    //post-condition: a search with an array filled with random numbers
    void init_array();
    
    //init_sorted_array function
    //Purpose: To initialize the array with sorted random numbers
    //Parameters: none
    //Returns: none
    //pre-conditions: array size is not set to 0
    //post-condition: a search with an array filled with sorted random numbers
    void init_sorted_array();
    
    //set_seed function
    //Purpose: set the seed for the rand() funciton
    //Parameters: an int, the seed
    //Returns: none
    //pre-conditions: none
    //post-condition: seed to be used when rand() is called
    void set_seed(int seed);
    
    //getSize function
    //Purpose: get the size of the array in Search object
    ///Parameters: none
    //Returns: an int, the size of the array
    //pre-conditions: none
    //post-condition: size of the array is returned, returns 0 if it's empty
    int getSize() const;
    
   
    
    //operater<< overload
    //purpose: overload<< operator to output a search object
    //parameters: an ostream object and a search object to output
    //returns: ostream object
    //pre-condition: a non empty array
    //post-condition: array in search object is outputed to the console
   friend ostream& operator<< (ostream& out, const Search& s)
    {
        // put the code in here.
        for(unsigned i=0; i<s.getSize(); i++)
        {
            out<<s.search_at(i)<<endl;
        }
        return out;
    }
    
    //Search constructor
    //Purpose: construct a Search object
    //Parameters: int, the size of the array, and an int to set to set the seed to zero or to user's choosing
    //Returns: none
    //pre-conditions: none
    ///post-condition: a search object is initialized
    Search(int size, int seed=0)
    {
        aSize=size;
        //mySeed=seed;
        set_seed(seed);
        array = new int[aSize];
    }
    
    //Search destructor
    //Purpose: return allocated memory to the computer
    //Parameters: none
    //Returns: none
    //pre-condition: int* array is not equal to nullptr
    //post-condition: memory of allocated array is returned to the computer
    ~Search();
    
private:
    //recursive search helper function
    //Purpose:a helper function to search recursively
    //Parameters: int to search, int to represent the beginning of the aray, int to represent the size of the array, int* pointer to the dynamic array to search
    //Returns: bool, if it found the number or not
    //Pre-conditions: non empty array
    //Post-condition: a bool true if found, false otherwise, to return to calling funciton
    bool recursive_search_helper(int num, int first, int size, int* theArray);
    
    //Private variables
  
    int aSize;
    int* array;
    
protected:
    //search_at function
    //Purpose: get number at an a certain index of the array
    //Parameters: an unsigned int, an array index
    //Returns: the int at that index
    //pre-condition: a valid index
    //post-condition: value at index is returned
    int search_at(unsigned i) const
    {
        assert(i<aSize);
        return array[i];
    }
};

