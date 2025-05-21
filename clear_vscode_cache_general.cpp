#include <iostream>
#include <filesystem>
#include <string>

using std::cerr;
using std::cout;
using std::string;
using std::endl;
namespace fs = std::filesystem;

// Helper function to safely delete a directory if it exists
// Helper function to calculate directory size in bytes
std::uintmax_t get_directory_size(const fs::path& dir_path) {
    std::uintmax_t size = 0;
    if (fs::exists(dir_path) && fs::is_directory(dir_path)) {
        for (const auto& entry : fs::recursive_directory_iterator(dir_path, std::filesystem::directory_options::skip_permission_denied)) {
            if (fs::is_regular_file(entry.path())) {
                std::error_code ec;
                size += fs::file_size(entry.path(), ec);
            }
        }
    }
    return size;
}

// Helper function to safely delete a directory if it exists and print its size
void delete_directory(const fs::path& dir_path) {
    if (fs::exists(dir_path)) {
        if (fs::is_directory(dir_path)) {
            std::uintmax_t size_bytes = get_directory_size(dir_path);
            double size_mb = static_cast<double>(size_bytes) / (1024 * 1024);
            cout << "[Info] Directory size: " << size_mb << " MB - " << dir_path << endl;

            std::error_code ec;
            fs::remove_all(dir_path, ec);
            if (ec) {
                cerr << "[Error] Failed to delete: " << dir_path << " - " << ec.message() << endl;
            } else {
                cout << "[Success] Deleted: " << dir_path << endl;
            }
        } else {
            cerr << "[Warning] Not a directory: " << dir_path << endl;
        }
    } else {
        cerr << "[Info] Directory does not exist: " << dir_path << endl;
    }
}

// C++
#include <cstdlib> // for std::getenv

int main() {
    const char* home = std::getenv("HOME");
    if (!home) {
        cerr << "[Error] HOME environment variable not set." << endl;
        return 1;
    }
    const string base_path = string(home) + "/.config/Code";
    const string dirs_to_delete[] = {"Cache", "CachedData", "CachedExtensionVSIXs"};

    for (const auto& dir : dirs_to_delete) {
        fs::path full_path = fs::path(base_path) / dir;
        delete_directory(full_path);
    }

    return 0;
}