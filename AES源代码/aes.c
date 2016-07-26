#include "common.h"
#include "AESkeys.h"
//S盒
unsigned char _sbox[256] = {
	0x63,0x7C,0x77,0x7B,0xF2,0x6B,0x6F,0xC5,0x30,0x01,0x67,0x2B,0xFE,0xD7,0xAB,0x76,
	0xCA,0x82,0xC9,0x7D,0xFA,0x59,0x47,0xF0,0xAD,0xD4,0xA2,0xAF,0x9C,0xA4,0x72,0xC0,
	0xB7,0xFD,0x93,0x26,0x36,0x3F,0xF7,0xCC,0x34,0xA5,0xE5,0xF1,0x71,0xD8,0x31,0x15,
	0x04,0xC7,0x23,0xC3,0x18,0x96,0x05,0x9A,0x07,0x12,0x80,0xE2,0xEB,0x27,0xB2,0x75,
	0x09,0x83,0x2C,0x1A,0x1B,0x6E,0x5A,0xA0,0x52,0x3B,0xD6,0xB3,0x29,0xE3,0x2F,0x84,
	0x53,0xD1,0x00,0xED,0x20,0xFC,0xB1,0x5B,0x6A,0xCB,0xBE,0x39,0x4A,0x4C,0x58,0xCF,
	0xD0,0xEF,0xAA,0xFB,0x43,0x4D,0x33,0x85,0x45,0xF9,0x02,0x7F,0x50,0x3C,0x9F,0xA8,
	0x51,0xA3,0x40,0x8F,0x92,0x9D,0x38,0xF5,0xBC,0xB6,0xDA,0x21,0x10,0xFF,0xF3,0xD2,
	0xCD,0x0C,0x13,0xEC,0x5F,0x97,0x44,0x17,0xC4,0xA7,0x7E,0x3D,0x64,0x5D,0x19,0x73,
	0x60,0x81,0x4F,0xDC,0x22,0x2A,0x90,0x88,0x46,0xEE,0xB8,0x14,0xDE,0x5E,0x0B,0xDB,
	0xE0,0x32,0x3A,0x0A,0x49,0x06,0x24,0x5C,0xC2,0xD3,0xAC,0x62,0x91,0x95,0xE4,0x79,
	0xE7,0xC8,0x37,0x6D,0x8D,0xD5,0x4E,0xA9,0x6C,0x56,0xF4,0xEA,0x65,0x7A,0xAE,0x08,
	0xBA,0x78,0x25,0x2E,0x1C,0xA6,0xB4,0xC6,0xE8,0xDD,0x74,0x1F,0x4B,0xBD,0x8B,0x8A,
	0x70,0x3E,0xB5,0x66,0x48,0x03,0xF6,0x0E,0x61,0x35,0x57,0xB9,0x86,0xC1,0x1D,0x9E,
	0xE1,0xF8,0x98,0x11,0x69,0xD9,0x8E,0x94,0x9B,0x1E,0x87,0xE9,0xCE,0x55,0x28,0xDF,
	0x8C,0xA1,0x89,0x0D,0xBF,0xE6,0x42,0x68,0x41,0x99,0x2D,0x0F,0xB0,0x54,0xBB,0x16
};

