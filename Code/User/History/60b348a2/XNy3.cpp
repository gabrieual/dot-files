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
        
    }

    std::string operator[](std::string key){
        return "";
    }

    void add(std::string key, std::string value){

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