#include <fmt/ranges.h>
#include <vector>
#include <algorithm>
#include <string>

auto reversed(std::string s) {
    auto vec = std::vector<std::string>();
    auto str = std::string();
    for (int i = 0; i <= s.size(); ++i) {
        if (s[i] == ' ' or i == s.size()){
            vec.push_back(str);
            str = "";
        } else {
            str += s[i];
        }
    }
    std::ranges::reverse(vec);
    for (auto i = 0; i < vec.size(); i++){
        str += vec[i] + " ";
    }
    return str;
 }
auto main() -> int{
    fmt::println(
            "{}\n{}\n{}\n{}",
            reversed("A quick brown fox"),
            reversed("Quick"),
            reversed(""),
            reversed("1 2 3")
    );
}
