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
      usleep(50000);
      
      if(stat==RP_HIGH){
        
        data = fopen("/tmp/uz_btn", "w+");  
        fclose(data);
      
      }else{    
        
        unlink ("/tmp/uz_btn");
      
      }        
    }

    rp_Release();

    return 0;
}
