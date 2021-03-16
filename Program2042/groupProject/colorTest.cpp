// color your text in Windows console mode
// colors are 0=black 1=blue 2=green and so on to 15=white  
// colorattribute = foreground + background * 16
// to get red text on yellow use 4 + 14*16 = 228
// light red on yellow would be 12 + 14*16 = 236
// a Dev-C++ tested console application by  vegaseat  07nov2004

#include <iostream>
#include <windows.h>   // WinApi header

using namespace std;    // std::cout, std::cin


int main()
{
    cout << R"(
d888888P                               .d88888b                                 dP   dP       oo                      
   88                                  88.    "'                                88   88                               
   88    dP    dP 88d888b. .d8888b.    `Y88888b. .d8888b. 88d8b.d8b. .d8888b. d8888P 88d888b. dP 88d888b. .d8888b.    
   88    88    88 88'  `88 88ooood8          `8b 88'  `88 88'`88'`88 88ooood8   88   88'  `88 88 88'  `88 88'  `88    
   88    88.  .88 88.  .88 88.  ...    d8'   .8P 88.  .88 88  88  88 88.  ...   88   88    88 88 88    88 88.  .88    
   dP    `8888P88 88Y888P' `88888P'     Y88888P  `88888P' dP  dP  dP `88888P'   dP   dP    dP dP dP    dP `8888P88    
              .88 88                                                                                           .88    
          d8888P  dP                                                                                       d8888P        
)" << '\n';

    return 0;
}