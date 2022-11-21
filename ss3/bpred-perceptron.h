#ifndef __BPRED_PERCEPTRON_H__
#define __BPRED_PERCEPTRON_H__

/*
 * bpred-perceptron.h: Perceptron based predictor
 */

#include <stdio.h>
#include <stdint.h>

/* Learning threshold */
#define LEARNING_THRESHOLD      ((1.93 * HISTORY_LENGTH) + 14)

/* Address Width */
#define ADDRESS_WIDTH           6

/* Perceptron Structure */
typedef struct {
    int32_t *w; /* Weights */
    int32_t bias;
} perceptron_t;

/* Learning threshold theta */
extern int32_t learning_threshold;

/* Number of perceptrons present in the perceptron table */
extern uint8_t num_of_perceptrons;

/* Function defines */

void perceptron_init(perceptron_t *p, uint8_t hist_len);

/* Select a perceptron from the perceptron table */
uint8_t perceptron_select(uint32_t branch_addr);

/* Calculate perceptron p's output */
int32_t perceptron_predict(perceptron_t *p, int *hist, uint8_t hist_len);

/* Update weights of a perceptron 'p' */
void perceptron_update_weights(perceptron_t *p, int *hist, uint8_t hist_len, int8_t correct);

/* Update saved history */
void perceptron_update_history(uint8_t hist_len, int8_t taken, int32_t *history);

void display_history(int32_t *hist, uint8_t hist_len);
#endif