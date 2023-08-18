#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>

int main()
{
    char data;
    char buf[100], pat[10], temp[1024];
    int ch1, ch = 0, fd, fd1, i, n, m, charcount = 0;
    int ret;
    char fname[10];
    char *newline;
    FILE *fp;
    struct stat *sb;

    do
    {
        printf("PERFORM OPERATIONS ON FILE\n");
        printf("1. Create File\n2. Read Contents\n3. Write In File\n4. Read File in Reverse \n5. Search Pattern in File\n6. Delete File\n");
        printf("Enter Your Choice : ");
        scanf("%d", &ch1);
        switch (ch1)
        {
        case 1:
            printf("ENTER FILE NAME TO BE CREATED : ");
            scanf("%s", fname);
            fd = creat(fname, 0777);
            if (fd == -1)
                printf("UNABLE TO CREATE FILE\n");
            else
            {
                printf("FILE CREATED\n");
                printf("ENTER CONTENTS TO WRITE (WITH UNDERSCORE AS SPACES) : \n");
                scanf("%s", buf);
                charcount = strlen(buf);
                write(fd, buf, charcount);
                close(fd);
            }
            break;

        case 2:
            char str[200];
            printf("Enter file name which you have to open : ");
            scanf("%s", fname);
            fd = open(fname, O_RDWR | O_CREAT, 0777);
            if (fd == -1)
                printf("UNABLE TO CREATE FILE\n");
            else
            {
                printf("File opened\n");
                printf("The contents are \n");
                read(fd, str, sizeof(str) - 1);
                printf("CONTENTS ARE --> %s\n", str);
                n = lseek(fd, 0, 2);
                printf("Size is \t %d \n", n);
                /*lseek(fd,0,0);
                for(i=1;i<=n;i++){
                 read(fd, data, 1);
                 printf("%c",data);
                 lseek(fd,1,1);
                }*/
            }
            printf("\n");
            close(fd);
            break;

        case 3:
            printf("Enter file name which you have to open : ");
            scanf("%s", fname);
            fd = open(fname, O_WRONLY | O_APPEND, 0777);
            if (fd == -1)
                printf("UNABLE TO CREATE FILE\n");
            else
            {
                printf("File opened\n ");
                printf("Enter the contents to write : ");
                scanf("%s", buf);
                charcount = strlen(buf);
                write(fd, buf, charcount);
            }
            close(fd);
            break;

        case 4:
            printf("Enter file you want to open : ");
            scanf("%s", fname);
            fd = open(fname, O_RDONLY, 0777);
            if (fd == -1)
                printf("UNABLE TO CREATE FILE\n");
            else
            {
                printf("File opened\n");
                printf("The contents are in reversed order\n");
                n = lseek(fd, 0, 2);
                lseek(fd, -1, 2);
                while ((n--) > 0)
                {
                    read(fd, &data, 1);
                    printf("%c", data);
                    lseek(fd, -2, 1);
                }
            }
            printf("\n");
            close(fd);
            break;

        case 5:
            char name[20];
            printf("Enter file name: ");
            scanf("%s", name);
            fd = open(name, O_RDWR | O_CREAT, 0777);
            if (fd == -1)
                printf("FILE NOT FOUND/ CREATED\n");
            else
            {
                printf("Enter a String to compare : ");
                scanf("%s", str);
                n = lseek(fd, 0, 2);
                int len = strlen(str);
                lseek(fd, 0, 0);
                int ptr = 1;
                while (n - len > 0)
                {
                    char temp[len + 1];
                    read(fd, temp, sizeof(temp));
                    str[len] = temp[len];
                    if (strstr(temp, str) != 0)
                    {
                        printf("Match Found\n");
                    }
                    lseek(fd, ptr, 0);
                    ptr++;
                    n--;
                }
            }
            close(fd);
            break;

        case 6:
            printf("ENTER FILE NAME TO BE DELETED\n");
            scanf("%s", fname);
            unlink(fname);
            break;
            printf("DO YOU WANT TO CONTINUE 0/1 : ");
            scanf("%d", &ch);
        }
    } while (ch == 1);
}