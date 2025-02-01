#include "blockchain.h"
#include <openssl/ec.h>
#include <openssl/pem.h>
#include <openssl/err.h>

EC_KEY *wallet = NULL;

int wallet_load(const char *path)
{
    FILE *file = fopen(path, "r");
    if (!file)
    {
        perror("Failed to load wallet");
        return 0;
    }

    wallet = PEM_read_ECPrivateKey(file, NULL, NULL, NULL);
    fclose(file);

    if (!wallet)
    {
        fprintf(stderr, "Error loading wallet: %s\n", ERR_reason_error_string(ERR_get_error()));
        return 0;
    }

    return 1;
}

int wallet_save(const char *path)
{
    if (!wallet)
    {
        fprintf(stderr, "No wallet to save.\n");
        return 0;
    }

    FILE *file = fopen(path, "w");
    if (!file)
    {
        perror("Failed to save wallet");
        return 0;
    }

    if (!PEM_write_ECPrivateKey(file, wallet, NULL, NULL, 0, NULL, NULL))
    {
        fprintf(stderr, "Error saving wallet: %s\n", ERR_reason_error_string(ERR_get_error()));
        fclose(file);
        return 0;
    }

    fclose(file);
    return 1;
}
