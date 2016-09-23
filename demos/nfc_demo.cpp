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

#include <unistd.h>
#include <iostream>

#include "../cpp/driver/nfc_spi.h"
#include "../cpp/driver/wishbone_bus.h"

namespace hal = matrix_hal;

int main() {
  hal::WishboneBus bus;
  bus.SpiInit();
 
  hal::NFCSpi nfc;
  nfc.Setup(&bus);
  uint16_t tx[1] = {0x0004};
  uint16_t rx[1];
  nfc.Transfer((uint16_t *)tx,(uint16_t *)rx,1);
  std::cout << "Read Data : " << std::hex  <<  rx[0]  << std::endl; 
  tx[0] = 0x8006; 
  nfc.Transfer((uint16_t *)tx,(uint16_t *)rx,1);
  std::cout << "Read Data : " << std::hex  <<  rx[0]  << std::endl; 
  return 0;
}
