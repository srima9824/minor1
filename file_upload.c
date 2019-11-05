#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct word_sort{
    int freq;
    char word[100];
}s[100];
char *encrpyt(void);
static int binary = 0;

void mwca_rsa_encrypt(char file[])
{
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    FILE *fp4;
    FILE *fp5;
    FILE *fp6;
    fp1 = fopen(file,"r");
    fp2 = fopen("dict1.txt","w+");
    fp3 = fopen("dict2.txt","w+");
    char c;
    int count1 = 0,i,j,m=0,n=0; //traversing the dictionaries
    if(fp1 == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    else
    {
        while(c = fgetc(fp1)!= EOF)
        {
           if(c!="\n")
           {
               count1++;   //for counting the length of file file.txt
           }
        }
    }
    //printf("Length of file = %d\n",count1);
    char file_size[count1];
    rewind(fp1);
    fgets(file_size,count1+1,fp1);
    char **str = (char*)malloc(1000*sizeof(char));  //for storing all words
    //char **str1 = (char*)malloc(1000*sizeof(char)); //for storing unique words
    int size_of_str=0,x,y,size_of_str1 = 0;
    char *token = strtok(file_size," ");
    char *tokencopy;
    while (token != NULL)
    {
        int flag=0;
        upper_string(token);

        for(x = 0;x < size_of_str1; x++)
        {
            if(strcmp(s[x].word,token)==0)
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)
        {
            strcpy(s[size_of_str1].word,token);
            size_of_str1++;
        }
        tokencopy = (char*)malloc(100*sizeof(char));
        strcpy(tokencopy,token);
        str[size_of_str]=tokencopy;
        size_of_str++;
        token = strtok(NULL, " ");
    }

     int z,v,loop_for_all_words,loop_for_unique_words;
        int freq[200],a=0;
        for(loop_for_unique_words=0;loop_for_unique_words<size_of_str1;loop_for_unique_words++) //calculating frequencies
        {
            int count = 0;
            for(loop_for_all_words=0;loop_for_all_words<size_of_str;loop_for_all_words++)
            {
                if(strcmp(str[loop_for_all_words],s[loop_for_unique_words].word)==0)
                {
                    count++;
                }
            }
            s[a].freq=count;
            a++;
        }
    bsort(s,size_of_str1);
    int bin,binary = 0,word_count = 0;
    for(bin=0;bin<size_of_str1;bin++)
    {
        int c,k,store_in_w=0;
        char *temp;
        temp = (char*)malloc(10*sizeof(char));
        char *w = (char*)malloc(10*sizeof(char));
        for (c = 7; c >= 0; c--)
        {
            k = binary >> c;

            if (k & 1)
             w[store_in_w] = '1';
            else
             w[store_in_w] = '0';
            store_in_w++;
        }
        word_count++;
        strcpy(temp,w);
        /*char *copy = start(s[bin].word);
        printf("%s\n",copy);
        strcpy(s[bin].word,copy);*/
        if(word_count<=255)
        {
            fprintf(fp2,"%s   %s\n",s[bin].word,temp);
        }
        else
        {
            fprintf(fp3,"%s   %s\n",s[bin].word,temp);
        }
        binary++;
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fp2 = fopen("dict1.txt","r");
    fp3 = fopen("dict2.txt","r");
    char **w1 = (char*)malloc(200*sizeof(char));
    char **w2 = (char*)malloc(200*sizeof(char));
    char *w3 = (char*)malloc(200*sizeof(char));
    char *w4 = (char*)malloc(200*sizeof(char));
    char *newstring1;
    char *newstring2;
    int even1 = 0,even2 = 0;
    while (fscanf(fp2,"%s",w3)==1) //for retrieving the first column of D1
    {
       if(even1%2==0)
       {
          newstring1 = (char *)malloc(sizeof(char)*20);
          strcpy(newstring1, w3);
          w1[m] = newstring1;
          m++;

       }
       even1++;
    }
    w1[m] = -999;
    while (fscanf(fp3,"%s",w4)==1) //for retrieving the first column of D2
    {
       if(even2%2==0)
       {
          newstring2 = (char *)malloc(sizeof(char)*20);
          strcpy(newstring2, w4);
          w2[n] = newstring2;
          n++;
       }
       even2++;
    }
    w2[n] = -999;
    rewind(fp2);
    rewind(fp3);
    char **w5 = (char*)malloc(200*sizeof(char));
    char **w6 = (char*)malloc(200*sizeof(char));
    char *w7 = (char*)malloc(200*sizeof(char));
    char *w8 = (char*)malloc(200*sizeof(char));
    char *newstring3;
    char *newstring4;
    int odd1 = 0,odd2 = 0;
    int o=0,p=0,q;
    while (fscanf(fp2,"%s",w7)==1) //for retrieving the first column of D1
    {
       if(odd1%2!=0)
       {
          newstring3 = (char *)malloc(sizeof(char)*20);
          strcpy(newstring3, w7);
          w5[o] = newstring3;
          o++;

       }
       odd1++;
    }
    w5[o] = -999;
    while (fscanf(fp3,"%s",w8)==1) //for retrieving the first column of D2
    {
       if(odd2%2!=0)
       {
          newstring4 = (char *)malloc(sizeof(char)*20);
          strcpy(newstring4, w8);
          w6[p] = newstring4;
          p++;
       }
       odd2++;
    }
    w6[p] = -999;

    rewind(fp2);
    rewind(fp3);

       fp5 = fopen("S1.txt","w+");;
       fp4 = fopen("BV.txt","w+");
       fp6 = fopen("S2.txt","w+");
    v=0,x;
    int flag1;
    for(z=0;z<size_of_str;z++)
    {
         flag1=0;
         v = 0;
           //  printf("\n XXw6 z : %s",w6[z]);
         //printf("\n Current z : %s",str[z]);
        do
        {
           // printf("\nIn do-while");
            //printf("\n Current v : %s",w1[v]);
            if(strcmp(str[z],w1[v])==0)
            {
                fprintf(fp4,"%c",'0');
                fprintf(fp5,"%s ",w5[v]);
                flag1=1;
                break;
            }
            v++;
            //printf("out dow hile");
        }while(w1[v]!=-999);
        if(flag1==0)
        {
            fprintf(fp4,"%c",'1');
            for(x=0;w2[x]!=-999;x++)
            {
                if(strcmp(str[z],w2[x])==0)
                {
                    fprintf(fp6,"%s ",w6[x]);
                }
            }

        }
    }
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
    fclose(fp6);
    FILE *fp7 = fopen("dict1.txt","r");
    char *p1 = (char*)malloc(100*sizeof(char));
    char **p2 = (char*)malloc(100*sizeof(char));
    int mooh = 0;
    int even3=0;
    while (fscanf(fp7,"%s",p1)==1) //for retrieving the first column of D1
    {
       if(even3%2==0)
       {
          char *newstring5 = start(p1);
          mooh++;

       }
       even3++;
    }
    fclose(fp7);
    return 0;
}
void upper_string(char s[]) {
   int c = 0;

   while (s[c] != '\0') {
      if (s[c] >= 'a' && s[c] <= 'z') {
         s[c] = s[c] - 32;
      }
      c++;
   }
}
void bsort(struct word_sort list[80],int s)
{
    int i, j;
    struct word_sort temp;

    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (list[j].freq < list[j + 1].freq)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
int p=3, q=7, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i,j;
int even1 = 0;
char *encrypt(int);
void start(char msg[])
{
  int a = 0;
  for (i = 0; msg[i] != '\0'; i++)
  {
      m[i] = msg[i];
      a++;
  }
  n = p * q;

  t = (p - 1) * (q - 1);
  ce();
//   printf("\nPOSSIBLE VALUES OF e AND d ARE\n");
  encrypt(a);
}
int prime(long int pr)
{
  int i;
  // j = sqrt(pr);
  for (i = 2; i * i <= pr; i++)
  {
    if (pr % i == 0)
      return 0;
  }
  return 1;
}
void ce()			//to calculate e
{
  int k;
  k = 0;
  for (i = 2; i < t; i++)
  {
    if (t % i == 0)
      continue;
    flag = prime(i);
    if (flag == 1 && i != p && i != q)
    {
      e[k] = i;
      flag = cd(e[k]);
      if (flag > 0)
      {
        d[k] = flag;
        k++;
      }
      if (k == 99)
        break;
    }
  }
}
int cd(int x)		//to calculate private key d
{
  int k = 1;
  while (1)
  {
    k = k + t;
    if (k % x == 0)
      return (k / x);
  }
}
char *encrypt(int a)
{
  FILE *fp1 = fopen("dict1.txt","r");
  FILE *fp2 = fopen("dict3.txt","a");
  char *w1 = (char*)malloc(100*sizeof(char));
  char **w2 = (char*)malloc(100*sizeof(char));
  char * newstring1;
  int pt, ct, key = e[0], k, len=0;
  i = 0;
  for(j = 0;j<a;j++)
  {
      len++;
  }
  while (i != len)
  {
    pt = m[i];
    pt = pt - 96;
    k = 1;
    for (j = 0; j < key; j++)

    {
      k = k * pt;
      k = k % n;
    }
    temp[i] = k;
    ct = k + 96;
    en[i] = ct;
    i++;
  }
en[i]=-1;
for (i = 0; en[i] != -1; i++)
    fprintf(fp2,"%c", en[i]);
 fprintf(fp2,"%s","   ");
int bin,word_count = 0;
int c,ko,store_in_w=0;
char *temp;
temp = (char*)malloc(10*sizeof(char));
char *w = (char*)malloc(10*sizeof(char));
for (c = 7; c >= 0; c--)
{
    ko = binary >> c;

    if (ko & 1)
     w[store_in_w] = '1';
    else
     w[store_in_w] = '0';
    store_in_w++;
}
strcpy(temp,w);
fprintf(fp2,"%s\n",temp);
binary++;
  /*while(fscanf(fp1,"%s",w1)==1)
  {
      if(even1%2!=0)
      {
          printf("Value of even = %d\n",even1);
          fprintf(fp2,"%s\n",w1);
          break;
      }
      even1++;
  }*/
  rewind(fp1);
  fclose(fp1);
  fclose(fp2);
  return en;
}

void file_upload()
{
	printf("%s%c%c\n",
  "Content-Type:text/html;charset=iso-8859-1",13,10);
	FILE *fp1;
	FILE *fp2;
	FILE *fp3;
	fp1 = fopen("file_cred.txt","r");
	fp2 = fopen("file_cred_final.txt","w+");
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
	while(c[i]!=' ')
	{
	//printf("%c",c[i++]);
    fprintf(fp2,"%c",c[i++]);
	}
	fprintf(fp2," ");
	fclose(fp1);
	fclose(fp2);
	//create_file();
	fp2 = fopen("file_cred_final.txt","r");
	char filename[100];
	int l = 0,j=0;
	fscanf(fp2,"%[^\n]",ch);
	while(ch[l]!=' ')
		{
			filename[j++] =ch[l++] ;
		}
		++l;
		char file_[100];
		strcpy(file_,strcat(filename,".txt"));
	fp3 = fopen(file_,"w");
	//fprintf(fp3,"%s ", "hello"); 
	rewind(fp2);
     int count=0;
     char cha ;
     while(cha = fgetc(fp2)!= EOF)
     {
     	if(cha!='\n')
		 {
		    count++;	
		 }
	 }
     char text[count];
     rewind(fp2);
     fgets(text,count+1,fp2);
     printf("Text,,,,,,,,,,,,%s",text);
     char* token = strtok(text, " +"); 
     int co = 0;
     while (token != NULL) { 
        if(co!=0)
		{
			fprintf(fp3,"%s ", token); 
	    }
	    token = strtok(NULL, " +"); 
	    co++;
    } 
  

	fclose(fp3);
	fclose(fp2);
	fclose(fp1);
	
	mwca_rsa_encrypt(file_);
		
		
		
}



void upload(char filename[],char content[])
{
	FILE *fp;
    fp = fopen("file_cred.txt", "w");
    
    fprintf(fp,"%s",filename);
    fprintf(fp," ");
    fclose(fp);
    file_upload();
}


int main()
{
	printf("%s%c%c\n",
  "Content-Type:text/html;charset=iso-8859-1",13,10);
		char *filename, *content, file[100],cont[100000];
		filename = getenv("QUERY_STRING");
		sscanf(filename,"%s",&file);
		printf("%s",file);
		content = getenv("QUERY_STRING");
		sscanf(content,"%s ",&cont);
		printf("%s",cont);
		upload(file,cont);
		return 0;
}
