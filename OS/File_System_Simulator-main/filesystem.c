#include "filesystem.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Directory *root;
Directory *currentDir; // points to the current directory

void initializeFileSystem()
{
    root = malloc(sizeof(Directory));
    strcpy(root->dirname, "/");
    root->fileCount = 0;
    root->subdirCount = 0;
    currentDir = root; // Initially, we are at the root
}

int createFile(char *filename, char *content)
{
    if (currentDir->fileCount >= 10)
    {
        printf("Directory full!\n");
        return -1;
    }
    File *newFile = malloc(sizeof(File));
    strcpy(newFile->filename, filename);
    strcpy(newFile->content, content);
    currentDir->files[currentDir->fileCount++] = newFile;
    return 0; // Success
}
int deleteFile(char *filename)
{
    for (int i = 0; i < currentDir->fileCount; i++)
    {
        if (strcmp(currentDir->files[i]->filename, filename) == 0)
        {
            free(currentDir->files[i]);
            // shift all files after this position up
            for (int j = i; j < currentDir->fileCount - 1; j++)
            {
                currentDir->files[j] = currentDir->files[j + 1];
            }
            currentDir->fileCount--;
            return 0; // Success
        }
    }
    printf("File not found!\n");
    return -1;
}
int readFile(char *filename)
{
    for (int i = 0; i < currentDir->fileCount; i++)
    {
        if (strcmp(currentDir->files[i]->filename, filename) == 0)
        {
            printf("Content of %s:\n%s\n", filename, currentDir->files[i]->content);
            return 0; // Success
        }
    }
    printf("File not found!\n");
    return -1;
}
int writeFile(char *filename, char *content)
{
    for (int i = 0; i < currentDir->fileCount; i++)
    {
        if (strcmp(currentDir->files[i]->filename, filename) == 0)
        {
            strcpy(currentDir->files[i]->content, content);
            return 0; // Success
        }
    }
    printf("File not found!\n");
    return -1;
}
int createDirectory(char *dirname)
{
    if (currentDir->subdirCount >= 10)
    {
        printf("Directory full!\n");
        return -1;
    }
    Directory *newDir = malloc(sizeof(Directory));
    strcpy(newDir->dirname, dirname);
    newDir->fileCount = 0;
    newDir->subdirCount = 0;
    currentDir->subdirs[currentDir->subdirCount++] = newDir;
    return 0; // Success
}
int deleteDirectory(char *dirname)
{
    for (int i = 0; i < currentDir->subdirCount; i++)
    {
        if (strcmp(currentDir->subdirs[i]->dirname, dirname) == 0)
        {
            if (currentDir->subdirs[i]->fileCount == 0 && currentDir->subdirs[i]->subdirCount == 0)
            {
                free(currentDir->subdirs[i]);
                // shift all dirs after this position up
                for (int j = i; j < currentDir->subdirCount - 1; j++)
                {
                    currentDir->subdirs[j] = currentDir->subdirs[j + 1];
                }
                currentDir->subdirCount--;
                return 0; // Success
            }
            else
            {
                printf("Directory not empty!\n");
                return -1;
            }
        }
    }
    printf("Directory not found!\n");
    return -1;
}
int changeDirectory(char *dirname)
{
    if (strcmp(dirname, "..") == 0)
    { // If user wants to move to the parent directory
        if (currentDir == root)
        {
            printf("Already at root.\n");
            return -1;
        }
        // For simplicity, let's use nested loops to find the parent directory
        // A more efficient approach would be to add a parent pointer in the Directory structure
        for (int i = 0; i < root->subdirCount; i++)
        {
            Directory *dir = root->subdirs[i];
            for (int j = 0; j < dir->subdirCount; j++)
            {
                if (dir->subdirs[j] == currentDir)
                {
                    currentDir = dir;
                    return 0; // Success
                }
            }
        }
        printf("Error finding parent directory.\n");
        return -1;
    }
    else
    { // If user wants to move to a specific sub-directory
        for (int i = 0; i < currentDir->subdirCount; i++)
        {
            if (strcmp(currentDir->subdirs[i]->dirname, dirname) == 0)
            {
                currentDir = currentDir->subdirs[i];
                return 0; // Success
            }
        }
    }
    printf("Directory not found!\n");
    return -1;
}

void listDirectory()
{
    printf("Directories:\n");
    for (int i = 0; i < currentDir->subdirCount; i++)
    {
        printf(" - %s/\n", currentDir->subdirs[i]->dirname);
    }
    printf("Files:\n");
    for (int i = 0; i < currentDir->fileCount; i++)
    {
        printf(" - %s\n", currentDir->files[i]->filename);
    }
}
