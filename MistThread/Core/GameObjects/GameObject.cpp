#include "GameObject.h"
#include "Components/DrawEvent.h"
#include "Components/ObjectDestroyedEvent.h"
#include "Components/TransformComponent.h"

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      GameObject& GameObject::CreateChild()
      {
        GameObject *obj = new MistThread::Core::GameObjects::GameObject(Game, Space);
        Objects.push_back(obj);
        RegisterDraw(obj);
        return *obj;
      }

      GameObject& GameObject::CreateChildAt(const Vector2 &pos, float zLayer)
      {
        GameObject &obj = *new MistThread::Core::GameObjects::GameObject(Game, Space);
        Objects.push_back(&obj);
        auto& trans = *dynamic_cast<Components::TransformComponent*>(obj.AddComponentByName("Transform"));
        trans.Position = pos;
        trans.SetZLayer(zLayer);
        RegisterDraw(&obj);
        return obj;
      }

      GameObject& GameObject::FindChildByName(const std::string &name)
      {
        for (auto obj : Objects)
        {
          if (obj->Name == name)
            return *dynamic_cast<GameObject*>(obj);
        }

        std::string err("Could not find object: " + name);
        throw std::exception(err.c_str());
      }

      void GameObject::RemoveChildByName(const std::string &name)
      {
        RemoveGameObjectBaseByName(name);
      }

      void GameObject::RemoveChildByID(long long id)
      {
        RemoveGameObjectBaseByID(id);
      }

      void GameObject::ParentTo(GameObject &object)
      {
        object.Adopt(*this);
      }

      void GameObject::UnParent()
      {
        if (Parent)
          Parent->Orphan(*this);
        else
          return;
        //get space to adopt it
        Space.Objects.push_back(this);
        Space.RegisterDraw(this);
      }

      void GameObject::Adopt(GameObject &object)
      {
        if (object.Parent)
          object.Parent->Orphan(object);
        else
        {
          for (auto it = Space.Objects.begin(); it != Space.Objects.end(); it++)
          {
            if ((*it)->ID == object.ID)
            {
              Space.Objects.erase(it);
              break;
            }
          }
        }
        Objects.push_back(&object);
        object.Parent = this;
      }

      void GameObject::Orphan(GameObject &object)
      {
        for (auto it = Objects.begin(); it != Objects.end(); it++)
        {
          if ((*it)->ID == object.ID)
          {
            Objects.erase(it);
            break;
          }
        }

        Space.Objects.push_back(&object);
        object.Parent = NULL;
      }

      int GameObject::CompareTo(const GameObjectBase* other)const
      {
        if (other->Type != "GameObject")
          return -1;

        const GameObject &g = *dynamic_cast<const GameObject *>(other);

        const Components::TransformComponent * myTrans = dynamic_cast<const Components::TransformComponent *>(GetComponentByName("Transform"));
        const Components::TransformComponent * gTrans = dynamic_cast<const Components::TransformComponent *>(g.GetComponentByName("Transform"));

        if (!myTrans && !gTrans)
          return 0;
        else if (!myTrans)
          return 1;
        else if (!gTrans)
          return -1;

        if (myTrans->GetZLayer() < gTrans->GetZLayer())
          return -1;
        else if (myTrans->GetZLayer() > gTrans->GetZLayer())
          return 1;
        else
          return 0;
      }

      void GameObject::InitializeFromXML(const IO::XML::XMLElement & element)
      {
        Name = element.GetAttributeByName("Name").Value;

        for (auto el : element.GetElementsByName("Component"))
        {
          AddComponentByName(el->GetAttributeByName("Name").Value)->InitializeFromXML(*el);
        }

        for (auto el : element.GetElementsByName("GameObject"))
        {
          CreateChild().InitializeFromXML(*el);
        }
      }

      void GameObject::Destroy()
      {
        Components::ObjectDestroyedEvent eve(this);
        DispatchEvent("ObjectDestroyed", &eve);
        for (auto comp : Components)
        {
          comp.second->Destroyed();
        }

        if (Parent)
          Parent->RemoveChildByID(ID);
        else
          Space.RemoveObjectByID(ID);
      }

      /// <summary>
      /// returns if a component has already been added to an XML element
      /// </summary>
      /// <param name="name">the name of the component</param>
      /// <param name="element">the element to check against</param>
      static bool AlreadyAdded(const std::string &name, const IO::XML::XMLElement & element)
      {
        for (auto el : element.GetElementsByName("Component"))
        {
          if (el->GetAttributeByName("Name").Value == name)
            return true;
        }

        return false;
      }
      /// <summary>
      /// Adds all dependencies of a component to an XML element
      /// </summary>
      /// <param name="component">the component that has dependencies to add</param>
      /// <param name="element">the element to add to</param>
      /// <param name="components">the components of an object to find dependencies from</param>
      static void AddDependencys(const Components::Component &component, IO::XML::XMLElement & element, const std::map<std::string, Components::Component*> &components)
      {
        for (auto dep : component.Dependencies)
        {
          if (!AlreadyAdded(dep, element))
          {
            //! GEEZE AGAIN!?!?!?!?!?!?! WTF MAN!! *not as panicked hoers noises*
            //it's fine cause I'm not changing it though >.>
            //or at least I shouldn't be because all the dependencies should be there in the first place
            const Components::Component& comp = *static_cast<std::map<std::string, Components::Component*>>(components)[dep];

            AddDependencys(comp, element, components);

            IO::XML::XMLElement el("Component");
            comp.PopulateXML(el);
            element.Elements.push_back(el);
          }
        }
      }

      void GameObject::PopulateXML(IO::XML::XMLElement & element) const
      {
        element.SetAttribute("Name", Name);

        for (auto comp : Components)
        {
          if (!AlreadyAdded(comp.first, element))
          {
            AddDependencys(*comp.second, element, Components);

            IO::XML::XMLElement el("Component");
            comp.second->PopulateXML(el);
            element.Elements.push_back(el);
          }
        }
        for (auto *objb : Objects)
        {
          GameObject* obj = dynamic_cast<GameObject*>(objb);
          if (obj)
          {
            IO::XML::XMLElement el("GameObject");
            obj->PopulateXML(el);
            element.Elements.push_back(el);
          }
        }
      }

      GameObject::GameObject(Core::Game &game, GameObjects::Space &space) : GameObjectBase(game, space)
      {
        Type = "GameObject";
      }

      GameObject::~GameObject()
      {

      }
    }
  }
}
