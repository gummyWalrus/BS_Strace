/*
** EPITECH PROJECT, 2022
** bs_strace
** File description:
** main
*/

#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/resource.h>
#include <stdio.h>

int main(int ac, char **av)
{
    pid_t pid = -1;
    int status = -1;
    struct rusage ruse;
    void *addr;
    int signal = SIGINT;
    extern char **environ;

    if (ac > 1) {
        pid = fork();
        while (1) {
            if (pid) {
                if (ptrace(PTRACE_SYSCALL, pid, addr, &signal) >= 0) {
                    wait4(pid, &status, 0, &ruse);
                    printf("")
                    if (WIFSIGNALED(status)) printf("Error\n");
                    else if (WEXITSTATUS(status)) printf("Exited Normally\n");
                } else return 0;
            } else {
                ptrace(PTRACE_TRACEME, pid, NULL, NULL);
                execve(av[1], &av[1], environ);
            }
        }
    }
    return 84;
}