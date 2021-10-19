exec = a.out
sources = $(wildcard src/*.cpp *.cpp)
includes = -Iinclude/
objects = $(sources:.c=.o)
flags = -g -Wall -lm -ldl -fPIC -rdynamic

$(exec): $(objects)
	g++ $(objects) $(includes) $(flags) -o $(exec)

%.o: %.c include/%.h
	g++ -c $(includes) $(flags) $< -o $@

clean:
	-rm *.out
	-rm *.o
	-rm *.a
	-rm src/*.o

lint:
	clang-tidy src/*.cpp include/*.h
