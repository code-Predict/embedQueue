queuePath = -I Queue/ -I DqThread -I Threads
includePath = $(queuePath)

a.out: main.c Queue.dll Threads.dll
	gcc $(includePath) Queue.dll Threads.dll main.c -pthread

Threads.dll: Threads/Threads.h Threads/DqThread.c Threads/EqThread.c
	gcc $(includePath) -c Threads/DqThread.c -pthread
	gcc $(includePath) -c Threads/EqThread.c -pthread
	gcc $(includePath) Queue.dll DqThread.o EqThread.o -fPIC -shared -o Threads.dll -pthread

Queue.dll: Queue/Queue.h Queue/Dump.c Queue/Initializer.c Queue/Operate.c Queue/MTSOperate.c
	gcc $(queuePath) -c Queue/Dump.c 
	gcc $(queuePath) -c Queue/Initializer.c
	gcc $(queuePath) -c Queue/Operate.c -pthread
	gcc $(queuePath) -c Queue/MTSOperate.c -pthread
	gcc Dump.o Initializer.o Operate.o MTSOperate.o -fPIC -shared -o Queue.dll -pthread