/*
 * Copyright 2016 <Admobilize>
 * MATRIX Labs  [http://creator.matrix.one]
 * This file is part of MATRIX Creator HAL
 *
 * MATRIX Creator HAL is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CPP_DRIVER_NFC_SPI_H
#define CPP_DRIVER_NFC_SPI_H

#include <string>
#include "./matrix_driver.h"

const uint32_t DATA_ADDR = 0;
const uint32_t BUSY_ADDR = 1;
const uint32_t CS_ADDR  = 2;     
const uint32_t DIVISOR_ADDR = 3;
const uint32_t NRST_ADDR = 4;

namespace matrix_hal {

class NFCSpi : public MatrixDriver {
 public:
  NFCSpi();
  bool Init();
  bool Transfer(uint16_t * txData, uint16_t * rxData, uint16_t length);

 private:
  bool SetCS();
  bool ClearCS();
  bool IsBusy();
  uint16_t divisor_;
  uint16_t busy_;
};
};      // namespace matrix_hal
#endif  // CPP_DRIVER_PRESSURE_SENSOR_H_

