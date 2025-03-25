#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int TABLE_SIZE = 101;
const int MAX_PROBES = 20;

// Structure to represent entries in the hash table
struct Entry {
    string key;
    bool isEmpty;
    bool isDeleted;

    Entry() : isEmpty(true), isDeleted(false) {}
};

// Hash function as defined in the problem
int Hash(const string& key) {
    long long h = 0;
    for (size_t i = 0; i < key.length(); i++) {
        h += static_cast<int>(key[i]) * (i + 1);
    }
    h = (h * 19) % 101;
    return h;
}

// Hash table class
class HashTable {
private:
    Entry table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i].isEmpty = true;
            table[i].isDeleted = false;
        }
    }

    // Find the index of the element with the given key
    int find(const string& key) {
        int hashValue = Hash(key);
        
        for (int j = 0; j < MAX_PROBES; j++) {
            int index;
            if (j == 0) {
                index = hashValue;
            } else {
                index = (hashValue + j*j + 23*j) % TABLE_SIZE;
            }
            
            if (table[index].isEmpty && !table[index].isDeleted) {
                // Element not found
                return -1;
            }
            
            if (!table[index].isEmpty && table[index].key == key) {
                // Element found
                return index;
            }
        }
        
        // Element not found after MAX_PROBES
        return -1;
    }

    // Insert a new key into the table
    bool insert(const string& key) {
        // Check if key already exists
        if (find(key) != -1) {
            return false; // Key already exists
        }
        
        int hashValue = Hash(key);
        
        for (int j = 0; j < MAX_PROBES; j++) {
            int index;
            if (j == 0) {
                index = hashValue;
            } else {
                index = (hashValue + j*j + 23*j) % TABLE_SIZE;
            }
            
            if (table[index].isEmpty || table[index].isDeleted) {
                // Found an empty or deleted slot
                table[index].key = key;
                table[index].isEmpty = false;
                table[index].isDeleted = false;
                return true;
            }
        }
        
        // Could not insert after MAX_PROBES
        return false;
    }

    // Delete a key from the table
    bool remove(const string& key) {
        int index = find(key);
        if (index == -1) {
            return false; // Key not found
        }
        
        // Mark as deleted
        table[index].isDeleted = true;
        table[index].isEmpty = true;
        return true;
    }

    // Get the number of keys in the table
    int count() {
        int cnt = 0;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (!table[i].isEmpty && !table[i].isDeleted) {
                cnt++;
            }
        }
        return cnt;
    }

    // Print all non-empty entries sorted by index
    void printEntries() {
        // Create a temporary array to store non-empty entries
        pair<int, string> entries[TABLE_SIZE];
        int entryCount = 0;
        
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (!table[i].isEmpty && !table[i].isDeleted) {
                entries[entryCount++] = make_pair(i, table[i].key);
            }
        }
        
        // Sort entries by index
        sort(entries, entries + entryCount);
        
        for (int i = 0; i < entryCount; i++) {
            cout << entries[i].first << ":" << entries[i].second << endl;
        }
    }
};

int main() {
    int t;
    cin >> t;
    
    for (int testCase = 0; testCase < t; testCase++) {
        int n;
        cin >> n;
        
        HashTable hashTable;
        
        for (int i = 0; i < n; i++) {
            string operation;
            cin >> operation;
            
            size_t colonPos = operation.find(':');
            string command = operation.substr(0, colonPos);
            string key = operation.substr(colonPos + 1);
            
            if (command == "ADD") {
                hashTable.insert(key);
            } else if (command == "DEL") {
                hashTable.remove(key);
            }
        }
        
        cout << hashTable.count() << endl;
        hashTable.printEntries();
    }
    
    return 0;
}