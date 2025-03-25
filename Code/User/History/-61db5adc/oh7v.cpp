#include <iostream>
#include <string>
#include <vector>
struct Node{
    char value;
    Node *left = nullptr, *right = nullptr;
    Node(char value):value(value){}
};

class Bst{
private:
    Node *root;
public:
    void insert(char value, Node* curr = nullptr){
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

    std::string preOrder(std::string output = "", Node *curr = nullptr){
        if (curr == nullptr){
            curr = root;
        }
        output += std::to_string(curr->value);

        if (curr->left != nullptr){
        output = preOrder(output, curr->left);
        }
        if (curr->right){
        output = preOrder(output, curr->right);
        }
        return output;
    }
};

int main(){
    char entry;
    while (true){
        if entry 
        while (true){
            std::string entry;
            std::cin >> entry;
            ;
        }

    }
    return 0;
}