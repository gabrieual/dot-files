#include <iostream>

struct Node {
    double value;
    Node* next;
    Node(double newvalue, Node* newnext = nullptr):
    value(newvalue), next(newnext) {}; 
};

class Queue {
    private:
        Node* head;
        Node* tail;
        int len;
    public:

        Queue() {
            head = tail = nullptr;
            len = 0;
        };

        ~Queue() {
            for (int i=0; i< len;i++){
                remove();
            }
        };

        void insert(double item){
            Node *new_node = new Node(item);
            if (head == nullptr){
                head = new_node;
                tail = new_node;
            }
            else{ 
                tail->next = new_node;
                tail = new_node;
            }
            len++;
        }

        double remove(){
            if (head == nullptr){
                return -1;
            }
            double value = head->value; 
            Node* temp = head;
            head = head->next;
            delete temp;
            len--;
            if (head == nullptr){tail=nullptr;}
            return value;
        }
        
        double head_value(){return head->value;}
        
        int length(){return len;}
};

int main(){
    int cases;
    std::cin >> cases;
    for (int i=0; i<cases; i++){
        int len_ferry, num_cars;
        
        std::cin >> len_ferry >> num_cars;
        Queue Right, Left;
        
        double len_car;
        std::string car_side;
        
        for (int j=0; j<num_cars; j++){
            std::cin >> len_car >> car_side;
            
            if (car_side == "left"){
                Left.insert(len_car/100);
            }else{
                Right.insert(len_car/100);
            }
        }
        int times_cross = 0;
        bool ferry_left = true; 
        while (Right.length() > 0 || Left.length() > 0){
            double space_ferry = len_ferry;

            if (ferry_left) {
                while(space_ferry > 0 && Left.length() > 0){
                    len_car = Left.head_value();
                    if (space_ferry >= len_car){
                        Left.remove();
                        space_ferry -= len_car;
                    } else {
                        break;
                    }
                }
            } else {
                while(space_ferry > 0 && Right.length() > 0){
                    len_car = Right.head_value();
                    if (space_ferry >= len_car){
                        Right.remove();
                        space_ferry -= len_car;
                    } else {
                        break;
                    }
                }
            }
            
            times_cross++;
            ferry_left = !ferry_left;
        }
        std::cout << times_cross << std::endl;
    }

    return 0;
}