#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<std::string> slovar;
    int n;
    std::cin >> n;
    slovar.reserve(n);
    std::string line;
    for (auto i = 0; i < n; i++) {
        std::cin >> line;
        slovar.push_back(line);
    }
    
    std::cin >> line;
    std::vector<std::string> result;
    std::copy_if(slovar.cbegin(),slovar.cend(),std::back_inserter(result),[line](const auto& element) {
        return element[0] == line[0];
    });
    std::copy(result.begin(),result.end(),std::ostream_iterator<std::string>(std::cout,"\n"));
}