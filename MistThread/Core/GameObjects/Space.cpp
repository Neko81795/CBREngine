#include "Space.h"
#include "Components/UpdateEvent.h"
#include "Components/TransformComponent.h"
#include "Components/CameraComponent.h"
#include "../../IO/XML/XMLFile.h"
#include "../../Utilities/ContentManager.h"
#include "../../Graphics/Engines/GraphicsEngineCore.h"
#include "../Exception.h"

#include <fstream>

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      void Space::LoadXML(const IO::XML::XMLElement &element)
      {
        for(auto el : element.GetElementsByName("GameObject"))
        {
          auto &obj = CreateObject();
          obj.DeSerialize(*el);
        }
      }

      void Space::SaveXML(IO::XML::XMLElement &element) const
      {
        for(auto obj : Objects)
        {
          GameObject * ptr = dynamic_cast<GameObject*>(obj);
          if(ptr)
          {
            IO::XML::XMLElement el("GameObject");
            ptr->Serialize(el);
            element.Elements.push_back(el);
          }
        }
      }

      void Space::SetCamera()
      {
        auto trans = Camera->GetComponentByName<Components::TransformComponent>("Transform");
        Game.Graphics->CameraPos = trans->Position;
        Game.Graphics->CameraRotation = trans->Rotation;
        Game.Graphics->CameraZ = trans->GetZLayer();
        Game.Graphics->CameraScale = Camera->GetComponentByName<Components::CameraComponent>("Camera")->CameraScale;
      }

      void Space::Update()
      {
        SetCamera();
        GameTime.Tick();
        Components::UpdateEvent ue(GameTime);
        DispatchEvent("Update", &ue);
      }

      GameObject& Space::CreateObject()
      {
        GameObject *obj = new MistThread::Core::GameObjects::GameObject(Game, *this);
        Objects.push_back(obj);
        RegisterDraw(obj);
        return *obj;
      }

      GameObject& Space::CreateObjectAt(const Vector2 &pos, float zLayer)
      {
        GameObject &obj = *new MistThread::Core::GameObjects::GameObject(Game, *this);
        Objects.push_back(&obj);
        auto& trans = *dynamic_cast<Components::TransformComponent*>(obj.AddComponentByName("Transform"));
        trans.Position = pos;
        trans.SetZLayer(zLayer);
        RegisterDraw(&obj);
        return obj;
      }

      GameObject& Space::FindObjectByName(const std::string &name)
      {
        for(auto obj : Objects)
        {
          if(obj->Name == name)
            return *dynamic_cast<GameObject*>(obj);
        }
        //TODO add what the name of the object was.
        throw Exception("Could not find object");
      }

      const std::list<GameObject *> Space::FindObjectsByName(const std::string &name)
      {
        std::list<GameObject *> objects;
        for(auto obj : Objects)
        {
          if(obj->Name == name)
            objects.push_back(static_cast<GameObject*>(obj));
        }
        return objects;
      }

      void Space::RemoveObjectByName(const std::string &name)
      {
        RemoveGameObjectBaseByName(name);
      }

      void Space::RemoveObjectByID(long long id)
      {
        RemoveGameObjectBaseByID(id);
      }

      int Space::CompareTo(const GameObjectBase* other)const
      {
        if(other->Type == "Game")
          return -1;
        if(other->Type == "GameObject")
          return 1;

        const Space &s = *dynamic_cast<const Space*>(other);

        return this->SpaceLayer - s.SpaceLayer;
      }

      void Space::LoadLevel(const std::string &path)
      {
        IO::XML::XMLFile level(Utilities::ContentManager::RootFolder + path);
        auto el = level.Elements.back();

        for(int i = 0; i < Objects.size();)
        {
          if(!Objects[i]->Persistent)
            RemoveGameObjectBaseByID(Objects[i]->ID);
          else
            ++i;
        }
        LoadXML(el);

        if(Game.GetIsRunning())
          Initialize();
      }

      void Space::SaveLevel(const std::string &path) const
      {
        IO::XML::XMLElement level("Level");

        SaveXML(level);

        std::fstream file(Utilities::ContentManager::RootFolder + path, std::fstream::out);
        

        file << level;

        file.close();
      }

      void Space::SetSpaceLayer(int layer)
      {
        SpaceLayer = layer;
        if (DrawnBy)
          DrawnBy->UpdateObjectDrawOrder(this);
        UpdateOwnDrawOrder();
      }

      int Space::GetSpaceLayer() const
      {
        return SpaceLayer;
      }

      void Space::Draw(Graphics::Engines::GraphicsEngineCore &graphics, GameObjectBase* caller)
      {
        if(caller != this)
          SetCamera();

        GameObjectBase::Draw(graphics, caller);
      }

      Space::Space(Core::Game & game) : GameObjectBase(game, *this)
      {
        Type = "Space";
      }

      Space::~Space()
      {

      }
    }
  }
}
