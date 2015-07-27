
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/rp.h"

int main(int argc, char **argv){

    /* Print error, if rp_Init() function failed */
    if(rp_Init() != RP_OK){
        fprintf(stderr, "Rp api init failed!\n");
    }

    /*Var definition */
    uint32_t buff_size = 16 * 1024;
    float *buffer = malloc(buff_size * sizeof(float));

    rp_DpinSetDirection(RP_DIO1_N, RP_OUT);

    rp_DpinSetState(RP_DIO1_N, RP_HIGH);
    rp_DpinSetState(RP_LED5, RP_HIGH);

    /* Starts acquisition */
    rp_AcqStart();
    rp_AcqSetTriggerSrc(RP_TRIG_SRC_NOW);

    rp_GenFreq(RP_CH_2, 10000);//atof(argv[3]));
    rp_GenAmp(RP_CH_2, 1);//atof(argv[2]));
    rp_GenWaveform(RP_CH_2, RP_WAVEFORM_SQUARE);
    rp_GenMode(RP_CH_2, RP_GEN_MODE_CONTINUOUS);
    rp_GenOutEnable(RP_CH_2);

#if 0
    /* Enable output channel */
    usleep(50000);
    rp_GenBurstPeriod(RP_CH_2, 1000000*(1/(atof(argv[4]))));//time of one burst signal
    usleep(50000);
    rp_GenBurstCount(RP_CH_2, atof(argv[6])); //num of signal periodes inside burst
    usleep(50000);
    rp_GenBurstRepetitions(RP_CH_2, atof(argv[5]));//num of bursts!
    usleep(50000);
    rp_GenMode(RP_CH_2, RP_GEN_MODE_BURST);

    usleep(200000);
    rp_DpinSetState(RP_DIO1_N, RP_LOW);
    rp_DpinSetState(RP_LED5, RP_LOW);
#endif

    FILE *data = fopen("/tmp/burst_data", "w+");

    
 
    /* Get the whole buffer into buf */
    rp_AcqGetDataV(RP_CH_1, 0, &buff_size, buffer);

    for(int i = 0; i < buff_size; ++i){
        fprintf(data, "%f\n", buffer[i]);
    }

    /* Releasing resources */
    rp_Release();
    return 0;
}
