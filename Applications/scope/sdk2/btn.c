#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "rp.h"

int main(int argc, char **argv){

    /* Burst count */
//    int i;

    /* Print error, if rp_Init() function failed */
    if(rp_Init() != RP_OK){
        fprintf(stderr, "Rp api init failed!\n");
    }

   
    rp_pinState_t stat = RP_LOW;
    rp_DpinSetDirection(RP_DIO0_N, RP_IN);
    rp_DpinGetState(RP_DIO0_N, &stat);
    char b_command[100]; 
            
            /* If the file doesn't exists yet */
            if(fopen("/opt/www/apps/scope/uz_btn", "w") == NULL){
                /* Create a normal file, as txt is a just an interpreter */
                strcpy(b_command, "touch /opt/www/apps/scope/uz_btn");
                system(b_command);
            }

            /* Open file for writing */
            FILE *data = fopen("/opt/www/apps/scope/uz_btn", "w");

            if(stat==RP_HIGH){
            fprintf(data, "%.1d\n", 0);
            }
            else
            {
            fprintf(data, "%.1d\n", 1);
            }
            fclose(data);


    rp_Release();

        return 0;
}
