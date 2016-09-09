//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; If not, see <http://www.gnu.org/licenses/>.
//
// Copyright (C) 2016 PBR-Softwares (contact@pbr-softwares.com)
//

#pragma once

#include    <memory>
#include    <list>
#include    <unordered_map>
#include    <typeinfo>
#include    <utility>

#include    "PBR/Core/Configuration.hpp"
#include    "PBR/Core/MaterialLibrary.hpp"
#include    "PBR/Core/MeshLibrary.hpp"
#include    "PBR/Core/TextureLibrary.hpp"
#include    "PBR/Core/EventRegister.hpp"
#include    "PBR/Core/Clock.hpp"
#include    "PBR/Core/Transform.hpp"

namespace   PBR
{
    namespace   Core
    {
        class   Entity;
        ///
        /// \brief This class is used to represent a scene.
        ///
        /// The scene class use a scene graph to organize the scene.
        ///
        class PBR_CORE_EXPORTS Scene final
        {
            public:
                ///
                /// \brief The node class is used to represent a full scene graph.
                ///
                /// The scene graph is basically a n-ary tree.
                ///
                class   PBR_CORE_EXPORTS Node final
                {
                    public:
                        ///
                        /// \brief Default constructor for a node scene.
                        /// \param scene The scene that will contains the node.
                        /// \param parent The scene node parent of the node.
                        ///
                        Node(Scene *scene = nullptr, Node *parent = nullptr, const std::string &name = "root");

                        ///
                        /// \brief Copy constructor.
                        /// \param other The other node that will be copied.
                        ///
                        /// The copy constructor will also copy every children of the node.
                        /// If you only want to copy this node and not the children node,
                        /// you need to implement that yourself or to remove every child.
                        ///
                        Node(const Node &other);

                        ///
                        /// \brief Move constructor.
                        /// \param other The other node that will be moved into the new one.
                        ///
                        Node(Node &&other) noexcept;

                        ///
                        /// \brief Destructor.
                        ///
                        ~Node(void) noexcept;

                    public:
                        ///
                        /// \brief Copy assignment operator.
                        /// \param other the other node that will be copied into this one.
                        /// \return A reference to the result node.
                        ///
                        Node    &operator=(const Node &other);

                        ///
                        /// \brief Move assignment operator.
                        /// \param other The other node that will be moved into this one.
                        /// \return A reference to the result node.
                        ///
                        Node    &operator=(Node &&other) noexcept;

                    public:
                        ///
                        /// \brief Update the node, call the update method of the attached entity if the entity exist.
                        ///
                        void    update(void);

                        ///
                        /// \brief Create an empty child node.
                        /// \return The child node created.
                        ///
                        Node    &create_child(const std::string &child_name);

                        ///
                        /// \brief Create a child node from another node.
                        /// \return The new child node.
                        ///
                        Node    &create_child(const Node &other, const std::string &child_name);

                        ///
                        /// \brief Create a child node from another node.
                        ///
                        Node    &create_child(Node &&other, const std::string &child_name);

                        ///
                        /// \brief Remove the child named 'child_name'.
                        /// \brief Return true if the operation succeed, false otherwise.
                        ///
                        /// If the operation failed, thats most likely that no child exist with the name 'child_name'.
                        /// The method is not recursive. If you are not looking for direct child, you should not use this method.
                        /// I.e the method don't work for child of child.
                        ///
                        bool    remove_child(const std::string &child_name);

                    public:
                        ///
                        /// \brief Const iterator to the begin of the children list.
                        ///
                        /// This method should only be used to iterate over every child.
                        ///
                        /// If you want to remove or access a child, you need to use one of the following method :
                        ///     - bool remove_child(const std::string &child_name);
                        ///     - Node &child(onst std::string &child_name);
                        //. These functions use an unordered_map to keep O(1) lookup and deletion.
                        ///
                        std::list<Node>::const_iterator  child_begin(void) const;

                        ///
                        /// \brief Const iterator to the end of the children list.
                        ///
                        /// This method should only be used to iterate over every child.
                        ///
                        /// If you want to remove or access a child, you need to use one of the following method :
                        ///     - bool remove_child(const std::string &child_name);
                        ///     - Node &child(onst std::string &child_name);
                        //. These functions use an unordered_map to keep O(1) lookup and deletion.
                        ///
                        std::list<Node>::const_iterator  child_end(void) const;

