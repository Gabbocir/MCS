CC          = g++ 
CFLAGS      = --std=c++11 -g -Wall 
CFLAGSROOT  = `root-config --cflags`
LIBSROOT    = `root-config --glibs`

all: Main

Complex.o: Complex.cpp 
	$(CC) $(CFLAGS) -c Complex.cpp $(CFLAGSROOT)

Main: Main.cpp Complex.o
	$(CC) $(CFLAGS) -o Main Main.cpp Complex.o  $(CFLAGSROOT) $(LIBSROOT)

clean:
	rm *.o


