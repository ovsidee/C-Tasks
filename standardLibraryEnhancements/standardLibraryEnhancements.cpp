#include <fmt/ranges.h>
#include <vector>

namespace pjc{
    namespace ranges{
        //buble-sorting
        auto sort(std::vector<int> vec) -> std::vector<int>{
            int n = vec.size();
            for (int i = 0; i < n - 1; ++i) {
                for (int j = 0; j < n - i - 1; ++j) {
                    if (vec[j] > vec[j + 1]) {
                        int temp = vec[j];
                        vec[j] = vec[j + 1];
                        vec[j + 1] = temp;
                    }
                }
            }
            auto newVec = std::vector<int>(vec.size());
            for (auto i = 0; i< vec.size(); i++){
                newVec[i] = vec[i];
            }
            newVec = vec;
            return newVec;
        }

        auto reverse(std::vector<int> vec) -> std::vector<int>{
            for (int i = 0; i < vec.size()/2; ++i) {
                auto temp = vec[i];
                vec[i] = vec[vec.size() - 1 - i];
                vec[vec.size() - 1 - i] = temp;
            }
            auto newVec = std::vector<int>(vec.size());
            for (auto i = 0 ; i< vec.size(); i++) {
                newVec[i] = vec[i];
            }
            return newVec;
        }
    }
}
auto main() -> int{
    auto vec = std::vector<int>{21,2,8,4,5,6};
    fmt::println("{}", pjc::ranges::sort(vec));
    fmt::println("{}\n", vec);

    fmt::println("{}", vec);
    fmt::println("{}", pjc::ranges::reverse(vec));
}
