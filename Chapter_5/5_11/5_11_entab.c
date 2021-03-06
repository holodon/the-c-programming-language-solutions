/*
Exercise 5-11. Modify the program entab and detab (written as exercises in
Chapter 1) to accept a list of tab stops as arguments. Use the default tab
settings if there are no arguments.

entab - build upon 1_21

when testing do not forget to set your ide's tab width settings properly!
*/

#include <stdio.h>
#include <ctype.h>  // for isdigit()
#include <stdlib.h> // for atoi()

int main(int argc, char *argv[])
{
    int deftab = 8; // default tab size [0..7]
    int currtab = deftab;

    int c;
    int col = 0;    // column counter
    int sp = 0;     // space counter
    int arg = 1;    // argument counter


    while((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar(c);
            col = 0;
            arg = 1;
            sp = 0;                         // also remove trailing spaces
        } else if (c == ' ') {              // space
            sp++;
            if ((col + sp) % currtab == 0) {// tab possible?
                putchar('\t');
                sp = 0;
                col = 0;

                // get next tab
                if ((arg < argc) && ((currtab = atoi(argv[arg])) > 0) )
                    ;
                else
                    currtab = deftab;
                arg++;

            }

        } else {                            // everything else
            while (sp) {                    // print buffered spaces if any
                //putchar('_');             // for testing
                putchar(' ');
                col++;
                sp--;
            }
            putchar(c);                     // default print char
            col++;
        }
    }

    return 0;
}
