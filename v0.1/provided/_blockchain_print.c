#include <stdio.h>
#include <string.h>

#include "blockchain.h"

/**
 * print_hex_data - Display a buffer as hexadecimal values
 *
 * @buffer: Pointer to the buffer to be displayed
 * @length: Number of bytes from @buffer to display
 */
static void print_hex_data(uint8_t const *buffer, size_t length)
{
    size_t idx;

    for (idx = 0; buffer && idx < length; idx++)
        printf("%02x", buffer[idx]);

    fflush(NULL);
}

/**
 * print_block_info - Display detailed information about a Block
 *
 * @blk:    Pointer to the Block being displayed
 * @pos:    Position of the Block in the chain
 * @prefix: Prefix for each line
 *
 * Return: FOREACH_CONTINUE
 */
static int print_block_info(block_t const *blk, unsigned int pos, char const *prefix)
{
    if (!blk)
    {
        printf("%snull\n", prefix);
        return (0);
    }

    printf("%sBlock: {\n", prefix);

    printf("%s    metadata: {\n", prefix);
    printf("%s        index: %u,\n", prefix, blk->info.index);
    printf("%s        difficulty: %u,\n", prefix, blk->info.difficulty);
    printf("%s        timestamp: %lu,\n", prefix, blk->info.timestamp);
    printf("%s        nonce: %lu,\n", prefix, blk->info.nonce);
    printf("%s        prev_hash: ", prefix);
    print_hex_data(blk->info.prev_hash, SHA256_DIGEST_LENGTH);
    printf("\n%s    },\n", prefix);

    printf("%s    content: {\n", prefix);
    printf("%s        text: \"%s\",\n", prefix, blk->data.buffer);
    printf("%s        length: %u\n", prefix, blk->data.len);
    printf("%s    },\n", prefix);

    printf("%s    hash: ", prefix);
    print_hex_data(blk->hash, SHA256_DIGEST_LENGTH);

    printf("\n%s}\n", prefix);

    (void)pos;
    return (0);
}

/**
 * print_block_summary - Display summarized information about a Block
 *
 * @blk:    Pointer to the Block being summarized
 * @pos:    Position of the Block in the chain
 * @prefix: Prefix for each line
 *
 * Return: FOREACH_CONTINUE
 */
static int print_block_summary(block_t const *blk, unsigned int pos, char const *prefix)
{
    if (!blk)
    {
        printf("%snull\n", prefix);
        return (0);
    }

    printf("%sBlock: {\n", prefix);

    printf("%s    metadata: { %u, %u, %lu, %lu, ", prefix,
           blk->info.index, blk->info.difficulty, blk->info.timestamp, blk->info.nonce);
    print_hex_data(blk->info.prev_hash, SHA256_DIGEST_LENGTH);
    printf(" },\n");

    printf("%s    content: { \"%s\", %u },\n", prefix, blk->data.buffer, blk->data.len);

    printf("%s    hash: ", prefix);
    print_hex_data(blk->hash, SHA256_DIGEST_LENGTH);

    printf("\n%s}\n", prefix);

    (void)pos;
    return (0);
}

/**
 * print_full_blockchain - Display all Blocks in a Blockchain
 *
 * @chain: Pointer to the Blockchain to be displayed
 */
void print_full_blockchain(blockchain_t const *chain)
{
    printf("Blockchain: {\n");

    printf("    blocks [%d]: [\n", llist_size(chain->chain));
    llist_for_each(chain->chain, (node_func_t)print_block_info, "        ");
    printf("    ]\n");

    printf("}\n");
    fflush(NULL);
}

/**
 * print_blockchain_summary - Display summarized Blockchain information
 *
 * @chain: Pointer to the Blockchain to be summarized
 */
void print_blockchain_summary(blockchain_t const *chain)
{
    printf("Blockchain: {\n");

    printf("    blocks [%d]: [\n", llist_size(chain->chain));
    llist_for_each(chain->chain, (node_func_t)print_block_summary, "        ");
    printf("    ]\n");

    printf("}\n");
    fflush(NULL);
}
