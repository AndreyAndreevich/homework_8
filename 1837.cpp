#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>


int main() {
    std::map<std::string,int> numbers;
    std::vector<std::set<std::string>> commands;
    std::queue<std::string> names;
    int n;
    std::cin >> n;
    commands.reserve(n);
    std::string name;
    getline(std::cin, name);
    for (auto i = 0; i < n; i++) {
        std::set<std::string> group;
        for (auto j = 0; j < 3; j++) {
            std::cin >> name;
            group.insert(name);
            numbers[name] = -1;
        }
        commands.push_back(group);
    }

    if (numbers.find("Isenbaev") != numbers.end()) {
        numbers["Isenbaev"] = 0;
        names.push("Isenbaev");
    }
    while(!names.empty()) {
        auto name = names.front();
        names.pop();
        decltype(commands.begin()) iterCom;
        while(iterCom = std::find_if(commands.begin(),commands.end(),[name](auto& command) {
            auto iter = command.find(name);
            if (iter != command.end()) {
                command.erase(iter);
                return true;
            }
            return false;
        }),iterCom != commands.end()) {
            while(iterCom->size()) {
                auto iter = iterCom->begin();
                auto fname = *iter;
                iterCom->erase(iter);
                if (numbers[fname] == -1) {
                    numbers[fname] = numbers[name]+1;
                    names.push(fname);
                }
            }
        }
    }

    for(const auto& num : numbers) {
        std::cout << num.first << ' ';
        if (num.second == -1)
            std::cout << "undefined";
        else std::cout <<  num.second;
        std::cout  << '\n';
    }
}