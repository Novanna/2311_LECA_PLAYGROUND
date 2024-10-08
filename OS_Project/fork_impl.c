#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHILDREN 2

void create_processes(int current_id, int max_id, const char* name);
void print_memory_info();
char* secure_name(const char* name);
char* custom_hash(const char* name);
void process_task(int current_id, const char* name);

int main() {
    char name[100];
    printf("_______________________________________________________\n");
    printf("Masukkan Nama Lengkap: ");
    fgets(name, sizeof(name), stdin);
    // remove newline character
    name[strcspn(name, "\n")] = '\0';
    printf("_______________________________________________________\n");
    create_processes(1, 5, name); 
    return 0;
}

void create_processes(int current_id, int max_id, const char* name) {
    printf("[log] P%d: Started | ", current_id);
    print_memory_info();

    // create child processes
    pid_t children[MAX_CHILDREN];
    int num_children = 0;

    if (current_id == 1) {
        // p1 has children p2 and p3
        children[num_children++] = 2;
        children[num_children++] = 3;
    } else if (current_id == 3) {
        // p3 has p4 and p5
        children[num_children++] = 4;
        children[num_children++] = 5;
    }

    for (int i = 0; i < num_children; ++i) {
        pid_t pid = fork();
        if (pid == 0) {
            // child process
            create_processes(children[i], max_id, name);
            return;
        }
    }

    // wait for all child processes to finish
    while (wait(NULL) > 0);

    // perform task for current process
    process_task(current_id, name);

    printf("[log] P%d: Finished\n", current_id);
}

void print_memory_info() {
    printf("PID: %d | Parent PID: %d\n", getpid(), getppid());
}

char* secure_name(const char* name) {
    // hasing name
    size_t len = strlen(name);
    char* secure = malloc(len + 1);

    strncpy(secure, name, len);
    // replace characters except the first and last two
    for (int i = 2; i < len - 2; ++i) {
        if (secure[i] != ' ') {
            secure[i] = '*';
        }
    }
    secure[len] = '\0';
    return secure;
}

char* custom_hash(const char* name) {
    size_t len = strlen(name);
    char* hashed = malloc(len + 1);

    // copy the first two char
    strncpy(hashed, name, 2);

    // hash the characters in between
    for (int i = 2; i < len - 2; ++i) {
        if (name[i] != ' ') {
            hashed[i] = '*';
        } else {
            hashed[i] = ' ';
        }
    }

    // copy the last two char
    strncpy(hashed + (len - 2), name + (len - 2), 2);

    hashed[len] = '\0';
    return hashed;
}

void process_task(int current_id, const char* name) {

    if (current_id == 2) {
        printf("_______________________________________________________\n");
        printf("Selamat datang %s, kami sedang memproses tiket untukmu!\n", name);
        printf("_______________________________________________________\n");
    } else if (current_id == 3) {
        char* secured_name = secure_name(name);
        printf("_______________________________________________________\n");
        printf("Nama yang diamankan: %s\n", secured_name);
        printf("_______________________________________________________\n");
        free(secured_name);
    } else if (current_id == 4) {
        // Simpan nama ke sistem (simulasi)
        printf("_______________________________________________________\n");
        printf("Nama %s berhasil disimpan ke sistem.\n", name);
        printf("_______________________________________________________\n");
    } else if (current_id == 5) {
        // Hashing atau transformasi nama (simulasi)
        char* hashed_name = custom_hash(name);
        printf("_______________________________________________________\n");
        printf("Nama %s berhasil diubah/hashed.\n", hashed_name);
        printf("_______________________________________________________\n");
        free(hashed_name);
    }
}
