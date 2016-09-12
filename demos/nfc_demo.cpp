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

#include "../cpp/driver/everloop_image.h"
#include "../cpp/driver/everloop.h"
#include "../cpp/driver/wishbone_bus.h"

namespace hal = matrix_hal;

int main() {
  hal::WishboneBus* bus = new hal::WishboneBus();

  bus->SpiInit();
  
  uint16_t nfc_add = 0x3000;
  uint16_t cs = 0x0001;
  uint16_t counter_div = 0x00FF;
  uint16_t nfc_internal_add_0 = 0x0000;
  uint16_t nfc_internal_0 = 0x0003;
  uint16_t nfc_internal_add_1 = 0x0007;
  uint16_t dummy = 0x0000;
  uint16_t read_data;

  bus->SpiWrite16(nfc_add + 3, counter_div);
  bus->SpiWrite16(nfc_add + 2, cs);
  bus->SpiWrite16(nfc_add + 0, nfc_internal_add_0);
  bus->SpiRead16(0x3001, (unsigned char *)&read_data);
  std::cout << "Read RUN : " << read_data << std::endl;

  /*
  bus->SpiRead16(nfc_add+1, (unsigned char *)&read_data);
  while (read_data == 1){
   bus->SpiRead16(nfc_add+1, (unsigned char *)&read_data);
  }
  bus->SpiWrite16(nfc_add + 0, nfc_internal_0);
  
  bus->SpiRead16(nfc_add+1, (unsigned char *)&read_data);
  while (read_data == 1){
   bus->SpiRead16(nfc_add+1, (unsigned char *)&read_data);
  }

  bus->SpiWrite16(nfc_add + 0, nfc_internal_add_1);

  bus->SpiRead16(nfc_add+1, (unsigned char *)&read_data);
  while (read_data == 1){
   bus->SpiRead16(nfc_add+1, (unsigned char *)&read_data);
  }

  bus->SpiWrite16(nfc_add + 0, dummy);
  
  bus->SpiRead16(nfc_add+1, (unsigned char *)&read_data);
  while (read_data == 1){
   bus->SpiRead16(nfc_add+1, (unsigned char *)&read_data);
  }

  bus->SpiRead16(nfc_add, (unsigned char *)&read_data);

  std::cout << "Read : " << read_data << std::endl;
 */  
  return 0;
}
