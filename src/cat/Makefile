CC= gcc -std=gnu11
CFLAGS= -Wall -Werror -Wextra
OS=$(shell uname)

ifeq ($(OS),Darwin)
	LIBS=-lcheck -lm -lpthread
else
	LIBS=-lcheck -lm -lpthread -lrt -lsubunit
endif

SRC_DIR= cat
OBJ_DIR= cat_obj

all: s21_cat

s21_cat: $(OBJ_DIR)/Cat.o $(OBJ_DIR)/Flags_selection.o  $(OBJ_DIR)/Working_with_files.o $(OBJ_DIR)/Error_Processing.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/Cat.o: Cat.c  Cat.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/Flags_selection.o: Flags_selection.c Flags_selection.h | $(OBJ_DIR)
	$(CC) $(CFLAGS)  -c -o $@ $<

$(OBJ_DIR)/Working_with_files.o: Working_with_files.c Working_with_files.h | $(OBJ_DIR)
	$(CC) $(CFLAGS)  -c -o $@ $<

$(OBJ_DIR)/Error_Processing.o: Error_Processing.c Error_Processing.h | $(OBJ_DIR)
	$(CC) $(CFLAGS)  -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

test:
	sh tests/test.sh

check:
	cp ../../materials/linters/.clang-format ../../.clang-format
	@clang-format -i *.c *.h
	clang-format -n *.c *.h
	rm -rf ../../.clang-format

clean:
	rm -rf $(OBJ_DIR)/*.o s21_cat log.txt

rebuild: clean all