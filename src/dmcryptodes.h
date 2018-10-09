
#ifndef __DMCRYPTODES_H_INCLUDE__
#define __DMCRYPTODES_H_INCLUDE__

#include "dmdes.h"


//
// @brief          DES key schedule (56-bit, encryption)
//
// @param pCtx     DES context to be initialized
// @param acKey    8-byte secret key
//
void DESSetEncKey( DMDESContext *pCtx, uint8_t acKey[8] );

//
// @brief          DES key schedule (56-bit, decryption)
//
// @param pCtx     DES context to be initialized
// @param acKey    8-byte secret key
//
void DESSetDecKey( DMDESContext *pCtx, uint8_t acKey[8] );

//
// @brief		  DES initialization vector generator
//
//
//
void DESRandomKey( DMESBlock *pKey );

//
// @brief          DES-ECB block encryption/decryption
//
// @param pCtx     DES context
// @param acInput  64-bit input block
// @param acOutput 64-bit output block
//
void DESCryptECB( DMDESContext	*pCtx,
	uint8_t acInput[8],
	uint8_t acOutput[8] );

//
// @brief          DES-CBC buffer encryption/decryption
//
// @param pCtx        DES context
// @param nMode       DES_ENCRYPT or DES_DECRYPT
// @param nLength     length of the input data
// @param pIV         initialization vector (updated after use)
// @param pacInput    buffer holding the input data
// @param pacOutput   buffer holding the output data
//
void DESCryptCBC( DMDESContext	*pCtx,
	int32_t			nMode,
	int32_t			nLength,
	DMESBlock		*pIV,
	uint8_t *pacInput,
	uint8_t *pacOutput );



//
// @brief		Generate 3-DES key
// @param pKey	3DES key
//
void GenDES3Key( DMDES3Block  *pKey );

//
// @brief		Generate 3-DES key schedule table for encryption
// @param pCtx	3-DES Context which stored key schedule table
// @param pKey  3-DES key
//
void DES3SetEncKey( DMDES3Context *pCtx, DMDES3Block *pKey );

//
// @brief		Generate 3-DES key schedule table for decryption
// @param pCtx 	3-DES Context which stored key schedule table
// @param pKey  3-DES key
//
void DES3SetDecKey( DMDES3Context *pCtx, DMDES3Block *pKey );

//
// @brief		   Crypto in 3-DES ECB mode
// @param pCtx	   3-DES context
// @param acInput  input plain text buffer
// @param acOutput output cipher text buffer
//
void DES3CryptECB( DMDES3Context *pCtx,
	uint8_t acInput[8],
	uint8_t acOutput[8] );

//
// @brief			Crypto in 3-DES CBC mode
// @param pCtx		3-DES context
// @param nMode		encrypt/decrypt mode
// @param nLength	input length
// @param pIv		3-DES key
// @param pacInput  input text buffer
// @param pacOutput output text buffer
//
void DES3CryptCBC ( DMDES3Context *pCtx,
	int32_t		nMode,
	int32_t		nLength,
	DMDES3Block	*pIV,
	uint8_t *pacInput,
	uint8_t *pacOutput );



//
// @brief          Checkup routine
//
// @return         0 if successful, or 1 if the test failed
//
int32_t DESSelfTest( int32_t nVerbose );

#endif // __DMCRYPTODES_H_INCLUDE__
