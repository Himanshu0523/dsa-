#include<iostream>
#include <vector>

using namespace std;


int main() {

    // in 1D
    vector<int> v(10);

    // in 2d
    vector<vector<int>> mat(5, vector<int>(5));

    // Declaration and Initialization
        /*  
            vector<int> v1;                 // empty vector
            vector<int> v2(5);              // size 5, default initialized (0) 
            vector<int> v3(5, 10);          // size 5, all values = 10
            vector<int> v4 = {1 , 2, 3, 4}; // initializer list
            vector<int> v5(v4);                 // copy constructor
        */

    // Member Functions
        // Capacity Functions
            /*
                size()           Number of elements
                capacity()       Size of allocated memory (>= size)
                max_size()       Max possible elements
                empty()          returns true if vector is empty
                resize(n)        resizes to n elements
                shrink_to_fit()  Reduces capacity to match size
                reserve(n)       Pre-allocates memory foe at least n elements 
            */
        // Element Access
            /*
                operator[]   Access without bounds check
                at(i)        Access with bounds check
                froont()     first element 
                back()       last element
                data()       pointer to internal array
            */
        // Modifiers
            /*
                push_back()             adds elements at end
                pop_back()              remove last element
                inserrt(pos ,val)       inserts element at position 
                erase(pos)              Erases element at position 
                clear()                 removes all elements
                emplace(pos , ars....)  constructs element in-place
                emplace_back(args....)  in-place construct at end
                assign(count , value)   assign new values
                swap(vec2)              swaps contents with vec2

            */


    // Iterators
        /*
            begin()   iterator to first element
            end()     iterator to past-the-ends elements 
            rbegin()  reverse iterator to last
            rens()    reverse iterator to before-first
            cbegin()  const begin
            cend()    const end

        */

    // Performance
         /*
            Access[]             O(1)
            push_back()          O(1)
            insert()             O(n)
            erase()              O(n)
            clear()              O(n)     
         */

    // Memory Management
        /*
            vector used heap allocation.
            Grows by doubling capacity when needed (amortized cost).
            reserve() can present reallocations if size known in advance.
        */

    // Pitfalls and tips
        /*
            Prefer at() fro safety (with bounds check).
            use reserve() when adding amny elelments.
            avoid using vector<bool>  - it's bit packed and not a real vector of bools.
        */ 



    /*  Why to Avoid std::vector<bool>
            Bit-packed :- stortes 1 bit , not real bool values 
            No real reference : vb[i] give proxy , not bool&
            No address : &vb[i] - invalid
            Breaks templates - Generic code may not work 
            Debug-unfriendly - Compressed internals haed to inspect

    */

    return 0;
}
