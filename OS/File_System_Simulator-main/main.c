#include <stdio.h>
#include "filesystem.h"
#include <string.h>

int main()
{
    initializeFileSystem();

    int choice;
    char filename[100];
    char content[2048];
    char dirname[100];

    while (1)
    {
        printf("\n");
        printf("┌───────────────────────────────┐\n");
        printf("│ Simple File System Smiulator||│\n");
        printf("├───────────────────────────────┤\n");
        printf("│ 1. Create File                │\n");
        printf("│ 2. Delete File                │\n");
        printf("│ 3. Read File                  │\n");
        printf("│ 4. Write to File              │\n");
        printf("│ 5. Create Directory           │\n");
        printf("│ 6. Delete Directory           │\n");
        printf("│ 7. Change Directory           │\n");
        printf("│ 8. List Directory             │\n");
        printf("│ 9. Exit                       │\n");
        printf("└───────────────────────────────┘\n");
        printf("→ ");
        scanf("%d", &choice);
        getchar(); // This will consume the newline character left in the input buffer

        switch (choice)
        {
        case 1: 
            printf("Enter filename: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = 0; // Remove the newline character at the end
            printf("Enter content: ");
            fgets(content, sizeof(content), stdin);
            content[strcspn(content, "\n")] = 0; // Remove the newline character
            createFile(filename, content);
            break;
        case 2:
            printf("Enter filename to delete: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = 0; // Remove the newline character
            deleteFile(filename);
            break;
        case 3:
            printf("Enter filename to read: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = 0; // Remove the newline character
            readFile(filename);
            break;
        case 4:
            printf("Enter filename to write to: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = 0; // Remove the newline character
            printf("Enter content: ");
            fgets(content, sizeof(content), stdin);
            content[strcspn(content, "\n")] = 0; // Remove the newline character
            writeFile(filename, content);
            break;
        case 5:
            printf("Enter directory name: ");
            fgets(dirname, sizeof(dirname), stdin);
            dirname[strcspn(dirname, "\n")] = 0; // Remove the newline character
            createDirectory(dirname);
            break;
        case 6:
            printf("Enter directory name to delete: ");
            fgets(dirname, sizeof(dirname), stdin);
            dirname[strcspn(dirname, "\n")] = 0; // Remove the newline character
            deleteDirectory(dirname);
            break;
        case 7:
            printf("Enter directory name to navigate to (or .. for parent): ");
            fgets(dirname, sizeof(dirname), stdin);
            dirname[strcspn(dirname, "\n")] = 0; // Remove the newline character
            changeDirectory(dirname);
            break;
        case 8:
            listDirectory();
            break;
        case 9:
            printf("Goodbye!\n");
            return 0; // Exits the program.
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
