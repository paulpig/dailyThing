#ifndef COMMOM
#define COMMOM
#else
#include <stdbool.h>
#include <stdint.h>


#ifndef COMMON
#define COMMON
//����ģʽ
enum MODE
{
	ECB = 0, CBC, OFB, CFB, CTR, GCM
};

//���С
#define BLOCK 16

//״̬�����С
#define STATE_MATRIX_ROW 4
#define STATE_MATRIX_COLUMN 4

//����Կ������
#define KS_LENGTH_128Bits 44
#define KS_LENGTH_192Bits 52
#define KS_LENGTH_256Bits 60
#define KS_LENGTH 60


typedef struct
{
	uint32_t ks[KS_LENGTH];
} aes_ctx;

#endif
//S��
extern unsigned char _sbox[256];
//S��
extern unsigned char un_sbox[256];
//��ϵ��
extern unsigned char RC[10];

#define bytes2word(b0, b1, b2, b3)  (((uint32_t)(b3) << 24) | ((uint32_t)(b2) << 16) | ((uint32_t)(b1) << 8) | (b0))


#endif
