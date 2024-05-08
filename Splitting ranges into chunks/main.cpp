#include <vector>
#include <string>
#include <set>
#include <fmt/ranges.h>

template<typename T>
auto chunk(T range, int n){
    using D = std::ranges::range_value_t<T>;
    auto res = std::vector<std::vector<D>>( { { } });
    auto vnytriIndex = 0;
    auto elementsIndex = 0;
    for (auto i : range) {
        if (elementsIndex == n - 1) {
            res[vnytriIndex].push_back(i);
            if (i == *--range.end()){
                break;
            } else {
                res.push_back({});
            }
            vnytriIndex++;
            elementsIndex = 0;
        } else{
            res[vnytriIndex].push_back(i);
            elementsIndex++;
        }
    }
    return res;
}

auto main() -> int {;
    auto v1 = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto v2 = std::vector<std::string>{"a", "b", "c", "d", "e", "f"};
    auto v3 = std::set<float>{1.41, 1.61, 1.73, 2.72, 3.14};

    auto v1by3 = chunk(v1, 3);
    auto v1by2 = chunk(v1, 2);

    auto v2by5 = chunk(v2, 5);
    auto v2by1 = chunk(v2, 1);

    auto v3by2 = chunk(v3, 2);
    auto v3by3 = chunk(v3, 3);

    fmt::println("{}", v1by3);
    fmt::println("{}", v1by2);
    fmt::println("{}", v2by5);
    fmt::println("{}", v2by1);
    fmt::println("{}", v3by2);
    fmt::println("{}", v3by3);
}