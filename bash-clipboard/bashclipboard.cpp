#include <iostream>
#include <fstream>
#include <string>

// Define a temporary file path to simulate clipboard storage
const std::string kTempClipboardFile = "/tmp/clipboard_buffer";

int main(int argc, char* argv[]) {
    // Check for correct number of arguments
    if (argc != 2) {
        std::cerr << "Usage: clipboard -c | -p\n";
        return 1;
    }

    std::string mode = argv[1];

    // COPY MODE: Read from stdin, write to temp clipboard file
    if (mode == "-c") {
        std::ofstream out(kTempClipboardFile, std::ios::binary);
        if (!out) {
            std::cerr << "Error: Unable to open clipboard buffer for writing.\n";
            return 1;
        }

        // Disable whitespace skipping and copy input byte-by-byte
        std::cin >> std::noskipws;
        char c;
        while (std::cin >> c) {
            out.put(c);
        }

        out.close();
        if (!out) {
            std::cerr << "Error: Failed to write clipboard buffer.\n";
            return 1;
        }

        // PASTE MODE: Read from temp clipboard file and write to stdout
    } else if (mode == "-p") {
        std::ifstream in(kTempClipboardFile, std::ios::binary);
        if (!in) {
            std::cerr << "Error: Clipboard is empty or missing.\n";
            return 1;
        }

        std::cout << in.rdbuf();  // Stream file directly to stdout

    } else {
        std::cerr << "Error: Unknown option '" << mode << "'. Use -c or -p.\n";
        return 1;
    }

    return 0;
}
