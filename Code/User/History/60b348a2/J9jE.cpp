#include <iostream>
#include <string>
#include <vector>
#define LEN 10000
using namespace std;


class Dict{
private:
    vector<string> arr[LEN]; 
public:
    Dict(){
        for (int i=0; i<LEN; i++) {
            arr[i] = vector<string>();
        }
    }

    int hash(string key){
        int hash = 5381;
        for (int i = 0; i<key.length(); i++){
            hash = hash * 33 + static_cast<int>(key[i]); 
        }
        return hash % LEN;
    }

    std::string operator[](std::string key){
        int hash_key = hash(key);
        for (int i=0; i<arr[hash_key].size(); i+=2) {
            if 
        }
        return "";
    }

    void add(std::string key, std::string value){
        int hash_key = hash(key);
        arr[hash_key].push_back(key);
        arr[hash_key].push_back(value);  
    }
};

int main(){
    Dict dictionary;
    
    std::string english, foreign;
    while (true){
        std::cin >> english; 
        if (english == "\n"){break;}
        std::cin >> foreign;
        dictionary.add(foreign, english);
    }

    while (true){
        std::cin >> foreign;
        std::cout << dictionary[foreign];    
    }
    
    return 0;
}