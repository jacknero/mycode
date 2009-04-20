#include <iostream>
#include <boost/crc.hpp>

int main(void)
{
      char buf[] = {0, 0, 0, 0, 0};
          boost::crc_32_type crc;
              crc.process_bytes(buf, sizeof(buf));
                  std::cout << std::hex << crc.checksum() << std::endl;
                      return 0;
}


