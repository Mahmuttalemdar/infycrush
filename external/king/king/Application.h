#ifndef APPLICATION_H
#define APPLICATION_H

#include <cstdint>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <memory>


namespace King
{
   class Sprite;
   class Label;
   class InputManager;
   class BoardModel;
   class BoardView;
   class BoardController;
   class CountdownTimer;

   /*! Central Application class
*	Sets up the whole application and runs the main logic and rendering loop
*/
   class Application
   {

      public:

         /*! \brief Executes the application
         *
         *	\return Returns 0 if everything is ok and 1 if there was an error
         */
         int Execute(int argc, char* argv[]);

         // returns singleton instance
         static Application* GetInstance();

         // returns a pointer to the SDL renderer
         SDL_Renderer* GetRenderer() const;

         // returns the path where the assets root folder
         std::string GetRootAssetsFolder() const;

         // returns the path where the main font is located
         std::string GetMainFontPath() const;

      private:

         /*! \brief Executes the application
         *
         */
         bool Initialize();

         // logic loop
         void Update();

         // render loop
         void Render();

         // free all resources
         void CleanUp();

         // SDL Event Handler
         void OnEvent(SDL_Event* Event);

         // callback function that gets invokes when countdown has reached zero
         void OnCountdownFinished();

      private:
         // Singleton
         static Application Instance;

         // basic SDL stuff
         SDL_Window* m_Window = nullptr;
         SDL_Renderer* m_Renderer = nullptr;
         SDL_Surface* m_MainSurface = nullptr;
         std::unique_ptr<Sprite> m_Background;

         //target framerate
         static const uint32_t m_TargetFrameRate = 60;

         // inital window dimensions
         static const uint32_t m_WindowWidth = 755;
         static const uint32_t m_WindowHeight = 600;

         //input
         InputManager* m_InputMgr = nullptr;

         // controller that handles game logic
         std::unique_ptr<BoardController> m_BoardController;
         // visual representation of board
         std::unique_ptr<BoardView> m_BoardView;

         std::unique_ptr<CountdownTimer> m_CountdownTimer;

         // flags for determining the current game state
         bool m_IsRunning;
         bool m_HasGameStarted;
         bool m_HasGameFinished;

         // start screen
         std::unique_ptr<Sprite> m_OverlayBackground;
         std::unique_ptr<Label> m_WelcomeLabel;
         std::unique_ptr<Label> m_StartGameLabel;

         // game over screen
         std::unique_ptr<Label> m_GameOverLabel;
         std::unique_ptr<Label> m_PlayAgainLabel;

         // members for maintaining target framerate
         uint32_t m_WaitTime = static_cast<uint32_t>(1000.0f / m_TargetFrameRate);
         uint32_t m_FrameStartTime = 0;
         int32_t m_DelayTime;

         // file path to the root assets folder
         static const std::string ROOT_ASSETS_FOLDER;
         // file path to the main font
         static const std::string FONT_PATH;
         // file path to the overlay sprite
         static const std::string BACKGROUND_PATH;
         // file path to the overlay sprite
         static const std::string OVERLAY_PATH;

   };
}

#endif  // APPLICATION_H
