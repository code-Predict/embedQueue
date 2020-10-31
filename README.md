# embedQueue

## Overview

Generic queue implement written in C.  
**NOTE:** this repository is **minimized edition** for embedded device.  
Some features such multithreading queue is shrinked or abolished.

## Usage

### Generate sample program

 1. clone this repository.
 1. to generate `Queue.dll` and `a.out`(example program), please execute `make`/.

### Embed it to your projects

First, please clone or download this repository and put to your project directory.  
And then, insert `#include`. for example:  

```C
    #include "Queue/Queue.h"

    int main(void){
        // Queue initialize
        Queue queue, *Q;
        Q = &queue;
        initQueue(Q);

        // enQueue
        Item eqItem;
        initItem(&eqItem);
        eqItem.id = 1234;
        enQueue(Q, eqItem);

        while(1){
        }
    }
```

## Licence

All of code in this repository are published under the MIT licence.
