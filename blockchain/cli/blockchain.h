#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>  // for OpenSSL crypto functions

// Wallet functions
int wallet_load(const char *path);
int wallet_save(const char *path);

// Transaction functions
int send_transaction(int amount, const char *address);
void list_transactions();

// Mining functions
void mine_block();

// Blockchain functions
void load_blockchain(const char *path);
void save_blockchain(const char *path);
void display_info();

#endif // BLOCKCHAIN_H
