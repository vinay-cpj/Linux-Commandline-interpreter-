#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
int main(int argc,char *argv[2])
{
	struct stat buf[1024];
	struct dirent **entrylist;
	struct passwd *pw;
	int n,i,j;
	struct tm local_time;
	char time_buf[200];
	if(argc < 1)
	{
        	exit(EXIT_FAILURE);
	}
	else if (argc == 1)
	{
		n=scandir(".",&entrylist,NULL,alphasort);
		i=2;
		while (i<n)
		{
			printf("%s\n",entrylist[i]->d_name);
			free(entrylist[i]);
			i++;
		}
	}
	else if(argv[1][0]!='-')
	{
		n = scandir(argv[1], &entrylist, NULL, alphasort);
		i=2;
		while (i<n)
		{
			printf("%s\n",entrylist[i]->d_name);
			free(entrylist[i]);
			i++;
		}
	}
	else if(argv[1][0]=='-')
	{
		n=scandir(".",&entrylist,NULL,alphasort);
		if(argv[1][1]=='a')
		{
			i=0;
			while (i<n)
			{
				printf("%s\n",entrylist[i]->d_name);
				free(entrylist[i]);
				i++;
			}	
		}
		else if(argv[1][1]=='l')
		{
			i=2;
			while (i<n)
			{
				if((j=stat(entrylist[i]->d_name,buf))==0)
                {
                    if(S_ISDIR(buf->st_mode))putchar('d');
                    else putchar('-');
                    if(buf->st_mode & S_IRUSR)putchar('r');
                    else putchar('-');
                    if(buf->st_mode & S_IWUSR)putchar('w');
                    else putchar('-');
                    if(buf->st_mode & S_IXUSR)putchar('x');
                    else putchar('-');
                    if(buf->st_mode & S_IRGRP)putchar('r');
                    else putchar('-');
                    if(buf->st_mode & S_IWGRP)putchar('w');
                    else putchar('-');
                    if(buf->st_mode & S_IXGRP)putchar('x');
                    else putchar('-');
                    if(buf->st_mode & S_IROTH)putchar('r');
                    else putchar('-');
                    if(buf->st_mode & S_IWOTH)putchar('w');
                    else putchar('-');
                    if(buf->st_mode & S_IXOTH)putchar('x');
                    else putchar('-');
				    printf("%2d",(int)buf->st_nlink);
				    pw=getpwuid(buf->st_uid);
				    printf(" %-5s",pw->pw_name); 
				    printf(" %-5s", getgrgid(buf->st_gid)->gr_name);
				    printf(" %5d",(int)buf->st_size);
				    time_t t =buf->st_mtime;
				    localtime_r(&t, &local_time);
				    strftime(time_buf, sizeof(time_buf), " %b %e %H:%M", &local_time);
				    printf(" %s",time_buf);
				    printf(" %-5s",entrylist[i]->d_name);
				    printf("\n");}
			i++;
			}
			free(entrylist); 
		} 
	}
	printf("\n");
	exit(EXIT_SUCCESS);
}    

