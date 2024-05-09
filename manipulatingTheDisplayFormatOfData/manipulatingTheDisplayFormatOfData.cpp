#include <fmt/ranges.h>
#include <fmt/format.h>
#include <string>
#include <vector>
#include <iostream>

auto multipleTimes() -> void{
    auto number = int();
    std::cin >> number;
    fmt::println("({})({})({})", number, number, number);
}

//2
auto reversedChars() -> void{
    fmt::println("The simplest c++ program is: \"auto main() -> int {{ }}\" \n" , " " );
}

//3
auto separator(std::vector<int> vec) -> void{
//    fmt::println("{}" , vec);
//    fmt::println("${}$" , fmt::join(vec, " - "));
    fmt::println("{}\n"
                 "${}$\n", vec, fmt::join(vec, " - "));

}

//4
auto theOrder() -> void{
    fmt::println("{}{}{}\n", '?', "I'm enclosed in question marks", '?');
}

auto numberFormatting(float number, int hexa ) -> void{
    //1
    fmt::println("{:.2f}", number);
    //2
    fmt::println("{:b} {} {:x}\n", hexa, hexa, hexa);
}

auto justifying(std::string s, int n) -> void {
    fmt::println("{:#<20}", s);
    fmt::println("{:#^20}", s);
    fmt::println("{:#>20}", s);
}

auto main() -> int{
//1 task
    multipleTimes();
//2 task
    reversedChars();
//3 task
    auto vec = std::vector<int>{1,2,3,4,5};
    separator(vec);
//4 task
    theOrder();
//5 task
    auto anyNumberHere = float(1.3374);
    auto anyInteger = int(74);
    numberFormatting(anyNumberHere, anyInteger);
//6 task
    auto text = std::string("Hello!");
    auto N = text.size();
    justifying(text, N);
}