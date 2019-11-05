#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void log_upload()
{
	FILE *fp1;
	FILE *fp2;
	fp1 = fopen("log","r");
	fp2 = fopen("user_log.txt","w+");
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
		printf("%c",c[i]);
		i++;
	
	}
	++i;
	while(c[i]!='&')
	{
	//printf("%c",c[i++]);
    fprintf(fp2,"%c",c[i++]);
	}
	fprintf(fp2," ");

	fclose(fp1);
	fclose(fp2);
}
void upload(char username[],char password[])
{
	FILE *fp;
    fp = fopen("log.txt", "w");
    
    fprintf(fp,"%s %s",username, password);
    fprintf(fp,"%s","\n");
    fclose(fp);
    log_upload();
}
/*bool authenticate(char user[],char pass[])
{
	FILE *fp1,*fp2;
	char c1[10000],c2[10000];
    fp1 = fopen("user_reg.txt", "r");
    fp2 = fopen("user_log.txt","r");
    fscanf(fp1,"%[^\n]",c1);
    fscanf(fp1,"%[^\n]",c2);
   
    fclose(fp);
}*/
int main()
{
	
		printf("Content-Type: text/html;charset=us-ascii\n\n");
	printf(" ");

		char *username, *password, user[100],pass[100];
		username = getenv("QUERY_STRING");
		sscanf(username,"%s",&user);
		//printf("\n");
		//printf("%s",username);
		password = getenv("QUERY_STRING");
		sscanf(password,"%s",&pass);
		upload(user,pass);
		//printf("%s",pass);
		/* val = authenticate(user,pass);
		if(strcmpi(val,"True")==0)
		{
			//to redirect to portal
			break;
		}*/
	return 0;
}

