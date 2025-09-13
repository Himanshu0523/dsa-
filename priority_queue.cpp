#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// priority_queue

    // queue, which is FIFO, a priority_queue is a max-heap by default → the largest element has the highest priority.
    //  normal queue(FIFO) , element are ordered by priority (largest/smaller depending on comparator)
    //  binary heap internal implemented



    priority_queue< 
    typename T,                        // data type
    typename Container = vector<T>,    // underlying container
    typename Compare = less<T>> pq;         // comparator
    



int main() {

    
// Max-heap (default) → largest element is on top
priority_queue<int> maxHeap;

// Min-heap → smallest element is on top
priority_queue<int, vector<int>, greater<int>> minHeap;

// With custom comparator
priority_queue<int, vector<int>, MyComparator> customPQ;

// methods all 
    // top() - 
    // empty() -
    // size() - 

    // push(const T& val) -
    // push(T&& val) -
    // emplace(args...) - 
    // pop() - 

    // swap() -


    // internal  Working
    // push() - O(log n) - element is placed in container, heapify min/max heap property
    // pop - top element is removed , heapfiy-down - restore order
    // top() - O(1)
    // size() , empty() - O(1)

    // Max-heap (default)
    priority_queue<int> pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);

    cout << "Top element: " << pq.top() << endl; // 30

    pq.pop();
    cout << "Top after pop: " << pq.top() << endl; // 20

    cout << "Size: " << pq.size() << endl; // 2
    cout << "Empty? " << pq.empty() << endl; // 0 (false)

    // Min-heap
    priority_queue<int, vector<int>, greater<int>> minpq;
    minpq.push(10);
    minpq.push(30);
    minpq.push(20);

    cout << "Min-heap top: " << minpq.top() << endl; // 10


    // Max- heap (default)
    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    cout << pq.top(); // 30


    // Min - Heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    cout << pq.top(); // 10


    struct Compare {
        bool operator() (int a , int b){
            return a > b;  // smaller number has higher priority (min-heap)
        }
    }

    priority_queue<int , vector<int> Compare> pq;


    // Custom Comparator(lambda)
    auto cmp = [] (int a , int b){
        return a > b;
    }
    priority_queue < int , vector<int>, decltype(cmp)> pq(cmp);

    //   heap - complete binary tree stored in array
        // parent node at time i =>  (i - 1)/2 
        // left child node ar index i => 2* i + 1
        // right child => 2* i + 2



        // push(x) → constructs an object x, then copies/moves it into the container.

        // emplace(args...) → constructs the object in place inside the container.

        // This avoids unnecessary copies → faster and memory efficient


    // ✔️ Always empty() check before front() / pop().
    // ✔️ Prefer emplace → avoids extra copies.
    // ✔️ Use queue for pure FIFO, deque for FIFO + random access.
    // ✔️ Use swap to clear quickly.
    // ✔️ No iterators → use a temp queue for debugging.
    // ✔️ Pick the right container adapter for the problem.


        Why This Matters in CP / Real Projects?
        C++11: emplace & move → write faster, memory-efficient code.
        C++17: CTAD → less verbose, cleaner contest code.
        C++20: constexpr queues → useful in compile-time testing, meta-programming, and guaranteed noexcept swap.
}
