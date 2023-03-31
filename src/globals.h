#ifndef GLOBALS_H
#define GLOBALS_H

namespace global
{
   struct Const_Window_Custom
   {
      enum Const_Window
      {
         WINDOW_WIDTH = 950,
         WINDOW_HEIGHT = 950
      };
   };

   struct Const_Window_1920_1080
   {
      enum Const_Window
      {
         WINDOW_WIDTH  = 1920,
         WINDOW_HEIGHT = 1080
      };
   };

   struct Const_Window_1600_900
   {
      enum Const_Window
      {
         WINDOW_WIDTH  = 1600,
         WINDOW_HEIGHT = 900
      };
   };

   struct Const_Window_1280_1024
   {
      enum Const_Window
      {
         WINDOW_WIDTH  = 1280,
         WINDOW_HEIGHT = 1024
      };
   };

   struct Default_Size
   {
      enum Board_Size
      {
         BOARDSIZE_COLUMNS = 10,
         BOARDSIZE_ROWS    = 10,
         MINES             = 10
      };
   };

   struct Beginer_Size
   {
      enum Board_Size
      {
         BOARDSIZE_COLUMNS = 9,
         BOARDSIZE_ROWS    = 9,
         MINES             = 10
      };
   };

   struct Intermediate_Size
   {
      enum Board_Size
      {
         BOARDSIZE_COLUMNS = 16,
         BOARDSIZE_ROWS    = 16,
         MINES             = 40
      };
   };

   struct Expert_Size
   {
      enum Board_Size
      {
         BOARDSIZE_COLUMNS = 16,
         BOARDSIZE_ROWS    = 30,
         MINES             = 99
      };
   };
}

#endif

