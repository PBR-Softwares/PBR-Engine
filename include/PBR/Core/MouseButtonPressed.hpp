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
#include    "PBR/Core/Event.hpp"
#include    "PBR/Core/Inputs/Mouse/Button.hpp"

namespace   PBR
{
    namespace   Core
    {
        ///
        /// \brief Mouse Button pressed event class.
        ///
        class PBR_CORE_EXPORTS MouseButtonPressed : public Event
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                MouseButtonPressed(const Mouse::Button &code, const glm::vec2 &position);

                ///
                /// \brief Destructor.
                ///
                ~MouseButtonPressed(void) noexcept;

            public:
                ///
                /// \brief Get the mouse button key code.
                ///
                const Mouse::Button     &get_button(void) const;

                ///
                /// \brief Get the position of the mouse when the event happened.
                ///
                const glm::vec2         &get_position(void) const;

            private:
                ///
                /// \brief The pressed button code of the mouse.
                ///
                Mouse::Button   m_code;

                ///
                /// \brief The position of the mouse when the button has been pressed.
                ///
                glm::vec2       m_position;
        };
    }
}
