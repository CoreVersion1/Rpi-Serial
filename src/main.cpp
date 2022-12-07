#include "main.hpp"

#include <iostream>
#include <pigpio.h>
#include <glog/logging.h>

int main(int argc, char **argv)
{
  int gpio_cfg = gpioCfgGetInternals();
  gpio_cfg |= PI_CFG_NOSIGHANDLER; // (1<<10)
  gpioCfgSetInternals(gpio_cfg);
  int status = gpioInitialise();
  LOG(INFO) << "gpio init = " << status;

  int pHandle = serOpen((char*)"/dev/ttyUSB0",115200,0);//此处是ttyUSB0，根据实际设备节点进行配置
  char buff[0xFF] = {0};

  while (true)
  {
    //Send data = 0x31
    std::cout << "Write Byte state = " 
              << serWriteByte(pHandle,0x31)
              << std::endl;
    
    //Receive data
    uint16_t dataNum = serDataAvailable(pHandle);
    if(dataNum)
    {
      std::cout << "Read Bytes Number = " 
                << serRead(pHandle,buff,dataNum)
                << std::endl;

      std::cout << "Recv Data : ";
      for(uint16_t i =0;i<dataNum;i++)
      {
        std::cout << buff[i];
      }
      std::cout << "\r\n";
    }
    
    sleep(2);
  }

  return 0;
}
