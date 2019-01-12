#include <atomic>

class Stack
{
  public:
    ~Stack();

    bool Pop(int &);
    void Push(int);

  private:
    struct Node
    {
        int data;
        Node *next;

        Node() {}
        Node(int d) : data(d) {}
    };

    std::atomic<Node *> head_;
};