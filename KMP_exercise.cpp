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
		//next[i] = j; //��������
		next[i] = (p[i] == p[j]) ? next[j] : j; //�����ȹ���
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
int isitsame(char* p) // prefix==suffix�� ���̸� return���ִ� ����� �������.
{
	int i=0, j=1, k;
	for (j = 1; j < strlen(p); j++)
	{
		if (p[i] != p[j]) {
			if (i != 0)
				j = j - i; // Ư�� �������� ��ġ���� ���� ���, ��ġ�� ����ŭ �ڷ� �Ű���?
			i = 0; // prefix�� �ٽ� ó������ ��.
		}
		else if (p[i] == p[j])
			i++; // ��ġ�� ��� prefix�� suffix�� ���� ĳ���� ��.
	}
	return i;
}
int main()
{
	char buffer[3000];
	std::ifstream infile("RFC2616_modified.txt"); // text �����ϴµ� ifsteam �������. ��ü�����̶� ������.
	char text[100];
	char pattern[50];
	int M, N, pos, previous = 0, i = 0, k=1;
	std::cout << "enter pattern : ";
	std::cin >> pattern; // pattern �Է¹���. char ���¿��� ������ Ư������ �� �ν���..
	M = strlen(pattern) - isitsame(pattern); // suffix == prefix �� ���������� M�̶�� ����. ��ġ���� ������� strlen �״��.
	//std::cout << M << std::endl; //test��
	while (infile.peek() != EOF) { // ���� ���ϰ�� whileŻ��.
		infile.getline(buffer, 3000); // buffer�� �� �� �߰���. ���� ����� ���� 3õ�� �־���. �� �� �ܾ�� ���� ���Ͽ���..
		N = strlen(buffer);
		while (1) {
			pos = KMP(pattern, buffer + i);
			pos += previous;
			i = pos + M; // M�� strlen ��� ��ü��ŵ�ε� �׷��� �ȵ�. �յڰ� �Ȱ��� ��츦 ã�ƾ���.
			if (i <= N) printf("������ �߻��� ��ġ : %d�� %d\n",k, pos); // �߻���ġ �����. ������ ã�Ƽ� �ټ����� ǥ������.
			else break;
			previous = i;
		}
		i = 0, previous = 0,k++; // �� �� ���������̹Ƿ� i�� previous ���� �ʱ�ȭ��. �� ���� �ǹ��ϴ� k�� ++��.
	}
	printf("������Ű��а� 12151606 ������\n");
}