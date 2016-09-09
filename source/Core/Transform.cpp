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

#include    <glm/gtc/matrix_transform.hpp>

#include    "PBR/Core/Transform.hpp"

namespace   PBR
{
    namespace   Core
    {
        Transform::Transform(void) :
            m_matrix(1)
        {
            // nothing to do
        }

        Transform::~Transform(void)
        {
            // nothing to do
        }



        void
        Transform::translate(const glm::vec3 &tranlation)
        {
            m_matrix = glm::translate(m_matrix, tranlation);
        }

        void
        Transform::scale(const glm::vec3 &s)
        {
            m_matrix = glm::scale(m_matrix, s);
        }

        void
        Transform::rotate(const glm::vec3 &rotation)
        {
            this->m_matrix = glm::rotate(this->m_matrix, rotation.x, glm::vec3(1.0, 0.0, 0.0));
            this->m_matrix = glm::rotate(this->m_matrix, rotation.y, glm::vec3(0.0, 1.0, 0.0));
            this->m_matrix = glm::rotate(this->m_matrix, rotation.z, glm::vec3(0.0, 0.0, 1.0));
        }
    }
}
