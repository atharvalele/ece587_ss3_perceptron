#ifndef __BPRED_PERCEPTRON_H__
#define __BPRED_PERCEPTRON_H__

/*
 * bpred-perceptron.h: Perceptron based predictor
 */

#include <stdio.h>
#include <stdint.h>

/* TODO: Figure out how to get these from an environment variable */
/* Global Branch History Register Length */
#define HISTORY_LENGTH      12      // Paper started out from 12 length

/* Number of perceptrons present in the perceptron table */
#define NUM_OF_PERCEPTRONS     10


/* Perceptron Structure */
typedef struct {
    int32_t w[HISTORY_LENGTH];
} perceptron_t;

/* Perceptron array for 'NUM_OF_PERCEPTRONS' Global Branch Histories */
extern perceptron_t perceptrons[NUM_OF_PERCEPTRONS];

#endif