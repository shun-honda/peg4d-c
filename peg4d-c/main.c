//
//  main.c
//  peg4d-c
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void parseCommandArgument(int argc, char *argv[]);
void showUsage();

char *GrammarFile;
char *InputFileName;
//char *PEGFormatter;

int main(int argc, char * argv[])
{
    clock_t start, end;
    start = clock();
    parseCommandArgument(argc, argv);
    end = clock();
    printf("\n実行速度： %.3f [ms]\n", (double)(end-start)*1000/CLOCKS_PER_SEC);
    return 0;
}

void parseCommandArgument(int argc, char *argv[]) {
    int index = 1;
    while (index < argc) {
        char argument[30];
        strcpy(argument, argv[index]);
        if (argument[0] != '-') {
            break;
        }
        index++;
        if (strcmp(argument, "-p") == 0) {
            GrammarFile = argv[index];
            index++;
        }
        else {
            showUsage("unknown option: ", argument);
        }
    }
    if (index < argc) {
        InputFileName = argv[index];
    }
}

void showUsage(char *msg, char *err_option) {
    fprintf(stderr, "PEG4d:\n");
    fprintf(stderr, "  -p <FILE>                 Specify PEG file  default: PEG4d grammar˜\n");
    fprintf(stderr, "  -f | --format<type>       Specify PEG formatter\n");
    fprintf(stderr, "%s%s\n", msg, err_option);
    exit(0);
}

