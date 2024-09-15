#include "file_handler.h"
#include <fstream>
#include <sstream>

std::vector<Object> read_objects_from_file(const std::string& file_path) {
    std::vector<Object> objects;
    std::ifstream file(file_path);
    std::string line;
    
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, type;
        double x, y;
        std::time_t creation_time;
        
        if (iss >> name >> x >> y >> type >> creation_time) {
            objects.emplace_back(name, x, y, type, creation_time);
        }
    }
    return objects;
}

void write_objects_to_file(const std::string& file_path, const std::vector<Object>& objects) {
    std::ofstream file(file_path);
    for (const auto& obj : objects) {
        file << obj.name << " " << obj.x << " " << obj.y << " " << obj.type << " " << obj.creation_time << "\n";
    }
}
