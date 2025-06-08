#include <iostream>
#include <fstream>
#include <string>

const std::string kTempClipboardFile = "/tmp/clipboard_buffer";

void printHelp() {
    std::cout << R"(Usage: clipboard [OPTION]

Options:
  -c        Copy from stdin to clipboard
  -p        Paste clipboard content to stdout
  --help    Show this help message
)";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: clipboard -c | -p | --help\n";
        return 1;
    }

    std::string mode = argv[1];

    if (mode == "--help") {
        printHelp();
        return 0;
    }

    if (mode == "-c") {
        std::ofstream out(kTempClipboardFile, std::ios::binary);
        if (!out) {
            std::cerr << "Error: Unable to open clipboard buffer for writing.\n";
            return 1;
        }

        std::cin >> std::noskipws;
        out << std::cin.rdbuf();

        out.close();
        if (!out) {
            std::cerr << "Error: Failed to write clipboard buffer.\n";
            return 1;
        }

    } else if (mode == "-p") {
        std::ifstream in(kTempClipboardFile, std::ios::binary);
        if (!in) {
            std::cerr << "Error: Clipboard is empty or missing.\n";
            return 1;
        }

        std::cout << in.rdbuf();

    } else {
        std::cerr << "Error: Unknown option '" << mode << "'. Use -c, -p or --help.\n";
        return 1;
    }

    return 0;
}
