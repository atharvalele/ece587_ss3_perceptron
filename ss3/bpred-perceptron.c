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
uint8_t num_of_perceptrons;

/**
 * perceptron init
 * 
 * allocate memory for all the weights
 * assign learning threshold and number of perceptrons
 * 
 */
void perceptron_init(perceptron_t *p, uint8_t hist_len)
{
    p->w = calloc(hist_len, sizeof(int32_t));
    learning_threshold = (1.93 * hist_len) + 14;
    num_of_perceptrons = hist_len;
}

/**
 * @brief Select a perceptron from the perceptron table
 * 
 * @param branch_addr 
 * @return uint8_t 
 */
uint8_t perceptron_select(uint32_t branch_addr)
{
    uint8_t p = (branch_addr >> 3) % num_of_perceptrons;

    info("\nSelecting perceptron: %d", p);

    return p;
}

/**
 * @brief Get the prediction from a perceptron
 * 
 * @param p 
 * @return int32_t 
 */
int32_t perceptron_predict(perceptron_t *p, int *hist, uint8_t hist_len)
{
    /* Prediction output */
    int32_t y;

    /* Assign initial value = 1 * bias weight */
    y = p->bias;

    /* Calculate the perceptron output */
    for (int i = 0; i < hist_len; i++) {
        y += p->w[i] * hist[i];
    }

    info("p_out = %d", y);
    
    return y;
}

/**
 * @brief 
 * 
 * @param p 
 * @param hist_len 
 * @param correct 
 */
void perceptron_update_weights(perceptron_t *p, int *hist, uint8_t hist_len, int8_t correct)
{
    for (int i = 0; i < hist_len; i++)
    {
        if (!!correct == !!hist[i])
            p->w[i] += 1;
        else
            p->w[i] -= 1;
        
        info("w[%d] = %d", i, p->w[i]);
    }
    
    p->bias += correct;
    info("bias =  %d", p->bias);
}

/* Update saved history */
void perceptron_update_history(uint8_t hist_len, int8_t taken, int32_t *history)
{
    uint8_t h;
    for (h = hist_len; h > 0; h--){
        history[h] = history[h-1];
    }
    history[0] = taken;
    display_history(history, hist_len);
}

void display_history(int32_t *hist, uint8_t hist_len)
{
    uint8_t h;
    for (h = 0; h < hist_len; h++){
        info("Hist element %d: %d", h, hist[h]);
    }
}