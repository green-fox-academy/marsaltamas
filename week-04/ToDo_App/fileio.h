#ifndef FILEIO_H
#define FILEIO_H

/* writes the contents of the task_list into the given target file taken as parameter
 * formatted text file is the output
 * if file not exists, it is created first, if exists, its contents are deleted first
 */
void write(char target_file[]);

// reads from parameter source file to task_list
//(source_file must contain tasks in the default form of "write"
void read_from_file(char soruce_file[]);

#endif // FILEIO_H
