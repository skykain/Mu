/*
 * Copyright (C) Kreogist Dev Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#include <QBoxLayout>

//Dependence
#include "kncategorytab.h"
#include "kncategorytabbar.h"
#include "knhwidgetswitcher.h"
#include "knmousedetectheader.h"

//SDK Dependence.
#include "knmusicdetaildialog.h"
#include "knmusicparser.h"

//Ports
#include "knmusicdetaildialogpanel.h"

//Plugins
#include "plugin/knmusicdetailpaneloverview/knmusicdetailpaneloverview.h"

//Globals.
#include "knmusicglobal.h"

#include "knmusicplugin.h"

KNMusicPlugin::KNMusicPlugin(QWidget *parent) :
    KNAbstractMusicPlugin(parent),
    m_headerWidget(new KNMouseDetectHeader(this)),
    m_tabBar(new KNCategoryTabBar(this)),
    m_switcher(new KNHWidgetSwitcher(this))
{
    //Initial the basic infrastructure.
    initialInfrastructure();
    //Initial the detail dialog plugins.
    initialDetailDialogPanel();
    //Initial parser.
    initialParserPlugin();

    //Initial the .
}

QWidget *KNMusicPlugin::headerWidget()
{
    return m_headerWidget;
}

QPixmap KNMusicPlugin::icon()
{
    return QPixmap(":/plugin/music/public/icon.png");
}

QString KNMusicPlugin::title()
{
    return tr("Music");
}

void KNMusicPlugin::saveConfigure()
{
    ;
}

void KNMusicPlugin::onArgumentsAvailable(const QStringList &data)
{
    ;
}

void KNMusicPlugin::initialInfrastructure()
{
    //Initial the music global.
    KNMusicGlobal::initial(this);

    //Link the tab bar and switcher.
    connect(m_tabBar, &KNCategoryTabBar::currentIndexChange,
            m_switcher, &KNHWidgetSwitcher::setCurrentIndex);

    //Initial layout.
    QBoxLayout *mainLayout=new QBoxLayout(QBoxLayout::TopToBottom, this);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);
    setLayout(mainLayout);

    //Add widget to layout.
    mainLayout->addWidget(m_tabBar);
    mainLayout->addWidget(m_switcher, 1);
}

void KNMusicPlugin::initialDetailDialogPanel()
{
    //Add panels to detail dialog.
    knMusicGlobal->detailDialog()->addPanel(new KNMusicDetailPanelOverview);
}

void KNMusicPlugin::initialParserPlugin()
{
    ;
}