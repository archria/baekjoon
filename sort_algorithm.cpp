#include <iostream>
#include <time.h>

using namespace std;

void swap(int& i, int& j) // swap을 쓸 일이 많아서 따로 하나의 기능으로 구현해주었음.
{
    int temp;
    temp = i;
    i = j;
    j = temp;
}
void frontbig(int& i, int& j) // 앞을 더 크게 만들어주는 기능.
{
    if (i < j)
        swap(i, j);
}
void backbig(int& i, int& j) // 뒤를 더 크게 만들어주는 기능.
{
    if (i > j)
        swap(i, j);
}
void bitonicfrontbig(int i, int j, int t[]) { //시작지점 i, 간격크기 j, array 입력받아야됨. 시작지점의 경우 array 번호임. 내림차순 정렬해줌.
    // 비교횟수는 간격만큼임.
    for (int k = 0; k < j; k++)
    {
        frontbig(t[i + k], t[i + k + j]);
    }
    if (j != 1) { // 간격 크기가 1보다 클 경우, 간격을 2로 나누어주어 앞뒤로 다시 bitonic frontbig 수행함.
        // 어차피 가장 큰 모집단 내부에서 반으로 쪼개어 다시 수행하는 것이므로 딱히 크기의 리미트는 정해주지 않아도 됨.
        j = j / 2;
        bitonicfrontbig(i, j, t);
        bitonicfrontbig(i + 2 * j, j, t);
    }
}
void bitonicbackbig(int i, int j, int t[]) { // 시작지점 i , 간격크기 j , array 입력받아야됨. 시작지점의 경우 array 번호임. 오름차순 정렬해줌.
    //항상 그 간격에서의 비교횟수는 간격만큼이었음.간격이 1일경우 1번, 간격이 2일경우 2번, 간격이 4일경우 4번.
    for (int k = 0; k < j; k++)
    {
        backbig(t[i + k], t[i + k + j]); // 간격만큼 비교해줌.
    }
    if (j != 1) { // 간격 크기가 1보다 클 경우, 간격을 2로 나누어주어 앞뒤로 다시 bitonic backbig 수행함.
        j = j / 2;
        bitonicbackbig(i, j, t);
        bitonicbackbig(i + 2 * j, j, t);
    }
}
void selectionSort(int n, int t[]) // sizeof 대신 갯수 지정. 갯수별로 따로 지정함.
{
    int i, j, smallest, buf;
    for (i = 0; i < n - 1; i++)
    {
        smallest = i; // 위에 있는것이 가장 작은것이라 가정함.
        for (j = i + 1; j <= n; j++)
        {
            if (t[j] < t[smallest])
                smallest = j; //그 다음부터 더 작은것이 나오면 이것이 작은것임을 명시.
        }
        buf = t[i];
        t[i] = t[smallest];
        t[smallest] = buf; // 가장과 1순위 바꿔줌.
    }
}
void median_of_three(int a[], int l, int r) { // 어레이, 시작지점, 끝지점 인수로 받음
    int i, j, m, v;
    if (r - l > 1) {
        m = (l + r) / 2;
        if (a[l] > a[m])
            swap(a[l], a[m]);
        if (a[l] > a[r])
            swap(a[l], a[r]);
        if (a[m] > a[r])
            swap(a[m], a[r]); // 왼쪽에 가장 작고, 중간에 중간, 오른쪽에 가장 큰것을 배치함.
        swap(a[m], a[r - 1]);
        v = a[r - 1]; i = l; j = r - 1; // i = 시작 j = 끝 v = 피벗
        for (;;) {
            while (a[++i] < v); // 왼쪽에서 피벗보다 클때까지
            while (a[--j] > v); // 오른쪽에서 피벗보다 작을때까지
            if (i >= j) break; // 교차하면 루프 탈출함
            swap(a[i], a[j]); // 그게 아니라면 큰것, 작은것을 바꿔줌.
        }
        swap(a[i], a[r - 1]); // 마지막으로 피벗과 a[i]를 바꾸어줌. 강의노트 그림과 동일함.
        median_of_three(a, l, i - 1); // 피벗 기준 왼쪽을 다시 소팅
        median_of_three(a, i + 1, r); // 피벗 기준 오른쪽을 다시 소팅.
    }
    else if (a[l] > a[r])
        swap(a[l], a[r]); // 크기가 너무 작을경우
}
void shellsort(int a[], int n) { // array와 array size를 인수로 받음.
    int h, i, j, v;
    for (h = 1; h < n; h = 3 * h + 1) {}; // h값 계산함.
    for (; h > 0; h = h / 3) { // h값을 떨어뜨리며 계산을 계속함.
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
void bitonicsort(int n, int t[]) // 어레이의 사이즈 n과 그 어레이를 인수로 받음.
{
    for (int i = 1; i < n; i = 2 * i) // 늘어나는 간격을 표시함.
    {
        for (int j = 0; j < n; j = j + 4 * i) // 오름차순 시작지점을 말해줌.
            bitonicbackbig(j, i, t);
        for (int j = 2 * i; j < n; j = j + 4 * i) // 내림차순 시작지점을 말해줌. 간격의 4배만큼 떨어진것은 동일하나 첫 시작지점은 간격의 2배임
            bitonicfrontbig(j, i, t);
    }
} //1 * 2^n 개 차이로 하되 가장 큰 차이가 전체 데이터셋의 1/2로 될때까지만 재귀문으로 구현해야함.

void oddevens_sub(int t[], int space, int starting_point) //간격 = 비교횟수 이므로 시작점과 간격을 받아서 for문으로 여러개를 비교해줌.
{

    for (int i = 0; i < space; i++)
    {
        backbig(t[starting_point + i], t[starting_point + i + space]);
    }
}

void oddevens(int t[], int size) // array 와 그 어레이의 사이즈 size 를 입력받음.
{

    for (int i = 1; i < size; i = 2 * i) // stage 마다 늘어나는 간격을 표시해줌. size보다 작은 것이 가장 큰 범위였음.
    {

        for (int sp = 0; sp < size; sp = sp + 2 * i) { // sp = starting_point 각 뭉텅이의 첫 시작지점.
            oddevens_sub(t, i, sp); // 배열에서 가장 큰 간격
            int nsp = sp + 2 * i;// nsp = next starting_point
            int subspace = i / 2;

            for (subspace = i / 2; subspace > 0; subspace /= 2)
            {
                for (int ssp = sp + subspace; ssp + 2 * subspace < nsp; ssp += 2 * subspace) //ssp = sub_starting point
                    // 작은것들에서 시작 지점을 표시해줌. 첫 시작지점은 원 시작지점 + 축소된 간격임. 그다음은 위와 마찬가지로 2*space만큼 더해감
                    // stage 2 기준 0 12 3을 보게되면 0+1 = 1 이어서 1이 시작지점, 12 비교후 34를 비교해야되는데 4는 next_startingpoint
                    // 이므로 3은 sub_startingpoint가 될 수 없음.
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
    } // bitonic sort의 경우 2^n 개로 어레이를 지정해 주어야 함.
    int* bito = new int[jegobsize];// bitonic sort의 array size는 n임.
    int* oddeven = new int[jegobsize];
    clock_t start, end, start1, end1;
    float result;
    for (int i = 0; i < arraysize; i++) // 랜덤한 값을 array 에 하나씩 대입함.
        temp[i] = rand();
    for (int i = 0; i < arraysize; i++) {
        sel[i] = temp[i];
        med[i] = temp[i];
        shell[i + 1] = temp[i]; // 1~N 정렬이므로 어레이 번호를 하나씩 뒤로 미뤘음.
        bito[i] = temp[i];
        oddeven[i] = temp[i];
    } // 먼저 만든 어레이 모두 같은것을 넣어주는 for 문
    if (jegobsize != arraysize) // bitonic sort의 경우 2^n 개로 만들기 때문에 그 넘는 공간을 0으로 채워줌.
        for (int i = arraysize; i < jegobsize; i++) {
            bito[i] = 0;
            oddeven[i] = 0;
        } //oddeven 또한 2^n 사이즈 비교임.
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
