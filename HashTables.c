#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

//----------HASHTABLE-------------//
#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct
{
    char name[MAX_NAME];
    int age;
    //.. add other stuff later here..
} person;

person *hash_table[TABLE_SIZE];

void init_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

void print_table()
{
    printf("Start\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t%i\t---\n", i);
        }
        else
        {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("End\n");
}

unsigned int hash(char *name)
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

bool hash_table_insert(person *p)
{
    if (p == NULL)
        return false;
    int index = hash(p->name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL)
        {
            hash_table[try] = p;
            return true;
        }
    }
    return false;
}

person *hash_table_lookup(char *name)
{
    int index = hash(name);
    if (hash_table[index] != NULL && strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0)
    {
        return hash_table[index];
    }
    else
    {
        return NULL;
    }
}

person *hash_table_delete(char *name)
{
    int index = hash(name);
    if (hash_table[index] != NULL && strncmp(hash_table[index], name, TABLE_SIZE) == 0)
    {
        person *tmp = hash_table[index];
        hash_table[index] = NULL;
        return tmp;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    init_hash_table();
    //print_table();
    printf("\n\n");
    person jacob = {.name = "Jacob", .age = 26};
    person kate = {.name = "Kate", .age = 27};
    person tancred = {.name = "Tancred", .age = 14};
    person mpho = {.name = "Mpho", .age = 21};
    person farida = {.name = "Farida", .age = 23};
    person eusuf = {.name = "Eusuf", .age = 25};
    person ehsaan = {.name = "Ehsaan", .age = 10};
    person shamshuddin = {.name = "Shamshuddin", .age = 30};
    person rohit = {.name = "Rohit", .age = 24};
    person danish = {.name = "Danish", .age = 20};
    person sabika = {.name = "Sabika", .age = 21};
    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&tancred);
    hash_table_insert(&mpho);
    hash_table_insert(&farida);
    hash_table_insert(&ehsaan);
    hash_table_insert(&eusuf);
    hash_table_insert(&rohit);
    hash_table_insert(&danish);
    hash_table_insert(&sabika);

    print_table();

    person *tmp = hash_table_lookup("Mpho");
    if (tmp == NULL)
    {
        printf("Not Found!\n");
    }
    else
    {
        printf("Found %s.\n", tmp->name);
    }
    person *tmp2 = hash_table_delete("Mpho");
    if (tmp2 == NULL)
    {
        printf("Not Found!\n");
    }
    else
    {
        printf("Deleting %s.\n", tmp2->name);
        free(tmp2);
    }
    hash_table_insert(&shamshuddin);
    print_table();
    return -1;
}