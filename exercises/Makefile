# Copyright 2020 Yuxiao Cao
# yuxiao08

# default target
ex9: ex9.o IntPair.o
	g++ -Wall -g -std=c++11 -o ex9 ex9.o IntPair.o 

# individual source files
IntPair.o: IntPair.cc IntPair.h
	g++ -Wall -g -std=c++11 -c IntPair.cc

ex9.o: ex9.cc IntPair.h
	g++ -Wall -g -std=c++11 -c ex9.cc

# phony target - delete built files (including OS X debug files)
clean:
	rm -rf ex9 *.o *~ ex9.dSYM

