#include "mystack.h"

/**
empty() 堆栈为空则返回真

pop() 移除栈顶元素

push() 在栈顶增加元素

size() 返回栈中元素数目

top() 返回栈顶元素
 */


/**
STL 中的 stack 是一种容器适配器，而不是一种容器。

它是容器适配器是指，只要支持一系列方法的容器(empty, size, back, push_back, pop_back)，都能作为stack使用。

stack 有可能实际上是一个 vector, deque 或 list. 如果没有特殊指明，将使用 deque作为stack的实际容器。

构造函数

构造函数中包含两个模板参数。stack<stack::alue_type T, stack::container_type Container>

其中 T代表数值类型，可以是基本数据类型或用户自定义类型。

Container代表容器类型，可以是 vector, deque 或 list

 View Code
成员函数

empty()

 测试栈是否为空，为空返回true，否则返回false。

 bool empty() const;

size()

 返回栈中元素的个数

 size_type size() const;

top()

 返回栈顶元素(最后push进来的那个)的引用。

 referenc& top();

push(val)

 压一个值到栈中，其值将被初始化为 val

 void push(const value_type& val);

pop()

 将栈顶元素弹出，注意这个函数无返回值，如果需要获取栈顶元素，应先调用top()，再pop()

 void pop();

emplace(Args..)

 emplace 功能上与 push相同。不过emplace更高效。

 emplace 的参数不是容器元素本身，而是构造容器元素所需要的参数。即如果容器元素是一个类的对象，那么Args就是这个类构造函数的参数。

 push 是先构造一个 temporary 的元素对象，再将这个对象拷贝到容器中。而emplace是直接在容器内用参数构造一个对象。省略了拷贝的时间消耗。

 emplace 本质上是调用了各容器的 emplace_back(args...)函数

swap()

 swap将两个 stack的内容交换。这两个 stack的模板参数 T和 Container必须都相同。

 void swap(stack& x)　重载1：x.swap(y)

 void swap(stack& x, stack& y)  重载2: swap(x, y)

关系运算符

 取决于实际容器的关系运算符
 */

MyStack::MyStack()
{

}

// 栈的使用
void conversion1(int x, int i) {
    stack<int> m_stack;
    while(x != 0) {
        m_stack.push(x % i);
        x /= i;
    }
    while(!m_stack.empty()) {
        std::cout << m_stack.top();
        m_stack.pop();
    }
    std::cout << '\n';
}

// 队列的使用
void conversion2(int x, int i) {
    queue<int> m_queue;
    while(x != 0) {
        m_queue.push(x % i);
        x /= i;
    }
    while(!m_queue.empty()) {
        std::cout << m_queue.front();
        m_queue.pop();
    }
    std::cout << '\n';
}

int match(string str) {
    int len = str.length();
    const char *s = str.c_str();
    stack<char> stackChar;
    for(int i=0; i<len; i++) {
        char ch = s[i];
        switch (ch) {
        case '}':
            if(!stackChar.empty() && stackChar.top() == '{') {
                stackChar.pop();
            }else {
                return 1;
            }
            break;
        case ']':
            if(!stackChar.empty() && stackChar.top() == '[') {
                stackChar.pop();
            }else {
                return 1;
            }
            break;
        case ')':
            if(!stackChar.empty() && stackChar.top() == '(') {
                stackChar.pop();
            }else {
                return 1;
            }
            break;
        case '[':
            stackChar.push(ch);
            break;
        case '{':
            stackChar.push(ch);
            break;
        case '(':
            stackChar.push(ch);
            break;
        default:
            break;
        }
    }
    return 0;
}

int lh::stack_init(lh::stack_t *s, int size)
{
    s->top = 0;
    s->array = (item_t *)calloc(size, sizeof(item_t));
    if(s->array != NULL) {
        s->size = size;
        return 1;
    }else {
        s->size  = 0;
        fprintf(stderr, "Stack init fail.\n");
        return 0;
    }
}

int lh::stack_resize(lh::stack_t *s, int size)
{
    s->array = (item_t *)realloc(s->array, size * sizeof(item_t));
    if(s->array != NULL) {
        s->size = size;
        if(s->top > s->size) {
            s->top = s->size;
        }
        return 1;
    }else {
        s->size  = 0;
        s->top = 0;
        fprintf(stderr, "Stack resize fail.\n");
        return 0;
    }
}

int lh::stack_free(lh::stack_t *s)
{
    free(s->array);
    s->array = NULL;
    s->top = 0;
    s->size = 0;
    return 1;
}

int lh::stack_empty(lh::stack_t *s)
{
    if(s->array == NULL) {
        fprintf(stderr, "Stack is not initialized.\n");
        return 1;
    }
    if(s->top == 0) {
        return 1;
    }else {
        return 0;
    }
}

int lh::stack_push(lh::stack_t *s, lh::item_t item)
{
    if(s->array == NULL) {
        fprintf(stderr, "Stack is not initialized.\n");
        return 0;
    }
    if(s->top < s->size) {
        s->array[s->top++] = item;
        return 1;
    }else {
        fprintf(stderr, "Stack overflow.\n");
        return 0;
    }
}

int lh::stack_pop(lh::stack_t *s, lh::item_t *item)
{
    if(s->array == NULL) {
        fprintf(stderr, "Stack is not initialized.\n");
        return 0;
    }
    if(!stack_empty(s)) {
        *item = s->array[--s->top];
        return 1;
    }else {
        fprintf(stderr, "Stack underflow.\n");
        return 0;
    }
}

void lh::stack_info(lh::stack_t *s)
{
//    static int count = 0;
//    printf("%d:\n", count++);
    if(s->array == NULL) {
        fprintf(stderr, "Stack is not initialized.\n");
        return ;
    }
    printf("stack top:%d\n", s->top);
    printf("stack size:%d\n", s->size);
    printf("stack element:");
    for(int i=s->top - 1; i>=0; i--) {
        printf("%d ", s->array[i].key);
    }
}


void lh::stackTest1()
{
    stack_t myStack_t;
    item_t item;

    stack_init(&myStack_t, 10);
    for(int i=0; i<8; i++) {
        item.key = i;
        stack_push(&myStack_t, item);
    }

    stack_pop(&myStack_t, &item);

    printf("key = %d\n", item.key);

    stack_info(&myStack_t);

    stack_free(&myStack_t);

}

int lh::stack_push1(lh::stack_t1 *s, int num)
{
    if(s->top < 10) {
        s->array[s->top++] = num;
        return 1;
    }else {
        fprintf(stderr, "Stack overflow.\n");
        return 0;
    }
}

int lh::stack_pop1(lh::stack_t1 *s, int *num)
{
    if(s->top > 0) {
        *num = s->array[--s->top];
        return 1;
    }else {
        fprintf(stderr, "Stack underflow.\n");
        return 0;
    }
}

void lh::stack_info1(lh::stack_t1 *s)
{
    for(int i=s->top - 1; i>=0; i--) {
        printf("%d ", s->array[i]);
    }
}

void lh::stackTest2()
{
    stack_t1 myStack_t;
    int item;


    for(int i=0; i<8; i++) {
        item = i;
        stack_push1(&myStack_t, item);
    }

    stack_pop1(&myStack_t, &item);

    printf("key = %d\n", item);

    stack_info1(&myStack_t);

}
