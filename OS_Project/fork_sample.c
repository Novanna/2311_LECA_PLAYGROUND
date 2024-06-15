#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <sys/time.h> 
#include <time.h> 

void print_time() { 
    struct timeval tv; 
    gettimeofday(&tv, NULL); 
    // Convert timeval to local time 
    time_t rawtime = tv.tv_sec; 
    struct tm *ptm = gmtime(&rawtime); 
    // Adjust to WIB (UTC+7) 
    ptm->tm_hour = (ptm->tm_hour + 7) % 24; 
    printf(", Time: %02d:%02d:%02d:%06ld \n",  
           ptm->tm_hour, ptm->tm_min, ptm->tm_sec, tv.tv_usec); 
} 

void create_processes(int current_id, int max_id) { 

    if (current_id > max_id) { 
        return; 
    } 
    printf("P%d: Started", current_id); 
    print_time(); 
    fflush(stdout); 
  
    if (current_id == 1) { 
        pid_t pid1 = fork(); 
        if (pid1 == 0) { 
            // Child process 2 
            create_processes(2, max_id); 
            return; 
        } else { 
            // Parent process 
            wait(NULL); // Wait for the first child to finish 
        } 

        pid_t pid2 = fork(); 
        if (pid2 == 0) { 
            // Child process 3 
            create_processes(3, max_id); 
            return; 
        } else { 
            // Parent process 
            wait(NULL); // Wait second child to finish 
        } 
    } else if (current_id == 3) { 
        pid_t pid3 = fork(); 
        if (pid3 == 0) { 
            // Child process 4 
            create_processes(4, max_id); 
            return; 
        } else { 
            // Parent process 
            wait(NULL); // Wait first child to finish 
        } 
        pid_t pid4 = fork(); 
        if (pid4 == 0) { 
            // Child process 5 
            create_processes(5, max_id); 
            return; 
        } else { 
            // Parent process 
            wait(NULL); //Wait second child to finish 
        } 
    } 

    printf("P%d: Finished", current_id); 
    print_time(); 
    fflush(stdout); 
} 

int main() { 
    create_processes(1, 5);  
    return 0; 
} 
