#include <iostream>
#include <string>
#define LEN 101
#define EMPTY "-1"
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

    int hash(string key){
        int hashed_key=0;
        for (int i = 0; i<key.length(); i++) {
            hashed_key += (i+1) * static_cast<int>(key[i]);
        }
        return hashed_key * 19;
    }

    int length(){
        return len;
    }

    string operator[](int key){
        return "";
    }

    void add(string value){
        len += 1;
    }

    void del(string value){
        len -= 1;
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
            string instruction, value;
            cin >> instruction >> value;
            
            if (instruction == "ADD"){
                table.add(value);
            }else if (instruction == "DEL"){
                table.del(value);
            }
        }
        cout << table.length() << endl;
        for (int z=0;z<LEN;z++){
            cout << z << ":" << table[z] << endl;
        }
    }
    return 0;
}