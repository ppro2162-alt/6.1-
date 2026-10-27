#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include "tasks.h"
#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    const int N = 22;
    const int LO = -10, HI = 35;
    int a[N];

    srand(static_cast<unsigned>(time(nullptr)));
    fillArray(a, N, LO, HI, 0);

    printf("Початковий масив:\n%s\n\n", formatArray(a, N, 0).c_str());

    int count = countMatching(a, N, 0);
    int sum = sumMatching(a, N, 0);
    zeroMatching(a, N, 0);

    printf("Кількість елементів, що задовольняють критерій: %d\n", count);
    printf("Сума елементів, що задовольняють критерій: %d\n\n", sum);
    printf("Модифікований масив:\n%s\n", formatArray(a, N, 0).c_str());
    return 0;
}