

#ifndef __DOUBLE_LINKED_LIST_H
#define __DOUBLE_LINKED_LIST_H

struct list_head {
    struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
    struct list_head name = LIST_HEAD_INIT(name)

/*
 * Insert a new entry between two known consecutive entries.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */

static inline void
__list_add(struct list_head *n,
        struct list_head *prev,
        struct list_head *next)
{
    next->prev = n;
    n->next = next;
    n->prev = prev;
    prev->next = n;
}



static inline void
__list_del(struct list_head *prev, struct list_head *next)
{
    next->prev = prev;
    prev->next = next;
}

static inline void
__list_splice(struct list_head *list, struct list_head *head)
{
    struct list_head *first = list->next;
    struct list_head *last  = list->prev;
    struct list_head *at = head->next;

    first->prev = head;
    head->next = first;

    last->next = at;
    at->prev = last;
}
/**
 * list_add - add a new entry
 * @new: new entry to be added
 * @head: list head to add it after
 *
 * Insert a new entry after the specified haed
 * This is useful for implementing queues.
 */



#endif


