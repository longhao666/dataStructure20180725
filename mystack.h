#ifndef MYSTACK_H
#define MYSTACK_H


#include <stack>
#include <iostream>
#include <queue>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using std::queue;
using std::stack;
using std::cout;
using std::endl;
using std::string;

namespace lh {

typedef struct ITEM {
    int key;
    void *statellite;
}item_t;

typedef struct STACK {
    int top;
    int size;
    item_t *array;
}stack_t;

typedef struct STACK1 {
    int top = 0;
    int array[10] = {0};
}stack_t1;

int stack_init(stack_t *s, int size);
int stack_resize(stack_t *s, int size);
int stack_free(stack_t *s);
int stack_empty(stack_t *s);
int stack_push(stack_t *s, item_t item);
int stack_pop(stack_t *s,item_t *item);
void stack_info(stack_t *s);


int stack_push1(stack_t1 *s, int num);
int stack_pop1(stack_t1 *s,int *num);
void stack_info1(stack_t1 *s);

void stackTest1();
void stackTest2();


}
// 进制转换
void conversion1(int x, int i);

//
void conversion2(int x, int i);

// 括号检测
int match(string str);





class MyStack
{
public:
    MyStack();
};

#endif // MYSTACK_H
