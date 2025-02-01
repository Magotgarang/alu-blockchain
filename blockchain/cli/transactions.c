#include "blockchain.h"

typedef struct transaction
{
    int amount;
    char receiver[66];  // EC public key in hex
} transaction_t;

transaction_t transaction_pool[100];
int pool_size = 0;

int send_transaction(int amount, const char *address)
{
    if (pool_size >= 100)
    {
        fprintf(stderr, "Transaction pool is full\n");
        return 0;
    }

    transaction_t tx = {amount};
    strncpy(tx.receiver, address, sizeof(tx.receiver) - 1);
    transaction_pool[pool_size++] = tx;
    return 1;
}

void list_transactions()
{
    for (int i = 0; i < pool_size; i++)
    {
        printf("Transaction %d: %d coins to %s\n", i, transaction_pool[i].amount, transaction_pool[i].receiver);
    }
}
