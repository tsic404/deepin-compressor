/*
 * Copyright (C) 2019 ~ 2019 Deepin Technology Co., Ltd.
 *
 * Author:     dongsen <dongsen@deepin.com>
 *
 * Maintainer: dongsen <dongsen@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include "plugin.h"

#include <QMimeType>
#include <QVector>


class PluginManager : public QObject
{
    Q_OBJECT

public:
    enum MimeSortingMode {
        Unsorted,
        SortByComment
    };

    explicit PluginManager(QObject *parent = nullptr);
    QVector<Plugin *> installedPlugins() const;
    QVector<Plugin *> availablePlugins() const;
    QVector<Plugin *> availableWritePlugins() const;
    QVector<Plugin *> enabledPlugins() const;
    QVector<Plugin *> preferredPluginsFor(const QMimeType &mimeType);
    QVector<Plugin *> preferredWritePluginsFor(const QMimeType &mimeType) const;
    Plugin *preferredPluginFor(const QMimeType &mimeType);
    Plugin *preferredWritePluginFor(const QMimeType &mimeType) const;
    QStringList supportedMimeTypes(MimeSortingMode mode = Unsorted) const;
    QStringList supportedWriteMimeTypes(MimeSortingMode mode = Unsorted) const;
    QVector<Plugin *> filterBy(const QVector<Plugin *> &plugins, const QMimeType &mimeType) const;

private:

    void loadPlugins();
    QVector<Plugin *> preferredPluginsFor(const QMimeType &mimeType, bool readWrite) const;
    static QStringList sortByComment(const QSet<QString> &mimeTypes);
    static bool libarchiveHasLzo();

    QVector<Plugin *> m_plugins;
    QHash<QString, QVector<Plugin *>> m_preferredPluginsCache;
};


#endif
