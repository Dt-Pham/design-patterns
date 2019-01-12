#include "stack.h"

Stack::~Stack()
{
    while (head_)
    {
        Node *next = head_.load()->next;
        delete head_.load();
        head_ = next;
    }
}

void Stack::Push(int x)
{
    Node *new_head = new Node(x);
    do
    {
        new_head->next = head_;
    } while (!head_.compare_exchange_strong(new_head->next, new_head));
}

bool Stack::Pop(int &value)
{
    Node *current = head_;
    while (current)
    {
        if (head_.compare_exchange_strong(current, current->next))
        {
            value = current->data;
            delete current;
            return true;
        }
    }
    return false;
}