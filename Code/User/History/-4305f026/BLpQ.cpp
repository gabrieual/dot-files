#include <iostream>
#include <ostream>
#include <string>


using namespace std;

const int SIZE = 101;
const int PROBES = 20;

struct Entry {
    string key;
    bool is_empty;
    bool is_deleted;

    Entry() : is_empty(true), is_deleted(false) {}
};

int Hash(const string& key) {
    long long h = 0;
    for (size_t i = 0; i < key.length(); i++) {
        h += static_cast<int>(key[i]) * (i + 1);
    }
    h = (h * 19) % 101;
    return h;
}

class HashTable {
private:
    Entry table[SIZE];
    int len;

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i].is_empty = true;
            table[i].is_deleted = false;
        }
        len = 0;
    }

    string operator[](int hashed_key){return table[hashed_key].key;}

    int find(const string& key) {
        int hash_value = Hash(key);
        
        for (int j = 0; j < PROBES; j++) {
            int index;
            if (j == 0) {
                index = hash_value;
            } else {
                index = (hash_value + j*j + 23*j) % SIZE;
            }
            
            if (table[index].is_empty && !table[index].is_deleted) {
                return -1;
            }
            
            if (!table[index].is_empty && table[index].key == key) {
                return index;
            }
        }
        
        return -1;
    }

    bool insert(const string& key) {
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
            
            if (table[index].is_empty || table[index].is_deleted) {
                table[index].key = key;
                table[index].is_empty = false;
                table[index].is_deleted = false;
                return true;
                len += 1;
            }
        }
        
        return false;
    }

    bool remove(const string& key) {
        int index = find(key);
        if (index == -1) {
        }
        if (!table[index].is_empty || !table[index].is_deleted){
            table[index].is_deleted = true;
            table[index].is_empty = true;
            len -= 1;
        }
        return true;
    }

    int length() {
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
            
            size_t colonPos = operation.find(':');
            string command = operation.substr(0, colonPos);
            string key = operation.substr(colonPos + 1);
            
            if (command == "ADD") {
                hashTable.insert(key);
            } else if (command == "DEL") {
                hashTable.remove(key);
            }
        }
        
        cout << hashTable.length() << endl;
        Entry q = hashTable[2];
        for (int j=0;j<SIZE;j++){
            if (!hashTable[j].is_empty()){
                cout << hashTable[j]<<endl;
            }
        }
    }
    
    return 0;
}