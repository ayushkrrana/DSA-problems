#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

class NumberContainers {
public:
    unordered_map<int, int> indexMap;  // {index → number}
    map<int, set<int>> numberMap;      // {number → set of indexes}

    NumberContainers() {}

    void change(int index, int number) {
        if (indexMap.find(index) != indexMap.end()) {
            int oldNumber = indexMap[index];  
            numberMap[oldNumber].erase(index);  // Remove index from old number set
            if (numberMap[oldNumber].empty()) {
                numberMap.erase(oldNumber);
            }
        }
        indexMap[index] = number; 
        numberMap[number].insert(index); 
    }

    int find(int number) {
        if (numberMap.find(number) == numberMap.end() || numberMap[number].empty()) 
            return -1;
        return *numberMap[number].begin();  // Get smallest index
    }
};

