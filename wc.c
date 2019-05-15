#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main( int argc,char *argv[3] )
{
	int fd,bytecount=0,count=0,state=0,linecount=0,line_flag=0,option_flag=0;
	int g_bytecount=0,g_count=0,g_linecount=0;
	int i=1;	
	char ch[2];
	char * to="total";
	if(argv[1][0]=='-')
	{
	option_flag=1;
	i++;
	}
	for(;i<argc;i++){
		bytecount=count=state=linecount=line_flag=0;
		fd=open(argv[i],O_RDONLY);	
		if(fd==-1)
		{
			printf("file open error\n");
		}
		else
		{
			while(read(fd,ch,1)>0)
			{
				bytecount++;
				if(ch[0]=='\n')
				{
					linecount++;
					state=0;
					line_flag=1;
				}
				else if((ch[0]!=' '&& ch[0]!='\t')&& state==0)
				{
					state=1;
					count++;
				}
				else if(ch[0]!=' '&& state==1)
				{//Do nothing
				}
				else if(ch[0]==' '&& state==0)
				{
				}
				else if(ch[0]==' ' && state==1)
				{
					state=0;
				}
				
		}
		close(fd);
		if(bytecount>0&&line_flag==0)linecount++;
		g_bytecount+=bytecount;
		g_count+=count;
		g_linecount+=linecount;
		if(!option_flag)printf("%5d %5d %5d %-5s\n",linecount,count,bytecount,argv[i]);
		else if(argv[1][1]=='c'||argv[1][1]=='m')printf("%5d %-5s \n",bytecount,argv[i]);
		else if(argv[1][1]=='l')printf("%5d %-5s\n", linecount,argv[i]);
		else if(argv[1][1]=='w')printf("%5d %-5s\n", count,argv[i]);
		}
	}
	if(g_bytecount>bytecount)
	{
		if(!option_flag)printf("%5d %5d %5d %-5s\n",g_linecount,g_count,g_bytecount,to);
                else if(argv[1][1]=='c'||argv[1][1]=='m')printf("%5d %-5s \n",g_bytecount,to);
                else if(argv[1][1]=='l')printf("%5d %-5s\n",g_linecount,to);
                else if(argv[1][1]=='w')printf("%5d %-5s\n",g_count,to);

	}
return(0);
}
