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

#include    "PBR/Core/Entity.hpp"

namespace   PBR
{
    namespace   Core
    {
        Entity::Entity(Scene::Node *node) :
            m_node(node)
        {

        }

        Entity::Entity(const Entity &other) :
            m_node(other.m_node)
        {

        }

        Entity::Entity(Entity &&other) :
            m_node(std::move(other.m_node))
        {

        }

        Entity::~Entity(void)
        {

        }



        Entity &
        Entity::operator=(const Entity &other)
        {
            this->m_node = other.m_node;
            return *this;
        }

        Entity &
        Entity::operator=(Entity &&other)
        {
            this->m_node = std::move(other.m_node);
            return *this;
        }
    }
}
