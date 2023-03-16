#include "alist.h"

void append(alist *a, const alist *b)
{
    if (b->size == 0)
        return;

    int ans_size = a->size + b->size;
    int *ans_elements = new int[ans_size];

    for (int i = 0; i < a->size; i++)
    {
        ans_elements[i] = a->elements[i];
    }
    for (int i = 0; i < b->size; i++)
    {
        ans_elements[a->size + i] = b->elements[i];
    }

    delete[] a->elements;
    a->size = ans_size;
    a->elements = ans_elements;
}

int main()
{
    const int nA = 4;
    int eA[nA] = {1, 2, 3, 4};
    alist *a = build(nA, eA);
    const int nB = 3;
    int eB[nB] = {5, 6, 7};
    const alist *b = build(nB, eB);
    append(a, b);
    print(a);
    destroy(a);
    destroy(b);
    return 0;
}
