typedef struct File
{
    char filename[100];
    char content[2048];
} File;

typedef struct Directory
{
    char dirname[100];
    struct Directory *subdirs[10];
    File *files[10];
    int fileCount;
    int subdirCount;
} Directory;

// Function prototypes
void initializeFileSystem();
int createFile(char *filename, char *content);
int deleteFile(char *filename);
int readFile(char *filename);
int writeFile(char *filename, char *content);
int createDirectory(char *dirname);
int deleteDirectory(char *dirname);
int changeDirectory(char *dirname);
void listDirectory();
