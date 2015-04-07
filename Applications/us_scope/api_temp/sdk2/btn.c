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
    FILE *data;
     while(1){
    rp_pinState_t stat = RP_LOW;
    rp_DpinSetDirection(RP_DIO0_N, RP_IN);
    rp_DpinGetState(RP_DIO0_N, &stat);
    //char b_command[100]; 
           
            /* If the file doesn't exists yet */
           // if(fopen("/opt/www/apps/scope/uz_btn", "w") == NULL){
                /* Create a normal file, as txt is a just an interpreter */
          //      strcpy(b_command, "touch /opt/www/apps/scope/uz_btn");
          //      system(b_command);
          //  }
usleep(50000);
            /* Open file for writing */
   //         data = fopen("/tmp/uz_btn", "w+");
           // if(data==NULL)  { 
               // printf("Error: could not open file");
               // break;
            //}
            if(stat==RP_HIGH){
            //fprintf(data, "%.1d\n", 1);
                       data = fopen("/tmp/uz_btn", "w+");
                        fclose(data);
            }
            else
            {
             
                unlink ("/tmp/uz_btn");
            //fprintf(data, "%.1d\n", 0);
            }

            //fclose(data);


          //  if( access( fname, F_OK ) != -1 ) {
    // file exists
         //   } else {
    // file doesn't exist
         //   }
            
}

    rp_Release();

        return 0;
}
