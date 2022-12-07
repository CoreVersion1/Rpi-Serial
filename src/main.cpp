#include "main.hpp"

#include <iostream>
#include <unistd.h>

#include <pigpio.h>
#include <glog/logging.h>

int main(int argc, char **argv)
{
 int pHandle = serOpen("/dev/ttyUSB0",115200,0);

  while (true)
  {
    sleep(2);
    LOG(INFO) << "Write Byte state  = " 
              << serWriteByte(pHandle,0x31)
              << std::endl;
  }

  return 0;
}
