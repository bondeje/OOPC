#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define FILE_MODE "rb+"
#define WRITE_TAB buffer[j++] = '\t';
//#define WRITE_TAB for (int k = 0; k < 3; k++) {buffer[j++] = ' ';}

char logbuf[BUFSIZ] = {'\0'};
char buffer[BUFSIZ] = {'\0'};

const char * newline = "OOP_NEWLINE";
const char * tab = "OOP_TAB";
const char * oop = "OOP";
size_t oopl = 0;
size_t tabl = 0;
size_t newlinel = 0;
FILE * file = NULL;

enum process_buffer_state {
    IDLE = 0,
    IN_OOP,
    IN_TAB,
    IN_NL
};

int process_buffer(void) {
    //printf("processing buffer: %s\n", buffer);
    //for (int d = 0; d < strlen(buffer); d++) {
    //    printf("%d ", buffer[d]);
    //}
    //printf("\n");
    unsigned int ct = 0;
    int result = 0;
    // i is the read index, j is the write index
    unsigned int i = 0, j = 0, ref = 0;;
    enum process_buffer_state st = IDLE;

    while (1) {
        //printf("looping with state %d\n", st);
        switch (st) {
            case IDLE: {
                //printf("IDLE from %d (%s) (ct = %u)\n", i, buffer + i, ct);
                while (buffer[i] != '\0' && buffer[i] != oop[ct]) {
                    buffer[j++] = buffer[i++];
                }
                if (buffer[i] == '\0') {
                    buffer[j] = buffer[i];
                    //printf("exiting in IDLE\n");
                    return 0;
                } else {
                    //printf("entering IN_OOP at index %u\n", i);
                    st = IN_OOP;
                    i++;
                    ct = 1;
                }
                break;
            }
            case IN_OOP: {
                while (buffer[i] != '\0' && ct < oopl && buffer[i] == oop[ct]) {
                    //printf("IN_OOP: %c\n", buffer[i]);
                    i++;
                    ct++;
                }
                if (buffer[i] == '\0') { // buffer ends with O, OO, or OOP
                    buffer[j] = '\0';
                    //printf("exiting in IN_OOP\n");
                    return -ct;
                } else if (ct == oopl && buffer[i] == tab[ct]) { // exited loop with OOP_
                    i++;
                    ct++;
                    if (buffer[i] == tab[ct]) { // exited loop with OOP_T
                        //printf("entering IN_TAB at index %u: %s\n", i, buffer + i - ct);
                        st = IN_TAB;
                        i++;
                        ct++;
                    } else if (buffer[i] == newline[ct]) { // exited loop with OOP_N
                        //printf("entering IN_NL at index %u, %s\n", i, buffer + i - ct);
                        st = IN_NL;
                        i++;
                        ct++;
                    } else if (buffer[i] == '\0') { // buffer ends with OOP_
                        buffer[j] = '\0';
                        return -ct;
                    } else { // no matches up to this point
                        st = IDLE;
                        while (ct) {
                            buffer[j++] = buffer[i-ct--];
                        }
                        if (buffer[i] == oop[ct]) {
                            st = IN_OOP;
                            i++;
                            ct++;
                        }
                    }
                } else { // exited the while loop but only OOP found
                    st = IDLE;
                    while (ct) {
                        buffer[j++] = buffer[i-ct--];
                    }
                    if (buffer[i] == oop[ct]) {
                        st = IN_OOP;
                        i++;
                        ct++;
                    }
                }
                break;
            }
            case IN_TAB: {
                //printf("IN_TAB: %u, %c\n", i, buffer[i]);
                while (buffer[i] != '\0' && ct < tabl && buffer[i] == tab[ct]) {
                    i++;
                    ct++;
                    //printf("IN_TAB: %u, %c\n", i, buffer[i]);
                }
                if (buffer[i] == '\0') {
                    buffer[j] = '\0';
                    //printf("exiting in IN_TAB\n");
                    return -ct;
                } else if (ct == tabl) { // write tab
                    //printf("writing tab\n");
                    WRITE_TAB
                    st = IDLE;
                    ct = 0;
                } else { // exited the while loop but only OOP found
                    st = IDLE;
                    while (ct) {
                        buffer[j++] = buffer[i-ct--];
                    }
                    if (buffer[i] == oop[ct]) {
                        st = IN_OOP;
                        i++;
                        ct++;
                    }
                }
                break;
            }
            case IN_NL: {
                //printf("IN_NL: %u, %c\n", i, buffer[i]);
                while (buffer[i] != '\0' && ct < newlinel && buffer[i] == newline[ct]) {
                    i++;
                    ct++;
                    //printf("IN_NL: %u, %c\n", i, buffer[i]);
                }
                if (buffer[i] == '\0') {
                    buffer[j] = '\0';
                    //printf("exiting in IN_NL\n");
                    return -ct;
                } else if (ct == newlinel) { // write tab
                    //printf("writing newline\n");
                    buffer[j++] = '\n';
                    st = IDLE;
                    ct = 0;
                } else { // exited the while loop but only OOP found
                    st = IDLE;
                    while (ct) {
                        buffer[j++] = buffer[i-ct--];
                    }
                    if (buffer[i] == oop[ct]) {
                        st = IN_OOP;
                        i++;
                        ct++;
                    }
                }
                break;
            }
            default: {
                printf("invalid state in process_buffer\n");
                return 1;
            }
        }
    }
}

int process_file(void) {
    if (!file) {
        return 1;
    }
    unsigned int iread = 0;
    unsigned int iwrite = 0;
    // check for eof first and then fill buffer if able
    while (!ferror(file) && !feof(file) && fgets(buffer, BUFSIZ, file)) {
        iread = ftell(file);
        int status = process_buffer();
        int BufferAtEOF = (fgetc(file) == EOF && status < 0);
        if (status > 0) {
            return status;
        } else if (status <= 0) {
            iread += status;
            //printf("iread = %u, iwrite = %u\n", iread, iwrite);
            fseek(file, iwrite, SEEK_SET);
            //printf("writing buffer %s\n", buffer);
            fputs(buffer, file);
            fflush(file);
            iwrite += strlen(buffer);
            fseek(file, iread, SEEK_SET);
        }
        if (BufferAtEOF) { // write out remainder of file
            fgets(buffer, BUFSIZ, file);
            //printf("writing remaining buffer %s\n", buffer);
            iread = ftell(file);
            fseek(file, iwrite, SEEK_SET);
            fputs(buffer, file);
            fflush(file);
            iwrite += strlen(buffer);
            break;
        }
    }
    iread -= iwrite;
    if (iread) {
        fseek(file, iwrite, SEEK_SET);
        fputc('\n', file);
        while (!ferror(file) && !feof(file) && iread--) {
            fputc(' ', file);
        }
    }
    
    return ferror(file);
}

int main(int narg, char ** args) {
    if (narg > 1) {
        oopl = strlen(oop);
        newlinel = strlen(newline);
        tabl = strlen(tab);
        for (int i = 1; i < narg; i++) {
            printf("replacing OOP_NEWLINE and OOP_TAB in file: %s...", args[i]);
            if ((file = fopen(args[i], FILE_MODE))) {
                if (process_file()) {
                    snprintf(logbuf, BUFSIZ, "Error in processing file %s\n", args[i]);
                    if (ferror(file)) {
                        perror(logbuf);
                    } else {
                        printf("Parser Error - %s\n", logbuf);
                    }
                }
                printf("success!\n");
            } else {
                printf("Failed to open file %s\n", args[i]);
            }
            fclose(file);
            file = NULL;
        }
    }    
    return 0;
}