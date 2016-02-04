#include "vector.h"

void shell_sort (Vector* v, int num) 
{
    int i = 0, j = 0, k = 0, temp = 0;
    for(i = num / 2; i > 0; i = i / 2)
    {
        for(j = i; j < num; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if(v->data[k + i] >= v->data[k]) //the two elements are in sorted order if this is used
                {
                    break;
                }
                else //swaps data if the next element [k + i] is less than the current element [k]
                {
                    temp = v->data[k];
                    v->data[k] = v->data[k + i];
                    v->data[k + i] = temp;
                }
            }
        }
    }
}