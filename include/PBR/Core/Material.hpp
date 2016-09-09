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
#include    <glm/glm.hpp>

#include    "PBR/Core/Configuration.hpp"

namespace   PBR
{
    namespace   Core
    {
        ///
        /// \brief This class is used to represent a material which, applied to a mesh, determine how the mesh should be rendered.
        ///
        class PBR_CORE_EXPORTS Material
        {
            public:
                ///
                /// \brief Default constructor
                ///
                Material(void);

                ///
                /// \brief Copy constructor.
                ///
                Material(const Material &other);

                ///
                /// \brief Move constructor.
                ///
                Material(Material &&other) noexcept;

                ///
                /// \brief Destructor
                ///
                virtual ~Material(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                Material    &operator=(const Material &other);

                ///
                /// \brief Move assignment operator.
                ///
                Material    &operator=(Material &&other) noexcept;

            private:
                ///
                /// \brief The name of the material
                ///
                std::string     m_name;

        };
    }
}
