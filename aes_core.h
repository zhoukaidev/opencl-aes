#pragma once

namespace aes
{
	int AesExpandKey(unsigned int *roundkey, const unsigned char *key, 
		unsigned keySize);
}