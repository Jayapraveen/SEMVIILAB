#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int encrypt();
int decrypt();
char plaintext[50]={0},ciphertext[50]={0};
int c,d;
int main()
{
   int option;
   do
   {
    printf("Press 1 to Encrypt Plaintext \n");
    printf("Press 2 to Decrypt Ciphertext \n");
    printf("Press 9 to Exit \n");
    printf("Your option=");
    scanf("%d",&option);
    switch(option)
    {
     case 1: encrypt();
 
     printf("Ciphertext : %s \n",ciphertext);
     break;
     case 2: decrypt();
     printf("Plaintext : %s \n",plaintext);
             break;
     case 9: break;
     default: printf("Enter valid option! \n");
    }
   }while(option!=9);
   return 0;
}
int encrypt()
{
    static int i=0,j=0;
    printf("\nPlaintext : ");getchar();
    while((c=getchar()) != '\n')
    {
        plaintext[i++]=(char)c;
        ciphertext[j++]=(char)(c+3);
    }
    return 0;
 }
int decrypt()
{
    static int p=0,q=0;
    printf("\nCiphertext : ");getchar();
    while((d=getchar()) != '\n')
    {
ciphertext[p++]=(char)d;
plaintext[q++]=(char)(d-3);
    }
    return 0;
}
/*
Output:
[root@localhost security lab]#  gcc caesar.c
[root@localhost security lab]#  ./a.out
Press 1 to Encrypt Plaintext
Press 2 to Decrypt Ciphertext
Press 9 to Exit
Your option=1
Plaintext : INDIA
Ciphertext : LQGLD
Press 1 to Encrypt Plaintext
Press 2 to Decrypt Ciphertext
Press 9 to Exit
Your option=2
Ciphertext : LQGLD
Plaintext : INDIA
[root@localhost security lab]#  

*/