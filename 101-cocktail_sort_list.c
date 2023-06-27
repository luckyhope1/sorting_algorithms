#include "sort.h"

/**
* swap - swaps two nodes
* @head: head of the list
* @node1: first node to sort
* @node2: second node to sort
*/
void swap(listint_t **head, listint_t *node1, listint_t *node2)
{
listint_t *prev, *next;

prev = node1-&gt;prev;
next = node2-&gt;next;

if (prev != NULL)
prev-&gt;next = node2;
else
*head = node2;

node1-&gt;prev = node2;
node1-&gt;next = next;
node2-&gt;prev = prev;
node2-&gt;next = node1;
if (next)
next-&gt;prev = node1;
}
/**
* cocktail_sort_list - sorts a list using the cocktail sort algorithm
* @list: list to sort
*/
void cocktail_sort_list(listint_t **list)
{
listint_t *head;
int flag = 0;

if (!list || !*list || !(*list)-&gt;next)
return;

do {
for (head = *list; head-&gt;next != NULL; head = head-&gt;next)
{
if (head-&gt;n &gt; head-&gt;next-&gt;n)
{
swap(list, head, head-&gt;next);
print_list(*list);
flag = 1;
head = head-&gt;prev;
}

}
if (flag == 0)
break;
flag = 0;
for (; head-&gt;prev != NULL; head = head-&gt;prev)
{
if (head-&gt;n &lt; head-&gt;prev-&gt;n)
{
swap(list, head-&gt;prev, head);
print_list(*list);
flag = 1;
head = head-&gt;next;
}
}
} while (flag == 1);
}
