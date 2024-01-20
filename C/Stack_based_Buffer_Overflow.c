#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void manipulate_string(char* string) { //매개변수로 널 문자 포함해서 들어와!
	char buf[12]; //맨 뒤에는 널문자 넣어야해
	//strcpy(buf, string); //버퍼 크기보다 넘게 복사되면 버퍼 오버플로우 발생
	
	if (strlen(string) < sizeof(buf)) {
		strncpy(buf, string, sizeof(buf) - 1); //널문자 제외한 11개 문자 수만 복사
	}
	buf[sizeof(buf) - 1] = '\0'; //문자열 반드시 널로 종료

	printf("buf : %s", buf);
}

int main() {

	manipulate_string("Hello world");


	return 0;
}
