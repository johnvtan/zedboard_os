#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stddef.h>
#include <kernel/os_config.h>

template <typename T>
class QueueNode {
public:
    T *node;
    QueueNode<T> *next;
};

template <typename T>
class Queue {
public:
    Queue(void) {
        head = NULL;
        tail = NULL;
        len = 0;
    };

    ~Queue(void) {

    };

    T *pop(void) {
        if (head == NULL) {
            return NULL;
        }
        QueueNode<T> *rv = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        rv->next = NULL;
        len--;
        return rv->node;
    };

    void push(QueueNode<T> *node) {
        if (head == NULL && tail == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        len++;
    };

    int get_len(void) {
        return len;
    };
private:
    QueueNode<T> *head;
    QueueNode<T> *tail;
    int len;
};


template <typename T, typename P>
class PriorityQueueNode {
public:
    T *node;
    P priority;
};

// PQ is implemented as an array min-heap, where the array is the size of MAX_NUM_TASKS, as defined in kernel/os_config.h
template <typename T, typename P>
class PriorityQueue {
public:
    PriorityQueue(void) {
        len = 0;
    };  

    ~PriorityQueue(void) {

    };

    T *pop() {
        if (len <= 0) {
            return NULL;
        }
        if (len == 1) {
            --len;
            return min_heap[0].node; 
        }

        T *rv = min_heap[0].node;
        min_heap[0] = min_heap[len-1];
        --len;
        min_heapify(0);
        return rv;
    };

    void push(T *node, P priority) {
        ++len;
        int i = len - 1;
        min_heap[i].node = node;
        min_heap[i].priority = priority;

        while (i != 0 && min_heap[parent(i)].priority > min_heap[i].priority) {
            swap(i, parent(i));
            i = parent(i);
        }
    };

    P peek_prio(void) {
        if (len == 0) {
            return 0;
        }
        return min_heap[0].priority;
    }

private:
    // helper functions
    void swap(int i, int j) {
        PriorityQueueNode<T, P> temp = min_heap[i];
        min_heap[i] = min_heap[j];
        min_heap[j] = temp;
    };

    int parent(int i) {
        return (i - 1) / 2;
    };

    int left_idx(int i) {
        return (2*i + 1);
    };

    int right_idx(int i) {
        return (2*i + 2);
    };

    void min_heapify(int i) {
        int left = left_idx(i);
        int right = right_idx(i);
        int smallest = i;
        if (left < len && min_heap[left].priority < min_heap[i].priority) {
            smallest = left;
        }
        if (right < len && min_heap[right].priority < min_heap[smallest].priority) {
            smallest = right;
        }
        if (smallest != i) {
            swap(i, smallest);
            min_heapify(smallest);
        }
    };

    PriorityQueueNode<T, P> min_heap[MAX_NUM_TASKS]; 
    int len;
};
#endif
