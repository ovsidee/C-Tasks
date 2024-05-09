#include <fmt/ranges.h>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <fmt/core.h>
#include <fmt/format.h>
#include <set>
#include <ranges>

namespace pjc{
    namespace ranges{
        template <typename anyRange, typename predicate>
        auto partition(anyRange vec, predicate p) {

            auto allOk = std::vector<std::ranges::range_value_t<anyRange>>();
            auto allBad = std::vector<std::ranges::range_value_t<anyRange>>();

            for (int i = 0; i <vec.size() ; i++) {
                if(p(vec[i])){
                    allOk.push_back(vec[i]);
                } else{
                    allBad.push_back(vec[i]);
                }
            }

            return std::make_pair(allOk, allBad);
        }

        template <typename Range>
        auto drop(Range range, int n){
            return std::vector<std::ranges::range_value_t<Range>>(range.begin() + n, range.end());
        }

        template <typename Range>
        auto dropLast(Range range, int n){
            return std::vector<std::ranges::range_value_t<Range>>(range.begin(), range.end() - n);
        }

        template <typename Range>
        auto flatten(Range range){
            auto vec = std::vector<std::ranges::range_value_t<std::ranges::range_value_t<Range>>>();
            for (auto element : range){
                for (auto deepWay : element){
                    vec.push_back(deepWay);
                }
            }
            return vec;
        }

    }
}

auto main() -> int{
    auto vec = std::vector<int>{1,2,3,4,5,6,7,8};
    fmt::println("{}", pjc::ranges::partition(vec, [](auto x){
        auto b = bool();
        if (x > 4){
            b = true;
        } else{
            b = false;
        }
        return b;
    }));

    auto source1 = std::vector<std::set<int>>{ {10} , {1, 2, 3} , {5, 6} , {4} , {7, 8, 9} };
    auto source2 = std::set<std::set<int>>{ {10}, {3, 2, 1}, {6, 5}, {4}, {8, 7, 9} };
    fmt::println("{}", pjc::ranges::drop(vec, 4));
    fmt::println("{}", pjc::ranges::dropLast(vec, 4));
    fmt::println("{}", pjc::ranges::flatten(source1));
    fmt::println("{}", pjc::ranges::flatten(source2));
};