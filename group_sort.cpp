#include "group_sort.h"
#include <cmath>

std::map<std::string, std::vector<Object>> group_by_type(const std::vector<Object>& objects, size_t N) {
    std::map<std::string, std::vector<Object>> groups;

    for (const auto& obj : objects) {
        groups[obj.type].push_back(obj);
    }

    for (auto it = groups.begin(); it != groups.end(); ) {
        if (it->second.size() < N) {
            groups["Miscellaneous"].insert(groups["Miscellaneous"].end(), it->second.begin(), it->second.end());
            it = groups.erase(it);
        } else {
            ++it;
        }
    }

    return groups;
}

std::map<char, std::vector<Object>> group_by_name(const std::vector<Object>& objects) {
    std::map<char, std::vector<Object>> groups;

    for (const auto& obj : objects) {
        char first_char = std::toupper(obj.name[0]);
        if (std::isalpha(first_char)) {
            groups[first_char].push_back(obj);
        } else {
            groups['#'].push_back(obj);
        }
    }

    return groups;
}

std::map<std::string, std::vector<Object>> group_by_distance(const std::vector<Object>& objects) {
    std::map<std::string, std::vector<Object>> groups = {
        {"Within 100 units", {}}, {"Within 1000 units", {}}, {"Within 10000 units", {}}, {"Too far", {}}
    };

    for (const auto& obj : objects) {
        double dist = obj.distance();
        if (dist <= 100) {
            groups["Within 100 units"].push_back(obj);
        } else if (dist <= 1000) {
            groups["Within 1000 units"].push_back(obj);
        } else if (dist <= 10000) {
            groups["Within 10000 units"].push_back(obj);
        } else {
            groups["Too far"].push_back(obj);
        }
    }

    return groups;
}
