#include <stdio.h>
#include <string.h>
#include <openssl/x509v3.h>
#include <openssl/objects.h>
#include <openssl/pem.h>
#include <openssl/evp.h>
int main() {
   EVP_PKEY *privkey;
   FILE *fp;
   RSA *rsakey;
   /* ---------------------------------------------------------- *
    * Next function is essential to enable openssl functions     *
    ------------------------------------------------------------ */
   OpenSSL_add_all_algorithms();
   privkey = EVP_PKEY_new();
   fp = fopen ("test-key.pem", "r");
   PEM_read_PrivateKey( fp, &privkey, NULL, NULL);
   fclose(fp);
   rsakey = EVP_PKEY_get1_RSA(privkey);
   if(RSA_check_key(rsakey)) {
     printf("RSA key is valid.\n");
   }
   else {
     printf("Error validating RSA key.\n");
   }
   RSA_print_fp(stdout, rsakey, 3);
   PEM_write_PrivateKey(stdout,privkey,NULL,NULL,0,0,NULL);
   exit(0);
}
/*
Output:
[root@localhost security lab]# openssl genrsa -out test-key.pem 512
Generating RSA private key, 512 bit long modulus
........++++++++++++
.....++++++++++++
e is 65537 (0x10001)
[root@localhost security lab]# gcc digitalsign.c -lssl -lcrypto
[root@localhost security lab]# ./a.out
RSA key is valid.
   Private-Key: (512 bit)
   modulus:
       00:d6:03:7a:02:19:5b:70:fb:9d:a9:f4:cc:6f:01:
       35:52:48:84:b0:aa:b1:3c:5c:ab:1d:34:95:3d:bd:
       fa:ca:64:ed:67:89:a2:33:83:83:2f:1f:c1:2e:9e:
       d4:13:cc:df:9e:5c:1d:34:f5:60:cf:53:cd:49:01:
       95:11:55:17:ef
   publicExponent: 65537 (0x10001)
   privateExponent:
       00:af:bc:25:18:ca:27:ab:2c:02:38:48:1b:02:df:
       d4:20:20:0a:4d:63:ac:ab:eb:50:5b:68:0d:50:a8:
       ca:e2:1b:e3:b8:aa:41:aa:7c:5a:3e:d5:1d:82:84:
       4b:d6:ea:a3:d9:0d:18:7a:d1:4d:3d:7c:65:63:18:
       2e:fd:8b:eb:d1
   prime1:
       00:f1:89:83:42:b2:38:e6:4c:f7:1f:a7:96:76:f4:
       6b:ba:33:f6:b3:ac:7f:c4:cc:28:90:78:d7:ac:76:
       1b:09:b7
   prime2:
       00:e2:d4:0f:1a:fc:63:a5:48:92:3e:be:9c:2d:71:
       17:f5:d2:aa:7a:26:58:b7:03:ab:8c:bb:da:6b:09:
       3e:43:89
   exponent1:
       3f:3c:67:57:20:dd:f0:bd:99:bd:79:dc:d4:cb:ed:
       20:54:d6:73:f7:e7:83:98:87:ce:3b:35:0b:fb:e7:
       dc:45
   exponent2:
       1e:8a:5e:de:4b:4d:3f:5b:de:15:04:a5:12:99:3f:
       98:a1:9c:c2:85:97:3c:4d:0a:34:10:b6:ff:e2:66:
       b7:c1
   coefficient:
       76:a4:63:4d:e8:af:b3:b1:ac:81:15:13:6f:10:eb:
       82:f9:c6:6a:b0:c6:b5:39:2e:9b:35:0a:8d:c7:38:
       7d:d1
-----BEGIN PRIVATE KEY----MIIBVAIBADANBgkqhkiG9w0BAQEFAASCAT4wggE6AgEAAkEA1gN6AhlbcPudqfT
M
bwE1UkiEsKqxPFyrHTSVPb36ymTtZ4miM4ODLx/BLp7UE8zfnlwdNPVgz1PNSQGV
EVUX7wIDAQABAkEAr7wlGMonqywCOEgbAt/UICAKTWOsq+tQW2gNUKjK4hvju
KpB
qnxaPtUdgoRL1uqj2Q0YetFNPXxlYxgu/Yvr0QIhAPGJg0KyOOZM9x+nlnb0a7oz
9rOsf8TMKJB416x2Gwm3AiEA4tQPGvxjpUiSPr6cLXEX9dKqeiZYtwOrjLvaawk+
Q4kCID88Z1cg3fC9mb153NTL7SBU1nP354OYh847NQv759xFAiAeil7eS00/W94V
BKUSmT+YoZzChZc8TQo0ELb/4ma3wQIgdqRjTeivs7GsgRUTbxDrgvnGarDGtTku
mzUKjcc4fdE=
-----END
PRIVATE
KEY----[root@localhost
security
lab]#
*/