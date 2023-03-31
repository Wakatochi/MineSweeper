#include "boarder.h"

Boarder::Boarder()
{
   m_sizeX = 0.0f;
   m_sizeY = 0.0f;

   m_face = new Face();
   m_time = new Display();
   m_mines = new Display();
}

Boarder::~Boarder()
{
   delete m_face;
   delete m_time;
   delete m_mines;
}

void
Boarder::Draw()
{

}

void
Boarder::Update()
{

}
