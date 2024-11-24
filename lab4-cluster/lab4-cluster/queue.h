#pragma once
#include "stack.h"


template <class T>
class Queue
{   
    Stack<T> LeftStack, RightStack;
    void Transfer()
    {
        while (!LeftStack.Empty())
        {
            RightStack.Push(LeftStack.Top());
            LeftStack.Pop();
        }
    }
public:
    Queue(int size = MaxStackSize): LeftStack(size), RightStack(size) {}

    Queue(const Queue&) = delete;
    Queue(Queue&&) = delete;
    Queue& operator=(const Queue&) = delete;
    Queue& operator=(Queue&&) = delete;

    bool Empty() const
    {
        return (LeftStack.Empty() && RightStack.Empty());
    }
    
    bool Full() const
    {
        return (LeftStack.Full() || RightStack.Full());
    }

    int Size() const
    {
        return LeftStack.Size() + RightStack.Size();
    }

    void Push(const T& element)
    {
        if (Full())
            throw "Queue is full";
        LeftStack.Push(element);
    }

    void Pop()
    {
        if (RightStack.Empty())
        {
            if (LeftStack.Empty())
                throw "Queue is empty";
            Transfer();
        }
        RightStack.Pop();
    }

    T Top()
    {
        if (RightStack.Empty())
        {
            if (LeftStack.Empty())
                throw "Queue is empty";
            Transfer();
        }
        return RightStack.Top();
    }
};