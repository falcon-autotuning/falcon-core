/**
 * @file falcon_core_info.cpp
 * @brief Command-line utility to display version information for Falcon Core libraries
 */

#include <iostream>
#include <string>
#include <cstring>
#include <falcon_core/version.hpp>
#include <falcon_core/version_c_api.h>

void print_usage() {
    std::cout << "falcon-core-info - Falcon Core Version Information Utility\n\n";
    std::cout << "Usage: falcon-core-info [OPTIONS]\n\n";
    std::cout << "Options:\n";
    std::cout << "  --version, -v        Show version information\n";
    std::cout << "  --cpp-version        Show C++ core version only\n";
    std::cout << "  --c-api-version      Show C-API version only\n";
    std::cout << "  --full               Show full version with commit info\n";
    std::cout << "  --help, -h           Show this help message\n\n";
    std::cout << "Examples:\n";
    std::cout << "  falcon-core-info --version       # Show brief version info\n";
    std::cout << "  falcon-core-info --full          # Show detailed version info\n";
}

void print_brief_version() {
    std::cout << "Falcon Core Libraries Version Information:\n";
    std::cout << "  C++ Core: " << falcon_core::get_version() << std::endl;
    std::cout << "  C-API:    " << falcon_core_c_api_get_version() << std::endl;
}

void print_full_version() {
    std::cout << "Falcon Core Libraries - Full Version Information:\n";
    std::cout << "================================================\n";
    std::cout << "C++ Core Library:\n";
    std::cout << "  Version:     " << falcon_core::get_version() << std::endl;
    std::cout << "  Git Commit:  " << falcon_core::get_git_commit() << std::endl;
    std::cout << "  Git Tag:     " << (falcon_core::get_git_tag().empty() ? "(none)" : falcon_core::get_git_tag()) << std::endl;
    std::cout << "  Full:        " << falcon_core::get_full_version() << std::endl;
    std::cout << "\n";
    std::cout << "C-API Library:\n";
    std::cout << "  Version:     " << falcon_core_c_api_get_version() << std::endl;
    std::cout << "  Git Commit:  " << falcon_core_c_api_get_git_commit() << std::endl;
    std::cout << "  Git Tag:     " << (strlen(falcon_core_c_api_get_git_tag()) == 0 ? "(none)" : falcon_core_c_api_get_git_tag()) << std::endl;
    std::cout << "  Full:        " << falcon_core_c_api_get_full_version() << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        // Default behavior: show brief version
        print_brief_version();
        return 0;
    }

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        
        if (arg == "--version" || arg == "-v") {
            print_brief_version();
            return 0;
        } else if (arg == "--cpp-version") {
            std::cout << "falcon-core-cpp " << falcon_core::get_full_version() << std::endl;
            return 0;
        } else if (arg == "--c-api-version") {
            std::cout << "falcon-core-c-api " << falcon_core_c_api_get_full_version() << std::endl;
            return 0;
        } else if (arg == "--full") {
            print_full_version();
            return 0;
        } else if (arg == "--help" || arg == "-h") {
            print_usage();
            return 0;
        } else {
            std::cerr << "Unknown option: " << arg << std::endl;
            std::cerr << "Use --help for usage information." << std::endl;
            return 1;
        }
    }

    return 0;
}