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
  uint16_t cs = 0x0000;
  uint16_t counter_div = 0x2010;
  uint16_t nfc_internal_dat_0 = 0x0707;
  uint16_t nfc_internal_dat_1 = 0x0707;
  uint16_t dummy = 0x0000;
  uint16_t read_data;

  read_data = 0;
  bus->SpiWrite16(nfc_add + 2, 0x0001);
  bus->SpiWrite16(nfc_add + 3, counter_div);
  bus->SpiRead16(nfc_add + 3, (unsigned char *)&read_data);
  std::cout << "Read Divisor : " << std::hex << read_data << std::dec << std::endl;

  bus->SpiWrite16(nfc_add + 2, 0x0000);

  bus->SpiWrite16(nfc_add, nfc_internal_dat_0);
  bus->SpiRead16(nfc_add + 1, (unsigned char *)&read_data);
  std::cout << "Read busy : " << std::hex << read_data << std::dec << std::endl;
  while(read_data == 0x0001){
    bus->SpiRead16(nfc_add + 1, (unsigned char *)&read_data);
    std::cout << "Read busy 1 : " << std::hex << read_data << std::dec << std::endl;
  }
  
  bus->SpiWrite16(nfc_add + 2, 0x0001);
  usleep(100); 
  bus->SpiWrite16(nfc_add + 2, 0x0000);
 
  bus->SpiWrite16(nfc_add, nfc_internal_dat_1);
  bus->SpiRead16(nfc_add + 1, (unsigned char *)&read_data); 
  
  while(read_data == 0x0001){
   bus->SpiRead16(nfc_add + 1, (unsigned char *)&read_data);
   std::cout << "Read busy 2 : " << std::hex << read_data << std::dec << std::endl;
  }

  bus->SpiRead16(nfc_add + 4, (unsigned char *)&read_data);
  std::cout << "Read Data : "  << read_data  << std::endl; 

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
