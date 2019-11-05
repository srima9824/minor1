#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void upload(char size[])
{
	int i=0;
	FILE *fp1;
	FILE *fp2;
	FILE *fp3;
	char c[1000];
	fp1 = fopen("user1.txt","r");
	fp2 = fopen("user_extend.txt","w");
	fp3 = fopen("user4.txt","w");
	fscanf(fp1,"%[^\n]",c);
	fprintf(fp2,"%s ",c);

	fclose(fp1);
	fclose(fp2);
	fprintf(fp3,"%s ",size);
	fclose(fp3);
	fp3 = fopen("user4.txt","r");
	fp2 = fopen("user_extend.txt","w");
	fscanf(fp3,"%[^\n]",c);
	while(c[i]!='=')
	{
		printf("%c",c[i]);
		i++;
	
	}
	++i;
	while(c[i]!=' ')
	{
	//printf("%c",c[i++]);
    fprintf(fp2,"%c",c[i++]);
	}
	fprintf(fp2," ");
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}
int main()
{

	printf("%s%c%c\n",
  "Content-Type:text/html;charset=iso-8859-1",13,10);
		char *size,size_[100];
		size = getenv("QUERY_STRING");
		sscanf(size,"%s",&size_);
		printf("%s",size_);
		upload(size_);
		
		return 0;
}
