#include <iostream>
#include <string>

class Dict{
private:

public:
    void add(std::string key, std::string value){

    }
};

int main(){
    std::string english, foreign;
    Dict dictionary;
    while (true){
        std::cin >> english; 
        if (english == "\n"){break;}
        std::cin >> foreign;
        dictionary.add(foreign, english);
    }

    
    
    return 0;
}