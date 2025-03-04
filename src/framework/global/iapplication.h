/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef MU_FRAMEWORK_IAPPLICATION_H
#define MU_FRAMEWORK_IAPPLICATION_H

#include "modularity/imoduleexport.h"

class QObject;
class QEvent;
class QWindow;

namespace mu::framework {
class IApplication : MODULE_EXPORT_INTERFACE
{
    INTERFACE_ID(IApplication)
public:
    virtual ~IApplication() = default;

    enum class RunMode {
        Editor,
        Converter
    };

    virtual void setRunMode(const RunMode& mode) = 0;
    virtual RunMode runMode() const = 0;
    virtual bool noGui() const = 0;

    virtual QWindow* focusWindow() const = 0;

    virtual bool notify(QObject* object, QEvent* event) = 0;

    virtual void restart() = 0;
};
}

#endif // MU_FRAMEWORK_IAPPLICATION_H
