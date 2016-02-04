/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Jonathon Lantsberger
 * JTL378
 * CS3050
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "input_error.h"
#include "vector.h"


int main(int argc, char** argv) {

    if(argc != 3)
    {
        exit(INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS);
    }
    
    FILE* fp1 = fopen(argv[1], "r+");
    FILE* fp2 = fopen(argv[2], "r+");
    
    /*Error check for a null file pointer*/
    if(fp1 == NULL || fp2 == NULL)
    {
        exit(FILE_FAILED_TO_OPEN);
    }
    
    Vector vec1;
    Vector vec2;
    
    vec1 = parse_ints(fp1);
    vec2 = parse_ints(fp2);

    shell_sort(&vec1, vec1.size);
    shell_sort(&vec2, vec2.size);
    
    compare(vec1, vec2, vec1.size, vec2.size);
    
    free(vec1.data);
    free(vec2.data);

    fclose(fp1);
    fclose(fp2);
    
    if(fp1->_ptr != NULL || fp2->_ptr != NULL)
    {
        exit(FILE_FAILED_TO_CLOSE);
    }
    return (EXIT_SUCCESS);
}