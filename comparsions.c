#include "vector.h"

void compare(Vector v1, Vector v2, int size1, int size2)
{
    int i = 0, j = 0;
    
    while(size1 > i && size2 > j) 
    {
        if(v1.data[i] == v2.data[j]) //this is the only time something is printed in the entire program
        {
            printf("%d\n", v1.data[i]);
            i++;
            j++;
        }
        else if(v1.data[i] < v2.data[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}