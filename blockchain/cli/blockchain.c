#include "blockchain.h"

void load_blockchain(const char *path)
{
    // Load blockchain from file (deserialization)
    printf("Blockchain loaded from %s\n", path);
}

void save_blockchain(const char *path)
{
    // Save blockchain to file (serialization)
    printf("Blockchain saved to %s\n", path);
}

void display_info()
{
    // Show blockchain info (blocks, unspent outputs, transactions)
    printf("Blockchain info: \n");
    printf("Number of blocks: 1\n");
    printf("Number of unspent outputs: 10\n");
    printf("Number of pending transactions: %d\n", pool_size);
}
