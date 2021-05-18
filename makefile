CC = g++
SEMFLAG = -lpthread

exec.out: Source.cpp
	$(CC) Source.cpp $(SEMFLAG)

