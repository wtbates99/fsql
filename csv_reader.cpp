#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) { 
        std::cerr << "Usage: " << argv[0] << " <csv file>\n"; 
        return 1; 
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) { 
        std::cerr << "Cannot open file\n"; 
        return 1; 
    }

    std::vector<std::vector<std::string>> matrix;
    std::string line;

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::string field;
        bool in_quotes = false;

        for (size_t i = 0; i < line.size(); ++i) {
            char c = line[i];
            if (c == '"') {
                in_quotes = !in_quotes; // toggle inside quotes
            } else if (c == ',' && !in_quotes) {
                row.push_back(field);
                field.clear();
            } else {
                field += c;
            }
        }
        row.push_back(field); // last field
        matrix.push_back(std::move(row));
    }

    file.close();

    // Print first  rows to verify
    for (size_t i = 0; i < std::min(matrix.size(), size_t(2)); ++i) {
        for (auto& f : matrix[i]) std::cout << f << " | ";
        std::cout << "\n";
    }

    return 0;
}

