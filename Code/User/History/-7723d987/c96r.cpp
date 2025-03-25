#include <iostream>
#include <string>

class Dequeue{
private:
    char arr[128];
    int tail;
    int head;
public:
    Dequeue(){
        tail = head = 0;
    }
    void insert(char value){
        arr[tail] = value;
        tail += 1;
    }

    void remove_tail (){
        tail -= 1;
    }
    void remove_head(){
        if (head < 0){
            throw ("")
        }
        head -= 1;
    }
};

int main(){
    int cases;
    std::cin >> cases;
    for (int i=0;i<cases;i++){
        std::string input;
        std::cin >> input;
        if (input == ""){
            std::cout << "Yes";
            break;
        }


    }
}