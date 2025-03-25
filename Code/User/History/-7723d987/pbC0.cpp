#include <iostream>
#include <ostream>
#include <string>

class Dequeue{
private:
    char arr[128];
    int tail;
    int head;
public:
    Dequeue(){tail = head = -1;}

    void insert(char value){
        if (head < 0){head = 0;}
        tail += 1;
        arr[tail] = value;
    }

    void remove_tail (){
        if (tail < 0){
            throw ("tentou remover da lista vazia");
        }
        if (head == 0){head-=1;}
        tail -= 1;
    }

    void remove_head(){
        if (head < 0){
            throw ("tentou remover da lista vazia");
        }
        head += 1;
    }

    char head_value(){
        if (head < 0){
            throw ("tentou acessar a lista vazia");
        }
        return arr[head];}

    char tail_value(){
        if (tail < 0){
            throw ("tentou acessar a lista vazia");
        }
        return arr[tail];}

    bool is_empty(){
        if (tail < 0){return true;}
        return false;
    }

    bool match_tail(char token){
        if (token == ')' && tail_value() == '('){
            return true;
        }
        if (token == ']' && tail_value() == '['){
            return true;
        }
        return false;
    }
    bool match_head(char token){
        if (token == ')' && head_value() == '('){
            return true;
        }
        if (token == ']' && head_value() == '['){
            return true;
        }
        return false;
    }
};

int main(){
    int cases;
    std::cin >> cases;
    
    for (int i=0;i<cases;i++){
        bool response = true;
        std::string input;
        std::getline(std::cin, input);
        Dequeue Lista;
        for (int j=0; j<input.length(); j++){
            if (input == ""){
                break;
            }
            char token = input[j];
            try{ 
                if (token == '(' || token == '['){
                    Lista.insert(token);
                }
                else{
                    if (Lista.match_tail(token)){
                        Lista.remove_tail();
                    }
                    else if (Lista.match_head(token)){
                        Lista.remove_head();
                    }
                    else {
                        throw "tipos de parenteses não correspondem";
                    }
                }
            }
            catch(std::string){
                response = false;
            }
        }
        if (!Lista.is_empty()){
            response = false;
        }
        if (response){
            std::cout << "Yes" << std::endl;
        }
        else {
            std::cout<< "No" << std::endl;
        }
    }
}