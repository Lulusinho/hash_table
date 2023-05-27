/*
    I'm going to use chaing for the colision treatment,
    and make a more generic hash table using void*.
*/

/*
to do list:
    hash function; *
    hash inserting *
    hash treatment *
    hash search

*/

#include <stdio.h>
#include <stdlib.h>
#define sizeh 10

// struct for storing each data and implementing chaining
struct node
{
    int data;
    struct node *next;

} typedef node;

struct hash_T
{
    node *array[sizeh];
    int quantity;
}typedef hash_table;

// This hash function is used only to give a example, It's generic and is going to cause a lot of colision
void hashinicialize(hash_table **hash);
int hashfunction(int object);
node *allocnode(int object);
void insert_hash(hash_table **hash_t, int object);
node *hashsearch(hash_table **hash, int input);


void hashinicialize(hash_table **hash)
{
    for (int i = 0; i < sizeh; i++)
        (*hash)->array[i] = NULL;
    (*hash)->quantity = 0;
}

int hashfunction(int object)
{

    int value = object % sizeh;

    return value;
}

node *allocnode(int object)
{
    node *item = (node *)malloc(sizeof(node));

    item->data = object;
    item->next = NULL;
    return item;
}

void insert_hash(hash_table **hash_t, int object)
{
    int key = hashfunction(object);
    node *item = allocnode(object);

    if ((*hash_t)->array[key] = NULL)
    {
        (*hash_t)->array[key] = item;
    }
    else
    {
        node *aux = (*hash_t)->array[key];
        while (aux->next != NULL)
            aux = aux->next;
        aux->next = item;
    }
    (*hash_t)->quantity++;
}

node *hashsearch(hash_table **hash, int input){

    int key = hashfunction(input);
    node *object = (*hash)->array[key];

    while (object->data != input && object != NULL)
    {
        object = object->next;
    }
    if (object->data == input)
        return object;
    else
        printf("[ERROR] invalid input");
}