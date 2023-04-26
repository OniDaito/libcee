#ifndef __libcee_FILE_H__
#define __libcee_FILE_H__

/**
 *  (     (                           
 *  )\ )  )\ )   (     (              
 * (()/( (()/( ( )\    )\   (    (    
 *  /(_)) /(_)))((_) (((_)  )\   )\   
 * (_))  (_)) ((_)_  )\___ ((_) ((_)  
 * | |   |_ _| | _ )((/ __|| __|| __| 
 * | |__  | |  | _ \ | (__ | _| | _|  
 * |____||___| |___/  \___||___||___| 
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
#define  _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>
#endif

namespace libcee {

std::vector<char> ReadFile(const std::string& filename);
std::vector<std::string> ReadFileLines(const std::string& filename);
bool FileExists(const std::string& filename);
std::vector<std::string> ListFiles(const std::string &path);
std::vector<std::string> ListDirs(const std::string &path);

}

#endif