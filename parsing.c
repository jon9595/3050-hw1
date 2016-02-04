#include "input_error.h"
#include "vector.h"

Vector parse_ints(FILE* file)
{
    char* leftover;
    char input[64];
    int newResult = 0;
    errno = 0; //variable used for the strtol function for errors
    Vector v1;

    init_vector(&v1);
    /*The next few lines are an error check for an empty file. fseek til the end and if ftell returns 0, the file is empty*/
    fseek(file, 0, SEEK_END);
    if(ftell(file) == 0)
    {
        exit(PARSING_ERROR_EMPTY_FILE);
    }
    rewind(file);
    
    while(!feof(file))
    {
        fgets(input, 64, file);
        const long result = strtol(input, &leftover, 0); //converting the string input into a long to parse out integers
    
        if(input[0] == ' ') //checking for stray spaces in the input file
        {
            exit(PARSING_ERROR_INVALID_CHARACTER_ENCOUNTERED);
        }
        if(input == leftover) //if an invalid character is found (i.e. not an int, the leftover becomes the entire input )
        {
            exit(PARSING_ERROR_INVALID_CHARACTER_ENCOUNTERED);
        }
        else if(*leftover != '\n' && *leftover != '\0' && *leftover != '\r') //if the string being parsed begins with an int but ends with an invalid character, this will catch it and exit
        {
            exit(PARSING_ERROR_INVALID_CHARACTER_ENCOUNTERED);
        }
        else if(result <= 0)
        {
            exit(PARSING_ERROR_INVALID_CHARACTER_ENCOUNTERED);
        }
        else //character is an integer and it is then sent to the vector
        {
            newResult = (int)result;
            insert_element_vector(&v1, newResult);
        }
    }
    return v1;
}