unsigned char un_sbox[256] = {
0x52,0x09,0x6A,0xD5,0x30,0x36,0xA5,0x38,0xBF,0x40,0xA3,0x9E,0x81,0xF3,0xD7,0xFB,
0x7C,0xE3,0x39,0x82,0x9B,0x2F,0xFF,0x87,0x34,0x8E,0x43,0x44,0xC4,0xDE,0xE9,0xCB,
0x54,0x7B,0x94,0x32,0xA6,0xC2,0x23,0x3D,0xEE,0x4C,0x95,0x0B,0x42,0xFA,0xC3,0x4E,
0x08,0x2E,0xA1,0x66,0x28,0xD9,0x24,0xB2,0x76,0x5B,0xA2,0x49,0x6D,0x8B,0xD1,0x25,
0x72,0xF8,0xF6,0x64,0x86,0x68,0x98,0x16,0xD4,0xA4,0x5C,0xCC,0x5D,0x65,0xB6,0x92,
0x6C,0x70,0x48,0x50,0xFD,0xED,0xB9,0xDA,0x5E,0x15,0x46,0x57,0xA7,0x8D,0x9D,0x84,
0x90,0xD8,0xAB,0x00,0x8C,0xBC,0xD3,0x0A,0xF7,0xE4,0x58,0x05,0xB8,0xB3,0x45,0x06,
0xD0,0x2C,0x1E,0x8F,0xCA,0x3F,0x0F,0x02,0xC1,0xAF,0xBD,0x03,0x01,0x13,0x8A,0x6B,
0x3A,0x91,0x11,0x41,0x4F,0x67,0xDC,0xEA,0x97,0xF2,0xCF,0xCE,0xF0,0xB4,0xE6,0x73,
0x96,0xAC,0x74,0x22,0xE7,0xAD,0x35,0x85,0xE2,0xF9,0x37,0xE8,0x1C,0x75,0xDF,0x6E,
0x47,0xF1,0x1A,0x71,0x1D,0x29,0xC5,0x89,0x6F,0xB7,0x62,0x0E,0xAA,0x18,0xBE,0x1B,
0xFC,0x56,0x3E,0x4B,0xC6,0xD2,0x79,0x20,0x9A,0xDB,0xC0,0xFE,0x78,0xCD,0x5A,0xF4,
0x1F,0xDD,0xA8,0x33,0x88,0x07,0xC7,0x31,0xB1,0x12,0x10,0x59,0x27,0x80,0xEC,0x5F,
0x60,0x51,0x7F,0xA9,0x19,0xB5,0x4A,0x0D,0x2D,0xE5,0x7A,0x9F,0x93,0xC9,0x9C,0xEF,
0xA0,0xE0,0x3B,0x4D,0xAE,0x2A,0xF5,0xB0,0xC8,0xEB,0xBB,0x3C,0x83,0x53,0x99,0x61,
0x17,0x2B,0x04,0x7E,0xBA,0x77,0xD6,0x26,0xE1,0x69,0x14,0x63,0x55,0x21,0x0C,0x7D };

//字节代换层
inline void SubBytes(unsigned char *state)
{
	*state = _sbox[*state];
}

inline void UnSubBytes(unsigned char *state)
{
	*state = un_sbox[*state];
}
//ShiftRow层
inline void ShiftRow(unsigned char *state,unsigned char *buf)
{
	buf[0] = state[0];
	buf[1] = state[5];
	buf[2] = state[10];
	buf[3] = state[15];
	buf[4] = state[4];
	buf[5] = state[9];
	buf[6] = state[14];
	buf[7] = state[3];
	buf[8] = state[8];
	buf[9] = state[13];
	buf[10] = state[2];
	buf[11] = state[7];
	buf[12] = state[12];
	buf[13] = state[1];
	buf[14] = state[6];
	buf[15] = state[11];
}

//注：此处none_use无用，为适应接口做的调整 
/*void UnShiftRow(unsigned char*team,unsigned char * none_use)//逆向shiftRow
{
	unsigned char u;
	u = team[1];
	team[1] = team[13];
	team[13] = team[9];
	team[9] = team[5];
	team[5] = u;
	u = team[2];
	team[2] = team[10];
	team[10] = u;
	u = team[6];
	team[6] = team[14];
	team[14] = u;
	u = team[3];
	team[3] = team[7];
	team[7] = team[11];
	team[11] = team[15];
	team[15] = u;
}
*/
inline void UnShiftRow(unsigned char*state,unsigned char * buf)
{
	buf[0]= state[0];
	buf[1]= state[13];
	buf[2]=state[10];
	buf[3]=state[7];
	buf[4]= state[4];
	buf[5]= state[1];
	buf[6]=state[14];
	buf[7]=state[11];
	buf[8]= state[8];
	buf[9]= state[5];
	buf[10]=state[2];
	buf[11]=state[15];
	buf[12]= state[12];
	buf[13]= state[9];
	buf[14]=state[6];
	buf[15]=state[3];
}

//MixColumn层
unsigned char mul2(unsigned char a)
{
	unsigned char b;
	if (a<0x80)
	{
		b = a << 1;
	}
	else
	{
		b = (a << 1) ^ 0x1b;
	}
	return b;
}
unsigned char mul3(unsigned char a)
{
	unsigned char b;
	b = mul2(a) ^ a;
	return b;
}
void MixColumn(unsigned char B[4], unsigned char C[4])
{
	C[0] = mul2(B[0]) ^ mul3(B[1]) ^ B[2] ^ B[3];
	C[1] = B[0] ^ mul2(B[1]) ^ mul3(B[2]) ^ B[3];
	C[2] = B[0] ^ B[1] ^ mul2(B[2]) ^ mul3(B[3]);
	C[3] = mul3(B[0]) ^ B[1] ^ B[2] ^ mul2(B[3]);
}



