#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{

    /* filename */
    char filename[100];

    /* file descriptor */
    FILE *fd;

    /* read buffer */
    char buffer[100];

    /* retval */
    int status;

    /* read the input filename */
    status = scanf("%s", filename);

    /* open file using open, in read-only mode*/
    fd = fopen(filename, "r");

    /* read file using read*/
    fread(buffer, 1, 1, fd);

    /* write first byte from buffer to stdout using write*/
    fwrite(buffer, 1, 1, stdout);

    /* close file*/
    fclose(fd);

    return 0;
}
