# Unordered Map in C++

Unordered map is an associative container that contains **key-value pairs with unique keys**. Search, insertion, and removal of elements have **average constant-time complexity**.

Internally, the elements are **not** sorted in any particular order, but organized into **buckets**. Which bucket an element is placed into depends entirely on the hash of its key. This allows fast access to individual elements, since once the hash is computed, it refers to the exact bucket the element is placed into.

## Some Member Functions
### Capacity
|Function|Description|
|:-:|:-:|
|empty|checks whether the container is empty|
|size|returns the number of elements|
|max_size|returns the maximum possible number of elements|

### Modifiers
|Function|Description|
|:-:|:-:|
|clear|clears the contents|
|insert|inserts elements or nodes (since C++17)|
|erase|erases elements|
|swap|swaps the contents|
|merge|(C++17) splices nodes from another container|

### Look up
|Function|Description|
|:-:|:-:|
|operator[ ]|access or insert specified element|
|count|returns the number of elements matching specific key|
|find|finds element with specific key|
|contains|(C++20) checks if the container contains element with specific key|
|equal_range|returns range of elements matching a specific key|

## Example
### Code
```
#include <iostream>
#include <string>
#include <unordered_map>
 
int main()
{
    // Create an unordered_map of three strings (that map to strings)
    std::unordered_map<std::string, std::string> u = {
        {"RED","#FF0000"},
        {"GREEN","#00FF00"},
        {"BLUE","#0000FF"}
    };
 
    // Iterate and print keys and values of unordered_map
    for( const auto& n : u ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
 
    // Add two new entries to the unordered_map
    u["BLACK"] = "#000000";
    u["WHITE"] = "#FFFFFF";
 
    // Output values by key
    std::cout << "The HEX of color RED is:[" << u["RED"] << "]\n";
    std::cout << "The HEX of color BLACK is:[" << u["BLACK"] << "]\n";
 
    return 0;
}
```

### Output:
```
Key:[RED] Value:[#FF0000]
Key:[BLUE] Value:[#0000FF]
Key:[GREEN] Value:[#00FF00]
The HEX of color RED is:[#FF0000]
The HEX of color BLACK is:[#000000]
```