char mul9 (unsigned char a)
{
	unsigned char b;
    b=mul2(mul2(mul2(a)))^a;
	return b;
}
char mulb (unsigned char a)
{
	unsigned char b;
    b=mul2(mul2(mul2(a)))^mul2(a)^a;
	return b;
}
char muld (unsigned char a)
{
	unsigned char b;
    b=mul2(mul2(mul2(a)))^mul2(mul2(a))^a;
	return b;
}
char mule (unsigned char a)
{
	unsigned char b;
    b=mul2(mul2(mul2(a)))^mul2(mul2(a))^mul2(a);
	return b;
}

void UnMixColumn(unsigned char B[4],unsigned char C[4])
{

	 C[0]=mule(B[0])^mulb(B[1])^muld(B[2])^mul9(B[3]);
	 C[1]=mul9(B[0])^mule(B[1])^mulb(B[2])^muld(B[3]);
	 C[2]=muld(B[0])^mul9(B[1])^mule(B[2])^mulb(B[3]);
	 C[3]=mulb(B[0])^muld(B[1])^mul9(B[2])^mule(B[3]);


}

//KeyAddition
inline void KeyAddition(const uint32_t *in,uint32_t *out, const aes_ctx cx[1],char i)
{
	out[0] = in[0] ^ cx->ks[0 + i * 4];
	out[1] = in[1] ^ cx->ks[1 + i * 4];
	out[2] = in[2] ^ cx->ks[2 + i * 4];
	out[3] = in[3] ^ cx->ks[3 + i * 4];
}

//加密函数
bool aes128_encrypt(const unsigned char *in, unsigned char *out, const aes_ctx cx[1])
{
	unsigned char buf[16];
	//k0
	KeyAddition((uint32_t *)in, (uint32_t *)out, cx, 0);

	//round 1
	SubBytes(out);
	ShiftRow(out, buf);
	MixColumn(buf, out);
	MixColumn(&buf[4], &out[4]);
	MixColumn(&buf[8], &out[8]);
	MixColumn(&buf[12], &out[12]);
	KeyAddition((uint32_t *)out, (uint32_t *)out, cx, 1);

	//round 2
	SubBytes(out);
	ShiftRow(out, buf);
	MixColumn(buf, out);
	MixColumn(&buf[4], &out[4]);
	MixColumn(&buf[8], &out[8]);
	MixColumn(&buf[12], &out[12]);
	KeyAddition((uint32_t *)out, (uint32_t *)out, cx, 2);


	//round 3
	SubBytes(out);
	ShiftRow(out, buf);
	MixColumn(buf, out);
	MixColumn(&buf[4], &out[4]);
	MixColumn(&buf[8], &out[8]);
	MixColumn(&buf[12], &out[12]);
	KeyAddition((uint32_t *)out, (uint32_t *)out, cx, 3);


	//round 4
	SubBytes(out);
	ShiftRow(out, buf);
	MixColumn(buf, out);
	MixColumn(&buf[4], &out[4]);
	MixColumn(&buf[8], &out[8]);
	MixColumn(&buf[12], &out[12]);
	KeyAddition((uint32_t *)out, (uint32_t *)out, cx, 4);


	//round 5
	SubBytes(out);
	ShiftRow(out, buf);
	MixColumn(buf, out);
	MixColumn(&buf[4], &out[4]);
	MixColumn(&buf[8], &out[8]);
	MixColumn(&buf[12], &out[12]);
	KeyAddition((uint32_t *)out, (uint32_t *)out, cx, 5);


	//round 6
	SubBytes(out);
	ShiftRow(out, buf);
	MixColumn(buf, out);
	MixColumn(&buf[4], &out[4]);
	MixColumn(&buf[8], &out[8]);
	MixColumn(&buf[12], &out[12]);
	KeyAddition((uint32_t *)out, (uint32_t *)out, cx, 6);


	//round 7
	SubBytes(out);
	ShiftRow(out, buf);
	MixColumn(buf, out);
	MixColumn(&buf[4], &out[4]);
	MixColumn(&buf[8], &out[8]);
	MixColumn(&buf[12], &out[12]);
	KeyAddition((uint32_t *)out, (uint32_t *)out, cx, 7);


	//round 8
	SubBytes(out);
	ShiftRow(out, buf);
	MixColumn(buf, out);
	MixColumn(&buf[4], &out[4]);
	MixColumn(&buf[8], &out[8]);
	MixColumn(&buf[12], &out[12]);
	KeyAddition((uint32_t *)out, (uint32_t *)out, cx, 8);


	//round 9
	SubBytes(out);
	ShiftRow(out, buf);
	MixColumn(buf, out);
	MixColumn(&buf[4], &out[4]);
	MixColumn(&buf[8], &out[8]);
	MixColumn(&buf[12], &out[12]);
	KeyAddition((uint32_t *)out, (uint32_t *)out, cx, 9);


	//round 10
	SubBytes(out);
	ShiftRow(out, buf);
	KeyAddition((uint32_t *)buf, (uint32_t *)out, cx, 10);

	return true;
}

