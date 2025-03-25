
#include <iostream>
#include <string>
#define LEN 101
#define EMPTY "-1"

class HashTable {
private:
    std::string arr[LEN];
    int length;
public:
    HashTable() {
        length = 0;
        for (int i=0; i<LEN; i++){
            arr[i] = EMPTY;
        }
    }

    int getlength(){return length;}

    std::string operator[](int index){
        if (index > LEN || index < 0){throw "fora do range";} 
        return arr[index];
    }

    int hash(std::string key){
        int sum = 0;
        for (int i = 0; i < key.length(); i++){
            sum += ( (i+1) * static_cast<int>(key[i]) );
        }
        sum *= 19;
        return sum;
    }

    int offset(int i){
        return (i*i)+(23*i);
    }

    void add(std::string key){
        int hash_key = hash(key);
        for (int i=0; i<20; i++){
            hash_key = (hash_key + offset(i))%LEN;
            if (arr[hash_key] == key){return;}

            if (arr[hash_key] == EMPTY){
                arr[hash_key] = key;
                length += 1;
                return;
            }
            if (i==19){throw "muitas colisões";}
        }
    }

    void del(std::string key){
        int hash_key = find(key);
        if (hash_key >= 0){
            arr[hash_key] = EMPTY;
            length -= 1;
        }
    }

    int find(std::string key){
        int hash_key = hash(key);
        for (int j=0; j<20; j++){
            hash_key = (hash_key + offset(j))%LEN;
            if (arr[hash_key] == key){return hash_key;}
        }
        return -1;
    }
};

int main(){
    int t;
    std::cin >> t;
    for (int i=0; i<t; i++){
        int n; std::cin >> n;
        HashTable table;
        for (int j=0; j<n; j++){
            std::string instruction;
            std::getline(std::cin, instruction);
            std::cin.

            std::string command = instruction.substr(0,3);
            std::string key = instruction.substr(4, instruction.length()-1);
            
            if (command == "ADD"){
                table.add(key);
            }else if (command == "DEL"){
                table.del(key);
            }    
        std::cout << table.getlength() << std::endl;
        for (int z=0; z<LEN; z++){
            std::string item = table[z];
            if (item != EMPTY){
                std::cout << z << ":" << item << std::endl; 
            }
        }
    }
    return 0;
}