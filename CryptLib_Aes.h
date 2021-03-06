
#pragma once


#include <stdint.h>

/*
*  TYPES
*/

#define AES_KEY_SIZE_128        16
#define AES_KEY_SIZE_192        24
#define AES_KEY_SIZE_256        32
#define AES_BLOCK_SIZE          16    //分组字节16   16*8=128位

// AesContext - This must be initialised using AesInitialise128, AesInitialise192 or AesInitialise256
// Do not modify the contents of this structure directly.
typedef struct
{
    uint32_t        eK[60];
    uint32_t        dK[60];
    uint_fast32_t   Nr;
} AesContext;

/*
*  PUBLIC FUNCTIONS
*/


/*
*AesInitialise
*
*  Initialises an AesContext with an AES Key. KeySize must be 16, 24, or 32 (for 128, 192, or 256 bit key size)
*  Returns 0 if successful, or -1 if invalid KeySize provided
*/

int	AesInitialise( AesContext*         Context,                // [out]
                   void const*         Key,                    // [in]
                   uint32_t            KeySize                 // [in]
                 );

/*
 *  AesEncrypt
 *
 *  Performs an AES encryption of one block (128 bits) with the AesContext initialised with one of the functions
 *  AesInitialise[n]. Input and Output can point to same memory location, however it is more efficient to use
 *  AesEncryptInPlace in this situation.
 *
**/
void	AesEncrypt(
        AesContext const*   Context,                    // [in]
        uint8_t const       Input [AES_BLOCK_SIZE],     // [in]
        uint8_t             Output [AES_BLOCK_SIZE]     // [out]
    );

/*
 *  AesDecrypt
 *
 *  Performs an AES decryption of one block (128 bits) with the AesContext initialised with one of the functions
 *  AesInitialise[n]. Input and Output can point to same memory location, however it is more efficient to use
 *  AesDecryptInPlace in this situation.
**/
void  AesDecrypt(   AesContext const*   Context,                    // [in]
                    uint8_t const       Input [AES_BLOCK_SIZE],     // [in]
                    uint8_t             Output [AES_BLOCK_SIZE]     // [out]
                );

/*
 *  AesEncryptInPlace
 *
 *  Performs an AES encryption of one block (128 bits) with the AesContext initialised with one of the functions
 *  AesInitialise[n]. The encryption is performed in place.
**/
void  AesEncryptInPlace (	AesContext const*   Context,                    // [in]
                            uint8_t             Block [AES_BLOCK_SIZE]      // [in out]
                        );

/*
 *  AesDecryptInPlace
 *
 *  Performs an AES decryption of one block (128 bits) with the AesContext initialised with one of the functions
 *  AesInitialise[n]. The decryption is performed in place.
**/
void AesDecryptInPlace ( AesContext const*   Context,                    // [in]
                         uint8_t             Block [AES_BLOCK_SIZE]      // [in out]
                        );
