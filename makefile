INCLUDES = -I src/ -I thirdparty/
dirs = bin obj

all: ./bin/main ./bin/test testq

./bin/main: $(dirs) ./obj/main.o ./obj/root.o
	gcc -o ./bin/main ./obj/main.o ./obj/root.o -Wall -lm

./bin/test: $(dirs) ./obj/main_test.o ./obj/root_test.o
	gcc -o ./bin/test ./obj/main_test.o ./obj/root.o ./obj/root_test.o -Wall -lm

testq:
	./bin/test
	
$(dirs):
	mkdir obj
	mkdir bin

./obj/main.o: ./src/main.c
	gcc -c ./src/main.c -Wall -o ./obj/main.o $(INCLUDES)

./obj/root.o: ./src/root.c
	gcc -c ./src/root.c -Wall -o ./obj/root.o $(INCLUDES)

./obj/main_test.o: ./test/main.c
	gcc -c test/main.c -Wall -o ./obj/main_test.o $(INCLUDES)

./obj/root_test.o: ./test/root_test.c
	gcc -c test/root_test.c -Wall -o ./obj/root_test.o $(INCLUDES)

.PHONY: clean
clean:
	rm -f -r bin/ obj/
