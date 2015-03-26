/**
 * $Id: $
 *
 * @brief Red Pitaya library burst generate interface
 *
 * @Author
 *
 * (c) Red Pitaya  http://www.redpitaya.com
 *
 * This part of code is written in C programming language.
 * Please visit http://en.wikipedia.org/wiki/C_(programming_language)
 * for more details on the language used herein.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>


static size_t GENERATE_BASE_ADDRS = 0x40200000;
static size_t GENERATE_BASE_SIZE = 0x30000;

/* Inline function definition */
static int us_BurstInit(void);
static int us_BurstRelease(void);


typedef enum{
	RP_OK,
	RP_ERRNO,
}us_control;

/* Red Pitaya ASG register map */
typedef struct rp_asg_control{

	/* 31:25 R
	 * 24:0  R/W */
	uint32_t configuration;

	uint32_t cha_ampl_sca_offs;

	uint32_t cha_count_w;

	uint32_t cha_s_offs;

	uint32_t cha_count_stp;

	uint32_t cha_curr_buff_ptr;

	uint32_t cha_burst_read_cycl;

	uint32_t cha_burst_rep;

	uint32_t cha_burst_delay;

}rp_asg_control_t;

static rp_asg_control_t *bursts = NULL;
static volatile int32_t *data_chA = NULL;
static volatile int32_t *data_chB = NULL;


/* File descriptor */
static int us_generate_fd = -1;

int main(void){

	/* function init for -Werror */
	us_BurstInit();

	return RP_OK;
}

/* Init */
static int us_BurstInit(void){


	void *page_ptr;
    long page_addr, page_off, page_size = sysconf(_SC_PAGESIZE);

	if(us_BurstRelease() != RP_OK){
		fprintf(stderr, "Failed to release resources: %s\n", strerror(errno));
		return RP_ERRNO;
	}    

	us_generate_fd = open("/dev/mem", O_RDWR | O_SYNC);
	if(us_generate_fd < 0){
		fprintf(stderr, "open(/dev/mem) failed: %s\n", strerror(errno));
		return RP_ERRNO;
	}

	page_addr = GENERATE_BASE_ADDRS & (~(page_size-1));
	page_off = GENERATE_BASE_ADDRS - page_addr;

	page_ptr = mmap(NULL, GENERATE_BASE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, us_generate_fd, page_addr);

	if((void *)page_ptr == MAP_FAILED){
		fprintf(stderr, "mmap failed: %s\n", strerror(errno));
		us_BurstRelease();
	}
	/* Structure pointing directly to the FPGA ASG mem space */
	bursts = page_ptr + page_off;

	/* TODO: Add data pointers */

	return RP_OK;
}

static int us_BurstRelease(void){

	/* unmap register in case they are still mapped */
	if(bursts){
		if(munmap(bursts, GENERATE_BASE_SIZE) < 0){
			fprintf(stderr, "munmap() failed: %s\n", strerror(errno));
			return RP_ERRNO;
		}

		bursts = NULL;
		data_chA = NULL;
		data_chB = NULL;
	}

	if(us_generate_fd >= 0){
		close(us_generate_fd);
		us_generate_fd = -1;
	}

	return RP_OK;
}



