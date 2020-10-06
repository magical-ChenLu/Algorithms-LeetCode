#pragma once
#include <unordered_map>
#include <vector>

class RandomizedSet {
public:
    vector<int> nums;   // Store the values of elements
    unordered_map<int, int> val2Index;  // Record the index of each element

    /** Initialize your data structure here. */
    RandomizedSet() {

    }


    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        // If input value is already in our RandomizedSet, do not insert again
        if (val2Index.count(val)) {
            cout << "Insert Error: number " << val << " already exist!" << endl;
            return false;
        }

        // If input value is not in our RandomizedSet, insert to the back
        // and record its index number
        val2Index[val] = nums.size();
        nums.push_back(val);

        cout << "Insert number " << val << " successfully!" << endl;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        // If input value is not in our RandomizedSet, no need to remove
        if (!val2Index.count(val)) {
            cout << "Remove Error: number " << val << " is not in RandomizedSet!" << endl;
            return false;
        }

        // Get the index of value
        int index = val2Index[val];
        // Change the index of the last element to 'index'
        val2Index[nums.back()] = index;
        // Swap values
        swap(nums[index], nums.back());
        // Delete element
        nums.pop_back();
        val2Index.erase(val);

        cout << "Remove number " << val << " successfully!" << endl;
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int val = nums[rand() % nums.size()];
        cout << "Get number " << val << " successfully!" << endl;
        return val;
    }

    /** Print out the elements in the set **/
    void printSet() {
        cout << "Current elements in RandomizedSet: ";
        for (int i = 0; i < nums.size(); i++)
            cout << nums[i] << ", ";
        cout << endl << endl;
    }
};