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

#include    <glm/glm.hpp>

#include    "PBR/Core/Configuration.hpp"

namespace   PBR
{
    namespace   Core
    {
        ///
        /// \brief The Transform class is used to represent an object transformation in space. (like position, rotation and scale of the object)
        ///
        /// This class should be updated with quaternion support.
        ///
        class PBR_CORE_EXPORTS Transform
        {
            public:
                ///
                /// \brief Default constructor
                ///
                Transform(void);

                ///
                /// \brief Copy constructor.
                ///
                Transform(const Transform &other);

                ///
                /// \brief Move constructor.
                ///
                Transform(Transform &&other) noexcept;

                ///
                /// \brief Destructor
                ///
                virtual ~Transform(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                Transform   &operator=(const Transform &other);

                ///
                /// \brief Move assignment operator.
                ///
                Transform   &operator=(Transform &&other) noexcept;

            public:
                ///
                /// \brief Get the matrix of the transform.
                ///
                const glm::mat4 &local_matrix(void) const;
                const glm::mat4 &world_matrix(void) const;

            public:
                ///
                /// \brief This method translate the transform.
                ///
                void    translate(const glm::vec3 &translation);

                ///
                /// \brief This method scale the transform.
                ///
                void    scale(const glm::vec3 &scale);

                ///
                /// \brief This method rotate the transform.
                ///
                void    rotate(const glm::vec3 &rotation);

            protected:
                ///
                /// \brief This matrix represent the actual state of the transform.
                ///
                glm::mat4       m_matrix;
        };
    }
}
