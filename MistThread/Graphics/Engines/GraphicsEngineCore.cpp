#include "GraphicsEngineCore.h"


namespace MistThread
{
  namespace Graphics
  {
    namespace Engines
    {
      void GraphicsEngineCore::DrawRectangle(const Core::RectangleF & rectangle, const Color & color)
      {
        DrawRectangle(rectangle, color, 1, 0, Vector2::Zero);
      }

      void GraphicsEngineCore::DrawRectangle(const Core::RectangleF & rectangle, const Color & color, float stroke)
      {
        DrawRectangle(rectangle, color, stroke, 0, Vector2::Zero);
      }

      void GraphicsEngineCore::DrawRectangle(const Core::RectangleF & rectangle, const Color & color, float stroke, float rotation)
      {
        DrawRectangle(rectangle, color, stroke, rotation, Vector2::Zero);
      }

      void GraphicsEngineCore::DrawRectangle(const Core::Vector2 & position, const Core::Size2F & size, const Color & color)
      {
        DrawRectangle(position, size, color, 1, 0);
      }

      void GraphicsEngineCore::DrawRectangle(const Core::Vector2 & position, const Core::Size2F & size, const Color & color, float stroke)
      {
        DrawRectangle(position, size, color, stroke, 0);
      }

      void GraphicsEngineCore::DrawRectangle(const Core::Vector2 & position, const Core::Size2F & size, const Color & color, float stroke, float rotation, float zLayer)
      {
        Core::RectangleF rect(position.X, position.Y, size.Width, size.Height);
        DrawRectangle(rect, color, stroke, rotation, Vector2(size.Width/2, size.Height/2), zLayer);
      }

      void GraphicsEngineCore::DrawEllipse(const Core::Vector2 & posistion, const Core::Size2F size, const Color & color)
      {
        DrawEllipse(posistion, size, color, 1, 0, Vector2::Zero);
      }

      void GraphicsEngineCore::DrawEllipse(const Core::Vector2 & posistion, const Core::Size2F size, const Color & color, float stroke)
      {
        DrawEllipse(posistion, size, color, stroke, 0, Vector2::Zero);
      }

      void GraphicsEngineCore::DrawEllipse(const Core::Vector2 & posistion, const Core::Size2F size, const Color & color, float stroke, float rotation)
      {
        DrawEllipse(posistion, size, color, stroke, rotation, Vector2::Zero);
      }

      void GraphicsEngineCore::FillEllipse(const Core::Vector2 & position, const Core::Size2F size, const Color & color)
      {
        FillEllipse(position, size, color, 0, Vector2::Zero);
      }

      void GraphicsEngineCore::FillEllipse(const Core::Vector2 & position, const Core::Size2F size, const Color & color, float rotation)
      {
        FillEllipse(position, size, color, rotation, Vector2::Zero);
      }

      void GraphicsEngineCore::FillRectangle(const Core::RectangleF & rectangle, const Color & color)
      {
        FillRectangle(rectangle, color, 0, Vector2::Zero);
      }

      void GraphicsEngineCore::FillRectangle(const Core::RectangleF & rectangle, const Color & color, float rotation)
      {
        FillRectangle(rectangle, color, rotation, Vector2::Zero);
      }

      void GraphicsEngineCore::FillRectangle(const Core::Vector2 & position, const Core::Size2F & size, const Color & color)
      {
        FillRectangle(position, size, color, 0);
      }

      void GraphicsEngineCore::FillRectangle(const Core::Vector2 & position, const Core::Size2F & size, const Color & color, float rotation, float zLayer)
      {
        Core::RectangleF rect(position.X, position.Y, size.Width, size.Height);
        FillRectangle(rect, color, rotation, Vector2(size.Width / 2, size.Height / 2), zLayer);
      }

      void GraphicsEngineCore::DrawString(const std::string & text, const TextFormat & font, const Vector2 & position, const Color & color, float rotation, float zLayer)
      {
        Size2 bounds = GetWindowBounds();
        DrawString(text, font, Core::RectangleF(0.0f, 0.0f, static_cast<float>(bounds.Width), static_cast<float>(bounds.Height)), position, color, rotation, zLayer);
      }

      void GraphicsEngineCore::DrawString(const std::string & text, const Vector2 & position, const Color & color, float rotation, float zLayer)
      {
        Size2 bounds = GetWindowBounds();
        DrawString(text, GetDefaultTextFormat(), Core::RectangleF(0.0f, 0.0f, static_cast<float>(bounds.Width), static_cast<float>(bounds.Height)), position, color, rotation, zLayer);
      }
    }
  }
}
