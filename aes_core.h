#pragma once

namespace aes
{
	// only 128bit key is supported
	int AesExpandKey(unsigned int *roundkey, const unsigned char *key, 
		unsigned keySize);
}