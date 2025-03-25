#include <iostream>
#include <string>
#define LEN 101
#define EMPTY "-1"
using namespace std;

class HashTable{
private: 
    string arr[LEN];
public:
    HashTable(){
        for (int i=0; i<LEN; i++) {
            arr[i] = EMPTY;
        }
    }

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
        for (int j=0; j<n; j++) {
            string instruction, value;
            cin >> instruction >> value;
            if (instruction == "ADD"){

            }else if (instruction == "DEL"){
                
            }
            

        }
    }
    return 0;
}