                    public:
                        ///
                        /// \brief Setter for the node name.
                        /// \param name The new name of the node.
                        ///
                        void    name(const std::string &name);

                    public:

                        ///
                        /// \brief Const getter for the transform attached to this node.
                        /// \return The const name of the node.
                        ///
                        const std::string   &name(void) const;

                        ///
                        /// \brief Getter for the scene that contain the node.
                        /// \return The scene that contain the node.
                        ///
                        Scene   *scene(void);

                        ///
                        /// \brief Const getter for the scene that contain the node.
                        /// \return The const scene that contain the node.
                        ///
                        const Scene   *scene(void) const;

                        ///
                        /// \brief Getter for the parent node of the node.
                        /// \return the parent node.
                        ///
                        /// If the node is a root node, the parent will be nullptr.
                        ///
                        Node    *parent(void);

                        ///
                        /// \brief Const getter for the parent node.
                        /// \return the const parent node.
                        ///
                        /// If the node is a root node, the parent will be nullptr.
                        ///
                        const Node  *parent(void) const;

                        ///
                        /// \brief Getter for the child with the name 'name'
                        /// \return The child with the name 'name'
                        ///
                        /// The complexity of the function should be O(1).
                        ///
                        Node    &child(const std::string &name);

                        ///
                        /// \brief Const getter for the child with the name 'name'
                        /// \return The const child with the name 'name'
                        ///
                        /// The complexity of the function should be O(1).
                        ///
                        const Node  &child(const std::string &name) const;

                        ///
                        /// \brief Getter for the transform attached to this node.
                        /// \return The transform of the node.
                        ///
                        Transform     &transform(void);

                        ///
                        /// \brief Const getter for the transform attached to this node.
                        /// \return The const transform of the node.
                        ///
                        const Transform     &transform(void) const;

                    private:
                        ///
                        /// \brief The node name, mostly used to find a specific node in the scene graph.
                        ///
                        std::string         m_name;

                        ///
                        /// \brief The scene that contain this node.
                        ///
                        Scene               *m_scene;

                        ///
                        /// \brief The parent node of the node, used to implement the n-ary tree container.
                        ///
                        /// This attribute can be a nullptr, if the node is a root node.
                        ///
                        Node                *m_parent;

                        ///
                        /// \brief The childrens attached to this node, each childrens is owned by the parent node.
                        ///
                        /// This attribute can be empty.
                        /// This attribute is part of the n-ary container.
                        ///
                        std::list<Node>     m_childrens;

                        ///
                        /// \brief Internal use only, this attribute contain the iterator in the parent list of children.
                        ///
                        /// This attribute can be not initialized if the node parent is nullptr. This attribute is used
                        /// to keep the complexity of child deletion to O(1) (in most case).
                        ///
                        std::list<Node>::iterator   m_iterator;

                        ///
                        /// \brief The entity attached to the node, if any.
                        ///
                        Entity              *m_entity;

                        ///
                        /// \brief The transform that the node represent.
                        ///
                        Transform           m_transform;
                };

            public:
                ///
                /// \brief Default constructor. This constructor create an empty scene.
                ///
                Scene(const std::string &name);

                ///
                /// \brief Copy constructor.
                /// \param other The scene that will be copied into the new one.
                ///
                /// WARNING, this method will duplicate the scene, that can be extremely costly.
                ///
                Scene(const Scene &other);

                ///
                /// \brief Move constructor.
                /// \param other The scene that will be moved into the new one.
                ///
                Scene(Scene &&other) noexcept;

