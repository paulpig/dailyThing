#ifndef AESKEYS
#define AESKEYS
#else 
#include <stdbool.h>
#include <stdint.h>


//128Œª√‹‘ø‘§º∆À„
void aes_encrypt_key128(const unsigned char *key, aes_ctx cx[1]);
//192Œªº”√‹√‹‘ø‘§º∆À„
bool aes_encrypt_key192(const unsigned char *key, aes_ctx cx[1]);
//256Œªº”√‹√‹‘ø‘§º∆À„
bool aes_encrypt_key256(const unsigned char *key, aes_ctx cx[1]);



//128ŒªΩ‚√‹√‹‘ø‘§º∆À„
bool aes_decrypt_key128(const unsigned char *key, aes_ctx cx[1]);
//192ŒªΩ‚√‹√‹‘ø‘§º∆À„
bool aes_decrypt_key192(const unsigned char *key, aes_ctx cx[1]);
//256ŒªΩ‚√‹√‹‘ø‘§º∆À„
bool aes_decrypt_key256(const unsigned char *key, aes_ctx cx[1]);

#endif

