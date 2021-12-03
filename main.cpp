#include <iostream>
#include "traversals.h"
#include <vector>

int main() {
    Traversal obj = Traversal();
    std::cout<<obj.message()<<std::endl;

    std::ifstream file ("df_small.txt");
    
    std::vector<std::string> names;

    std::string input;
    while(file >> input) {
        names.push_back(input);
    }

    return 0;
}