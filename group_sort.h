#pragma once
#include "object.h"
#include <vector>
#include <map>

std::map<std::string, std::vector<Object>> group_by_type(const std::vector<Object>& objects, size_t N);
std::map<char, std::vector<Object>> group_by_name(const std::vector<Object>& objects);
std::map<std::string, std::vector<Object>> group_by_distance(const std::vector<Object>& objects);
