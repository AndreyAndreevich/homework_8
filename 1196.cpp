#include <iostream>
#include <set>
#include <algorithm>


int main() {
    std::set<int> pupil;
    int n,m;
    std::cin >> n;
    int number;
    for (auto i = 0; i < n; i++) {
        std::cin >> number;
        pupil.insert(number);
    }
    
    std::cin >> m;
    int sum = 0;
    for (auto i = 0; i < m; i++) {
        std::cin >> number;
        if (pupil.find(number) != pupil.end())
            sum++;
    }
    std::cout << sum << std::endl;
}