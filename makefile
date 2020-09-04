queuePath = -I Queue/
includePath = $(queuePath)

a.out: main.c Queue.dll
	gcc $(includePath) Queue.dll main.c

Queue.dll: Queue/Queue.h Queue/Dump.c Queue/Initializer.c Queue/Operate.c
	gcc $(queuePath) -c Queue/Dump.c 
	gcc $(queuePath) -c Queue/Initializer.c
	gcc $(queuePath) -c Queue/Operate.c
	gcc Dump.o Initializer.o Operate.o -fPIC -shared -o Queue.dll