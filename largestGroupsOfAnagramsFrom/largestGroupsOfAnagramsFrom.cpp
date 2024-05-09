#include <fmt/ranges.h>
#include <fmt/core.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

auto largestAnagramGroupsFrom(const std::string& s) {
    auto word = std::string();
    auto words = std::vector<std::string>();
    auto sizeOfString = s.size();
    auto count = 0;
    for (auto e: s) {
        e = tolower(e);
        if (e == ' ' || e == '\n') {
            words.push_back(word);
            word.clear();
        } else if (e >= 'a' && e <= 'z') {
            word += e;
        }
        if (count == sizeOfString - 1) {
            words.push_back(word);
        }
        count++;
    }
    auto groupVec = std::vector<std::string>();
    auto map = std::map<std::string, int>();
    for (auto el: words) {
        auto e = el;
        std::ranges::sort(e);
        for (const auto &el2: words)
            if (el != el2) {
                auto e2 = el2;
                std::ranges::sort(e2);
                if (e == e2) {
                    map[el2] += 1;
                }
            }
    }
    for (auto e: map) groupVec.push_back(e.first);
    return groupVec;
}

auto main() -> int {
    auto s = std::string("In life, we find ourselves perplexed\n"
                         "By twists and turns, and what comes next\n"
                         "We wonder where our path will lead\n"
                         "And hope for guidance, in our need\n"
                         "\n"
                         "But sometimes all we need to do\n"
                         "Is simply change our point of view\n"
                         "For “listen” can become “silent” too\n"
                         "And “love” can turn into “vole” anew\n"
                         "\n"
                         "There’s “evil” hiding in “live”\n"
                         "And “cinema” in “iceman” lives\n"
                         "To look for the positive, and let our hearts be lighter\n"
                         "But let’s focus on the good, and be a little kinder\n"
                         "\n"
                         "We can find “heart” in “earth” below\n"
                         "And “care” in “race” - it’s apropos\n"
                         "“Strained” can be “disrate,” and that’s okay\n"
                         "For tomorrow is a brand new day\n"
                         "\n"
                         "So let’s embrace the twists and turns\n"
                         "And all the lessons that life confirms\n"
                         "For every problem, there’s a clue\n"
                         "And an anagram to guide us through.\n"
                         "\n"
                         "For completeness, let’s add few more,\n"
                         "made-up, words: elov arce");
    fmt::println("{}", largestAnagramGroupsFrom(s));
}