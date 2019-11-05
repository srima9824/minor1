#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void reg_upload()
{
	FILE *fp1;
	FILE *fp2;
	fp1 = fopen("user.txt","r");
	fp2 = fopen("user1.txt","w+");
	char c[1000];
	char ch[1000];
	
	fscanf(fp1,"%[^\n]",c);
	printf("%s\n",c);
	int i = 0,k=0;
	while(c[i]!='=')
	{
		//printf("%c",c[i]);
		i++;
	
	}
	++i;
	while(c[i]!='&')
	{
	//printf("%c",c[i++]);
    fprintf(fp2,"%c",c[i++]);
	}
	fprintf(fp2," ");
	while(c[i]!='=')
	{
		//printf("%c",c[i]);
		i++;
	
	}
	++i;
	while(c[i]!=' ')
	{
	//printf("%c",c[i++]);
    fprintf(fp2,"%c",c[i++]);
	}
	fprintf(fp2,"%c"," ");

	fclose(fp1);
	fclose(fp2);
}
void upload(char username[],char ip[])
{
	FILE *fp;
    fp = fopen("user.txt", "w");
    
    fprintf(fp,"%s %s ",username, ip);
    fprintf(fp,"%s","\n");
    fclose(fp);
    reg_upload();
}


int main()
{
	
	/*printf("Content-Type: text/html;charset=us-ascii\n\n");
	printf(" ");*/
	printf("%s%c%c\n",
  "Content-Type:text/html;charset=iso-8859-1",13,10);
		char *username,*ip, user[100],i_p[100],user_final[100],str[100];
		username = getenv("QUERY_STRING");
		sscanf(username,"%s",&user);
		printf("\n");
		printf("%s",user);
		ip = getenv("QUERY_STRING");
		sscanf(ip,"%s",&i_p);
		//printf("%s",i_p);
		upload(user,i_p);
	return 0;
}
