#include <string>
struct Node{
    char value;
    Node *left = nullptr, *right = nullptr;
};

class Bst{
private:
    Node *root;
public:
    void insert(){

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
};

int main(){
    return 0;
}