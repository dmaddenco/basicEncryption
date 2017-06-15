CC	=	g++
FILES	=	*.cpp
OTHER	=	*.h makefile README
OUT_EXE	=	PA1
FLAGS	=	-I. -Wall -std=c++11 -g -o
PA1: $(FILES)
	$(CC) $(FLAGS) $(OUT_EXE) $(FILES)
clean:
	rm -rf cmake-build-debug/ .idea/ $(OUT_EXE).dSYM/ *.o $(OUT_EXE) $(OUT_EXE).tar
tar:
	tar cvf $(OUT_EXE).tar $(FILES) $(OTHER)