                ///
                /// \brief Destructor.
                ///
                ~Scene(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                /// \param other The scene that will be copied into this one.
                ///
                /// WARNING, this method will duplicate the scene, that can be extremely costly.
                ///
                Scene       &operator=(const Scene &other);

                ///
                /// \brief Move assignment operator.
                /// \param other The scene that will be moved into the new one.
                ///
                Scene       &operator=(Scene &&other) noexcept;

            public:
                ///
                /// \brief This function is used to update the scene.
                ///
                void    update(void);

                ///
                /// \brief This function is used to push a new event in the scene.
                ///
                void    push_event(const Event &event);

                ///
                /// \brief Get the entities that match the template class.
                /// \return The list of entities that match the template class.
                ///
                /// Should be O(1)
                ///
                template<class T>
                const std::list<T *>    &entities(void);

                ///
                ///
                ///
                std::unordered_map<std::string, Entity *>::const_iterator    &entities(void) const;

            public:
                ///
                /// \brief Getter for the scene name.
                /// \return The name of the scene.
                ///
                const std::string       &name(void) const;

                ///
                /// \brief Getter for the root node of the scene.
                /// \return The root node.
                ///
                Node    &root_node(void);

                ///
                /// \brief Const getter for the root node of the scene.
                /// \return the const root node.
                ///
                const Node  &root_node(void) const;

                ///
                /// \brief Getter for the texture library used by the scene.
                /// \return the texture library used by the scene.
                ///
                TextureLibrary  &texture_library(void);

                ///
                /// \brief Const getter for the texture library used by the scene.
                /// \return the const texture library used by the scene.
                ///
                const TextureLibrary    &texture_library(void) const;

                ///
                /// \brief Getter for the material library used by the scene.
                /// \return The material library used by the scene.
                ///
                MaterialLibrary   &material_library(void);

                ///
                /// \brief Const getter for the material library used by the scene.
                /// \return The const material library used by the scene.
                ///
                const MaterialLibrary   &material_library(void) const;

                ///
                /// \brief Getter for the mesh library used by the scene.
                /// \return The mesh library used by the scene.
                ///
                MeshLibrary     &mesh_library(void);

                ///
                /// \brief Const getter for the mesh library used by the scene.
                /// \return The const mesh library used by the scene.
                ///
                const MeshLibrary       &mesh_library(void) const;

                ///
                /// \brief Getter for the scene clock.
                /// \return The clock used by the scene.
                ///
                Clock     &clock(void);

                ///
                /// \brief Const getter for the scene clock.
                /// \return The const clock used by the scene.
                ///
                const Clock     &clock(void) const;

            private:
                ///
                /// \brief Private method used to reconstruct the unordered map node after a copy.
                ///
                /// This method is costly, should be O(N) with N the number of node in the scene graph.
                ///
                void    reconstruct_unordered_node_map(void);

            private:
                ///
                /// \brief The name of the scene.
                ///
                /// The scene name is not really useful for the scene, but can be helpful in order to
                /// search and store more than one scene.
                ///
                std::string     m_name;

                ///
                /// \brief The root node of the scene.
                ///
                Node    m_root_node;

                ///
                /// \brief Map of every existing node in the scene.
                ///
                /// Used to accelerate the lookup for node by name.
                ///
                std::unordered_map<std::string, Node *>   m_nodes;

                ///
                /// \brief Used to lookup in O(1) an entity from his name.
                ///
                std::unordered_map<std::string, Entity *>   m_entities;

                ///
                /// \brief This attribute is used to contain every entity of a specific type mapped with his type.
                ///
                std::unordered_map<std::size_t, void *>     m_sorted_entities;

                ///
                /// \brief Library of usable textures in the scene.
                ///
                TextureLibrary      m_texture_library;

                ///
                /// \brief Library of usable materials.
                ///
                MaterialLibrary     m_material_library;

                ///
                /// \brief Library of usable mesh in the scene.
                ///
                MeshLibrary     m_mesh_library;

                ///
                /// \brief The event register used in the scene.
                ///
                EventRegister   m_event_register;

                ///
                /// \brief The clock used in the scene.
                ///
                Clock   m_clock;
        };

        ///
        /// TODO try to not lookup two time in the library. I.e find && operator[]
        ///
        template<class T>
        const std::list<T *> &
        Scene::entities(void)
        {
            static_assert(std::is_base_of<Entity, T>::value and not std::is_same<Entity, T>::value, "The template class should be a sub-class of the Entity class.");
            std::size_t hash = typeid(T).hash_code();
            auto it = this->m_sorted_entities.find(hash);
            if (it == this->m_sorted_entities.end())
            {
                return *static_cast<std::list<T *> *>(this->m_sorted_entities[hash] = new std::list<T *>());
            }
            return *reinterpret_cast<const std::list<T *> *>(it->second);
        }
    }
}
