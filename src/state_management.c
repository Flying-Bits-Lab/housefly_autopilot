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

static FlightStatus flight_state;

void set_initflg(unsigned char *flags) { *flags |= (1 << 1); }

void set_sftytstflg(unsigned char *flags) { *flags |= (1 << 0); }

void reset_sftytstflg(unsigned char *flags) { *flags &= ~(1 << 0); }

void reset_flags(unsigned char *flags) { *flags = 0x00; }

void set_position(FlightStatus *flight_status, float new_longitude,
                  float new_latitude, float new_altitude) {
  flight_status->current_altitude = new_altitude;
  flight_status->current_latitude = new_latitude;
  flight_status->current_longitude = new_longitude;
}

void reset_state(FlightState *current_state) { *current_state = GND_STAT; }

char set_requested_state(FlightState *current_state, FlightState new_state,
                         unsigned char flags) {
  char result = -1;
  if (validate_requested_state(*current_state, new_state, flags)) {
    *current_state = new_state;
    result = 1;
  }
  return result;
}

char validate_requested_state(FlightState current_state, FlightState new_state,
                              unsigned char flags) {
  switch (new_state) {
    case GND_STAT:
      return (current_state == NON_STAT || current_state == LND_STAT ||
              current_state == TST_STAT)
                 ? 1
                 : 0;
    case TO_STAT:
      return (current_state == GND_STAT && (flags & 0x01)) ? 1 : 0;
    case LND_STAT:
      return current_state == IDLE_STAT ? 1 : 0;
    case TRN_STAT:
      return current_state == IDLE_STAT ? 1 : 0;
    case IDLE_STAT:
      return (current_state == TO_STAT || current_state == TRN_STAT) ? 1 : 0;
    case TST_STAT:
      return current_state == GND_STAT ? 1 : 0;
    case HLT_STAT:
      return 1;
    default:
      return 0;
  }
}

FlightStatus *init() {
  reset_flags(&flight_state.flags);
  reset_state(&flight_state.state);
  set_initflg(&flight_state.flags);
  return &flight_state;
}
