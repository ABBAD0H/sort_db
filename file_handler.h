#pragma once
#include "object.h"
#include <vector>
#include <string>

std::vector<Object> read_objects_from_file(const std::string& file_path);
void write_objects_to_file(const std::string& file_path, const std::vector<Object>& objects);
