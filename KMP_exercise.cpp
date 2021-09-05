#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <fcntl.h>
#pragma warning(disable : 4996)

int next[50];
void InitNext(char* p)
{
	int i, j = 0, M = strlen(p);

	next[0] = -1;
	for (i = 0, j = -1; i < M; i++, j++) {
		//next[i] = j; //원래버전
		next[i] = (p[i] == p[j]) ? next[j] : j; //개선된버전
		while ((j >= 0) && (p[i] != p[j]))
			j = next[j];
	}
}
int KMP(char *p, char *t)
{
	int i, j, M = strlen(p), N = strlen(t);
	InitNext(p);
	for (i = 0, j = 0; j < M && i < N; i++, j++)
		while ((j >= 0) && (t[i] != p[j])) j = next[j];
	if (j == M) return i - M;
	else return i;
}
int isitsame(char* p) // prefix==suffix인 길이를 return해주는 기능을 만들었음.
{
	int i=0, j=1, k;
	for (j = 1; j < strlen(p); j++)
	{
		if (p[i] != p[j]) {
			if (i != 0)
				j = j - i; // 특정 지점에서 일치하지 않을 경우, 일치한 수만큼 뒤로 옮겨줌?
			i = 0; // prefix는 다시 처음부터 비교.
		}
		else if (p[i] == p[j])
			i++; // 일치한 경우 prefix와 suffix의 다음 캐릭터 비교.
	}
	return i;
}
int main()
{
	char buffer[3000];
	std::ifstream infile("RFC2616_modified.txt"); // text 오픈하는데 ifsteam 사용했음. 객체형식이라 쉬웠음.
	char text[100];
	char pattern[50];
	int M, N, pos, previous = 0, i = 0, k=1;
	std::cout << "enter pattern : ";
	std::cin >> pattern; // pattern 입력받음. char 형태여서 어차피 특수문자 다 인식함..
	M = strlen(pattern) - isitsame(pattern); // suffix == prefix 인 시작지점을 M이라고 해줌. 일치하지 않을경우 strlen 그대로.
	//std::cout << M << std::endl; //test용
	while (infile.peek() != EOF) { // 파일 끝일경우 while탈출.
		infile.getline(buffer, 3000); // buffer에 한 줄 추가함. 대충 충분한 버퍼 3천을 넣어줌. 몇 줄 긁어보니 만개 이하여서..
		N = strlen(buffer);
		while (1) {
			pos = KMP(pattern, buffer + i);
			pos += previous;
			i = pos + M; // M이 strlen 경우 전체스킵인데 그러면 안됨. 앞뒤가 똑같은 경우를 찾아야함.
			if (i <= N) printf("패턴이 발생한 위치 : %d줄 %d\n",k, pos); // 발생위치 출력함. 여러번 찾아서 줄수까지 표시해줌.
			else break;
			previous = i;
		}
		i = 0, previous = 0,k++; // 한 줄 끝난상태이므로 i랑 previous 전부 초기화함. 줄 수를 의미하는 k는 ++함.
	}
	printf("정보통신공학과 12151606 이종현\n");
}