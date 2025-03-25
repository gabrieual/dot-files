#include <iostream>
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
    std::string preOrder(std::string output = "", Node *curr = nullptr){
        if (curr == nullptr){
            curr = root;
        }
        output += " ";
        output += std::to_string(curr->value);

        if (curr->left != nullptr){
        output = preOrder(output, curr->left);
        }
        if (curr->right){
        output = preOrder(output, curr->right);
        }
        return output;
    }
    
    std::string inOrder(std::string output = "", Node *curr = nullptr){
        if (curr == nullptr){
            curr = root;
        }
        
        if (curr->left != nullptr){
            output = inOrder(output, curr->left);
        }
        output += " ";
        output += std::to_string(curr->value);
        
        if (curr->right){
        output = inOrder(output, curr->right);
        }
        return output;
}
    
    std::string postOrder(std::string output = "", Node *curr = nullptr){
        if (curr == nullptr){
            curr = root;
        }
        
        if (curr->left != nullptr){
            output = postOrder(output, curr->left);
        }
        if (curr->right){
            output = postOrder(output, curr->right);
        }
        output += " ";
        output += std::to_string(curr->value);
    
        return output;
}
};

int main(){
    short n;
    std::cin >> n;
    short data; std::cin >> data;
    Bst Tree(data);
    for (short i = 0; i < n-1; i++){
        std::cin >> data;
        Tree.insert(data);
    }
    std::string output = "";
    std::cout << "Pre order :" << Tree.preOrder()  << std::endl
              << "In order  :" << Tree.inOrder()   << std::endl
              << "Post order:" << Tree.postOrder() << std::endl;

    return 0;
}