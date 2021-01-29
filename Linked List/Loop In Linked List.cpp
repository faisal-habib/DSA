/*
Resource:
https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/
Problem:
https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#
*/

typedef struct Node
{
    int val;
    struct Node *next;
}LL;

LL *hasLoop(LL *head)  // this function checks whether the list contain any loop using "Floyd’s Cycle-Finding Algorithm "
{
    LL *slowPointer = head, *fastPointer = head;

    while(slowPointer && fastPointer && fastPointer->next)
    {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
        if(slowPointer==fastPointer) return slowPointer;
    }
    return NULL;
}

void removeLoop(LL *head)
{
    LL *loopNode = hasLoop(head);
    if(!loopNode) return ;  // list doesn't contain any loop

    LL *slowPointer, *fastPointer = loopNode;    // slowPointer & fastPointer has met in this node which is within the loop
    slowPointer = head;

    /**
        now we need to go to the last node from where loop started
        if we start moving both pointers at same speed such that one pointer (slowPointer) begins from head
        and other pointer (fastPointer) begins from meeting point, then both pointers will reach at the beginning of loop same time.
    */
    if(slowPointer==fastPointer)    // for case where head node is included in loop and both pointer met here
    {
        while(fastPointer->next!=slowPointer)
        {
            fastPointer = fastPointer->next;
        }
    }
    else
    {
        while(slowPointer->next!=fastPointer->next)
        {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next;
        }
    }
    /*
    now slowPointer & fastPointer both are at the beginning of the loop,
    this is the first node of loop
    */
    fastPointer->next = NULL;  //removing loop
}


/* another approach to remove loop (using hash/map) */
void removeLoop(LL* head)
{
    unordered_map<LL*, bool>mp;
    LL *lastNode = NULL, *curr = head;
    while(curr)
    {
        if(!mp[curr])
        {
            mp[curr] = true;
            lastNode = curr;
            curr = curr->next;
        }
        else
        {
            lastNode->next = NULL;
            break;
        }
    }
}

LL *getFirstNodeOfLoop(LL *head)    // logic is same as remove loop
{
    LL *loopNode = hasLoop(head);
    LL *slowPointer = head, *fastPointer = loopNode;

    if(slowPointer==fastPointer)
    {
        while(fastPointer->next!=slowPointer) fastPointer = fastPointer->next;
    }
    else
    {
        while(slowPointer->next!=fastPointer->next)
        {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next;
        }
    }
    return fastPointer;
}
