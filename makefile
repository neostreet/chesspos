chesspos: chesspos.o posmsc.o posrd.o bitfuns.o chesspos.res
	g++ -mwindows -g -L"/cygdrive/c/Program Files (x86)/Windows Kits/8.0/Lib/win8/um/x86" -o chesspos chesspos.o posmsc.o posrd.o bitfuns.o chesspos.res -lGdi32 -lcurses -lComDlg32 -lComCtl32

chesspos.o: chesspos.c
	g++ -g -O0 -c -I./common chesspos.c

posmsc.o: ./common/posmsc.c
	g++ -g -O0 -c -I./common ./common/posmsc.c

posrd.o: ./common/posrd.c
	g++ -g -O0 -c -I./common ./common/posrd.c

bitfuns.o: ./common/bitfuns.c
	g++ -g -O0 -c -I./common ./common/bitfuns.c

chesspos.res: ./common/chesspos.rc
	windres ./common/chesspos.rc -O coff -o chesspos.res

clean:
	rm *.o *.res *.exe