//解密函数
bool aes128_decrypt(const unsigned char *in, unsigned char *out, const aes_ctx cx[1])
{
	unsigned char buf[16];
	        //第10轮 
		KeyAddition((uint32_t *)in, (uint32_t *)out, cx, 10);
		UnShiftRow(out,buf);
		UnSubBytes(buf);
		
	        //第9轮 
		KeyAddition((uint32_t *)buf, (uint32_t *)out, cx, 9);
		UnMixColumn(out, buf);
	    UnMixColumn(&out[4], &buf[4]);
	    UnMixColumn(&out[8], &buf[8]);
     	UnMixColumn(&out[12], &buf[12]);
		UnShiftRow(buf, out);
		UnSubBytes(out);
			//第8轮 
		KeyAddition((uint32_t *)out, (uint32_t *)out, cx, 8);
		UnMixColumn(out, buf);
	    UnMixColumn(&out[4], &buf[4]);
	    UnMixColumn(&out[8], &buf[8]);
     	UnMixColumn(&out[12], &buf[12]);
		UnShiftRow(buf, out);
		UnSubBytes(out);
			//第7轮 
		KeyAddition((uint32_t *)out, (uint32_t *)out, cx, 7);
		UnMixColumn(out, buf);
	    UnMixColumn(&out[4], &buf[4]);
	    UnMixColumn(&out[8], &buf[8]);
     	UnMixColumn(&out[12], &buf[12]);
		UnShiftRow(buf, out);
		UnSubBytes(out);
			//第6轮 
		KeyAddition((uint32_t *)out, (uint32_t *)out, cx, 6);
		UnMixColumn(out, buf);
	    UnMixColumn(&out[4], &buf[4]);
	    UnMixColumn(&out[8], &buf[8]);
     	UnMixColumn(&out[12], &buf[12]);
		UnShiftRow(buf, out);
		UnSubBytes(out);
			//第5轮 
		KeyAddition((uint32_t *)out, (uint32_t *)out, cx, 5);
		UnMixColumn(out, buf);
	    UnMixColumn(&out[4], &buf[4]);
	    UnMixColumn(&out[8], &buf[8]);
     	UnMixColumn(&out[12], &buf[12]);
		UnShiftRow(buf, out);
		UnSubBytes(out);
			//第4轮 
		KeyAddition((uint32_t *)out, (uint32_t *)out, cx, 4);
		UnMixColumn(out, buf);
	    UnMixColumn(&out[4], &buf[4]);
	    UnMixColumn(&out[8], &buf[8]);
     	UnMixColumn(&out[12], &buf[12]);
		UnShiftRow(buf, out);
		UnSubBytes(out);
			//第3轮 
		KeyAddition((uint32_t *)out, (uint32_t *)out, cx, 3);
		UnMixColumn(out, buf);
	    UnMixColumn(&out[4], &buf[4]);
	    UnMixColumn(&out[8], &buf[8]);
     	UnMixColumn(&out[12], &buf[12]);
		UnShiftRow(buf, out);
		UnSubBytes(out);
			//第2轮 
		KeyAddition((uint32_t *)out, (uint32_t *)out, cx, 2);
		UnMixColumn(out, buf);
	    UnMixColumn(&out[4], &buf[4]);
	    UnMixColumn(&out[8], &buf[8]);
     	UnMixColumn(&out[12], &buf[12]);
		UnShiftRow(buf, out);
		UnSubBytes(out);
			//第1轮 
		KeyAddition((uint32_t *)out, (uint32_t *)out, cx, 1);
		UnMixColumn(out, buf);
	    UnMixColumn(&out[4], &buf[4]);
	    UnMixColumn(&out[8], &buf[8]);
     	UnMixColumn(&out[12], &buf[12]);
		UnShiftRow(buf, out);
		UnSubBytes(out);
		   //第0轮
		KeyAddition((uint32_t *)out, (uint32_t *)out, cx, 0);  
		 
	return true;
}


