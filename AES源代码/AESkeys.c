#include "aes.h"
#include "common.h"

//¬÷œµ ˝
unsigned char RC[10] = { 0x01, 0x02, 0x04, 0x08,0x10,0x20, 0x40, 0x80,0x1b, 0x36 };

inline uint32_t g(uint32_t in,  unsigned char rci)
{
	char v1 = (in >> 8) & 0xff;
	char v2 = (in >> 16) & 0xff;
	char v3 = (in >> 24) & 0xff;
	char v0 = in & 0xff;

	v1 = _sbox[(unsigned)v1]^rci;
	v2 = _sbox[(unsigned)v2];
	v3 = _sbox[(unsigned)v3];
	v0 = _sbox[(unsigned)v0];

	in = bytes2word(v1, v2, v2, v0);

	return in;
}

//128Œª√‹‘ø‘§º∆À„
void aes_encrypt_key128(const unsigned char *key, aes_ctx cx[1])
{
	//round key 0
	cx->ks[0] = bytes2word(key[0], key[1], key[2], key[3]);
	cx->ks[1] = bytes2word(key[4], key[5], key[6], key[7]);
	cx->ks[2] = bytes2word(key[8], key[9], key[10], key[11]);
	cx->ks[3] = bytes2word(key[12], key[13], key[14], key[15]);

	//round key 1
	cx->ks[4] = cx->ks[0] ^ g(cx->ks[3], RC[0]);
	cx->ks[5] = cx->ks[1] ^ cx->ks[4];
	cx->ks[6] = cx->ks[2] ^ cx->ks[5];
	cx->ks[7] = cx->ks[3] ^ cx->ks[6];

	//round key 2
	cx->ks[8] = cx->ks[4] ^ g(cx->ks[7], RC[1]);
	cx->ks[9] = cx->ks[5] ^ cx->ks[8];
	cx->ks[10] = cx->ks[6] ^ cx->ks[9];
	cx->ks[11] = cx->ks[7] ^ cx->ks[10];

	//round key 3
	cx->ks[12] = cx->ks[8] ^ g(cx->ks[11], RC[2]);
	cx->ks[13] = cx->ks[9] ^ cx->ks[12];
	cx->ks[14] = cx->ks[10] ^ cx->ks[13];
	cx->ks[15] = cx->ks[11] ^ cx->ks[14];

	//round key 4
	cx->ks[16] = cx->ks[12] ^ g(cx->ks[15], RC[3]);
	cx->ks[17] = cx->ks[13] ^ cx->ks[16];
	cx->ks[18] = cx->ks[14] ^ cx->ks[17];
	cx->ks[19] = cx->ks[15] ^ cx->ks[18];


	//round key 5
	cx->ks[20] = cx->ks[16] ^ g(cx->ks[19], RC[4]);
	cx->ks[21] = cx->ks[17] ^ cx->ks[20];
	cx->ks[22] = cx->ks[18] ^ cx->ks[21];
	cx->ks[23] = cx->ks[19] ^ cx->ks[22];

	//round key 6
	cx->ks[24] = cx->ks[20] ^ g(cx->ks[23], RC[5]);
	cx->ks[25] = cx->ks[21] ^ cx->ks[24];
	cx->ks[26] = cx->ks[22] ^ cx->ks[25];
	cx->ks[27] = cx->ks[23] ^ cx->ks[26];

	//round key 7
	cx->ks[28] = cx->ks[24] ^ g(cx->ks[27], RC[6]);
	cx->ks[29] = cx->ks[25] ^ cx->ks[28];
	cx->ks[30] = cx->ks[26] ^ cx->ks[29];
	cx->ks[31] = cx->ks[27] ^ cx->ks[30];

	//round key 8
	cx->ks[32] = cx->ks[28] ^ g(cx->ks[31], RC[7]);
	cx->ks[33] = cx->ks[29] ^ cx->ks[32];
	cx->ks[34] = cx->ks[30] ^ cx->ks[33];
	cx->ks[35] = cx->ks[31] ^ cx->ks[34];

	//round key 9
	cx->ks[36] = cx->ks[32] ^ g(cx->ks[35], RC[8]);
	cx->ks[37] = cx->ks[33] ^ cx->ks[36];
	cx->ks[38] = cx->ks[34] ^ cx->ks[37];
	cx->ks[39] = cx->ks[35] ^ cx->ks[38];

	//round key 10
	cx->ks[40] = cx->ks[36] ^ g(cx->ks[39], RC[9]);
	cx->ks[41] = cx->ks[37] ^ cx->ks[40];
	cx->ks[42] = cx->ks[38] ^ cx->ks[41];
	cx->ks[43] = cx->ks[39] ^ cx->ks[42];
}

/* 
//192Œªº”√‹√‹‘ø‘§º∆À„
bool aes_encrypt_key192(const unsigned char *key, aes_ctx cx[1])
{
	return true;
}

//256Œªº”√‹√‹‘ø‘§º∆À„
bool aes_encrypt_key256(const unsigned char *key, aes_ctx cx[1])
{
	return true;
}



//128ŒªΩ‚√‹√‹‘ø‘§º∆À„
bool aes_decrypt_key128(const unsigned char *key, aes_ctx cx[1])
{
	return true;
}

//192ŒªΩ‚√‹√‹‘ø‘§º∆À„
bool aes_decrypt_key192(const unsigned char *key, aes_ctx cx[1])
{
	return true;
}

//256ŒªΩ‚√‹√‹‘ø‘§º∆À„
bool aes_decrypt_key256(const unsigned char *key, aes_ctx cx[1])
{
	return true;
}
*/
