/*
 * キュー 
*/
#include <stdio.h>
#include "Queue.h"

int main(int argc, char const *argv[]) {
    // キュー初期化
    Queue queue, *Q;
    Q = &queue;
    initQueue(Q);

    // enQueue
    Item item;

    int rst = 0, cnt = 0;
    while (rst == QUEUE_OK) {
        initItem(&item);
        item.id = cnt;
        rst = enQueue(Q, item);
        printf("result: %d, e: %d\n", rst, item.id);
        cnt++;
    }
    printf("enQueue: %d\n", cnt);

    cnt = 0;
    rst = 0;
    while (rst == QUEUE_OK) {
        initItem(&item);
        rst = deQueue(Q, &item);
        printf("result: %d, d: %d\n", rst, item.id);
        cnt++;
    }
    printf("deQueue: %d\n", cnt);
    
    deinitQueue(Q);
    return 0;
}
