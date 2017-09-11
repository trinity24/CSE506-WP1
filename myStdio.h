      /*
 				if(i==count){
            //for the last token
            eachCommand =strtok(NULL,"|\n");

            command=strtok(eachCommand," \n");
            args =strtok(NULL," \n");
          }
         else if(i==0)
         {
            //for the first token 
            eachCommand=strtok(readline, "|");
            command=strtok(eachCommand," \n");
            args =strtok(NULL," \n");

         }
         else
         {
            eachCommand =strtok(NULL,"|");
            command=strtok(eachCommand," ");
            args =strtok(NULL," \n");

         } */


int Mygetline(char *string, size_t *size, FILE *stream)
{
		unsigned int fd=
		MyRead(unsigned int fd, const char *buf,size_t count)
	return 
}

/* 
 struct  mydirent
 {
 	unsigned long  inode_num;     /* Inode number */
   // unsigned long  offset;     /* Offset to next linux_dirent */
//	unsigned short len_directory;  /* Length of this linux_dirent */
//	char name_directory[];  /* Filename (null-terminated) */
                                 /* length is actually (d_reclen - 2 -
                                    offsetof(struct linux_dirent, d_name)) */
               /*
               char           pad;       // Zero padding byte
               char           d_type;    // File type (only since Linux
                                         // 2.6.4); offset is (d_reclen - 1)
               */
// };
 /*
 int Mygetdents(unsigned int fd, struct mydirent *d, unsigned int size)
 {

 }*/