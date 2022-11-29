#ifndef RESOURCEHANDLER_H
#define RESOURCEHANDLER_H

#include <SFML/Graphics.hpp>
#include "singleton.h"

#include <sstream>

using namespace sf;
using namespace std;

class ResourceHandler: public Singleton<ResourceHandler>
{
   public:
      ResourceHandler();
      ~ResourceHandler();

      CircleShape getTestShape();

      Sprite& getHiddenSprite();
      Sprite& getOpenSprite();
      Sprite& getBombSprite();
      Sprite& getFlaggSprite();

      Font& getFont();
      Text& getText(int mines, Color color);

   private:
      CircleShape m_testShape;

      Texture m_hiddenTexture;
      Texture m_openTexture;
      Texture m_bombTexture;
      Texture m_flaggTexture;

      Sprite m_hiddenSprite;
      Sprite m_openSprite;
      Sprite m_bombSprite;
      Sprite m_flaggSprite;

      Font m_font;
      Text m_text;

      String toString(int val);
      String toStringf(float val);
};

#endif
