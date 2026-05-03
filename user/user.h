struct stat;

// system calls 
int fork(void);                          // Creates a new process; takes no arguments
int exit(int) __attribute__((noreturn)); //int exit(int status);  -- Terminates current process with exit status.
int wait(int*);                      //int wait(int *status);  -- Waits for a child process; stores child exit status in status.
int pipe(int*);                      //int pipe(int *p);  -- Creates a pipe; fds[0] is read end, fds[1] is write end.
int write(int, const void*, int);    //int write(int fd, const void *buf, int n); -- Writes n bytes from buf to file descriptor fd.
int read(int, void*, int);           //int read(int fd, void *buf, int n); -- Reads up to n bytes from fd into buf.
int close(int);                      //int close(int fd); -- Closes the given file descriptor
int kill(int);                       //int kill(int pid); -- Marks process pid to be killed.
int exec(const char*, char**);       //int exec(const char *path, char **argv); -- Replaces current process with program at path and arguments argv.
int open(const char*, int);          //int open(const char *path, int flags); -- Opens file at path using flags; returns file descriptor.
int mknod(const char*, short, short);  //int mknod(const char *path, short major, short minor); -- Creates a device file with major/minor numbers -- not relly important
int unlink(const char*);               //int unlink(const char *path); -- Removes a file name from the file system. 
int fstat(int fd, struct stat*);      //int fstat(int fd, struct stat *st); -- Gets file information for open file descriptor fd into st.
int link(const char*, const char*);  //int link(const char *old, const char *new); -- Creates a hard link new to existing file old -- another name to the same inode
int mkdir(const char*);              //int mkdir(const char *path); -- Creates a new directory at path. 
int chdir(const char*);             // int chdir(const char *path); -- Changes current working directory to path.
int dup(int);                       // int dup(int fd); -- Duplicates file descriptor fd.
int getpid(void);                   //int getpid(void);  -- Returns the current process ID
char* sbrk(int);                    //char *sbrk(int n);  -- Grows process memory by n bytes; returns old end address.
int sleep(int);                     //int sleep(int ticks); -- Sleeps for the given number of timer ticks.
int uptime(void);                   //int uptime(void);  -- Returns number of timer ticks since boot.
int memsize(void);                  //   <-- Task2
int co_yield(int pid, int value);   //   <-- Task3

// ulib.c
int stat(const char*, struct stat*);     //int stat(const char *path, struct stat *st);  -- Gets file information for path into st.
char* strcpy(char*, const char*);        //char *strcpy(char *dst, const char *src);  -- Copies string src into dst.
void *memmove(void*, const void*, int); //void *memmove(void *dst, const void *src, int n); -- Copies n bytes from src to dst safely, even if overlapping.
char* strchr(const char*, char c);      //char *strchr(const char *s, char c);  -- Finds first occurrence of character c in string s.
int strcmp(const char*, const char*);   //int strcmp(const char *p, const char *q);  -- Compares strings p and q.
void fprintf(int, const char*, ...);    //void fprintf(int fd, const char *fmt, ...); -- Prints formatted output to file descriptor fd.
void printf(const char*, ...);          //void printf(const char *fmt, ...);  -- // Prints formatted output to standard output.
char* gets(char*, int max);             //char *gets(char *buf, int max);  -- Reads a line into buf, up to max bytes.
uint strlen(const char*);               //uint strlen(const char *s); -- Returns length of string s.
void* memset(void*, int, uint);         //void *memset(void *dst, int c, uint n);  -- Fills n bytes at dst with byte value c.
void* malloc(uint);                     //void *malloc(uint n);  -- Allocates n bytes on the heap.
void free(void*);                       //void free(void *p);  -- Frees heap memory previously allocated by malloc.
int atoi(const char*);                 //int atoi(const char *s); -- Converts string s to an integer.
int memcmp(const void *, const void *, uint);   //int memcmp(const void *p, const void *q, uint n); -- Compares n bytes at p and q.
void *memcpy(void *, const void *, uint);   //void *memcpy(void *dst, const void *src, uint n);  -- Copies n bytes from src to dst.
