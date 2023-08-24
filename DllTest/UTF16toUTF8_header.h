#pragma once

#include <string.h>
#include "iconv.h"
#include <stdlib.h>

typedef unsigned __int32 uint32;
typedef unsigned __int64 uint64;
typedef unsigned __int64 __uint64_t;
typedef __int64 __int64_t;

char* _buf = 0;
size_t	_bufSize;
char UnKnownStr[100];

#pragma comment (lib, "libiconvStatic.lib")


char* resize(int newSize)
{
	if (_bufSize < newSize)
	{
		// DEBUG_PRINT("[+]resize = resizeresizeresize");
		if (_buf != 0) {
			free(_buf);
		}
		_bufSize = newSize;
		_buf = (char*)malloc(newSize);
	}
	memset(_buf, 0, newSize);
	return _buf;
}

//取得wchar_t字符串长度  
int wlen(const unsigned short* strString)
{
	int i = 0;
	while (1)
	{
		if (strString[i] == 0)
		{
			break;
		}
		else
		{
			i++;
		}
	}
	return i;
}


char* convertString(const char* fromCode, const char* toCode, const char* source)
{
	size_t retlen = 0;
	size_t inbytesleft = strlen(source);
	if (!strncmp(fromCode, "UTF-16LE", 8))
	{
		inbytesleft = wlen((unsigned short*)source) * 2;
	}
	size_t outbytesleft = inbytesleft * 4 + 2;
	retlen = outbytesleft;

	//DEBUG_PRINT("[+]retlen = %d",wlen((unsigned short *)source));

	char* tmp = resize(outbytesleft);

	char* inbuf = (char*)source;
	char* outbuf = (char*)tmp;

	iconv_t cd = iconv_open(toCode, fromCode);
	size_t errorNo = iconv(cd, &inbuf, &inbytesleft, &outbuf, &outbytesleft);

	retlen -= outbytesleft;

	if (errorNo == -1)
	{

		if (!strncmp(toCode, "UTF-16LE", 8))
		{
			memcpy(tmp, source, inbytesleft * 2);
		}
		else {
			memcpy(tmp, source, inbytesleft);
		}
	}
	else {
		memset(tmp + retlen, 0, outbytesleft);

	}

	//DumpMemory256(tmp);

	iconv_close(cd);

	return tmp;
}

char* UTF16ToUTF8(const char* _unicode)
{
	if ((__int64_t)_unicode != 0) {
		return convertString("UTF-16LE", "UTF-8", (const char*)_unicode);
	}
	else {
		return UnKnownStr;
	}

}

char* UTF8ToUTF16(const char* _unicode)
{
	if ((__int64_t)_unicode != 0) {
		return convertString("UTF-8", "UTF-16LE", (const char*)_unicode);
	}
	else {
		return UnKnownStr;
	}

}



