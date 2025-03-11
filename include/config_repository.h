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

#ifndef CONFIG_REPOSITORY_H_
#define CONFIG_REPOSITORY_H_

/* -- DEFAULT CONFIGURATIONS -- */
#define FLYING_VEHICLE_REACTION_LATENCY 150
#define FLYING_VEHICLE_SERVICE_CEILING 10
#define FLYING_VEHICLE_WEIGHT 1.0

typedef struct {
  unsigned char service_ceiling;
  unsigned char reaction_latency;
  float weight;
} FlyingVehicle;

typedef struct {
  FlyingVehicle flying_vehicle;
} ConfigRepository;

/**
 * @brief Returns the config repository
 * @return Returns the pointer to the config repository
 */
ConfigRepository *get_config();

#endif  // CONFIG_REPOSITORY_H_
