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

#include    "PBR/Core/Configuration.hpp"
#include    "PBR/Core/Event.hpp"
#include    "PBR/Core/Inputs/Keyboard/Key.hpp"

namespace   PBR
{
    namespace   Core
    {
        ///
        /// \brief The KeyPressed event class, containing a key pressed event.
        ///
        class PBR_CORE_EXPORTS KeyPressed final : public Event
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                KeyPressed(const Keyboard::Key &code);

                ///
                /// \brief Copy constructor.
                ///
                KeyPressed(const KeyPressed &other);

                ///
                /// \brief Move constructor.
                ///
                KeyPressed(KeyPressed &&other) noexcept;

                ///
                /// \brief Destructor.
                ///
                virtual ~KeyPressed(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                void    operator=(const KeyPressed &other);

                ///
                /// \brief Move assignment operator.
                ///
                void    operator=(KeyPressed &&other);

            public:
                ///
                /// \brief Get the key value of the keypressed event.
                ///
                const Keyboard::Key     &get_key(void) const;

            private:
                ///
                /// \brief The key code of the key pressed.
                ///
                Keyboard::Key     m_code;
        };
    }
}
