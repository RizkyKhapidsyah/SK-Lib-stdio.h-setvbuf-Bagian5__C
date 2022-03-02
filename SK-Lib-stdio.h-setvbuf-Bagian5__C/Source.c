#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
    Source by AlphaCodingSkills
    Modified For Learn by RK
    I.D.E : VS2019
*/

int main() {
    char buf[50];

    if (setvbuf(stdout, buf, _IOFBF, sizeof buf)) {
        perror("Failed to change the buffer of stdout");
        return EXIT_FAILURE;
    }

    printf("Programming"); //The buffer contains "Programming" 
    //but nothing is written to stdout yet
    fflush(stdout);  //Now "Programming" is written to stdout

    if (setvbuf(stdout, NULL, _IONBF, 0)) {
        perror("Failed to change the buffer of stdout");
        return EXIT_FAILURE;
    }

    printf(" is"); //" is" is written to stdout
    //there is no buffering

    if (setvbuf(stdout, buf, _IOLBF, sizeof buf)) {
        perror("Failed to change the buffer of stdout");
        return EXIT_FAILURE;
    }
    printf(" fun."); //The buffer now contains " fun."
    //but nothing is written to stdout yet
    putchar('\n'); //stdout is line buffered 
    //everything in the buffer is now written to 
    //stdout along with the newline

    _getch();
    return EXIT_SUCCESS;
}

