#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

/**
 * @file map.cpp
 * @brief Demonstrates the usage of std::map, std::multimap, and std::unordered_map in C++.
 *
 * This program creates a map, multimap, and unordered_map of strings to integers and performs various operations
 * such as insertion, access, search, iteration, deletion, and clearing of elements.
 * 
 * The std::map is implemented using a self-balancing binary search tree, typically a Red-Black Tree.
 * The std::multimap allows multiple elements with the same key.
 * The std::unordered_map is implemented using a hash table.
 *
 * Operations and their time complexities:
 * - Insertion: O(log n) for map and multimap, O(1) average for unordered_map
 * - Access: O(log n) for map and multimap, O(1) average for unordered_map
 * - Search: O(log n) for map and multimap, O(1) average for unordered_map
 * - Iteration: O(n) for all
 * - Deletion: O(log n) for map and multimap, O(1) average for unordered_map
 * - Size: O(1) for all
 * - Clear: O(n) for all
 *
 * @return int Returns 0 upon successful execution.
 */

void demonstrateMap() {
    // Create a map of strings to integers
    map<string, int> myMap;

    // Insert some values into the map using operator[]
    myMap["apple"] = 1;  // O(log n) insertion
    myMap["banana"] = 2; // O(log n) insertion
    myMap["cherry"] = 3; // O(log n) insertion

    // Access and print values in the map using operator[]
    cout << "apple: " << myMap["apple"] << endl;   // O(log n) access
    cout << "banana: " << myMap["banana"] << endl; // O(log n) access
    cout << "cherry: " << myMap["cherry"] << endl; // O(log n) access

    // Check if a key exists in the map using find()
    if (myMap.find("date") != myMap.end()) { // O(log n) search
        cout << "date is in the map" << endl;
    } else {
        cout << "date is not in the map" << endl;
    }

    // Iterate over the map and print all key-value pairs
    for (const auto& pair : myMap) { // O(n) iteration
        cout << pair.first << ": " << pair.second << endl;
    }

    // Erase an element by key
    myMap.erase("banana"); // O(log n) deletion

    // Size of the map
    cout << "Size of the map: " << myMap.size() << endl; // O(1) size

    // Clear all elements in the map
    myMap.clear(); // O(n) clear
}

void demonstrateMultimap() {
    // Create a multimap of strings to integers
    multimap<string, int> myMultimap;

    // Insert some values into the multimap using insert()
    myMultimap.insert({"apple", 1});  // O(log n) insertion
    myMultimap.insert({"banana", 2}); // O(log n) insertion
    myMultimap.insert({"cherry", 3}); // O(log n) insertion
    myMultimap.insert({"apple", 4});  // O(log n) insertion

    // Iterate over the multimap and print all key-value pairs
    for (const auto& pair : myMultimap) { // O(n) iteration
        cout << pair.first << ": " << pair.second << endl;
    }

    // Erase an element by key
    myMultimap.erase("banana"); // O(log n) deletion

    // Size of the multimap
    cout << "Size of the multimap: " << myMultimap.size() << endl; // O(1) size

    // Clear all elements in the multimap
    myMultimap.clear(); // O(n) clear
}

void demonstrateUnorderedMap() {
    // Create an unordered_map of strings to integers
    unordered_map<string, int> myUnorderedMap;

    // Insert some values into the unordered_map using operator[]
    myUnorderedMap["apple"] = 1;  // O(1) average insertion
    myUnorderedMap["banana"] = 2; // O(1) average insertion
    myUnorderedMap["cherry"] = 3; // O(1) average insertion

    // Access and print values in the unordered_map using operator[]
    cout << "apple: " << myUnorderedMap["apple"] << endl;   // O(1) average access
    cout << "banana: " << myUnorderedMap["banana"] << endl; // O(1) average access
    cout << "cherry: " << myUnorderedMap["cherry"] << endl; // O(1) average access

    // Check if a key exists in the unordered_map using find()
    if (myUnorderedMap.find("date") != myUnorderedMap.end()) { // O(1) average search
        cout << "date is in the unordered_map" << endl;
    } else {
        cout << "date is not in the unordered_map" << endl;
    }

    // Iterate over the unordered_map and print all key-value pairs
    for (const auto& pair : myUnorderedMap) { // O(n) iteration
        cout << pair.first << ": " << pair.second << endl;
    }

    // Erase an element by key
    myUnorderedMap.erase("banana"); // O(1) average deletion

    // Size of the unordered_map
    cout << "Size of the unordered_map: " << myUnorderedMap.size() << endl; // O(1) size

    // Clear all elements in the unordered_map
    myUnorderedMap.clear(); // O(n) clear
}

int main() {
    cout << "Demonstrating std::map:" << endl;
    demonstrateMap();

    cout << "\nDemonstrating std::multimap:" << endl;
    demonstrateMultimap();

    cout << "\nDemonstrating std::unordered_map:" << endl;
    demonstrateUnorderedMap();

    return 0;
}