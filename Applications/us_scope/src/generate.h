/**
 * $Id: generate.h 882 2013-12-16 12:46:01Z crt.valentincic $
 *
 * @brief Red Pitaya simple signal/function generator with pre-defined
 *        signal types.
 *
 * @Author Jure Menart <juremenart@gmail.com>
 *         
 * (c) Red Pitaya  http://www.redpitaya.com
 *
 * This part of code is written in C programming language.
 * Please visit http://en.wikipedia.org/wiki/C_(programming_language)
 * for more details on the language used herein.
 */

#ifndef __GENERATE_H
#define __GENERATE_H

#include "main.h"
#include "calib.h"

/** @defgroup generate_h Arbitrary Signal Generator
 * @{
 */

#define BURST_PERIOD_MIN        1           // us
#define BURST_PERIOD_MAX        500000000   // us
#define MICRO                   1e6

/** Signal types */
typedef enum awg_signal_e {
    eSignalSine = 0,     /* Sinusoidal waveform. */
    eSignalSquare,       /* Square waveform. */
    eSignalTriangle,     /* Triangular waveform. */
    eSignalFile          /* Waveform read from file */
} awg_signal_t;

/** AWG FPGA parameters */
typedef struct awg_param_s {
    int32_t  offsgain;   /* AWG offset & gain. */
    uint32_t wrap;       /* AWG buffer wrap value. */
    uint32_t step;       /* AWG step interval. */
} awg_param_t;

/** @} */

int generate_init(rp_calib_params_t *calib_params);
int generate_exit(void);

int generate_update(rp_app_params_t *params);
int gen_setBurstPeriod(rp_app_params_t *params, uint32_t period);
int generate_burst(rp_app_params_t *params, uint32_t period);

#endif // __GENERATE_H
