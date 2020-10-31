/*
 * Queue.hをC++に対応させる
*/
#include "Queue.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
    // キュー初期化
    Queue queue, *Q;
    Q = &queue;
    initQueue(Q);

    // 適当なアイテムを追加してenQueue
    char buffer[8] = "enQueue";
    Item item;
    item.id = 12;
    memcpy(item.data, buffer, 8);
    enQueue(Q, item);

    // deQueueして値を読む
    char dumpbuffer[256];
    memset(dumpbuffer, 0, 35);
    Item dequeueItem;
    deQueue(Q, &dequeueItem);
    dumpItem(&dequeueItem, dumpbuffer);

    printf("%s\n", dumpbuffer);

    return 0;
}
