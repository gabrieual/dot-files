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
        if (arr[hashed_key].empty()) return ":";
        
        std::string result = "";
        for (int i = 0; i < arr[hashed_key].size(); i++) {
            if (i > 0) result += ",";
            result += "(" + arr[hashed_key][i] + ")";
        }
        return result;
    }

    void add(int key, std::string value){
        int hashed_key = hash(key);
        std::string entry = std::to_string(key) + "," + value;
        
        // Verificar se a chave já existe
        if (!arr[hashed_key].empty()) {
            for (const std::string& item : arr[hashed_key]) {
                size_t pos = item.find(",");
                if (pos != std::string::npos) {  // Verifica se encontrou a vírgula
                    std::string key_str = item.substr(0, pos);
                    if (key_str == std::to_string(key)) {
                        return; // Ignora se a chave já existe
                    }
                }
            }
        }
        
        arr[hashed_key].push_back(entry);
        load += 1;
    }

    void del(int key){
        int hashed_key = hash(key);
        for (auto it = arr[hashed_key].begin(); it != arr[hashed_key].end(); ++it) {
            if (it->substr(0, it->find(",")) == std::to_string(key)) {
                arr[hashed_key].erase(it);
                load -= 1;
                return;
            }
        }
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
                std::cout << z << dicionary[z] << std::endl;
            }        
        }catch (char* erro){
            std::cout << erro;
    }
    }
}
