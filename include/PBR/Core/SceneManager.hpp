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
#include    <unordered_map>
#include    <stack>

#include    "PBR/Core/Configuration.hpp"

namespace   PBR
{
    namespace   Core
    {
        class Scene;
        ///
        /// \brief The SceneManager class is used to manage the scene that will be used by the engine.
        ///
        /// You can easily search, add, delete, active or disactive scene in the scene manager.
        ///
        class PBR_CORE_EXPORTS SceneManager final
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                /// The default constructor don't create any scene, you will get a scene manager with no active scene
                /// and no scene at all in the scene container.
                ///
                SceneManager(void);

                ///
                /// \brief Copy constructor.
                /// \param other The original scene manager that will be used for the copy.
                ///
                /// When you copy a scene manager into another, the original scene manager keep
                /// the same configuration. I.E the active scene and the scenes doesnt change.
                ///
                /// For the destination scene manager, the scenes are not copied, that only instantiate
                /// a new shared_ptr for the scenes managed by the scene manager.
                ///
                /// If you want to copy the scenes in order to have two differents scene manager with
                /// no scene in common, you need to do that yourself.
                ///
                SceneManager(const SceneManager &other);

                ///
                /// \brief Move constructor.
                /// \param other The original scene manager that will be moved into the new one.
                ///
                /// When you move a scene manager into another, the original scene manager
                /// will be emptied and the destination sm will be filled with the scenes
                /// from the original one.
                ///
                SceneManager(SceneManager &&other) noexcept;

                ///
                /// \brief Destructor.
                ///
                /// The scene are not destructed, only the shared_ptr. So the scene will be free only if the are used
                /// only in this scene manager.
                ///
                ~SceneManager(void);

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                /// When you copy a scene manager into another, the original scene manager keep
                /// the same configuration. I.E the active scene and the scenes doesnt change.
                ///
                /// For the destination scene manager, the scenes are not copied, that only instantiate
                /// a new shared_ptr for the scenes managed by the scene manager.
                ///
                /// If you want to copy the scenes in order to have two differents scene manager with
                /// no scene in common, you need to do that yourself.
                ///
                SceneManager    &operator=(const SceneManager &other);

                ///
                /// \brief Move assignment operator.
                ///
                /// When you move a scene manager into another, the original scene manager
                /// will be emptied and the destination sm will be filled with the scenes
                /// from the original one.
                ///
                SceneManager    &operator=(SceneManager &&other) noexcept;

            public:
                ///
                /// \brief Search if in the SceneManager a scene match the name 'scene_name'.
                /// \param scene_name The name of the scene that should be searched.
                /// \return True if a scene exist with this name, false otherwise.
                ///
                bool    exist(const std::string &scene_name);

                ///
                /// \brief Search in the SceneManager the map that match the name 'scene_name'.
                /// \param scene_name The name of the scene that should be searched.
                /// \return A shared_ptr that point to the scene researched or nullptr if the scene as not been found.
                ///
                std::shared_ptr<Scene>  &search(const std::string &scene_name);

                ///
                /// \brief Search in the SceneManager the map that match the name 'scene_name'.
                /// \param scene_name The name of the scene that should be searched.
                /// \return A const shared_ptr that point to the scene researched or nullptr if the scene as not been found.
                ///
                const std::shared_ptr<Scene>  &search(const std::string &scene_name) const;

            public:
                ///
                /// \brief Create a new empty scene, the scene name will be set to 'scene_name'.
                /// \param scene_name The scene name used for the new scene.
                /// \return A shared_ptr that point to the new scene.
                ///
                std::shared_ptr<Scene>  &create(const std::string &scene_name);

                ///
                /// \brief Add an external scene to the scene manager.
                /// \return True if the scene as been inserted in the scene manager, false otherwise. If the scene has not been inserted, thats most likely because another scene exist with the name of the scene.
                ///
                /// This function can throw an exception if the scene name is already used by another scene in this scene manager.
                ///
                bool    add(std::shared_ptr<Scene> &scene);

                ///
                /// \brief Remove the scene named 'scene_name'.
                /// \return True if the scene has been removed from the scene manager, false otherwise. If the scene has not been removed thats most likely that no scene exist with the name given in parameter.
                ///
                /// The scene will be really destroyed only if no other shared_ptr point to this scene.
                ///
                bool    remove(const std::string &scene_name);

            public:
                ///
                /// \brief Set the active scene to the scene that match the scene name given in parameter.
                /// \param scene_name The scene name that should be set as active.
                /// \return True if the scene has been found and set as active, false otherwise.
                ///
                bool    active_scene(const std::string &scene_name);

                ///
                /// \brief This function desactive the current active scene. No scene will be set as active.
                ///
                void    unactive_scene(void);

            public:
                ///
                /// \brief Getter for the active scene of the SceneManager.
                /// \return A valid shared pointer or a shared_ptr that point to nullptr if no active scene is set in the scene manager.
                ///
                std::shared_ptr<Scene>          &active_scene(void);

                ///
                /// \brief Const getter for the active scene of the SceneManager.
                /// \return A valid const shared pointer or a shared_ptr that point to nullptr if no active scene is set in the scene manager.
                ///
                const std::shared_ptr<Scene>    &active_scene(void) const;

            private:
                ///
                /// \brief This pointer is used to keep the scene as active.
                ///
                std::shared_ptr<Scene>  m_active_scene;

                ///
                /// \brief Container for the scene managed by the scene manager.
                ///
                /// We use an unordered_map in order to have an efficient scene search.
                ///
                std::unordered_map<std::string, std::shared_ptr<Scene>>     m_scenes;
        };
    }
}
