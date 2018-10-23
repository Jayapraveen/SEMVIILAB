#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <openssl/des.h>

char *Encrypt( char *Key, char *Msg, int size)
{
        static char*    Res;
        int             n=0;
        DES_cblock      Key2;
        DES_key_schedule schedule;

        Res = ( char * ) malloc( size );

        /* Prepare the key for use with DES_cfb64_encrypt */
        memcpy( Key2, Key,8);
        DES_set_odd_parity( &Key2 );
        DES_set_key_checked( &Key2, &schedule );

        /* Encryption occurs here */
        DES_cfb64_encrypt( ( unsigned char * ) Msg, ( unsigned char * ) Res,size, &schedule,
&Key2, &n, DES_ENCRYPT );
        return (Res);
}
char *Decrypt( char *Key, char *Msg, int size)
{
        static char*    Res;
        int             n=0;
        DES_cblock      Key2;
        DES_key_schedule schedule;
         Res = ( char * ) malloc( size );

        /* Prepare the key for use with DES_cfb64_encrypt */
        memcpy( Key2, Key,8);
        DES_set_odd_parity( &Key2 );
        DES_set_key_checked( &Key2, &schedule );

        /* Decryption occurs here */
        DES_cfb64_encrypt( ( unsigned char * ) Msg, ( unsigned char * ) Res,size, &schedule,
&Key2, &n, DES_DECRYPT );
        return (Res);
}
int main()
{
char key[]="BENEDICT";
char plaintext[]="ENJOYCNS";
char *decrypted;
char *encrypted;
encrypted=malloc(sizeof(plaintext));
decrypted=malloc(sizeof(plaintext));
printf("\nPlaintext\t\t\t : %s",plaintext);
printf("\nPlaintext in Hex Code \t\t : %X",plaintext);
printf("\nKey in Hex Code \t\t : %X",key);
memcpy(encrypted,Encrypt(key,plaintext,sizeof(plaintext)), sizeof(plaintext));
printf("\nEncrypted Text\t\t\t : %s",encrypted);
memcpy(decrypted,Decrypt(key,encrypted,sizeof(plaintext)), sizeof(plaintext));
printf("\nDecrypted Text\t\t\t : %s",decrypted);
printf("\nDecrypted Text in Hex Code \t : %X \n",decrypted);
return (0);
}
/*
Output:
[root@localhost security lab]# gcc desopen.c -lssl -lcrypto
[root@localhost security lab]# ./a.out
Plaintext
 
: ENJOYCNS
Plaintext in Hex Code 
 
: BFD28266
Key in Hex Code 
 
: BFD2826F
Encrypted Text
 
: 
{S S
���� ��
Decrypted Text
 
: ENJOYCNS
Decrypted Text in Hex Code  
: 848D030 
[root@localhost security lab]# 
*/