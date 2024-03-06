#include <iostream>
#include <map>
#include <algorithm>
int main()
{
    std::map<std::string, bool> testMap;
    testMap["Hello"] = true;
    testMap["world"] = true;
    testMap["cpp"] = false;
    auto it = std::find_if(testMap.begin(), testMap.end(), [](const std::pair<std::string, int>& elem){
        return elem.second == false;
                      });
    if (it != testMap.end()) {
        std::cout << it->first << " " << it->second << std::endl;
    } else {
        std::cout << "element does not exist" << std::endl;
    }
    return 0;
}

