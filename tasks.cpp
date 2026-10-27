#include "tasks.h"
#include <cstdio>
#include <cstdlib>

bool meetsCriterion(int x)
{
    return x > 0 && x % 3 != 0;
}

void fillArray(int a[], int n, int lo, int hi, int i)
{
    if (i == n)
        return;
    a[i] = lo + rand() % (hi - lo + 1);
    fillArray(a, n, lo, hi, i + 1);
}

std::string formatArray(const int a[], int n, int i)
{
    if (i == n)
        return "";
    char buf[16];
    snprintf(buf, sizeof(buf), "%4d", a[i]);
    return buf + formatArray(a, n, i + 1);
}

int countMatching(const int a[], int n, int i)
{
    if (i == n)
        return 0;
    if (meetsCriterion(a[i]))
        return 1 + countMatching(a, n, i + 1);
    return countMatching(a, n, i + 1);
}

int sumMatching(const int a[], int n, int i)
{
    if (i == n)
        return 0;
    if (meetsCriterion(a[i]))
        return a[i] + sumMatching(a, n, i + 1);
    return sumMatching(a, n, i + 1);
}

void zeroMatching(int a[], int n, int i)
{
    if (i == n)
        return;
    if (meetsCriterion(a[i]))
        a[i] = 0;
    zeroMatching(a, n, i + 1);
}