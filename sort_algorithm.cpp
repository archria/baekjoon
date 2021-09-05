#include <iostream>
#include <time.h>

using namespace std;

void swap(int& i, int& j) // swap�� �� ���� ���Ƽ� ���� �ϳ��� ������� �������־���.
{
    int temp;
    temp = i;
    i = j;
    j = temp;
}
void frontbig(int& i, int& j) // ���� �� ũ�� ������ִ� ���.
{
    if (i < j)
        swap(i, j);
}
void backbig(int& i, int& j) // �ڸ� �� ũ�� ������ִ� ���.
{
    if (i > j)
        swap(i, j);
}
void bitonicfrontbig(int i, int j, int t[]) { //�������� i, ����ũ�� j, array �Է¹޾ƾߵ�. ���������� ��� array ��ȣ��. �������� ��������.
    // ��Ƚ���� ���ݸ�ŭ��.
    for (int k = 0; k < j; k++)
    {
        frontbig(t[i + k], t[i + k + j]);
    }
    if (j != 1) { // ���� ũ�Ⱑ 1���� Ŭ ���, ������ 2�� �������־� �յڷ� �ٽ� bitonic frontbig ������.
        // ������ ���� ū ������ ���ο��� ������ �ɰ��� �ٽ� �����ϴ� ���̹Ƿ� ���� ũ���� ����Ʈ�� �������� �ʾƵ� ��.
        j = j / 2;
        bitonicfrontbig(i, j, t);
        bitonicfrontbig(i + 2 * j, j, t);
    }
}
void bitonicbackbig(int i, int j, int t[]) { // �������� i , ����ũ�� j , array �Է¹޾ƾߵ�. ���������� ��� array ��ȣ��. �������� ��������.
    //�׻� �� ���ݿ����� ��Ƚ���� ���ݸ�ŭ�̾���.������ 1�ϰ�� 1��, ������ 2�ϰ�� 2��, ������ 4�ϰ�� 4��.
    for (int k = 0; k < j; k++)
    {
        backbig(t[i + k], t[i + k + j]); // ���ݸ�ŭ ������.
    }
    if (j != 1) { // ���� ũ�Ⱑ 1���� Ŭ ���, ������ 2�� �������־� �յڷ� �ٽ� bitonic backbig ������.
        j = j / 2;
        bitonicbackbig(i, j, t);
        bitonicbackbig(i + 2 * j, j, t);
    }
}
void selectionSort(int n, int t[]) // sizeof ��� ���� ����. �������� ���� ������.
{
    int i, j, smallest, buf;
    for (i = 0; i < n - 1; i++)
    {
        smallest = i; // ���� �ִ°��� ���� �������̶� ������.
        for (j = i + 1; j <= n; j++)
        {
            if (t[j] < t[smallest])
                smallest = j; //�� �������� �� �������� ������ �̰��� ���������� ���.
        }
        buf = t[i];
        t[i] = t[smallest];
        t[smallest] = buf; // ����� 1���� �ٲ���.
    }
}
void median_of_three(int a[], int l, int r) { // ���, ��������, ������ �μ��� ����
    int i, j, m, v;
    if (r - l > 1) {
        m = (l + r) / 2;
        if (a[l] > a[m])
            swap(a[l], a[m]);
        if (a[l] > a[r])
            swap(a[l], a[r]);
        if (a[m] > a[r])
            swap(a[m], a[r]); // ���ʿ� ���� �۰�, �߰��� �߰�, �����ʿ� ���� ū���� ��ġ��.
        swap(a[m], a[r - 1]);
        v = a[r - 1]; i = l; j = r - 1; // i = ���� j = �� v = �ǹ�
        for (;;) {
            while (a[++i] < v); // ���ʿ��� �ǹ����� Ŭ������
            while (a[--j] > v); // �����ʿ��� �ǹ����� ����������
            if (i >= j) break; // �����ϸ� ���� Ż����
            swap(a[i], a[j]); // �װ� �ƴ϶�� ū��, �������� �ٲ���.
        }
        swap(a[i], a[r - 1]); // ���������� �ǹ��� a[i]�� �ٲپ���. ���ǳ�Ʈ �׸��� ������.
        median_of_three(a, l, i - 1); // �ǹ� ���� ������ �ٽ� ����
        median_of_three(a, i + 1, r); // �ǹ� ���� �������� �ٽ� ����.
    }
    else if (a[l] > a[r])
        swap(a[l], a[r]); // ũ�Ⱑ �ʹ� �������
}
void shellsort(int a[], int n) { // array�� array size�� �μ��� ����.
    int h, i, j, v;
    for (h = 1; h < n; h = 3 * h + 1) {}; // h�� �����.
    for (; h > 0; h = h / 3) { // h���� ����߸��� ����� �����.
        for (i = h + 1; i <= n; i = i + 1) {
            v = a[i];
            j = i;
            while (j > h && a[j - h] > v) {
                a[j] = a[j - h];
                j = j - h;
            }
            a[j] = v;
        }
    }
}
void bitonicsort(int n, int t[]) // ����� ������ n�� �� ��̸� �μ��� ����.
{
    for (int i = 1; i < n; i = 2 * i) // �þ�� ������ ǥ����.
    {
        for (int j = 0; j < n; j = j + 4 * i) // �������� ���������� ������.
            bitonicbackbig(j, i, t);
        for (int j = 2 * i; j < n; j = j + 4 * i) // �������� ���������� ������. ������ 4�踸ŭ ���������� �����ϳ� ù ���������� ������ 2����
            bitonicfrontbig(j, i, t);
    }
} //1 * 2^n �� ���̷� �ϵ� ���� ū ���̰� ��ü �����ͼ��� 1/2�� �ɶ������� ��͹����� �����ؾ���.

