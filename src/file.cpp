/**
 *  _____   _______ ______ _______ _______ _______ 
 * |     |_|_     _|   __ \     __|    ___|    ___|
 * |       |_|   |_|   __ <__     |    ___|    ___|
 * |_______|_______|______/_______|_______|_______|
 *                                               
 * @file util_file.cc
 * @author Benjamin Blundell - me@benjamin.computer
 * @date 26/04/2021
 * @brief Basic file utilities
 *
 */

#include "file.hpp"

namespace libsee {

/**
 * Basic file reading. Reads chars
 *
 * @param path - the file path
 * 
 * @return vector of char for this file.
 */

std::vector<char> ReadFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::ate | std::ios::binary);

    // TODO - no exceptions! Replace with our final error handling
    if (!file.is_open()) {
        throw std::runtime_error("failed to open file!");
    }

    size_t fileSize = (size_t) file.tellg();
    std::vector<char> buffer(fileSize);
    file.seekg(0);
    file.read(buffer.data(), fileSize);
    file.close();

    return buffer;
}

/**
 * Basic file reading. Reads text file by lines
 *
 * @param path - the file path
 * 
 * @return vector of string for this file.
 */
std::vector<std::string> ReadFileLines(const std::string& filename) {
    std::fstream newfile;
    std::vector<std::string> lines;
    newfile.open(filename.c_str(), std::ios::in);

    if (newfile.is_open()){ 
        std::string tp;
        while(getline(newfile, tp)){ 
            lines.push_back(tp);
        }
        newfile.close();
    }
    return lines;
}


/**
 * Check if this file exists
 * 
 * @param filename - the file path
 * 
 * @return bool
 */

bool FileExists(const std::string& filename) {
    std::ifstream ifile(filename.c_str());
    return (bool)ifile;
}

/**
 * List files inside the given path
 * 
 * @param path - the directory path
 * 
 * @return vector of strings of files
 */

std::vector<std::string> ListFiles(const std::string &path) {
    std::vector<std::string> res;
#ifdef _WIN32
    for (const auto & entry : std::experimental::filesystem::directory_iterator(path)) {
#else
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
#endif
        if (entry.is_regular_file()){
            res.push_back(entry.path());
        }
    }
    
    return res;
    
}

/**
 * List directories inside the given path
 * 
 * @param path - the directory path
 * 
 * @return vector of strings of directories
 */

std::vector<std::string> ListDirs(const std::string &path) {
    std::vector<std::string> res;
    
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_directory()){
            res.push_back(entry.path());
        }
    }

    return res;
}

}