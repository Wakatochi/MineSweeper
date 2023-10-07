#include "gamehandler.h"
#include "globals.h"

#include "resourcehandler.h"

GameHandler::GameHandler()
{
   m_mainWindow = NULL;
//   m_board = new GameBoard(global::Default_Size::BOARDSIZE_COLUMNS, global::Default_Size::BOARDSIZE_ROWS, global::Default_Size::MINES);
 m_board = new GameBoard(global::Intermediate_Size::BOARDSIZE_COLUMNS, global::Intermediate_Size::BOARDSIZE_ROWS, global::Intermediate_Size::MINES);
// m_board = new GameBoard(40, 40, global::Intermediate_Size::MINES);
   
   m_face = new Face(0.0f, 0.0f);

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

   if(m_face != NULL)
   {
      delete m_face;
      m_face = NULL;
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
      m_mainWindow = new RenderWindow(VideoMode(global::Const_Window_Custom::WINDOW_WIDTH, global::Const_Window_Custom::WINDOW_HEIGHT), "Minesweeper", Style::Close);
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
               m_board->setFaceState(Face::Face_Normal);
               //m_face->setState(Face::Face_Normal);
            }

         case Event::MouseButtonPressed:
            if(event.mouseButton.button == Mouse::Left)
            {
               //m_face->setState(Face::Face_Open);
               m_board->setFaceState(Face::Face_Open);
            }
            break;

         case Event::MouseButtonReleased:
            if(event.mouseButton.button == Mouse::Left)
            {
               //m_face->setState(Face::Face_Normal);
               m_board->setFaceState(Face::Face_Normal);
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

      m_board->Update();
   }

   if(m_board->getGameOver())
   {
      //m_face->setState(Face::Face_Dead);
      m_board->setFaceState(Face::Face_Dead);
   }
   else if(m_board->getGameWin())
   {
      //m_face->setState(Face::Face_Win);
      m_board->setFaceState(Face::Face_Win);
   }

   return true;
}

void
GameHandler::Draw()
{
   m_mainWindow->clear(Color::Blue);
   
   m_board->Draw(*m_mainWindow);
//   m_face->Draw(*m_mainWindow);

   m_mainWindow->display();
}