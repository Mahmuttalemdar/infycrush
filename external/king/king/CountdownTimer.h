#ifndef COUNTDOWN_TIMER_H
#define COUNTDOWN_TIMER_H

#include <functional>
#include <cstdint>
#include <memory>

namespace King
{
   class Label;

   /*! Counts down time in a given interval
*
*/
   class CountdownTimer
   {
      public:
         CountdownTimer(uint32_t startTime);
         virtual ~CountdownTimer();

         /*! \brief Set the countdown interval
       *
       * \param interval The interval in milliseconds
       */
         void SetInterval(uint32_t const& interval);

         /*! Starts  timer */
         void Start();

         /*! Stops  timer	*/
         void Stop();

         /*! Resets timer to start time	*/
         void Reset();

         /*! Updates timer logic	*/
         void Update();

         /*! Renders the countdown label */
         void Render();

         /*! Registers a handler that gets called when time is over */
         void SetFinishedHandler(std::function < void()> handlerFunction);

      private:
         uint32_t m_Time;
         uint32_t m_StartTime;
         uint32_t m_StartTicks;
         uint32_t m_Interval;

         bool m_HasStarted;

         std::unique_ptr<Label> m_Label;
         std::function < void()> m_CountdownFinishEvent;
   };
}

#endif   // COUNTDOWN_TIMER_H

