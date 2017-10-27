#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"

void write(char target_file[])
{
    printf("write was called.\n");

    char *reader = NULL;

    if(target_file[0] != 34) // 34 == "
        printf("Invalid instruction. Enclose the target file between \"...\".\n");
    else {
        target_file++; // dodge first dbl quot mark
        reader = strchr(target_file, 34);
        if (reader != NULL) {
            *reader = '\0';
        }
        else
            printf("Invalid instruction. Enclose the target file between \"...\".\n");
    }

    FILE *file_p;

    file_p = fopen(target_file, "w");

    if (file_p == NULL) {
        printf("I could not open the file: %s.\n", target_file);
        return;
    }

    fprintf(file_p, "\t\t\t|TASK LIST|\nNum Chk Pri| Task Description\n=======================================================\n");
    for (int i = 0; i < 10; i++) {
            if (task_list[i].active == TRUE) {
                fprintf(file_p, "%3d ", i + 1);
                fprintf(file_p, "%s\t", task_list[i].checked_display);
                fprintf(file_p, " %d | ", task_list[i].priority);
                fprintf(file_p, "%s\n", task_list[i].description);
                fprintf(file_p, "_______________________________________________________\n");
            }
    }

    fclose(file_p);
}

void read_from_file(char soruce_file[])
{
    printf("read was called.\n");

    char *reader = NULL;

    if(soruce_file[0] != 34) // 34 == "
        printf("Invalid instruction. Enclose the target file between \"...\".\n");
    else {
        soruce_file++; // dodge first dbl quot mark
        reader = strchr(soruce_file, 34);
        if (reader != NULL) {
            *reader = '\0';
        }
        else
            printf("Invalid instruction. Enclose the target file between \"...\".\n");
    }

    FILE *file_p;
    char buffer[57];
    int linecounter = 0;
    int i = 0;

    file_p = fopen(soruce_file, "r");

    if (file_p == NULL) {
        printf("I could not open the file: %s.\n", soruce_file);
        return;
    }

    while (fgets(buffer, 57, file_p)) {
        ++linecounter;
        if (linecounter > 3 && !(linecounter % 2)) {
            task_list[i].active = 1;
            if (buffer[5] == 'x') {
                task_list[i].is_checked = 1;
                strcpy(task_list[i].checked_display, "[x]");
            }
            task_list[i].priority = atoi(&buffer[9]);
            strcpy(task_list[i].description, &buffer[13]);
            i++;
        }
    }
    fclose(file_p);
}
