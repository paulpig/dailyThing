#ifndef AES
#define AES
#else
#include "common.h"
//º”√‹
bool aes128_encrypt(const unsigned char *in, unsigned char *out, const aes_ctx cx[1]);

//Ω‚√‹
bool aes128_decrypt(const unsigned char *in, unsigned char *out, const aes_ctx cx[1]);
#endif
