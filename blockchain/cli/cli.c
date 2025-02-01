#include "blockchain.h"
#include <stdio.h>
#include <string.h>

int main()
{
    char command[256];
    char param1[256], param2[256];
    
    while (1)
    {
        printf("> ");
        fgets(command, sizeof(command), stdin);

        if (sscanf(command, "wallet_load %s", param1) == 1)
        {
            wallet_load(param1);
        }
        else if (sscanf(command, "wallet_save %s", param1) == 1)
        {
            wallet_save(param1);
        }
        else if (sscanf(command, "send %d %s", &param1, param2) == 2)
        {
            send_transaction(atoi(param1), param2);
        }
        else if (strcmp(command, "mine\n") == 0)
        {
            mine_block();
        }
        else if (strcmp(command, "info\n") == 0)
        {
            display_info();
        }
        else if (sscanf(command, "load %s", param1) == 1)
        {
            load_blockchain(param1);
        }
        else if (sscanf(command, "save %s", param1) == 1)
        {
            save_blockchain(param1);
        }
        else
        {
            printf("Unknown command: %s", command);
        }
    }

    return 0;
}
