#ifndef GEM_H
#define GEM_H

#include <cstdint>
#include <string>
#include <memory>

namespace King
{
   class Sprite;
   /*! Holds the visual representation of a color
   *
   */
   class Gem
   {
      public:
         // gem colors
         enum class Color { Red, Green, Blue, Purple, Yellow, COUNT, NONE };
         enum class State { Normal, Dragged, Highlighted, Removed, Selected };

         Gem(Color color);
         virtual ~Gem();

         /*! Sets gem's sprite */
         void SetSprite(Sprite* const sprite);

         /*! Modifies the gem state */
         void SetState(State newState);
         /*! Returns current gem state */
         const State& GetState();

         // Getters
         Color GetColor() const { return m_Color; }

         // is the gem used on the board right now
         void SetUsed(const bool& isInUse) { m_IsInUse = isInUse; }
         bool IsUsed() const { return m_IsInUse; }

         Sprite* GetSprite() { return std::move(m_Sprite); }

         void Render();

         uint8_t m_Alpha;

      private:
         Color m_Color;
         State m_State;
         Sprite* m_Sprite;

         // flag that indicates whether the gem is currently used or not
         bool m_IsInUse;

   };
}

#endif	  // GEM_H

