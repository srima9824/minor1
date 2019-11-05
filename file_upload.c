#include<stdio.h>
#include<stdlib.h>
void upload(char filename[],char content[])
{
	FILE *fp;
    fp = fopen(filename, "w");
    fprintf(fp,"%s",content);
    fclose(fp);
    //mwca
    //rsa
    //store in lvm
}

int main()
{
	printf("Content-Type: text/html;charset=us-ascii\n\n");
	printf(" ");
		char *file, *cont, file_name[100], cont_ent[10000000];
		file = getenv("QUERY_STRING");
		sscanf(file,"%s",&file_name);
		printf("%s",file_name);
		file = getenv("QUERY_STRING");
		sscanf(cont,"%s",&cont_ent);
		printf("%s",cont_ent);
		upload(file_name,cont_ent);
		return 0;
}
