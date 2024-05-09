#include <iostream>
#include <vector>

auto boxPrint(std::vector<std::string> vec, char sign = '*') -> void{
    auto maxSizeOfTheWordInVector = int();

    for (auto i = 0; i < vec.size(); i++){
        if (vec[i].size() > maxSizeOfTheWordInVector){
            maxSizeOfTheWordInVector = vec[i].size();
        }
    }

    auto signs = std::string(maxSizeOfTheWordInVector + 2, sign);

    std::cout << signs << "\n";

    for (auto i = 0; i < vec.size(); i++){
        std::cout << sign << vec[i];
        auto howMuchNeedToBePrinted = int();
        howMuchNeedToBePrinted = maxSizeOfTheWordInVector - vec[i].size();
        auto spaces = std::string (howMuchNeedToBePrinted, ' ');
        std::cout << spaces << sign << "\n";
    }
    std::cout << signs << "\n";

    std::cout << "\n";
}


auto main() -> int{
    boxPrint({"a", "quick", "brown", "fox"});
    boxPrint({"a", "quick", "brown", "fox"}, '*');
    boxPrint({"a", "quick", "brown", "fox"}, '#');
    boxPrint(std::vector<std::string>{"a", "quick", "brown", "fox"}, '#');
    boxPrint({""});
    boxPrint({});
    boxPrint({}, '#');
    boxPrint({"", "hmmmm", ""});
    boxPrint({"", "", ""});
}