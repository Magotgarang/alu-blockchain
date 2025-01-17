#include "endianness.h"

/**
 * detect_endianness - Determines the current system endianness
 *
 * Return: 1 for little endian, 2 for big endian, 0 for unknown
 */
uint8_t detect_endianness(void)
{
    endian_check_t checker = {1};

    if (checker.bytes[0] == 1)
        return (1);
    if (checker.bytes[0] == 0)
        return (2);

    /* Unexpected case */
    return (0);
}

/**
 * reverse_endianness - Reverses the byte order of a memory block
 * @ptr: Pointer to the memory block to modify
 * @length: The number of bytes in the memory block
 */
void reverse_endianness(void *ptr, size_t length)
{
    size_t i;
    uint8_t *byte_ptr = (uint8_t *)ptr;

    for (i = 0; i < length / 2; i++)
    {
        byte_ptr[i] ^= byte_ptr[length - i - 1];
        byte_ptr[length - i - 1] ^= byte_ptr[i];
        byte_ptr[i] ^= byte_ptr[length - i - 1];
    }
}

