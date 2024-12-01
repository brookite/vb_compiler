#include "utils.hpp"

static size_t IdCounter = 0;

size_t getNewId() {
    return ++IdCounter;
}

size_t lastId() {
    return IdCounter;
}

void debug_print(const char* format, ...) {
    if (DEBUG) {
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        if (!endsWith(format, "\n")) {
            printf("\n");
        }
        va_end(args);
    }
}

void internal_error(const char* msg) {
    printf("Internal Error:");
    puts(msg);
}

bool endsWith(const std::string& str, const std::string& suffix)
{
    return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

std::vector<std::string> find_files(const std::string& directory, const std::string& ext) {
    std::vector<std::string> vb_files;

    try {
        for (const auto& entry : fs::recursive_directory_iterator(directory)) {
            if (entry.is_regular_file() && entry.path().extension() == ext) {
                vb_files.push_back(entry.path().string());
            }
        }
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Error accessing the directory: " << e.what() << '\n';
    }

    return vb_files;
}