/*
 *
 * ad_system.hpp
 * IOS disabled the system function
 * So re-realize the system function
 *
*/

#ifndef AD_SYSTEM_HPP
#define AD_SYSTEM_HPP

#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

inline int ad_system_impl(const std::string& command, const char* shell_path, const char* shell_name);

inline int ad_bash_system(const std::string& command);
inline int ad_zsh_system(const std::string& command);

// Use inline functions to create aliases
inline int ad_bash_sys(const std::string& command) {
    return ad_bash_system(command);
}

inline int ad_zsh_sys(const std::string& command) {
    return ad_zsh_system(command);
}

inline int ad_system_impl(const std::string& command, const char* shell_path, const char* shell_name) {
    if (command.empty()) {
        return 1;
    }

    int status = 0;
    pid_t pid = fork();
    
    if (pid == -1) {
        return -1;
    } else if (pid == 0) {
        execl(shell_path, shell_name, "-c", command.c_str(), (char *)NULL);
        _exit(127);
    } else {
        waitpid(pid, &status, 0);
        
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return -1;
        }
    }
}

inline int ad_bash_system(const std::string& command) {
    return ad_system_impl(command, "/var/jb/bin/bash", "bash"); // Other absolute paths that need to be modified to Shell, such as /bin/sh
}

inline int ad_zsh_system(const std::string& command) {
    return ad_system_impl(command, "/var/jb/bin/zsh", "zsh"); // Annotation with bash
}

#endif