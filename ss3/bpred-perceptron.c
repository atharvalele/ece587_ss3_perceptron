/*
 * bpred-perceptron.h: Perceptron based predictor
 */

#include <stdio.h>
#include <stdint.h>

#include "bpred-perceptron.h"

/* Perceptron array for 'NUM_OF_PERCEPTRONS' Global Branch Histories */
perceptron_t perceptrons[NUM_OF_PERCEPTRONS] = {0};

/**
 * @brief Select a perceptron from the perceptron table
 * 
 * @param branch_addr 
 * @return uint8_t 
 */
uint8_t perceptron_select(uint32_t branch_addr)
{
    return ((branch_addr >> ADDRESS_WIDTH) / NUM_OF_PERCEPTRONS);
}

