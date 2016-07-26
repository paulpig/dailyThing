#include "common.h"
#include "aes.h"
#include "AESkeys.h"
#include <stdio.h>
#include <stdlib.h>


/*
#include <sys/stat.h>

unsigned long get_file_size(const char *path)
{
	unsigned long filesize = -1;	
	struct stat statbuff;
	if(stat(path, &statbuff) < 0){
		return filesize;
	}else{
		filesize = statbuff.st_size;
	}
	return filesize;
}
*/

inline int filelength(FILE* file)
{
	int size;
	fseek(file,0L,SEEK_END);
	size=ftell(file);
	fseek(file,0L,SEEK_SET);
    
	return size;
}

inline int AESEncryptECB(FILE *plaintextFile, FILE *ciphertextFile, const aes_ctx cx[1])
{
	int i;
	//读取到的数据大小
	int numofread;

	//补齐后的字节数
	int amount;
	//已加密节数 
	int amountBytes = 0;

	unsigned char *plaintext;
	unsigned char *ciphertext;

	unsigned char *pplain;
	unsigned char *pcipher;

//	int length_of_file = filelength(fileno(plaintextFile));
	int length_of_file = filelength(ciphertextFile);
	int sizeofbuf = length_of_file - length_of_file%BLOCK + BLOCK;
	while ((plaintext = (unsigned char *)malloc(sizeofbuf)) == NULL)
	{
		sizeofbuf = sizeofbuf >> 1;
		sizeofbuf = sizeofbuf - sizeofbuf%BLOCK + BLOCK;
		if (sizeofbuf == BLOCK)
			return -1;
	}

	while ((ciphertext = (unsigned char *)malloc(sizeofbuf)) == NULL)
	{
		sizeofbuf = sizeofbuf >> 1;
		sizeofbuf = sizeofbuf - sizeofbuf%BLOCK + BLOCK;
		if (sizeofbuf == BLOCK)
			return -1;
	}

	pplain = plaintext;
	pcipher = ciphertext;

	do {
		amount = numofread = fread(plaintext, sizeof(char), sizeofbuf, plaintextFile);
		for (i = 0; i < numofread; i += BLOCK)
		{
			aes128_encrypt(pplain, pcipher, cx);
			pplain += BLOCK;
			pcipher += BLOCK;
			amountBytes += BLOCK;
		}

		if (length_of_file - amountBytes < BLOCK)
		{
			amount = numofread + BLOCK - numofread%BLOCK;
			plaintext[numofread] = 0x01 << 7;
			for (i = numofread + 1; i < amount; ++i)
			{
				plaintext[i] = 0x0;
			}
			aes128_encrypt(&plaintext[amount - BLOCK], &ciphertext[amount - BLOCK], cx);
			//break;
		}
		else if (numofread < 0)
		{
			return -1;
		}
		fwrite(ciphertext, sizeof(char), amount, ciphertextFile);
	} while (!feof(plaintextFile));



	free(plaintext);
	free(ciphertext);
	return 0;
}

int aes_encrypt(FILE *plaintextFile, FILE *ciphertextFile, FILE *keyFile, MODE mode, unsigned short length_of_key)
{
	//密钥
	unsigned char key[16] = { 0 };
	aes_ctx cx;


	switch (length_of_key)
	{
	case 128:

		//密钥初始化
		if (fread(key, 1, 16, keyFile) != 16)
			return -1;
		aes_encrypt_key128(key, &cx);

		switch (mode)
		{
		case ECB:
			AESEncryptECB(plaintextFile, ciphertextFile, &cx);
			break;
		case CBC:
			break;
		case OFB:
			break;
		case CTR:
			break;
		case GCM:
			break;
		default:
			break;
		}
	case 192:break;
	case 256:break;
	default:
		return -1;
		break;
	}

	return 0;
}















inline int AESDecryptECB(FILE *plaintextFile, FILE *ciphertextFile, const aes_ctx cx[1])
{
	int i;
	//读取到的数据大小
	int numofread;


	//已解密字节数 
	int amountBytes = 0;

	unsigned char *plaintext;
	unsigned char *ciphertext;

	unsigned char *pplain;
	unsigned char *pcipher;

	//int length_of_file = filelength(fileno(ciphertextFile));
	int length_of_file = filelength(ciphertextFile);
	int sizeofbuf = length_of_file - length_of_file%BLOCK + BLOCK;
	while ((ciphertext = (unsigned char *)malloc(sizeofbuf)) == NULL)
	{
		sizeofbuf = sizeofbuf >> 1;
		sizeofbuf = sizeofbuf - sizeofbuf%BLOCK + BLOCK;
		if (sizeofbuf == BLOCK)
			return -1;
	}

	while ((plaintext = (unsigned char *)malloc(sizeofbuf)) == NULL)
	{
		sizeofbuf = sizeofbuf >> 1;
		sizeofbuf = sizeofbuf - sizeofbuf%BLOCK + BLOCK;
		if (sizeofbuf == BLOCK)
			return -1;
	}

	pplain = plaintext;
	pcipher = ciphertext;

	do {
		numofread = fread(ciphertext, sizeof(char), sizeofbuf, ciphertextFile);
		for (i = 0; i < numofread; i += BLOCK)
		{
			aes128_decrypt(pcipher, pplain, cx);
			pplain += BLOCK;
			pcipher += BLOCK;
		}

		amountBytes += numofread;

		if (amountBytes == length_of_file && numofread > 0)
		{
			while (plaintext[--numofread] == 0x0)
			{
			}
		}

		fwrite(plaintext, sizeof(char), numofread, plaintextFile);
	} while (!feof(ciphertextFile));



	free(plaintext);
	free(ciphertext);
	return 0;
}

int aes_decrypt(FILE *plaintextFile, FILE *ciphertextFile, FILE *keyFile, MODE mode, unsigned short length_of_key)
{
	//密钥
	unsigned char key[16] = { 0 };
	aes_ctx cx;


	switch (length_of_key)
	{
	case 128:

		//密钥初始化
		if (fread(key, 1, 16, keyFile) != 16)
			return -1;
		aes_encrypt_key128(key, &cx);

		switch (mode)
		{
		case ECB:
			AESDecryptECB(plaintextFile, ciphertextFile, &cx);
			break;
		case CBC:
			break;
		case OFB:
			break;
		case CTR:
			break;
		case GCM:
			break;
		default:
			break;
		}
	case 192:break;
	case 256:break;
	default:
		return -1;
		break;
	}

	return 0;
}


