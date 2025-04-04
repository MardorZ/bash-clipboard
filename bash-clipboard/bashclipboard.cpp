#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

const std::string temp_clipboard = "/tmp/clipboard_buffer";

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: clipboard -c|-p\n";
        return 1;
    }

    std::string mode = argv[1];
    if (mode == "-c") {
        std::ofstream out(temp_clipboard, std::ios::binary);
        if (!out) {
            std::cerr << "Failed to open temp file for writing\n";
            return 1;
        }
        std::cin >> std::noskipws;
        char c;
        while (std::cin >> c) out << c;
    } else if (mode == "-p") {
        std::ifstream in(temp_clipboard, std::ios::binary);
        if (!in) {
            std::cerr << "Clipboard is empty or missing\n";
            return 1;
        }
        std::cout << in.rdbuf();
    } else {
        std::cerr << "Unknown option: " << mode << "\n";
        return 1;
    }

    return 0;
}
