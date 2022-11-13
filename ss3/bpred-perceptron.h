#ifndef __BPRED_PERCEPTRON_H__
#define __BPRED_PERCEPTRON_H__

/*
 * bpred-perceptron.h: Perceptron based predictor
 */

#include <stdio.h>
#include <stdint.h>

/* TODO: Figure out how to get these from an environment variable */
/* Global Branch History Register Length */
#define HISTORY_LENGTH          12      // Paper started out from 12 length

/* Number of perceptrons present in the perceptron table */
#define NUM_OF_PERCEPTRONS      10

/* Learning threshold */
#define LEARNING_THRESHOLD      ((1.93 * HISTORY_LENGTH) + 14)

/* Address Width */
#define ADDRESS_WIDTH           4

/* Perceptron Structure */
typedef struct {
    int32_t w[HISTORY_LENGTH];
} perceptron_t;

/* Perceptron array for 'NUM_OF_PERCEPTRONS' Global Branch Histories */
extern perceptron_t perceptrons[NUM_OF_PERCEPTRONS];

/* Function defines */

/* Select a perceptron from the perceptron table */
uint8_t perceptron_select(uint32_t branch_addr);

/* Calculate perceptron p's output */
int32_t perceptron_predict(uint8_t p);

/* Update weights of a perceptron 'p' */
void perceptron_update_weights(uint8_t p);

#endif