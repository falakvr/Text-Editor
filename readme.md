This is an implementation of a Text Editor using a binary search tree. It supports the following operations - 

- text_t * create_text() creates an empty text, whose length is 0.

- int length_text( text_t *txt) returns the number of lines of the current text.

- char * get_line( text_t *txt, int index) gets the line of number index, if such a line exists, and
returns NULL else.

- void append_line( text_t *txt, char * new_line) appends new line as new last line.

- char * set_line( text_t *txt, int index, char * new_line) sets the line of number index, if such
a line exists, to new line, and returns a pointer to the previous line of that number. If no line of
that number exists, it does not change the structure and returns NULL.

- void insert_line( text_t *txt, int index, char * new_line) inserts the line before the line of
number index, if such a line exists, to new line, renumbering all lines after that line. If no such
line exists, it appends new line as new last line.

- char * delete_line( text_t *txt, int index) deletes the line of number index, renumbering all
lines after that line, and returns a pointer to the deleted line.

The text editor is built on top of the basic binary search tree implementation available at -

http://www-cs.ccny.cuny.edu/~peter/dstest/h_bl_tree.c

References - 

http://www-cs.ccny.cuny.edu/~peter/dstest/h_bl_tree.c

Peter Brass: Advanced Data Structures, Cambridge University Press 2008.