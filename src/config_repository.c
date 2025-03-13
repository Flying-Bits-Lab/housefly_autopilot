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

#include "../include/config_repository.h"

const ConfigRepository *get_config() {
  static const ConfigRepository config = {
      .flying_vehicle = {
          .service_ceiling = FLYING_VEHICLE_SERVICE_CEILING,
          .reaction_latency = FLYING_VEHICLE_REACTION_LATENCY,
          .registry_number = FLYING_VEHICLE_REGISTRY_NUMBER,
          .latitude_diff_boundary = FLYING_VEHICLE_LATITUDE_DIFF_BOUNDARY,
          .longitude_diff_boundary = FLYING_VEHICLE_LONGITUDE_DIFF_BOUNDARY,
          .weight = FLYING_VEHICLE_WEIGHT,
          .cg_x = FLYING_VEHICLE_CG_X,
          .cg_y = FLYING_VEHICLE_CG_Y,
          .cg_z = FLYING_VEHICLE_CG_Z}};
  return &config;
}
