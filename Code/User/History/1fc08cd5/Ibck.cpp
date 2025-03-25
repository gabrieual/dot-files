#include <iostream>
#include <ostream>
#include <string>
int main(){
    std::string str = "È";
    for (int i=0; i<str.length(); i++) {
        std::cout << str[i]<< " ";
    }
    return 0;
}