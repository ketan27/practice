CC = gcc
CFLAGS = -I -G.

# The object holding directory
OBJ_DIR = obj

# dependent header files, add them here in comma separated form
DEPS = linked_list.h

# location of .o files, future files are going to be added here
_OBJ = single_linked_list.o linked_list.o
OBJ = $(patsubst %, $(OBJ_DIR)/%,$(_OBJ))

# how to create .o files
$(OBJ_DIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# the final output
sll: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ_DIR)/*.o sll
