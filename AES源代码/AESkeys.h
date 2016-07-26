#ifndef AESKEYS
#define AESKEYS
#else 
#include <stdbool.h>
#include <stdint.h>


//128λ��ԿԤ����
void aes_encrypt_key128(const unsigned char *key, aes_ctx cx[1]);
//192λ������ԿԤ����
bool aes_encrypt_key192(const unsigned char *key, aes_ctx cx[1]);
//256λ������ԿԤ����
bool aes_encrypt_key256(const unsigned char *key, aes_ctx cx[1]);



//128λ������ԿԤ����
bool aes_decrypt_key128(const unsigned char *key, aes_ctx cx[1]);
//192λ������ԿԤ����
bool aes_decrypt_key192(const unsigned char *key, aes_ctx cx[1]);
//256λ������ԿԤ����
bool aes_decrypt_key256(const unsigned char *key, aes_ctx cx[1]);

#endif

