#ifndef __LIBSEE_FILE_H__
#define __LIBSEE_FILE_H__

/**
 *  _____   _______ ______ _______ _______ _______ 
 * |     |_|_     _|   __ \     __|    ___|    ___|
 * |       |_|   |_|   __ <__     |    ___|    ___|
 * |_______|_______|______/_______|_______|_______|
 *                                               
 * @file util_file.h
 * @author Benjamin Blundell - me@benjamin.computer
 * @date 26/04/2021
 * @brief Utils for use with files.
 *
 */

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <filesystem>
#ifdef _WIN32
#include <experimental/filesystem>
#endif

namespace libsee {

std::vector<char> ReadFile(const std::string& filename);
std::vector<std::string> ReadFileLines(const std::string& filename);
bool FileExists(const std::string& filename);
std::vector<std::string> ListFiles(const std::string &path);
std::vector<std::string> ListDirs(const std::string &path);

}

#endif