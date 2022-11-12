/*
 * bpred-perceptron.h: Perceptron based predictor
 */

#include <stdio.h>
#include <stdint.h>

#include "bpred-perceptron.h"

/* Perceptron array for 'NUM_OF_PERCEPTRONS' Global Branch Histories */
perceptron_t perceptrons[NUM_OF_PERCEPTRONS] = {0};