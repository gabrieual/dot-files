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
        for (int i = 0; i < mod; i++) {
            arr[i] = std::vector<std::string>();
        }
    }

    int getLoad(){return load;}

    int hash(int key){return key % mod;}

    std::string operator[](int key){
        int hashed_key = hash(key);
    }

    void add(int key, std::string value){
        int hashed_key = hash(key);
        load += 1;
    }

    void del(int key){
        load -= 1;
        return;
    }
};

int main(){
    int c; std::cin >> c;
    for (int i=0;i<c;i++){
        int n; std::cin >> n;
        
        Dict dicionary;
        try {
            for (int j=0; j<n; j++) {
                std::string command, value;
                int key;
                std::cin >> command >> key;

                if (command == "add"){
                    std::cin >> value;
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
        }catch (char* erro){
            std::cout << erro;
    }
    }
}
