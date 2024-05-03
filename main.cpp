#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
//malware analysis from testDOME coding 
std::vector<int> simulate(const std::vector<int>& entries) {
    if (entries.size() < 4)
        return entries;

    std::vector<int> simEntries{ entries };
    std::vector<std::vector<int>::iterator> tempEntries{};

    for (auto itX = std::begin(simEntries); itX != std::end(simEntries) - 4; ++itX) {
       const auto rightT = itX + 4;
       if (*itX <= *rightT)
           tempEntries.push_back(itX);
    }

    for (auto itX = std::begin(simEntries) + 3; itX != std::end(simEntries); ++itX) {
        const auto leftT = itX - 3;
        if (*itX <= *leftT)
            tempEntries.push_back(itX);
    }

    for (auto it = std::begin(simEntries); it != std::end(simEntries); ++it) {
        if (std::find(std::begin(tempEntries), std::end(tempEntries), it) != std::end(tempEntries))
            *it = 0;
    }

    return simEntries;
}

#ifndef RunTests
int main() {
    std::vector<int> result = simulate({ 1, 2, 0, 5, 0, 2, 4, 3, 3, 3 });
    for (int value : result) {
        std::cout << value << " ";
    }
    // Expected output
    // 1, 0, 0, 5, 0, 0, 0, 3, 3, 0
}
#endif
