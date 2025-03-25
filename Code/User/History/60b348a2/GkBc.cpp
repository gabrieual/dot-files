#include <iostream>
#include <string>

class Dict{
private:

public:
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
        
    }
    
    return 0;
}