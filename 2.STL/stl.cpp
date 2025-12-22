#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm> // Required for STL algorithms
#include <iterator>  // Required for iterator adaptors
#include <deque>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>

// --- Function to print elements of any container ---
// This is a template function, so it can work with different container types (vector, list, etc.).
template<typename T>
void printContainer(const T& container, const std::string& name) {
    std::cout << "---- " << name << " ----" << std::endl;
    // An iterator is an object that points to an element inside the container.
    // 'cbegin()' returns a constant iterator to the beginning.
    // 'cend()' returns a constant iterator to the end (one past the last element).
    for (auto it = container.cbegin(); it != container.cend(); ++it) {
        // We use the '*' operator to dereference the iterator and get the value.
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;
}

int main() {
    // ====================================================================
    // 1. CONTAINERS - Objects that store data.
    // ====================================================================

    // A. `std::vector` - A dynamic array that can grow or shrink in size.
    std::vector<int> numbers = {5, 2, 8, 1, 9};
    numbers.push_back(3); // Add an element to the end.
    printContainer(numbers, "Vector (after push_back)");

    // B. `std::list` - A doubly-linked list. Good for fast insertions and deletions.
    std::list<std::string> fruits = {"Apple", "Banana", "Cherry"};
    fruits.push_front("Orange"); // Add to the front.
    printContainer(fruits, "List");

    // C. `std::set` - A collection of unique, sorted elements.
    std::set<int> unique_numbers = {4, 1, 8, 4, 5, 1}; // Duplicates are automatically removed.
    unique_numbers.insert(2);
    printContainer(unique_numbers, "Set (stores unique, sorted elements)");

    // D. `std::map` - A collection of key-value pairs, with unique keys.
    std::map<std::string, int> ages;
    ages["Alice"] = 30;
    ages["Bob"] = 25;
    ages["Charlie"] = 30;
    std::cout << "---- Map (Key-Value Pairs) ----" << std::endl;
    // Iterate through a map to see keys and values.
    for (const auto& pair : ages) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    std::cout << std::endl;

    // E. `std::deque` (Double-Ended Queue) - Like a vector, but with fast insertions/deletions at both ends.
    std::deque<int> d_numbers = {10, 20, 30};
    d_numbers.push_front(5);  // Fast insertion at the front
    d_numbers.push_back(40); // Fast insertion at the back
    printContainer(d_numbers, "Deque");

    // F. `std::unordered_set` - Like a set, but elements are not sorted. Uses hashing for faster lookups.
    std::unordered_set<int> unique_items = {100, 20, 500, 20, 100}; // Order not guaranteed
    unique_items.insert(30);
    printContainer(unique_items, "Unordered Set (unique, unordered elements)");

    // G. `std::unordered_map` - Like a map, but key-value pairs are not sorted by key. Faster than map.
    std::unordered_map<std::string, std::string> capitals;
    capitals["USA"] = "Washington D.C.";
    capitals["France"] = "Paris";
    capitals["Japan"] = "Tokyo";
    std::cout << "---- Unordered Map (Unordered Key-Value Pairs) ----" << std::endl;
    for (const auto& pair : capitals) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    std::cout << std::endl;


    // ====================================================================
    // 1.5. CONTAINER ADAPTORS - LIFO/FIFO data structures.
    // ====================================================================
    // These adapt other containers (like vector, list, or deque) to provide a specific interface.
    // They don't have iterators, so we can't use `printContainer`.

    // A. `std::stack` - Last-In, First-Out (LIFO).
    std::cout << "---- Stack (LIFO) ----" << std::endl;
    std::stack<std::string> books;
    books.push("The Hobbit");
    books.push("A Tale of Two Cities");
    books.push("Moby Dick");

    std::cout << "Top of stack: " << books.top() << std::endl;
    std::cout << "Processing books from the stack:" << std::endl;
    while (!books.empty()) {
        std::cout << "  - Popping: " << books.top() << std::endl;
        books.pop(); // Removes the top element.
    }
    std::cout << std::endl;

    // B. `std::queue` - First-In, First-Out (FIFO).
    std::cout << "---- Queue (FIFO) ----" << std::endl;
    std::queue<std::string> line;
    line.push("Person 1");
    line.push("Person 2");
    line.push("Person 3");

    std::cout << "Front of queue: " << line.front() << std::endl;
    std::cout << "Processing people from the queue:" << std::endl;
    while (!line.empty()) {
        std::cout << "  - Serving: " << line.front() << std::endl;
        line.pop(); // Removes the front element.
    }
    std::cout << std::endl;

    // C. `std::priority_queue` - The element with the highest value is always at the top.
    std::cout << "---- Priority Queue ----" << std::endl;
    std::priority_queue<int> high_scores;
    high_scores.push(85);
    high_scores.push(92);
    high_scores.push(78);
    high_scores.push(95);

    std::cout << "Highest score: " << high_scores.top() << std::endl;
    std::cout << "Processing scores from highest to lowest:" << std::endl;
    while (!high_scores.empty()) {
        std::cout << "  - " << high_scores.top() << std::endl;
        high_scores.pop();
    }
    std::cout << std::endl;


    // ====================================================================
    // 2. ITERATORS - Objects to traverse containers.
    // ====================================================================
    // We've already been using iterators in `printContainer`. Let's explore more.

    std::cout << "---- Iterators in Action (Vector) ----" << std::endl;
    std::vector<int>::iterator vec_it; // Declare an iterator for a vector of ints.

    // `begin()` points to the first element.
    vec_it = numbers.begin();
    std::cout << "First element: " << *vec_it << std::endl;

    // We can move iterators. `std::next` is a safe way to advance it.
    auto next_it = std::next(vec_it, 2); // Move 2 positions forward.
    std::cout << "Third element: " << *next_it << std::endl;

    // Reverse iterators: Traverse the container backward.
    std::cout << "Vector in reverse: ";
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;


    // ====================================================================
    // 3. ALGORITHMS - Functions that perform operations on containers.
    // ====================================================================
    // Algorithms operate on ranges specified by iterators.

    // A. `std::sort` - Sorts a range of elements. (Not applicable for list, set, map).
    std::sort(numbers.begin(), numbers.end());
    printContainer(numbers, "Vector (after sort)");

    // B. `std::find` - Finds the first occurrence of a value in a range.
    int value_to_find = 8;
    // `find` returns an iterator to the found element, or the `end()` iterator if not found.
    auto found_it = std::find(numbers.begin(), numbers.end(), value_to_find);
    if (found_it != numbers.end()) {
        std::cout << "Value " << value_to_find << " found in the vector." << std::endl;
    } else {
        std::cout << "Value " << value_to_find << " not found." << std::endl;
    }
    std::cout << std::endl;

    // C. `std::for_each` - Applies a function to each element in a range.
    std::cout << "---- Using for_each to double vector elements ----" << std::endl;
    // The function is provided as a lambda expression here.
    std::for_each(numbers.begin(), numbers.end(), [](int& n){ n *= 2; });
    printContainer(numbers, "Vector (after for_each)");

    // D. `std::count` - Counts occurrences of a value in a range.
    int count_of_10 = std::count(numbers.begin(), numbers.end(), 10); // Should be 1, because 5*2=10
    std::cout << "The number 10 appears " << count_of_10 << " time(s)." << std::endl << std::endl;

    // E. `std::transform` - Creates a new sequence by transforming elements from another.
    std::vector<int> squares;
    // Reserve space to avoid reallocations
    squares.resize(numbers.size());
    // `back_inserter` is an iterator adaptor that allows adding elements to the back of a container.
    std::transform(numbers.begin(), numbers.end(), squares.begin(), [](int n) {
        return n * n;
    });
    printContainer(squares, "New Vector (squares of the doubled numbers)");

    return 0;
}

