#ifndef IMOUSE_LISTENER_H
#define IMOUSE_LISTENER_H

#include <SDL.h>

namespace King
{
   /*! Interface to listen to SDL Mouse events
   *
   */
   class IMouseListener
   {
      public:
         virtual ~IMouseListener() {}
         /*! Get called when user moves the mouse */
         virtual void OnMouseMove(const uint32_t& mouseX, const uint32_t& mouseY) = 0;
         /*! Get called when user presses a mouse button */
         virtual void OnMouseDown(SDL_Event* in_Event) = 0;
         /*! Get called when user releases a mouse button */
         virtual void OnMouseReleased(SDL_Event* in_Event) = 0;
   };
}

#endif
