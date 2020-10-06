/* **************************************************************************************************
LeetCode #380
	Insert Delete GetRandom O(1)

Description:
	Implement the `RandomizedSet` class:
		+ bool insert(int val)
			Inserts an item val into the set if not present. 
			Returns `true` if the item was not present, false otherwise.
		+ bool remove(int val)
			Removes an item val from the set if present. 
			Returns `true` if the item was present, false otherwise.
		+ int getRandom()
			Returns a random element from the current set of elements 
			(it's guaranteed that at least one element exists when this method is called). 
			Each element must have the **same probability** of being returned.

Follow up:
	Could you implement the functions of the class with each function works in **average** `O(1)` time?
******************************************************************************************************* */

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

#include "RandomizedSet.h"

int main() {
	RandomizedSet* randomizedSet = new RandomizedSet();

	randomizedSet->insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
	randomizedSet->printSet();

	randomizedSet->remove(2); // Returns false as 2 does not exist in the set.
	randomizedSet->printSet();

	randomizedSet->insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
	randomizedSet->printSet();

	randomizedSet->getRandom(); // getRandom() should return either 1 or 2 randomly.
	randomizedSet->printSet();

	randomizedSet->remove(1); // Removes 1 from the set, returns true. Set now contains [2].
	randomizedSet->printSet();

	randomizedSet->insert(2); // 2 was already in the set, so return false.
	randomizedSet->printSet();

	randomizedSet->getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
	randomizedSet->printSet();
}