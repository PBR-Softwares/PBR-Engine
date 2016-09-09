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

#include    <string>

#include    "PBR/Core/Configuration.hpp"

namespace   PBR
{
    namespace   Core
    {
        ///
        /// \brief The Mesh class
        ///
        class PBR_CORE_EXPORTS Mesh final
        {
            public:
                ///
                /// \brief Create an empty mesh.
                ///
                Mesh(void);

                ///
                /// \brief Copy constructor.
                ///
                Mesh(const Mesh &other) = default;

                ///
                /// \brief Move constructor.
                ///
                Mesh(Mesh &&other) noexcept = default;

                ///
                /// \brief Destructor
                ///
                virtual ~Mesh(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                Mesh    &operator=(const Mesh &other) = default;

                ///
                /// \brief Move assignment operator.
                ///
                Mesh    &operator=(Mesh &&other) noexcept = default;

            private:
                ///
                /// \brief The name of the mesh.
                ///
                /// the name is optional, could be an empty string.
                ///
                std::string     m_name;

        };
    }
}
