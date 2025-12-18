#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1

int ht[100];
int m;


int hash(int key)
{
    return key % m;
}


void insert(int key)
{
    int index = hash(key);
    int startIndex = index;

    while (ht[index] != EMPTY)
    {
        index = (index + 1) % m;

        if (index == startIndex)
        {
            printf("Hash Table is full. Cannot insert %d\n", key);
            return;
        }
    }

    ht[index] = key;
    printf("Key %d inserted at address %d\n", key, index);
}


void display()
{
    int i;
    printf("\nHash Table Contents:\n");
    printf("Address\tKey\n");
    for (i = 0; i < m; i++)
    {
        if (ht[i] == EMPTY)
            printf("%d\t---\n", i);
        else
            printf("%d\t%d\n", i, ht[i]);
    }
}

int main()
{
    int n, key, i;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);


    for (i = 0; i < m; i++)
        ht[i] = EMPTY;

    printf("Enter number of employee records (N): ");
    scanf("%d", &n);

    printf("Enter %d employee keys (4-digit):\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}

