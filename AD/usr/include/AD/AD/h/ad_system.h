#ifndef AD_SYSTEM_H
#define AD_SYSTEM_H

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

static int ad_system_impl(const char* command, const char* shell_path, const char* shell_name);

static int ad_bash_system(const char* command);
static int ad_zsh_system(const char* command);

// 舊版函式已淘汰，僅作紀念註解
// int ad_system(const char* command);

// 建立別名函式
static inline int ad_bash_sys(const char* command) {
    return ad_bash_system(command);
}

static inline int ad_zsh_sys(const char* command) {
    return ad_zsh_system(command);
}

static int ad_system_impl(const char* command, const char* shell_path, const char* shell_name) {
    if (command == NULL || strlen(command) == 0) {
        return 1;
    }

    int status = 0;
    pid_t pid = fork();
    
    if (pid == -1) {
        return -1;
    } else if (pid == 0) {
        execl(shell_path, shell_name, "-c", command, (char *)NULL);
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

static int ad_bash_system(const char* command) {
    return ad_system_impl(command, "/var/jb/bin/bash", "bash");
}

static int ad_zsh_system(const char* command) {
    return ad_system_impl(command, "/var/jb/bin/zsh", "zsh");
}

#endif