void oddevens_sub(int t[], int space, int starting_point) //���� = ��Ƚ�� �̹Ƿ� �������� ������ �޾Ƽ� for������ �������� ������.
{

    for (int i = 0; i < space; i++)
    {
        backbig(t[starting_point + i], t[starting_point + i + space]);
    }
}

void oddevens(int t[], int size) // array �� �� ����� ������ size �� �Է¹���.
{

    for (int i = 1; i < size; i = 2 * i) // stage ���� �þ�� ������ ǥ������. size���� ���� ���� ���� ū ��������.
    {

        for (int sp = 0; sp < size; sp = sp + 2 * i) { // sp = starting_point �� �������� ù ��������.
            oddevens_sub(t, i, sp); // �迭���� ���� ū ����
            int nsp = sp + 2 * i;// nsp = next starting_point
            int subspace = i / 2;

            for (subspace = i / 2; subspace > 0; subspace /= 2)
            {
                for (int ssp = sp + subspace; ssp + 2 * subspace < nsp; ssp += 2 * subspace) //ssp = sub_starting point
                    // �����͵鿡�� ���� ������ ǥ������. ù ���������� �� �������� + ��ҵ� ������. �״����� ���� ���������� 2*space��ŭ ���ذ�
                    // stage 2 ���� 0 12 3�� ���ԵǸ� 0+1 = 1 �̾ 1�� ��������, 12 ���� 34�� ���ؾߵǴµ� 4�� next_startingpoint
                    // �̹Ƿ� 3�� sub_startingpoint�� �� �� ����.
                    oddevens_sub(t, subspace, ssp);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    int arraysize, jegobsize = 1;
    cout << "enter array size\n";
    cin >> arraysize;
    int* temp = new int[arraysize];
    int* sel = new int[arraysize];
    int* med = new int[arraysize];
    int* shell = new int[arraysize + 1];
    for (;;) {
        if (jegobsize < arraysize)
            jegobsize = 2 * jegobsize;
        else if (jegobsize >= arraysize)
            break;
    } // bitonic sort�� ��� 2^n ���� ��̸� ������ �־�� ��.
    int* bito = new int[jegobsize];// bitonic sort�� array size�� n��.
    int* oddeven = new int[jegobsize];
    clock_t start, end, start1, end1;
    float result;
    for (int i = 0; i < arraysize; i++) // ������ ���� array �� �ϳ��� ������.
        temp[i] = rand();
    for (int i = 0; i < arraysize; i++) {
        sel[i] = temp[i];
        med[i] = temp[i];
        shell[i + 1] = temp[i]; // 1~N �����̹Ƿ� ��� ��ȣ�� �ϳ��� �ڷ� �̷���.
        bito[i] = temp[i];
        oddeven[i] = temp[i];
    } // ���� ���� ��� ��� �������� �־��ִ� for ��
    if (jegobsize != arraysize) // bitonic sort�� ��� 2^n ���� ����� ������ �� �Ѵ� ������ 0���� ä����.
        for (int i = arraysize; i < jegobsize; i++) {
            bito[i] = 0;
            oddeven[i] = 0;
        } //oddeven ���� 2^n ������ ����.
    start = clock();
    selectionSort(arraysize, temp);
    end = clock();
    result = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "selection sort : " << result << " sec\n";
    start1 = clock();
    median_of_three(med, 0, arraysize - 1);
    end1 = clock();
    result = (float)(end1 - start1) / CLOCKS_PER_SEC;
    cout << "quick sort : " << result << " sec\n";
    start = clock();
    shellsort(shell, arraysize + 1);
    end = clock();
    result = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "shell sort : " << result << " sec\n";
    start = clock();
    bitonicsort(jegobsize, bito);
    end = clock();
    result = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "bitonic sort : " << result << " sec\n";
    start = clock();
    oddevens(oddeven, jegobsize);
    end = clock();
    result = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "odd-even merge sort : " << result << " sec\n";

    return 0;
}
