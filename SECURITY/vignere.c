//This program works for plaintext and keyword entered in Capital Letter only
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char plaintext[20],keyword[20],ciphertext[20];
void encrypt();
void main()
{
int i,j=0,n,k;
printf("\nEnter the plaintext : ");
scanf("%s",plaintext);
n=strlen(plaintext);
printf("\nEnter the keyword : ");
scanf("%s",keyword);
k=strlen(keyword);
        if(n>k)
        {
 
for(i=k;i<n;i++)
{
keyword[i]=keyword[j];  //fill the keyword till the size of plaintext
j++;
}
}
       
encrypt(n);
printf("Ciphertext:  %s\n",ciphertext);
}
void encrypt(int count)
{
int i,sum;
for(i=0;i<count;i++)
{
sum= plaintext[i]+keyword[i];
if(sum<130||sum>180)
{
printf("\nEnter input in CAPS only \n");
exit(0);
}
else ciphertext[i]= (sum % 26) + 65;
}
}
/*
Output:
[root@localhost security lab]# gcc bensvignere.c
[root@localhost security lab]# ./a.out
Enter the plaintext : WEAREDISCOVEREDSAVEYOURSELF
Enter the keyword : DECEPTIVE
Ciphertext:  ZICVTWQNGRZGVTWAVZHCCMEZIPY
[root@localhost security lab]#
*/