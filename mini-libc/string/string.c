// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	size_t i = 0;
	for(i = 0; i < strlen(source); i++) {
		destination[i] = source[i];
	}
	destination[i] = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	if (len <= strlen(source)) {
		size_t i = 0;
		for(i = 0; i < len; i++) {
			destination[i] = source[i];
		}
		destination[i] = '\0';
	} else {
		strcpy(destination, source);
		for(size_t i = strlen(source); i < len; i++) {
			destination[i] = '\0';
		}
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int pos = strlen(destination);
	for(size_t i = 0; i < strlen(source); i++) {
		destination[pos++] = source[i];
	}
	destination[pos] = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	if (len <= strlen(source)) {
		int pos = strlen(destination);
		for(size_t i = 0; i < len; i++) {
			destination[pos++] = source[i];
		}
		destination[pos] = '\0';
	} else {
		strcat(destination, source);
	}
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len = 0;
	if (len1 > len2) {
		len = len2;
	} else {
		len = len1;
	}
	int ok = 0;
	for(int i = 0; i < len; i++) {
		if (str1[i] > str2[i]) {
			ok = 1;
		} else if (str1[i] < str2[i]) {
			ok = -1;
		}
	}
	if (ok == 0) {
		if (len1 > len2) {
			ok = 1;
		} else if (len1 < len2) {
			ok = -1;
		}
	}
	return ok;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);
	size_t lenghMin = 0;
	size_t lenghMax = 0;
	int dif = 0;
	if (len1 > len2) {
		lenghMax = len1;
		lenghMin = len2;
		dif = len1 - len2;
	} else {
		lenghMin = len1;
		lenghMax = len2;
		dif = len2 - len1;
	}
	if (len <= lenghMin) {
		strcpy(str1 + len, str1 + strlen(str1));
		strcpy(str2 + len, str2 + strlen(str2));
		return strcmp(str1, str2);
	} else if (len > lenghMin && len < lenghMax) {
		if (strlen(str1) == lenghMax) {
			strcpy(str1 + len, str1 + strlen(str1));
		} else {
			strcpy(str2 + len, str2 + strlen(str2));
		}
		return strcmp(str1, str2);
	}
	return strcmp(str1, str2);
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	for(int i = 0; i < strlen(str); i++) {
		if (str[i] == c) {
			return &(str[i]);
		}
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char *ptr;
	int ok = 0;
	for(int i = 0; i < strlen(str); i++) {
		if (str[i] == c) {
			ok = 1;
			ptr = &(str[i]);
		}
	}
	if (ok) {
		return ptr;
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	for(int i = 0; i < strlen(haystack); i++) {
		int count = 0; int k = 0;
		for(int j = i; j < strlen(haystack); j++) {
			if (needle[k++] == haystack[j]) {
				count++;
				if (count == strlen(needle)) {
					return &(haystack[i]);
				}
			}
		}
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	int end_val = strlen(haystack) - strlen(needle) - 1;
	for(int i = end_val; i >= 0; i--) {
		int count = 0; int k = 0;
		for(int j = i; j < strlen(haystack); j++) {
			if (needle[k++] == haystack[j]) {
				count++;
				if (count == strlen(needle)) {
					return &(haystack[i]);
				}
			}
		}
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	unsigned char *dest = (unsigned char *) destination;
	unsigned char *src = (unsigned char *) source;
	for(size_t i = 0; i < num; i++) {
		dest[i] = src[i];
	}
	return dest;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	unsigned char *dest = (char *) destination;
	unsigned char *src = (char *) source;
	int n = (int) num;
	char aux[105];
	if (src == NULL || dest == NULL) {
		return NULL;
	}
	if ((src < dest) && (dest < (src + num))) {
		for(dest += num, src += num; num--;) {
			*--dest = *--src;
		}
	} else {
		while(num--) {
			*dest++ = *src++;
		}
	}
	return dest;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	unsigned char *p1 = (unsigned char *) ptr1;
    unsigned char *p2 = (unsigned char *) ptr2;
    for (size_t i = 0; i < num; i++) {
        if (p1[i] < p2[i]) {
            return -1;
		} else if (p1[i] > p2[i]) {
            return 1;
        }
    }
    return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char *src = (unsigned char *) source;
	for(size_t i = 0; i < num; i++) {
		src[i] = (unsigned char) value;
	}
	return src;
}
