#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#define mod 10

class Dict{
private:
    std::vector<std::string> arr[9];
    int load;
public:
    
    Dict(){
        load = 0; 
    }

    std::string operator[](int key){
        
        return "";
    }

    int getLoad(){return load;}

    int hash(int key){return key % mod;}

    void add(int key, std::string value){
        int hased_key = hash(key);
        for (int i=0; i<arr[hased_key].size(); i++){

        }
        load += 1;
    }

    void del(int key){
        load -= 1;
    }
};

int main(){
    int c; std::cin >> c;
    for (int i=0;i<c;i++){
        int n; std::cin >> n;
        
        Dict dicionary;
        for (int j=0; j<n; j++) {
            std::string command, value;
            int key;
            std::cin >> command >> key >> value;

            if (command == "add"){
                dicionary.add(key, value);
            }else if (command == "del") {
                dicionary.del(key);
            }else {throw "comando desconhecido";}
        }
        std::cout << "caso " << i << ":" << std::endl;
        std::cout << "alpha = " << dicionary.getLoad()<<"/10" << std::endl;

        for (int z=0; z<10; z++) {
            std::cout << z << ":" << dicionary[z] << std::endl;
        }  
    }
}