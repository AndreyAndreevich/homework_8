#include <iostream>
#include <vector>
#include <set>
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
    
    std::sort(slovar.begin(),slovar.end());
    std::set<std::string> result;
    auto iter = slovar.begin();
    while(iter != slovar.end()) {
        iter = std::adjacent_find(iter,slovar.end());
        if (iter != slovar.end()) {
            result.insert(*iter);
            iter++;  
        } 
    }
    std::copy(result.begin(),result.end(),std::ostream_iterator<std::string>(std::cout,"\n"));
}