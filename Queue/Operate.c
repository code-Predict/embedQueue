/*
 * 処理
*/
#include "Queue.h"

int enQueue(Queue* queue, Item item){
    int *tail = &(queue->tail);
    int *head = &(queue->head);

    // tailの次=head -> 満杯
    if(((*tail) + 1) % (QUEUE_SIZE + 1) == *head){
        return QUEUE_FULL;
    }

    // 末尾に追加し、ポインタを進める 配列の終端にきたら先頭に戻る
    queue->data[*tail] = item;
    (*tail)++;
    if(*tail > QUEUE_SIZE){
        *tail = 0;
    }
    queue->length++;
    return QUEUE_OK;
}

int deQueue(Queue* queue, Item* item){
    int *tail = &(queue->tail);
    int *head = &(queue->head);

    // head==tail -> キューは空
    if(*head == *tail){
        return QUEUE_EMPTY;
    }

    // 先頭から取り出し、ポインタを進める 配列の終端にきたら先頭に戻る
    *item = queue->data[*head];
    (*head)++;
    if(*head > QUEUE_SIZE){
        *head = 0;
    }
    queue->length--;
    return QUEUE_OK;
}