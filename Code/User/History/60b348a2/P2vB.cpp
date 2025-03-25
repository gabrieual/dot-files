#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Dict{
private:
    vector<string> arr[10000]; 
public:

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