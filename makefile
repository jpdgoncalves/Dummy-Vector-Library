
LIB_NAME = libmvector.a
LIBS = build/$(LIB_NAME) -lm
FLAGS = -Wall -std=c99

SRC_FOLDER = src/
BUILD_FOLDER = build/
TEST_FOLDER = test/


clean:
	rm -f $(TEST_FOLDER)demo.out
	rm -f $(BUILD_FOLDER)*.o
	rm -f $(BUILD_FOLDER)$(LIB_NAME)
	rm -f $(BUILD_FOLDER)mvector.h


compile:
	cd build && gcc $(FLAGS) -c ../$(SRC_FOLDER)*.c


build: compile
	cd build && ar -vq libmvector.a *.o
	cp $(SRC_FOLDER)mvector.h build


demo: build
	gcc $(FLAGS) -o $(TEST_FOLDER)demo.out $(TEST_FOLDER)demo.c $(BUILD_FOLDER)/mvector.h $(LIBS)


test: demo
	./$(TEST_FOLDER)demo.out


all: build test