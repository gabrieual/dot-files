#include <iostream>
#include <ostream>
#include <string>


using namespace std;

const int SIZE = 101;
const int PROBES = 20;

struct Entry {
    string key;
    bool is_valid;

Entry() : is_valid(false) {}
};

int Hash(const string& key) {
    long long h = 0;
    for (size_t i = 0; i < key.length(); i++) {
        h += static_cast<int>(key[i]) * (i + 1);
    }
    h = (h * 19) % SIZE;
    return h;
}

class HashTable {
private:
    Entry table[SIZE];
    short len;

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i].is_valid = false;
        }
        len = 0;
    }

    Entry operator[](int hashed_key){return table[hashed_key];}

    int find(string key) {
        int hash_value = Hash(key);
        
        for (int j = 0; j < PROBES; j++) {
            int index;
            if (j == 0) {
                index = hash_value;
            } else {
                index = (hash_value + j*j + 23*j) % SIZE;
            }
            
            if (!table[index].is_valid) {
                return -1;
            }
            
            if (table[index].is_valid && table[index].key == key) {
                return index;
            }
        }
        
        return -1;
    }

    bool insert(string key) {
        if (find(key) != -1) {
            return false;
        }
        
        int hash_value = Hash(key);
        
        for (int j = 0; j < PROBES; j++) {
            int index;
            if (j == 0) {
                index = hash_value;
            } else {
                index = (hash_value + j*j + 23*j) % SIZE;
            }
            
            if (!table[index].is_valid) {
                len += 1;
                table[index].key = key;
                table[index].is_valid = true;
                return true;
            }
        }
        
        return false;
    }

    bool remove(string key) {
        int index = find(key);
        if (index == -1) {return false;}
        if (table[index].is_valid){
            len -= 1;
            table[index].is_valid = false;
        }
        return true;
    }

    short length() {
        return len;
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
                        
            string command = operation.substr(0, 3);
            string key = operation.substr(4);
            
            if (command == "ADD") {
                hashTable.insert(key);
            } else if (command == "DEL") {
                hashTable.remove(key);
            }
        }
        
        cout << hashTable.length() << endl;
        for (int j=0;j<SIZE;j++){
            if (hashTable[j].is_valid){
                cout << j << ":" << hashTable[j].key << endl;
            }
        }
    }
    
    return 0;
}