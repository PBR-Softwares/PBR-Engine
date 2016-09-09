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

#include    "PBR/Core/SceneManager.hpp"
#include    "PBR/Core/Scene.hpp"

namespace   PBR
{
    namespace   Core
    {
        SceneManager::SceneManager(void) :
            m_active_scene(nullptr),
            m_scenes()
        {

        }

        SceneManager::SceneManager(const SceneManager &other) :
            m_active_scene(other.m_active_scene),
            m_scenes(other.m_scenes)
        {

        }

        SceneManager::SceneManager(SceneManager &&other) noexcept :
            m_active_scene(std::move(other.m_active_scene)),
            m_scenes(std::move(other.m_scenes))
        {
        }

        SceneManager::~SceneManager(void)
        {

        }



        SceneManager &
        SceneManager::operator=(const SceneManager &other)
        {
            this->m_active_scene = other.m_active_scene;
            this->m_scenes = other.m_scenes;
            return *this;
        }

        SceneManager &
        SceneManager::operator=(SceneManager &&other) noexcept
        {
             this->m_active_scene = std::move(other.m_active_scene);
             this->m_scenes = std::move(other.m_scenes);
             return *this;
        }



        bool
        SceneManager::exist(const std::string &scene_name)
        {
            return this->m_scenes.find(scene_name) != this->m_scenes.end();
        }

        std::shared_ptr<Scene> &
        SceneManager::search(const std::string &scene_name)
        {
            return this->m_scenes.find(scene_name)->second;
        }

        const std::shared_ptr<Scene> &
        SceneManager::search(const std::string &scene_name) const
        {
            return this->m_scenes.find(scene_name)->second;
        }



        std::shared_ptr<Scene> &
        SceneManager::create(const std::string &scene_name)
        {
            auto result = this->m_scenes.insert({scene_name, std::make_shared<Scene>(scene_name)});
            if (result.second == false)
            {
                throw std::runtime_error("A scene name with a similar name already exist in the scene manager.");
            }
            return (*(result.first)).second;
        }

        bool
        SceneManager::add(std::shared_ptr<Scene> &scene)
        {
            return this->m_scenes.insert({scene->name(), scene}).second;
        }

        bool
        SceneManager::remove(const std::string &scene_name)
        {
            return this->m_scenes.erase(scene_name) > 0;
        }



        bool
        SceneManager::active_scene(const std::string &scene_name)
        {
            this->m_active_scene = this->search(scene_name);
            return this->m_active_scene == nullptr;
        }

        void
        SceneManager::unactive_scene(void)
        {
            this->m_active_scene = nullptr;
        }



        std::shared_ptr<Scene> &
        SceneManager::active_scene(void)
        {
             return this->m_active_scene;
        }

        const std::shared_ptr<Scene> &
        SceneManager::active_scene(void) const
        {
            return this->m_active_scene;
        }
    }
}
