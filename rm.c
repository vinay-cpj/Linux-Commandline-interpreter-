#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
int main(int argc, char **argv)
{
	int fd,i,prmpt,err;
	char ch[1],ip[16];
	if(argv[1][1]=='i'&&argv[1][0]=='-'){
		prmpt=1;
		argc--;
	}
	for(i=1;i<argc;i++)
	{
		if(prmpt){
			printf("rm: remove regular file '%s'?",argv[i+1]);
			scanf("%s",ip);
			if(!(strcmp("yes",ip))||!(strcmp("YES",ip))||!(strcmp("y",ip))||!(strcmp("1",ip)||strcmp("Y",ip)))
			{
				if(remove(argv[i+1]))
				printf("rm: cannot remove '%s'\n",argv[i+1]);
			}
		}
		else{
		if(remove(argv[i]))
		printf("rm: cannot remove '%s'\n",argv[i]);
		}
	}
	return 0;
}
