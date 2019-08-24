#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Problem statement: https://leetcode.com/contest/biweekly-contest-7/problems/design-file-system/

// Input: 
// ["FileSystem","create","get"]
// [[],["/a",1],["/a"]]
// 
// Output: 
// [null,true,1]
// 
// Explanation: 
//
// FileSystem fileSystem = new FileSystem();
// fileSystem.create("/a", 1); // return true
// fileSystem.get("/a"); // return 1

// Input: 
// ["FileSystem","create","create","get","create","get"]
// [[],["/leet",1],["/leet/code",2],["/leet/code"],["/c/d",1],["/c"]]
//
// Output: 
// [null,true,true,2,false,-1]
//
// Explanation: 
//
// FileSystem fileSystem = new FileSystem();
// fileSystem.create("/leet", 1); // return true
// fileSystem.create("/leet/code", 2); // return true
// fileSystem.get("/leet/code"); // return 2
// fileSystem.create("/c/d", 1); // return false because the parent path "/c" doesn't exist.
// fileSystem.get("/c"); // return -1 because this path doesn't exist.

class FileSystem {
private:    
        unordered_map<string, int> map;
public:
    bool create(string path, int value) {
        // if path is "/leetcode/a"
        // then parent will be "/leetcode"
        auto parent = string(path.begin(), path.end() + path.rfind('/'));

        if (!parent.empty() && !map.count(parent)) {
            return false;
        }

        return map.emplace(path, value).second;
    }
    
    int get(string path) {
        auto it = map.find(path);
        // if found
        if (it != map.end()) {
            return it->second;
        }
        return -1;
    }
};
