#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum { 
	BUFSIZE = 10
};
size_t strlcpy(char* dest, const char* src, size_t size) {
	size_t i;

	for (i = 0; (i < size - 1) && src[i] != '\0'; ++i) {
		dest[i] = src[i];
	}

	dest[i] = '\0'; //i= (size-1) 즉 마지막 원소

	// Count the length of the source string
	//목적지 버퍼에 정확히 몇 개의 문자가 복사되었는지
	while (src[i] != '\0') { 
		++i;
	}

	return i;
}
//strlcpy  입력된 문자열에 대해 길이 제한
//It's not part of the C standard library, but it's commonly found on systems like BSD.

int main() {

	char* dest = NULL;
	dest = (char *)malloc(BUFSIZE); //sizeof(char) * BUFSIZE 와 동일
	

	char src[] = "GOOSUNDAS1234";
	//strcpy(dest, src);
	int n=strlcpy(dest, src, BUFSIZE); 

	printf("dest: %s\nlen of copy: %d\n", dest,n);

	free(dest);
	return 0;
}
