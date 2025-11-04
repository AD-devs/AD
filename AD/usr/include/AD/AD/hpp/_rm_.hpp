/* _rm_.hpp
 *
 * The standard of AD private library
 * Delete documents and use folders
 * 
*/

#ifndef _AD_RM_HPP_
#define _AD_RM_HPP_

#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

namespace AD_private {

/*
 *
 * @brief Delete a single file
 * @param filePath File path
 * @return int Success returns 1, failure returns 0
 *
*/

int _AD_rm(const fs::path& filePath) {
    try {
        if (!fs::exists(filePath)) {
            std::cout << "Document does not exist: " << filePath << std::endl;
            return 0;
        }
        
        if (!fs::is_regular_file(filePath)) {
            std::cout << "Path is not a regular file: " << filePath << std::endl;
            return 0;
        }
        
        if (fs::remove(filePath)) {
            std::cout << "File deleted successfully: " << filePath << std::endl;
            return 1;
        } else {
            std::cout << "Failed to delete file: " << filePath << std::endl;
            return 0;
        }
        
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Delete file error: " << e.what() << std::endl;
        return 0;
    }
}

/*
 *
 * @brief Delete empty folders
 * @param dirPath Folder Path
 * @return int Success returns 1, failure returns 0
 *
*/

int _AD_rmdir(const fs::path& dirPath) {
    try {
        if (!fs::exists(dirPath)) {
            std::cout << "Directory does not exist: " << dirPath << std::endl;
            return 0;
        }
        
        if (!fs::is_directory(dirPath)) {
            std::cout << "Path is not a directory: " << dirPath << std::endl;
            return 0;
        }
        
        // 檢查目錄是否為空
        if (!fs::is_empty(dirPath)) {
            std::cout << "Directory is not empty, use _AD_rmdirf instead: " << dirPath << std::endl;
            return 0;
        }
        
        if (fs::remove(dirPath)) {
            std::cout << "Empty directory deleted successfully: " << dirPath << std::endl;
            return 1;
        } else {
            std::cout << "Failed to delete empty directory: " << dirPath << std::endl;
            return 0;
        }
        
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Delete directory error: " << e.what() << std::endl;
        return 0;
    }
}

/*
 *
 * @brief Recursively delete the folder and all its contents
 * @param dirPath Folder path
 * @return int Success returns the number of items deleted, failure returns 0
 *
*/

int _AD_rmdirf(const fs::path& dirPath) {
    try {
        if (!fs::exists(dirPath)) {
            std::cout << "Directory does not exist: " << dirPath << std::endl;
            return 0;
        }
        
        if (!fs::is_directory(dirPath)) {
            std::cout << "Path is not a directory: " << dirPath << std::endl;
            return 0;
        }
        
        std::uintmax_t count = fs::remove_all(dirPath);
        if (count > 0) {
            std::cout << "Directory and its contents deleted successfully: " << dirPath << std::endl;
            std::cout << "Total items deleted: " << count << std::endl;
            return static_cast<int>(count);
        } else {
            std::cout << "Failed to delete directory: " << dirPath << std::endl;
            return 0;
        }
        
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Recursive deletion error: " << e.what() << std::endl;
        return 0;
    }
}

/*
 *
 * @brief Automatically select the deletion method according to the type
 * @param path Way
 * @return int Success returns 1, failure returns 0
 *
*/

int _AD_rm_safe(const fs::path& path) {
    try {
        if (!fs::exists(path)) {
            std::cout << "Path does not exist: " << path << std::endl;
            return 0;
        }
        
        if (fs::is_directory(path)) {
            return _AD_rmdirf(path) > 0 ? 1 : 0;
        } else if (fs::is_regular_file(path)) {
            return _AD_rm(path);
        } else {
            std::cout << "Unsupported file type: " << path << std::endl;
            return 0;
        }
        
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Safe deletion error: " << e.what() << std::endl;
        return 0;
    }
}

} // namespace AD_private

namespace AD = AD_private;

#endif