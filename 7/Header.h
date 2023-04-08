#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    Node *next;
};

struct Stack
{
    Node *head;

    Stack() {
        head = nullptr;
    }
    ~Stack() {
        clear();
    }

    inline void pushHead(const int _value)
    {
        Node *tmp = (Node *) malloc(sizeof(Node));
        tmp->data = _value;
        tmp->next = head;
        head = tmp;
    }

    inline int eraseHead()
    {
        Node *tmp = head;
        int val = head->data;
        head = head->next;
        free(tmp);
        return val;
    }

    inline int getTop()
    {
        return head->data;
    }

    bool isEmpty()
    {
        if (!head)
            return true;
        return false;
    }
    
    void clear();
};

void Stack::clear()
{
    while (head)
    {
        eraseHead();
    }
}

void printStack(Stack _stack)
{
    Node *tmp = _stack.head;
    printf("[");
    while (tmp->next)
    {
        printf("%d, ", tmp->data);
        tmp = tmp->next;
    }
    printf("%d]", tmp->data);
}