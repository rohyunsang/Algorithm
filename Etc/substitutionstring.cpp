#include <stdio.h>
#include <string.h> //strstr 함수가 선언된 헤더 파일
#include <cstring> //c++일경우
int main()
{
    char str[] = "This is a simple string";
    char* ptr = strchr(str, 'p');  // p가 존재하는 위치를 찾음
    if (ptr) {
        *ptr = 't';  // t로 변경
        puts(str);
    }

    return 0;
}
