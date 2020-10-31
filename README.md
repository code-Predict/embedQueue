# Queue

## Overview

Generic queue implement written in C.(It supports multi-thread queue using pthread and mutex.)  

## Usage

 1. clone this repository.
 1. `make` to generate `Queue.dll`. (If you only make `Queue.h`, you can use `make Queue.dll`.)

### How to embed it to your projects

If you use queue with single-thread system, you only need include `Queue.h`.  
But, queue will be used with multi-thread system generally. In this case, you need include `QueueThreads.h` additional.  

## Licence

All of code in this repository are published under the MIT licence.
