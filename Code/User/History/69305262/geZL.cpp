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

    int length(){
        return len;
    }

    string operator[](){}

    void add(string value){

    }

    void del(string value){

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
            cout << table[z];
        }
    }
    return 0;
}