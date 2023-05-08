
#include <libnfnetlink.h>
#include <iostream>
#include <unistd.h>
#include <unordered_map>
#include <chrono>
#include <thread>
#include <net/if.h>

// IFNAMSIZ

bool getIfUpState(nlif_handle* ifH,unsigned int index)
{
  unsigned int flags;
  nlif_get_ifflags(ifH, index, &flags);
  return flags & IFF_RUNNING;
}

int main(int argc, char *argv[]) {

  auto ifHandle = nlif_open();

  nlif_query(ifHandle);
  char ifName[IFNAMSIZ];


  std::unordered_map<std::string, int> indexByName;

  {
    unsigned int index = 1;
    int result = -1;
    do {
      if( (result = nlif_index2name(ifHandle, index, ifName)); result >= 0)
      {
        std::cout << "Found device #" << index << ": " << ifName << std::endl;
        indexByName.emplace(ifName, index);
      }
      ++index;

    } while(result>=0);
  }

  // nlif_get_ifflags(ifHandle, 4, 0);

  if(!indexByName.count(argv[1]))
  {
    std::cerr << "Device doesnt exist";
    return -1;
  }
  auto ifIndex = indexByName.at(argv[1]);

  auto ifState = getIfUpState(ifHandle, ifIndex);
  std::cout << (ifState?"up":"down") << std::endl;

  while (1)
  {
    nlif_catch(ifHandle);
     auto ifStateNew = getIfUpState(ifHandle, ifIndex);
     if(ifStateNew != ifState)
     {
       ifState = ifStateNew;
       std::cout << (ifState?"up":"down") << std::endl;
     }
     std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }


}


