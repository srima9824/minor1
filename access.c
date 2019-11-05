#include<stdio.h>

long int p=3, q=7, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
char msg[100],ch;
int prime(long int);
void ce();
long int cd(long int);
void mwca_decompress(char file_dec[],char s1[],char s2[],char d1[],char d3[],char BV[],char file[])
{
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    FILE *fp4;
    FILE *fp5;
    FILE *fp6;
    fp1 = fopen(BV,"r+");
    fp2 = fopen(s1,"r");
    fp3 = fopen(s2,"r");
    fp5 = fopen(d2,"r");
    fp6 = fopen(file,"w");
    char *w2 = (char*)malloc(200*sizeof(char));
    char *w3 = (char*)malloc(200*sizeof(char));
    char *w4 = (char*)malloc(200*sizeof(char));
    char *w5 = (char*)malloc(200*sizeof(char));
    char **w6 = (char*)malloc(200*sizeof(char));
    char **w7 = (char*)malloc(200*sizeof(char));
    char **w8 = (char*)malloc(200*sizeof(char));
    char *newstring1;
    char *newstring2;
    char c;
    int count = 0;
    int count1=0,count2=0;  //for calculating the index of values obtained thru s1 and s2 taaki d1 and d2 meh word mile
    int i = 1;
    while((c=fgetc(fp1))!= EOF)
    {
    count++;
    int x = (int)c;
    i++;
      if(x==48)
      {
       printf("True");
       fscanf(fp2,"%s",w2);
        printf("W2 %s\n",w2);
        fp4 = fopen("dict1.txt","r");
        while(fscanf(fp4,"%s",w4)==1)
        {
           //printf("W4 %s\n",w4);

           newstring1 = (char *)malloc(sizeof(char)*200);
           strcpy(newstring1, w4);
           w6[count1] = newstring1;
           //printf("w6[count1] = %s\n",w6[count1]);
           count1++;
           if(strcmp(w2,w4)==0)
           {
               printf("true and value of w6[count1-2] = %s\n",w6[count1-2]);
               fprintf(fp6,"%s ",w6[count1-2]);
               printf("Executed\n");

           }
           rewind(fp1);
        }
        fclose(fp4);
    }
    //printf("End reached");
    else
    {
        fscanf(fp3,"%s",w3);
        while(fscanf(fp5,"%s",w5)==1)
        {
           newstring2 = (char *)malloc(sizeof(char)*20);
           strcpy(newstring2, w5);
           w7[count2] = newstring2;
           count2++;
           if(strcmp(w3,w5)==0)
           {
               printf("true and value of w7[count1-2] = %s\n",w7[count2-2]);
               fprintf(fp6,"%s ",w7[count2-2]);
           }
        }
        rewind(fp5);
    }

}
    printf("Count = %d\n",count);
    printf("End reached");
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp5);
    fclose(fp6);
}

void rsa_decrypt(char file_enc)
{
    
   // printf("\nENTER MESSAGE\n");
  scanf(" %[^\t\n]s",&msg);
  for (i = 0; msg[i] != '\0'; i++)
    m[i] = msg[i];
  n = p * q;

  t = (p - 1) * (q - 1);
  ce();
//   printf("\nPOSSIBLE VALUES OF e AND d ARE\n");
  for (i = 0; i < j - 1; i++)
    printf("\n%ld\t%ld", e[i], d[i]);

  decrypt();
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
long int cd(long int x)		//to calculate private key d
{
  long int k = 1;
  while (1)
  {
    k = k + t;
    if (k % x == 0)
      return (k / x);
  }
}
void decrypt()
{

  long int pt, ct, key = d[0], k;
  i = 0;

  while (en[i] != -1)
  {
    ct = temp[i];
    k = 1;
    for (j = 0; j < key; j++)
    {
      k = k * ct;
      k = k % n;
    }
    pt = k + 96;
    m[i] = pt;
    i++;
  }
  m[i] = -1;

  //printf("\nTHE DECRYPTED MESSAGE IS\n");
  for (i = 0; m[i] != -1; i++)
    fprintf(fp7,"%c", m[i]);
}

mwca_decompress(dec,s1,s2,d1,d3,BV);
}
void mwca_rsa_enc(char file_enc[],char s1[],char s2[],char d1[],char d3[],char BV[])
{
	FILE *f1 = fopen(file_enc,"r");
	FILE *f2 = fopen(s1,"r");
	FILE *f3 = fopen(s2,"r");
	FILE *f4 = fopen(d1,"r");
	FILE *f5= fopen(d3,"r");
	rsa_decrypt(file_enc);
	
	
}
int main()
{
	return 0;
}
