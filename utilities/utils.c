#include <stdlib.h>

void clearTerminal()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int checkInput (int input, int inputValid, int startRange, int endRange) {
    if (inputValid != 1 || startRange <= input <= endRange) {
        return 1;
    } else {
        return -1;
    }
}