#include "string_utilities.h"

int substrcmp(char* str1, char* str2, int lng){
    int i;
    for(i = 0; i < lng; i++){
        if (*(str1 + i) != *(str2 + i)){
            return 0;
        }
    }
    return 1;
}