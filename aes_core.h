#pragma once

namespace aes
{
	int AesExpandEncryptKey(unsigned int *roundkey, const unsigned char *key, 
		unsigned keySize);
	int AesExpandDecryptKey(unsigned int *roundkey, const unsigned char *key,
		unsigned keySize);
}