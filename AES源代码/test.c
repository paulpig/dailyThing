#include "AESopt.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	FILE *plaintextFile;
	FILE *ciphertextFile;
	FILE *newclearFile;
	FILE *keyFile;
	int t1, t2;

	plaintextFile = fopen("plaintext.txt", "rb+");
	ciphertextFile = fopen("ciphertext.txt", "wb+");
	newclearFile = fopen("newplaintext.txt", "wb+");
	keyFile = fopen("key.txt", "rb");

	t1 = clock();
	aes_encrypt(plaintextFile, ciphertextFile, keyFile, ECB, 128);
	fseek(keyFile, 0, SEEK_SET);
	fseek(ciphertextFile, 0, SEEK_SET);
	t2 = clock();
	
	printf("加密时间：%d\n", t2 - t1);
	//system("pause");
	
	t1 = clock();
	aes_decrypt(newclearFile, ciphertextFile, keyFile, ECB, 128);
	t2 = clock();
	
	printf("解密时间：%d\n", t2 - t1);
	
	//system("pause");
	fclose(plaintextFile);
	fclose(ciphertextFile);
	fclose(keyFile);
	return 0;
}
