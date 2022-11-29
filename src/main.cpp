// --- Memory Leak detection --- //
#define _CRTDBG_MAP_ALLOC //to get more details
#include <stdlib.h>  
#include <crtdbg.h>   //for malloc and free
// ------------------------------//

#include "gamehandler.h"


int main()
{
   // Calls "_CrtDumpMemoryLeaks" at exit point
   _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

   GameHandler app;
   
   app.Run();

   return 0;
}