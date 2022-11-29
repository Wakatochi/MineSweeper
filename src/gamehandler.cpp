#include "gamehandler.h"
#include "globals.h"

#include "resourcehandler.h"

GameHandler::GameHandler()
{
   m_mainWindow = NULL;
// m_board = new GameBoard(global::Default_Size::BOARDSIZE_COLUMNS, global::Default_Size::BOARDSIZE_ROWS, global::Default_Size::MINES);
   m_board = new GameBoard(global::Intermediate_Size::BOARDSIZE_COLUMNS, global::Intermediate_Size::BOARDSIZE_ROWS, global::Intermediate_Size::MINES);

   InitWindow();
}

GameHandler::~GameHandler()
{
   if(m_board != NULL)
   {
      delete m_board;
      m_board = NULL;
   }

   if(m_mainWindow != NULL)
   {
      delete m_mainWindow;
      m_mainWindow = NULL;
   }
}

bool
GameHandler::Run()
{
   while(m_mainWindow->isOpen())
   {
      Update();
      Draw();
   }

   return true;
}

void
GameHandler::InitWindow()
{
   if(m_mainWindow == NULL)
   {
      m_mainWindow = new RenderWindow(VideoMode(global::Const_Window_1280_1024::WINDOW_WIDTH, global::Const_Window_1280_1024::WINDOW_HEIGHT), "Minesweeper");
   }
}

bool
GameHandler::Update()
{
   Event event;
   while(m_mainWindow->pollEvent(event))
   {
      switch(event.type)
      {
         case Event::Closed:
            m_mainWindow->close();
            return false;

         case Event::KeyPressed:
            if(event.key.code == Keyboard::Escape)
            {
               // Open menu
               m_mainWindow->close();
               return false;
            }
            else if(event.key.code == Keyboard::Space)
            {
               m_board->reset();
            }

         case Event::MouseButtonReleased:
            if(event.mouseButton.button == Mouse::Left)
            {
               // Open tile;
               m_board->openKlick((float)Mouse::getPosition(*m_mainWindow).x, (float)Mouse::getPosition(*m_mainWindow).y);
            }
            else if(event.mouseButton.button == Mouse::Right)
            {
               // Flag tile;
               m_board->flag((float)Mouse::getPosition(*m_mainWindow).x, (float)Mouse::getPosition(*m_mainWindow).y);
            }
            break;
      }
   }

   return true;
}

void
GameHandler::Draw()
{
   m_mainWindow->clear();
   
   m_board->Draw(*m_mainWindow);

   m_mainWindow->display();
}