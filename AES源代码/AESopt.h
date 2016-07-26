#ifndef AESOPT
#define AESOPT
#else
#include <stdio.h>

//²Ù×÷Ä£Ê½
enum MODE
{
	ECB = 0, CBC, OFB, CFB, CTR, GCM
};

int aes_encrypt(FILE *plaintext, FILE *cipher, FILE *key, MODE mode, unsigned short length_of_key);
int aes_decrypt(FILE *plaintext, FILE *cipher, FILE *key, MODE mode, unsigned short length_of_key);
#endif
