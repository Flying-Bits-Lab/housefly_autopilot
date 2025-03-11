/*
 * MIT License
 *
 * Copyright (c) 2025 Flying Bits Lab
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef STATE_MANAGEMENT_H_
#define STATE_MANAGEMENT_H_

typedef enum {
  NON_STAT = -1,
  GND_STAT = 0,
  TO_STAT = 1,
  LND_STAT = 2,
  TRN_STAT = 3,
  IDLE_STAT = 4,
  TST_STAT = 5,
  HLT_STAT = 6
} FlightState;

typedef struct {
  unsigned char flags;
  FlightState state;
} FlightStatus;

/**
 * @brief Sets inti flag to 1
 * @param[out] flags
 * @return void
 */
void set_initflg(unsigned char *flags);

/**
 * @brief Sets the safety test flag to 1
 * @param[out] flags
 * @return void
 */
void set_sftytstflg(unsigned char *flags);

/**
 * @brief Resets the safety test flag
 * @param[out] flags
 * @return void
 */
void reset_sftytstflg(unsigned char *flags);

/**
 * @brief Resets all flags
 * @param[out] flags
 * @return void
 */
void reset_flags(unsigned char *flags);

/**
 * @brief Resets the flight state. The value will be set GND_STAT
 * @param[out] current_state
 * @return void
 */
void reset_state(FlightState *current_state);

/**
 * @brief Sets the flight state to the requested state
 * @param[in,out] curren_state
 * @param new_state
 * @return void
 */
void set_requested_state(FlightState *current_state, FlightState new_state,
                         unsigned char flags);

/**
 *@brief Validates requested sate. Returns either 1 or 0 for which mean valid
 * and invalid respectively
 *@param current_state
 *@param new_state
 *@param flags
 *@return 1 if valid and 0 if invalid
 */
char validate_requested_state(FlightState current_state, FlightState new_state,
                              unsigned char flags);

/**
 * @brief Initiates the flight state machine
 * @returns Returns the pointer to the flight state machine
 */
FlightStatus *init();

#endif  // STATE_MANAGEMENT_H_
