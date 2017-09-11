#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscall.h>

/*
int read(int fd, char *buf, int n);
int write(int fd, char *buf, int n);

int fstat(int fd, struct stat *st);
  */ 
char Mygetc()
{
    
    char *c=NULL;
    c=(char *)malloc(sizeof(char));
    read(0,c,1);
    return *c;
}
char* Mygets(char *s,int size)
{
    char c;
    int i=0;
    //c=Mygetc();
    //char *s1;
    s=(char*)(malloc(sizeof(char)*size));
    while((c=Mygetc())!='\n' && i<size)
    {
            
        s[i++]=c;
    }
    s[i]='\0';
    //s=s1;
    return s;

}
struct Mydirentry{
    long inode_dirent;
    char name_dirent[15];
} ;

struct MyDIR{
    int fd;
    struct Mydirentry dir;
} ;
struct Mydirect
{
	long inode_direct;
	char name_direct[15];
};


//now declare the function prototype here

struct MyDIR *Myopendir(char *);
struct Mydirentry *Myreaddir(struct MyDIR *);
void Myclosedir(struct MyDIR *);


// opendir is written here
struct MyDIR * Myopendir(char *dirname)
{
    int fd;
    struct MyDIR *d;

    if ((fd = open(dirname,O_RDONLY,0)) == -1|| (d = malloc(sizeof(struct MyDIR))) == NULL)
        return NULL;
   d->fd = fd;
   printf("my dir is returning  fd = %d\n" ,d->fd);
   return d;
}
//readdirectory

struct Mydirentry *Myreaddir(struct MyDIR *dir)
{
    printf("The one that entered the myread is %d\n",dir->fd);
    struct Mydirect directbuf;
    static struct Mydirentry direntry;
    
    while ((syscall(78,dir->fd,&directbuf,1000)) != -1) {
        printf("%s\n", directbuf.name_direct);
            
        if (directbuf.inode_direct == 0) {
            printf("Nothing \n");
            continue;
        }
        direntry.inode_dirent = directbuf.inode_direct;
        printf("%ld is the inode of the direntry  \n", direntry.inode_dirent);
        strncpy(direntry.name_dirent, directbuf.name_direct, 14);
        direntry.name_dirent[14] = '\0';
        return &direntry;
    }
    printf("-----");

    return NULL;
}
//closedirectory

void Myclosedir(struct MyDIR *d)
{
    if(d!=NULL) {
        
        close(d->fd);
        free(d);
    }
}

 int Myls(char *filename)
 {	
    struct Mydirentry *de;
 	struct MyDIR *dir=Myopendir(filename); // Pointer for directory entry
    if (dir == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Failed opening the directory!!");
        return 0;
    }
 	
    while ((de = Myreaddir(dir)) != NULL)
            printf("%s\n", de->name_dirent);
 	
    Myclosedir(dir);    
    return 0;

 }

int main()
{
	char *command;
	command=Mygets(command,100);
	strtok(command," ");
    char *filename=strtok(NULL," ");
	Myls(filename);
 
	return 0;

}
