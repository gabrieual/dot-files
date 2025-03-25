#include <iostream>
#include <iterator>
#include <ostream>
#include <string>

struct Node{
    short value;
    Node *left = nullptr, *right = nullptr;
    Node(short value):value(value){}
};

class Bst{
private:
    Node *root;
public:
    Bst(short value){
        root = new Node(value);
    }

    void insert(short value, Node *curr = nullptr){
        if (curr == nullptr){
            curr = root;
        }
        if (value < curr->value){
            if (curr->left == nullptr){
                curr->left = new Node(value); 
                return;
            }
            return insert(value, curr->left);
        }
        else{
            if (curr->right == nullptr){
                curr->right = new Node(value); 
                return;
            }
            return insert(value, curr->right);
        }
    }
    std::string preOrder(std::string &output, Node *curr = nullptr){
        if (curr == nullptr){
            curr = root;
        }
        output += " " += curr->value;
        while(true){
            output += " ";
            output += curr
        }
        return output;
    }
    
    short inOrder(){return 0;}
    
    short postOrder(){return 0;}
};

int main(){
    short n;
    std::cin >> n;
    short data;
    Bst Tree(data);
    for (short i = 0; i < n; i++){
        std::cin >> data;

    }

    std::cout << "Pre order :" << Tree.preOrder() << std::endl;
    std::cout << "In order  :" << Tree.inOrder() << std::endl;
    std::cout << "Post order:" << Tree.postOrder() << std::endl;


    return 0;
}