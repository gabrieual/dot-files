#include <iostream>
#include <string>
#define LEN 101
#define EMPTY "."
using namespace std;

class HashTable{
private: 
    string arr[LEN];
    int len;
public:
    HashTable(){
        for (int i=0; i<LEN; i++) {
            arr[i] = EMPTY;
        }
        len = 0;
    }

    int hash(string value){
        int hashed_key=0;
        for (int i = 0; i<value.length(); i++) {
            hashed_key += 19 * (i+1) * static_cast<int>(value[i]);
        }
        return hashed_key;
    }

    int length(){
        return len;
    }

    string operator[](int key){
        if (key < 0 || key > LEN){return EMPTY;}
        return arr[key];
    }

    void add(string value){
        int hashed = hash(value);
        for (int i=0; i<20; i++) {
            int key = (hashed + (i*i) + (23*i)) % LEN;
            if (arr[key] == value){return;}
            if (arr[key] == EMPTY){
                arr[key] = value;
                len += 1;
                return;
            }
        }
    }

    void del(string value){
        int hashed = hash(value);
        for (int i=0; i<20; i++) {
            int key = (hashed + (i*i) + (23*i)) % LEN;
            if (arr[key] == value){
                arr[key] = EMPTY;
                len -= 1;
                return;
            }
        }
    }

};

int main(){
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        int n;
        cin >> n;

        HashTable table;
        for (int j=0; j<n; j++) {
            string command;
            cin >> command;

            string instruction = command.substr(0,3);
            string value = command.substr(4);

            if (instruction == "ADD"){
                table.add(value);
            }else if (instruction == "DEL"){
                table.del(value);
            }
        }
        cout << table.length() << endl;
        for (int z=0;z<LEN;z++){
            if (table[z] != EMPTY){
                cout << z << ":" << table[z] << endl;
            }
        }
    }
    return 0;
}