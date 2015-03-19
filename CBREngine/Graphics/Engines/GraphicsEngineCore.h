#pragma once
#include "LimitedGraphicsEngineCore.h"
#include "../Color.h"

namespace CBREngine
{
  namespace Graphics
  {
    namespace Engines
    {
      class GraphicsEngineCore : LimitedGraphicsEngineCore
      {
      public:
        /// <summary>
        /// begins the draw
        /// </summary>
        virtual void BeginDraw() __ABSTRACT;
        /// <summary>
        /// clears the screen to the specified color
        /// </summary>
        virtual void Clear(const Color &color) __ABSTRACT;
        /// <summary>
        /// ends the draw
        /// </summary>
        virtual void EndDraw() __ABSTRACT;
      };
    }
  }
}
