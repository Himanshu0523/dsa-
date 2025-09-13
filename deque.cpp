#include<iostream>
#include<deque>
using namespace std;

#define x 12
/*
    std::deque (Double Ended Queue)
        is a sequence container in C++ STL (Standard Template Library)
        allows fast insertion and deletion at both the front and the back.

    //  Internal Implementation


*/
 
/*   Thread safety
        A piece of code or a function behaves correctly when multiple threads access it simultaneously.
        if not Thread safe 
                cause - Race condition , Crashes , Undefined Behavior , data corruption
*/

/*  No bounds checks
        access an index that is out of range, it won’t throw an error — instead, it results in undefined behavior.
        code :- 
            std::deque<int> dq = {10, 20, 30};
            std::cout << dq[1] << "\n";  // ✅ 20 (safe)
            std::cout << dq[10] << "\n"; // ⚠️ No error, but undefined behavior!

        safe Alternative    .at(index)
            std::cout << dq.at(1);   // ✅ Works: prints 20
            std::cout << dq.at(10);  // ❌ Throws std::out_of_range exception

*/
/*  Buffers
        is a temporary storage area , to astored before it's processed or moved.
*/

int main() {

    // Syntax
    std::deque <int> dq;

    // Constructors
        deque<int> dq1;                         // empty deque
        deque<int> dq2(5);                      // deque of size 5 (all zeros)
        deque<int> dq3(5, 100);                 // {100, 100, 100, 100, 100}
        deque<int> dq4 = {1, 2, 3, 4};          // initializer list
        deque<int> dq5(dq3.begin(), dq3.end()); // range constructor

    // Element Access
    /*
        dq[i]	    Access ith element (no bounds check)
        dq.at(i)	Bounds-checked access
        dq.front()	First element
        dq.back()	Last element
    */

    // key characteristics
    /*
        Random Access                       in constant time 
        Insertion / Delection(front/back)    O(1)
        insertion / Delection(Middle)        O(n)

        Memory               Multiple chunks of memory(not contiguous like vector)
        Thread Safety        Not thread-safe
    */ 

    // Key operation
    /*
        | Operation         | Function               | Time |

        | Insert at back    | dq.push_back(x)        | O(1) |
        | Insert at front   | dq.push_front(x)       | O(1) |
        | Delete from back  | dq.pop_back()          | O(1) |
        | Delete from front | dq.pop_front()         | O(1) |
        | Access front/back | dq.front() / dq.back() | O(1) |
        | Access element    | dq[i], dq.at(i)        | O(1) |
        | Clear all         | dq.clear()             | O(n) |
        | Resize deque      | dq.resize(n)           | O(n) |

    */

    // Capacity Function
         dq.size();            // No. of elements
         dq.empty();           // true if dq is empty
    
    // Iterators
        dq.begin() , dq.end();         // Forward iteration
        dq.rbegin(), dq.rend();        // Reverse iteration
    
    // Range loop 
        for (int xp : dq) cout << xp << " ";

    // Emplace (c++11+)
    dq.emplace_back(x);      // Insert at back (faster than push_back)
    dq.emplace_front(x);     // Insert at front



    /*
        | Feature        | vector     | deque    | list     |
        | Random Access  | ✅        | ✅       | ❌      |
        | Front Insert   | ❌ O(n)   | ✅ O(1)  | ✅ O(1) |
        | Back Insert    | ✅ O(1)   | ✅ O(1)  | ✅ O(1) |
        | Cache Locality | ✅        | ❌       | ❌      |

    */
    return 0;
}
