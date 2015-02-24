//  http://danluu.com/malloc-tutorial/
#include <stdio.h>
void* my_malloc(size_t size);
void free(void*);
struct block {
    size_t size;
    int free;
    struct block *next;
    int debug;
};

block *head = NULL;
block *tail = NULL;

struct block* allocate_space(size_t size) {
    struct block *current = sbrk(0);
    void *request = brk(block,size+sizeof(struct block));
    if (request == (void *)-1) {
        return NULL;
    }
    if (tail) {
        tail->next = current;
        tail = tail->next;
    } else {
        tail = current;
    }
    return current;
}


void *find_free_block(block *head, size_t size) {
    block *current = head;
    if (head == NULL) {
        return NULL;
    }
    while (current && current->free == 1 && current->size < size) {
        current = current->next;
    }
    return current;
}

void* my_malloc(size_t size) {
    if (size == 0) {
        return NULL;
    }
    block *request;
    if(head == NULL) {
        head = allocate_space(size);
        if (head == NULL) {
            return NULL;
        }
        request = head;
    } else {
        request = find_free_block(head,size);
        if (!request) {
            request = allocate_space(size);
            if (!request) {
                return NULL;
            }
        } else {
            request->free = 0;
            request->size = size;
        }
    }
    return (request+1);
}

void *my_realloc(void *ptr, size_t size) {
    if(!ptr) {
        return NULL;
    }
    block *current = virtualToBlock(ptr);
    if (current->size >= size) {
        return ptr;
    }

    void *newPtr = my_malloc(size);
    if (!newPtr) {
        return NULL;
    }
    memcpy(newPtr,ptr,size);
    free(ptr);
    return newPtr;
}

void *my_calloc(size_t nelem, size_t elsize) {
    size_t size = nelem*elsize;
    void *ptr = malloc(size);
    memset(ptr,0,size);
    return ptr;
}

block *virtualToBlock(void *ptr) {
    block *current = (block*)ptr;
    return current-1;
}

void free(void *ptr) {
    if (!ptr) {
        return;
    }
    block *current = virtualToBlock(ptr);
    assert(current->free == 0);
    current->free = 1;
}

main() {
}
    
