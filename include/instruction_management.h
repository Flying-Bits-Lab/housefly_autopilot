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

#include "../include/state_management.h"

#ifndef INSTRUCTION_MANAGEMENT_H_
#define INSTRUCTION_MANAGEMENT_H_

typedef enum {
  ATC_INS_TAKE_OFF,
  ATC_INS_LAND,
  ATC_INS_TRANSITION,
  ATC_INS_SAFETY_TEST,
  ATC_INS_HALT,
  ATC_ECHO
} ATCInstructionType;

typedef struct {
  ATCInstructionType type;
  union {
    struct {
      float target_altitude;
    } take_off;

    struct {
      float new_longitude;
      float new_latitude;
      float new_altitude;
    } transition;
  } params;
} ATCInstruction;

/**
 * @brief Validates the transition instruction specifically
 * @param[in] flight_status
 * @param new_altitude
 * @param new_longitude
 * @param new_latitude
 * @return 1 if transition valid and -1 if not valid
 */
static char is_transition_valid(const FlightStatus* flight_status,
                                float new_altitude, float new_longitude,
                                float new_latitude);
/**
 * @brief Checks wether the instruction is valid
 * @param instruction
 * @return 1 if the instruction valid and -1 if not valid
 */
static char is_instruction_valid(const ATCInstruction instruction);

/**
 * @brief Determines the ultimate state if the instruction is executed. The
 * result should be passed down to state manageman as a new requested state.
 * Whether the state transition is possible or not is the responsibility of the
 * state management
 * @param instruction
 * @return Flight (new requested) state
 */
FlightState which_new_state(const ATCInstruction instruction);

#endif  // INSTRUCTION_MANAGEMENT_H_
