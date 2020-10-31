queuePath = -I Queue/ -I DqThread -I QueueThreads
includePath = $(queuePath)

# for C
a.out: main.c Queue.dll QueueThreads.dll
	gcc $(includePath) Queue.dll QueueThreads.dll main.c -pthread

#for C++
cpp: main.cpp Queue.dll 
	gcc $(includePath) Queue.dll main.cpp

QueueThreads.dll: QueueThreads/QueueThreads.h QueueThreads/DqThread.c QueueThreads/EqThread.c
	gcc $(includePath) -c QueueThreads/DqThread.c -pthread
	gcc $(includePath) -c QueueThreads/EqThread.c -pthread
	gcc $(includePath) Queue.dll DqThread.o EqThread.o -fPIC -shared -o QueueThreads.dll -pthread

Queue.dll: Queue/Queue.h Queue/Dump.c Queue/Initializer.c Queue/Operate.c Queue/MTSOperate.c
	gcc $(queuePath) -c Queue/Dump.c 
	gcc $(queuePath) -c Queue/Initializer.c
	gcc $(queuePath) -c Queue/Operate.c -pthread
	gcc $(queuePath) -c Queue/MTSOperate.c -pthread
	gcc Dump.o Initializer.o Operate.o MTSOperate.o -fPIC -shared -o Queue.dll -pthread