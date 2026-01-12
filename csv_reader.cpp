#include <iostream>
#include <fstream>
#include <string>
#include "csv.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) { 
        std::cerr << "Usage: " << argv[0] << " <csv file>\n"; 
        return 1; 
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) { 
        std::cerr << "Cannot open file: " << argv[1] << "\n"; 
        return 1; 
    }

    // CSVReader from csv.hpp
    csv::CSVReader reader(argv[1]);

    for (csv::CSVRow& row : reader) {
        for (csv::CSVField& field : row) {
            std::cout << field.get<>() << " ";
        }
        std::cout << "\n";
    }

    return 0;
}

