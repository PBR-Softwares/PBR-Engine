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

#include    "PBR/Core/EventRegister.hpp"
#include    "PBR/Core/Event.hpp"

namespace   PBR
{
    namespace   Core
    {
        EventRegister::EventRegister(void) :
            m_temporary()
        {

        }

        EventRegister::~EventRegister(void)
        {

        }



        void
        EventRegister::push_event(const Event &event)
        {
        }

        void
        EventRegister::register_callback(const Event::Type &type, const std::function<void(const Event &)> &callback)
        {
            this->m_temporary[type].push_back(callback);
        }
    }
}
