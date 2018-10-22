#include<stdio.h>
void main()
{
int I, kl, pl;
char p[pl], k[kl];
printf("Enter the length of the key stream. ");
scanf("%d",&kl);
printf("Enter the length of the plain text stream.(Without spaces) ");
scanf("%d",&pl);
printf("\nEnter the Key. ");
for(i=-1;i<kl;++i)
scanf("%c",&k[i]);
printf("\nEnter the Plain text. ");
for(i=-1;i<pl;++i)
scanf("%c",&p[i]);
int s[3][pl];
for(i=0;i<pl;++i)
{
if(65<=p[i] && p[i]<=91)
s[0][i]=p[i]%65;
else
s[0][i]=p[i]%97;
}
for(i=0;i<pl;++i)
printf("%d ",s[0][i]);
int count=0;
while(count<pl)
{
for(i=0;i<kl;++i)
{
if(65<=k[i] && k[i]<=91)
s[1][count+i]=k[i]%65;
else
s[1][count+i]=k[i]%97;
}
count=count+kl;
}
printf("\n");
for(i=0;i<pl;++i)
printf("%d ",s[1][i]);
printf("\n");
for(i=0;i<pl;++i)
printf("%d ",s[2][i]);
printf("\n\nThe cipher text is: ");
char cipher[kl];
for(i=0;i<pl;++i)
{
s[2][i]=(s[0][i]+s[1][i])%26;
cipher[i]=(char)(s[2][i]+65);
printf("%c ",cipher[i]);
}
}
/*
Output:
[root@localhost security lab]# gcc vigenere2.c
[root@localhost security lab]# ./a.out
Enter the length of the key stream. 9
Enter the length of the plain text stream.(Without spaces) 27 
Enter the Key. deceptive
Enter the Plain text. wearediscoveredsaveyourself
22 4 0 17 4 3 8 18 2 14 21 4 17 4 3 18 0 21 4 24 14 20 17 18 4 11 5
3 4 2 4 15 19 8 21 4 3 4 2 4 15 19 8 21 4 3 4 2 4 15 19 8 21 4 
The cipher text is: Z I C V T W Q N G R Z G V T W A V Z H C Q Y G L M G J
[root@localhost security lab]# 
*/