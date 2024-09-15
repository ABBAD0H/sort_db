#include "file_handler.h"
#include "group_sort.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <string>

void add_object(std::vector<Object>& objects) {
    std::string name, type;
    double x, y;
    std::time_t creation_time;

    std::cout << "Enter object name: ";
    std::cin >> name;
    std::cout << "Enter coordinates (x and y): ";
    std::cin >> x >> y;
    std::cout << "Enter object type: ";
    std::cin >> type;
    creation_time = std::time(nullptr); // Current time

    objects.emplace_back(name, x, y, type, creation_time);
}

int main() {
    std::vector<Object> objects = read_objects_from_file("data/objects.txt");
    bool running = true;

    while (running) {
        int choice;
        std::cout << "\nMenu:\n"
                  << "1. Add an object\n"
                  << "2. Group by distance\n"
                  << "3. Group by name\n"
                  << "4. Group by type\n"
                  << "5. Save objects to file\n"
                  << "6. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            add_object(objects);
            break;
        case 2: {
            auto grouped = group_by_distance(objects);
            std::cout << "Objects grouped by distance:\n";
            for (const auto& [group, objs] : grouped) {
                std::cout << "Group: " << group << "\n";
                for (const auto& obj : objs) {
                    std::cout << obj.name << " " << obj.x << " " << obj.y << "\n";
                }
            }
            break;
        }
        case 3: {
            auto grouped = group_by_name(objects);
            std::cout << "Objects grouped by name:\n";
            for (const auto& [letter, objs] : grouped) {
                std::cout << "Group: " << letter << "\n";
                for (const auto& obj : objs) {
                    std::cout << obj.name << " " << obj.x << " " << obj.y << "\n";
                }
            }
            break;
        }
        case 4: {
            size_t N = 3;  // Set the minimum number of objects for a group
            auto grouped = group_by_type(objects, N);
            std::cout << "Objects grouped by type:\n";
            for (const auto& [type, objs] : grouped) {
                std::cout << "Group: " << type << "\n";
                for (const auto& obj : objs) {
                    std::cout << obj.name << " " << obj.x << " " << obj.y << "\n";
                }
            }
            break;
        }
        case 5:
            write_objects_to_file("data/result.txt", objects);
            std::cout << "Result saved to file\n";
            break;
        case 6:
            running = false;
            break;
        default:
            std::cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}
