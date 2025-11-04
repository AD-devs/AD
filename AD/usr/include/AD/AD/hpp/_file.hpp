/* _file.hpp
 *
 * The standard of AD private library
 * A small interface is provided for unified mobility.
 *
*/

#ifndef _AD_FILE_HPP_
#define _AD_FILE_HPP_

#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

// 創建文件夾
void _AD_mkdir(const std::string& path) {
    fs::create_directories(path);
}

// 創建文件
void _AD_touch(const std::string& filename) {
    std::ofstream file(filename);
}

#endif