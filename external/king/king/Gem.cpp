#include "Gem.h"
#include "Sprite.h"

namespace King
{
   Gem::Gem(Color color) :
      m_Color(color),
      m_State(State::Normal),
      m_Sprite(new Sprite()),
      m_IsInUse(false)
   {

   }

   Gem::~Gem()
   {
   }

   void Gem::SetSprite(Sprite* const sprite)
   {
      if(sprite != nullptr)
         {
            m_Sprite = sprite;
         }
      else
         {
            // TODO : log error here
         }
   }

   void Gem::SetState(State newState)
   {
      m_State = newState;
   }

   Gem::State const& Gem::GetState()
   {
      return m_State;
   }

   void Gem::Render()
   {
      if (m_State == State::Highlighted)
         {
            m_Sprite->SetColor(200,200,200);
         }
      else
         {
            m_Sprite->SetColor(255, 255, 255);
         }

      m_Sprite->Render();
   }
}
