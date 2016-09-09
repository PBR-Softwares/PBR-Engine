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
// Copyright (C) 2016 PBR-Software
//

#include    "PBR/Core/Version.hpp"
#include    "PBR/Core/Configuration.hpp"
#include    "PBR/Core/Engine.hpp"
#include    "PBR/Core/SceneManager.hpp"
#include    "PBR/Core/Scene.hpp"

namespace   PBR
{
    namespace   Core
    {
        Engine::Engine(void) :
            m_scene_manager()
        {
            // Nothing to do
        }

        Engine::Engine(const Engine &other) :
            m_scene_manager(other.m_scene_manager)
        {
            // Nothing to do.
        }

        Engine::Engine(Engine &&other) noexcept :
        m_scene_manager(std::move(other.m_scene_manager))
        {
            // nothing to do.
        }

        Engine::~Engine(void)
        {
            // Nothing to do.
        }



        Engine &
        Engine::operator=(const Engine &other)
        {
            this->m_scene_manager = other.m_scene_manager;
            return *this;
        }

        Engine &
        Engine::operator=(Engine &&other) noexcept
        {
            this->m_scene_manager = std::move(other.m_scene_manager);
            return *this;
        }



        void
        Engine::update(void)
        {
            this->m_scene_manager.active_scene()->update();
        }

        void
        Engine::push_event(const Event &event)
        {
            this->m_scene_manager.active_scene()->push_event(event);
        }
    }
}
