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

#include    <glm/glm.hpp>
#include    <algorithm>

#include    "PBR/Core/Scene.hpp"
#include    "PBR/Core/Object.hpp"

namespace   PBR
{
    namespace   Core
    {
        Scene::Scene(const std::string &name) :
            m_name(name),
            m_root_node(this),
            m_nodes(),
            m_texture_library(),
            m_material_library(),
            m_mesh_library(),
            m_event_register(),
            m_clock()
        {
            // nothing to do.
        }

        Scene::Scene(const Scene &other) :
            m_name(other.m_name),
            m_root_node(other.m_root_node),
            m_nodes(),
            m_texture_library(other.m_texture_library),
            m_material_library(other.m_material_library),
            m_mesh_library(other.m_mesh_library),
            m_event_register(other.m_event_register),
            m_clock(other.m_clock)
        {
            this->reconstruct_unordered_node_map();
        }

        Scene::Scene(Scene &&other) noexcept :
            m_name(std::move(other.m_name)),
            m_root_node(std::move(other.m_root_node)),
            m_nodes(std::move(other.m_nodes)),
            m_texture_library(std::move(other.m_texture_library)),
            m_material_library(std::move(other.m_material_library)),
            m_mesh_library(std::move(other.m_mesh_library)),
            m_event_register(std::move(other.m_event_register)),
            m_clock(std::move(other.m_clock))
        {
        }

        Scene::~Scene(void)
        {
        }



        Scene &
        Scene::operator=(const Scene &other)
        {
            this->m_name = other.m_name;
            this->m_root_node = other.m_root_node;
            this->m_texture_library = other.m_texture_library;
            this->m_material_library = other.m_material_library;
            this->m_mesh_library = other.m_mesh_library;
            this->m_event_register = other.m_event_register;
            this->m_clock = other.m_clock;
            this->reconstruct_unordered_node_map();
            return *this;
        }

        Scene &
        Scene::operator=(Scene &&other) noexcept
        {
            this->m_name = std::move(other.m_name);
            this->m_root_node = std::move(other.m_root_node);
            this->m_nodes = std::move(other.m_nodes);
            this->m_texture_library = std::move(other.m_texture_library);
            this->m_material_library = std::move(other.m_material_library);
            this->m_mesh_library = std::move(other.m_mesh_library);
            this->m_event_register = std::move(other.m_event_register);
            this->m_clock = std::move(other.m_clock);
            return *this;
        }



        void
        Scene::update(void)
        {
            this->m_root_node.update();
        }

        void
        Scene::push_event(const Event &event)
        {
            this->m_event_register.push_event(event);
        }



        const std::string &
        Scene::name(void) const
        {
            return this->m_name;
        }

        Scene::Node &
        Scene::root_node(void)
        {
            return this->m_root_node;
        }

        const Scene::Node &
        Scene::root_node(void) const
        {
            return this->m_root_node;
        }

        TextureLibrary &
        Scene::texture_library(void)
        {
            return this->m_texture_library;
        }

        const TextureLibrary &
        Scene::texture_library(void) const
        {
            return this->m_texture_library;
        }

        MaterialLibrary &
        Scene::material_library(void)
        {
            return this->m_material_library;
        }

        const MaterialLibrary &
        Scene::material_library(void) const
        {
            return this->m_material_library;
        }

        MeshLibrary &
        Scene::mesh_library(void)
        {
             return this->m_mesh_library;
        }

        const MeshLibrary &
        Scene::mesh_library(void) const
        {
             return this->m_mesh_library;
        }

        Clock &
        Scene::clock(void)
        {
            return this->m_clock;
        }

        const Clock &
        Scene::clock(void) const
        {
            return this->m_clock;
        }
    }
}
