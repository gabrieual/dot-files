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
    std::string entry;
    while (true){
        if (entry == "$"){
            break;
        } 
        std::vector<std::string> leaves;
        while (true){
            std::cin >> entry;
            if (entry == "*"){
                break;
            }
            leaves.push_back(entry);
        }
        for (int i = leaves.size()-1; i>=0; i--){
            for (int j = leaves[i].size()-1; j>=0; i--)
        }

    }
    return 0;
}