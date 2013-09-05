/**
 *	single list,单链表删除的优化的思想！
 */

/**
 * 方法的思想是：链表中每一个元素都有一个指针指向，那么可以使用一个二级指针来遍
 * 历每一个元素，可以"非常自然流畅"的完成删除工作，避免了条件判断和prev指针。
 *
 * 	通常 单链表，遍历删除，如下:
 */
typedef struct node
{
    struct node * next;
    ....
} node;

typedef bool (* remove_fn)(node const * v);

// Remove all nodes from the supplied list for which the
// supplied remove function returns true.
// Returns the new head of the list.
node * remove_if(node * head, remove_fn rm)
{
    for (node * prev = NULL, * curr = head; curr != NULL; ) {
        node * next = curr->next;
        if (rm(curr)) {
            if (prev)
                prev->next = curr->next;
            else
                head = curr->next;
            free(curr);
        }  else
            prev = curr;
        curr = next;
    }
    return head;  	/* head = remove_if(...) */
}

/**
 * Two star programming：
 */
void remove_if(node ** head, remove_fn rm)
{
    for (node** curr = head; *curr; ) {
        node * entry = *curr;
        if (rm(entry)) {
            *curr = entry->next;
            free(entry);
        } else
            curr = &entry->next;
    }
}
