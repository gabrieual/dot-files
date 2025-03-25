#include <iostream>
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
};

int main(){
    int cases;
    std::cin >> cases;
    std::string reponse = "Yes";

    for (int i=0;i<cases;i++){
        std::string input;
        std::cin >> input;
        if (input == ""){
            std::cout << "Yes";
            break;
        }
        Dequeue Lista;
        for (int j=0; j<input.length(); j++){
            char token = input[j];
            try{ 
                if (token == '(' || token == '['){
                    Lista.insert(token);
                }
                else{
                    if (token == Lista.tail_value()){
                        Lista.remove_tail();
                    }
                    else{
                        Lista.remove_head();
                    }
                }
            }
            catch(std::string){
                reponse = "no";
            }
        }
    }
}