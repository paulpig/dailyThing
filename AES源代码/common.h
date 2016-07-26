#ifndef COMMOM
#define COMMOM
#else
#include <stdbool.h>
#include <stdint.h>


#ifndef COMMON
#define COMMON
//操作模式
enum MODE
{
	ECB = 0, CBC, OFB, CFB, CTR, GCM
};

//块大小
#define BLOCK 16

//状态矩阵大小
#define STATE_MATRIX_ROW 4
#define STATE_MATRIX_COLUMN 4

//子密钥单词数
#define KS_LENGTH_128Bits 44
#define KS_LENGTH_192Bits 52
#define KS_LENGTH_256Bits 60
#define KS_LENGTH 60


typedef struct
{
	uint32_t ks[KS_LENGTH];
} aes_ctx;

#endif
//S盒
extern unsigned char _sbox[256];
//S盒
extern unsigned char un_sbox[256];
//轮系数
extern unsigned char RC[10];

#define bytes2word(b0, b1, b2, b3)  (((uint32_t)(b3) << 24) | ((uint32_t)(b2) << 16) | ((uint32_t)(b1) << 8) | (b0))


#endif
