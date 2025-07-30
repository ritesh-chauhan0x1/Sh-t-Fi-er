#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

void switchProfile(const char *username, const char *email) {
    char cmd[512];

    // Set Git user name
    sprintf(cmd, "git config --global user.name \"%s\"", username);
    system(cmd);

    // Set Git user email
    sprintf(cmd, "git config --global user.email \"%s\"", email);
    system(cmd);

    printf("Switched to GitHub account:\nName: %s\nEmail: %s\n", username, email);
}

void listProfiles() {
    FILE *file = fopen("config.txt", "r");
    if (!file) {
        printf("No profiles found.\n");
        return;
    }

    char line[MAX_LINE];
    printf("Available GitHub Profiles:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("- %s", line);
    }
    fclose(file);
}

void help() {
    printf("GitHub Shifter - CLI Tool\n");
    printf("Usage:\n");
    printf("  ./github-shifter add [name] [email]   -> Add new profile\n");
    printf("  ./github-shifter switch [name]        -> Switch to profile\n");
    printf("  ./github-shifter list                 -> List all profiles\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        help();
        return 1;
    }

    if (strcmp(argv[1], "add") == 0 && argc == 4) {
        FILE *file = fopen("config.txt", "a");
        fprintf(file, "%s,%s\n", argv[2], argv[3]);
        fclose(file);
        printf("Added profile: %s (%s)\n", argv[2], argv[3]);
    } else if (strcmp(argv[1], "switch") == 0 && argc == 3) {
        FILE *file = fopen("config.txt", "r");
        if (!file) {
            printf("No profiles found.\n");
            return 1;
        }

        char line[MAX_LINE];
        int found = 0;
        while (fgets(line, sizeof(line), file)) {
            char name[100], email[100];
            sscanf(line, "%[^,],%s", name, email);
            if (strcmp(name, argv[2]) == 0) {
                switchProfile(name, email);
                found = 1;
                break;
            }
        }
        fclose(file);
        if (!found) {
            printf("Profile '%s' not found.\n", argv[2]);
        }
    } else if (strcmp(argv[1], "list") == 0) {
        listProfiles();
    } else {
        help();
    }

    return 0;
}
