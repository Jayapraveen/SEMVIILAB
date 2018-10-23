#include<stdio.h>
#include<string.h>
int check(int );
void calc(int );
//a[][] denotes encryption key K
//b[][] denotes K inverse
unsigned int a[3][3]={{17,17,5},{21,18,21},{2,2,19}};
unsigned int b[3][3]={{4,9,15},{15,17,6},{24,0,17}};
unsigned int c[20],d[20];
int n;
int main()
{
int i=0,t=0,j,q;
char msg[20];
printf("\nEnter plain text\n");
scanf("%s",msg);
n=strlen(msg);
q=check(n);
if(q==1) return 0;
else
{
for(i=0;i<n;i++)
{
	c[i]=msg[i]-65;
printf("%d ",c[i]);
}
while(t<n)
{
   calc(t);
   t=t+3;
}
printf("\nEncrypted Cipher Text :");
for(i=0;i<n;i++)
printf(" %c",d[i]+65);
for(i=0;i<3;i++)
{
t=0;
for(j=0;j<3;j++)
{
t=t+(d[j]*b[j][i]);
}
c[i]=t%26;
}
printf("\nDecrypted Cipher Text :");
for(i=0;i<n;i++)
printf(" %c",c[i]+65);
printf("\n");
}
return 0;
}
void calc(int k)
{
    int i,j,t;
    for(i=0;i<3;i++)
    {
      
t=0;
 
for(j=0;j<3;j++)
{
t=t+(c[j+k]*a[j][i]);
}
d[i+k]=t%26;
    }
}
int check(int p)
{
  if(n%3!=0)
  {
     printf("\nEnter Plaintext in multiples of three \n");
     return 1;
  }
  else return 0;
}
/*
Output:
[root@localhost security lab]# gcc hillfinal.c
[root@localhost security lab]# ./a.out
Enter plain text
PAYMOREMONEY
15 0 24 12 14 17 4 12 14 13 4 24
Encrypted Cipher Text : R R L M W B K A S P D H
Decrypted Cipher Text : P A Y M O R E M O N E Y
[root@localhost security lab]# 
[root@localhost security lab]# 
*/