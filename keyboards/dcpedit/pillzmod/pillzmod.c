// Copyright 2024 Ming-Gih Lam (@dcpedit)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"

#define NUM_LAYER     1

void matrix_init_user(void) {
  setPinOutput(LED_LAYER_PIN);
}

// Initialize your default layer
layer_state_t layer_state_set_user(layer_state_t state) {
  if (IS_LAYER_ON_STATE(state, NUM_LAYER)) {
#ifdef LED_ACTIVE_LOW
    writePinLow(LED_LAYER_PIN);
#else
    writePinHigh(LED_LAYER_PIN);
#endif
  }
  else {
#ifdef LED_ACTIVE_LOW
    writePinHigh(LED_LAYER_PIN);
#else
    writePinLow(LED_LAYER_PIN);
#endif
  }

  return state;
}