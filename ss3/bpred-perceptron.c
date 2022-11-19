/*
 * bpred-perceptron.h: Perceptron based predictor
 */

#include <stdio.h>
#include <stdint.h>

#include "host.h"
#include "misc.h"
#include "machine.h"
#include "bpred-perceptron.h"

int32_t learning_threshold;

/**
 * perceptron init
 * 
 * allocate memory for all the weights
 * 
 */
void perceptron_init(perceptron_t *p, uint8_t hist_len)
{
    p->w = calloc(hist_len, sizeof(int32_t));
    learning_threshold = (1.93 * hist_len) + 14;
}

/**
 * @brief Select a perceptron from the perceptron table
 * 
 * @param branch_addr 
 * @return uint8_t 
 */
uint8_t perceptron_select(uint32_t branch_addr)
{
    info("Selecting perceptron\n");

    return ((branch_addr >> ADDRESS_WIDTH) % NUM_OF_PERCEPTRONS);
}

/**
 * @brief Get the prediction from a perceptron
 * 
 * @param p 
 * @return int32_t 
 */
int32_t perceptron_predict(perceptron_t *p, int *hist, uint8_t hist_len)
{
    info("%d\n", hist_len);
    info("calculting perceptron output\n");
    /* Prediction output */
    int32_t y;

    /* Assign initial value = 1 * bias weight */
    y = p->bias;

    /* Calculate the perceptron output */
    for (int i = 0; i < hist_len; i++) {
        y += p->w[i] * hist[i];
    }

    info("do we reach here? Yes %d", y);
    
    return y;
}

/**
 * @brief 
 * 
 * @param p 
 * @param hist_len 
 * @param correct 
 */
void perceptron_update_weights(perceptron_t *p, uint8_t hist_len, uint8_t correct)
{
    for (int i = 0; i < hist_len; i++)
    {
        p->w[i] += correct;
    }
    p->bias += correct;
}