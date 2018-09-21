CC = gcc
CFLAGS = -I -G. -g

# The object holding directory
OBJ_DIR = obj

# dependent header files, add them here in comma separated form
DEPS = queue.h

# location of .o files, future files are going to be added here
_OBJ = queue.o queue_problems.o
OBJ = $(patsubst %, $(OBJ_DIR)/%,$(_OBJ))

# how to create .o files
$(OBJ_DIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# the final output
queue: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ_DIR)/*.o queue
