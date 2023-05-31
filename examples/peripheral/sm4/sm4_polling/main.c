#include <string.h>
#include <stdlib.h>
#include "ls_hal_sm4.h"
#include "platform.h"
#include "ls_soc_gpio.h"
#include "log.h"

const uint8_t key[16] = {
    0x01, 0x23, 0x45, 0x67,
    0x89, 0xab, 0xcd, 0xef,
    0xfe, 0xdc, 0xba, 0x98,
    0x76, 0x54, 0x32, 0x10};
const uint8_t plaintext[64] = {
    0x01, 0x23, 0x45, 0x67,0x89, 0xab, 0xcd, 0xef,0xfe, 0xdc, 0xba, 0x98,0x76, 0x54, 0x32, 0x10,
    0x01, 0x23, 0x45, 0x67,0x89, 0xab, 0xcd, 0xef,0xfe, 0xdc, 0xba, 0x98,0x76, 0x54, 0x32, 0x10,
    0x01, 0x23, 0x45, 0x67,0x89, 0xab, 0xcd, 0xef,0xfe, 0xdc, 0xba, 0x98,0x76, 0x54, 0x32, 0x10,
    0x01, 0x23, 0x45, 0x67,0x89, 0xab, 0xcd, 0xef,0xfe, 0xdc, 0xba, 0x98,0x76, 0x54, 0x32, 0x10};
const uint8_t ciphertext[64] = {
    0x68, 0x1e, 0xdf, 0x34,0xd2, 0x06, 0x96, 0x5e,0x86, 0xb3, 0xe9, 0x4f,0x53, 0x6e, 0x42, 0x46,
    0x68, 0x1e, 0xdf, 0x34,0xd2, 0x06, 0x96, 0x5e,0x86, 0xb3, 0xe9, 0x4f,0x53, 0x6e, 0x42, 0x46,
    0x68, 0x1e, 0xdf, 0x34,0xd2, 0x06, 0x96, 0x5e,0x86, 0xb3, 0xe9, 0x4f,0x53, 0x6e, 0x42, 0x46,
    0x68, 0x1e, 0xdf, 0x34,0xd2, 0x06, 0x96, 0x5e,0x86, 0xb3, 0xe9, 0x4f,0x53, 0x6e, 0x42, 0x46};

uint8_t plainbuffer[64];
uint8_t cipherbuffer[64];
uint32_t length;

void sm4_init(void)
{
    HAL_SM4_Init();
    HAL_SM4_KeyExpansion(key);
}

void sm4_crypt_test(void)
{
    HAL_SM4_Encrypt(plaintext, cipherbuffer, length);
    if(!memcmp(cipherbuffer,ciphertext,length))
    {
        LOG_I("SM4_ENCRYPT_POLLING_%d_TEST_SUCCESS!",length);
    }
    else
    {
        LOG_I("SM4_ENCRYPT_POLLING_%d_TEST_FAIL!",length);
    }
    HAL_SM4_Decrypt(ciphertext, plainbuffer, length);
    if(!memcmp(plainbuffer,plaintext,length))
    {
        LOG_I("SM4_DECRYPT_POLLING_%d_TEST_SUCCESS!",length);
    }
    else
    {
        LOG_I("SM4_DECRYPT_POLLING_%d_TEST_FAIL!",length);
    }
}

int main()
{
    sys_init_none();
    sm4_init();
    length = 16;
    sm4_crypt_test();
    length = 32;
    sm4_crypt_test();
    length = 64;
    sm4_crypt_test();
    while (1)
    {
        
    }
}
