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
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#ifndef KNMUSICTTPODLYRICS_H
#define KNMUSICTTPODLYRICS_H

#include "knmusiclyricsdownloader.h"

/*!
 * \brief The KNMusicTTPodLyrics class provide the policy to download lyrics
 * files from the server of TTPod.
 */
class KNMusicTtpodLyrics : public KNMusicLyricsDownloader
{
public:
    /*!
     * \brief Construct a KNMusicTTPodLyrics object.
     * \param parent The parent object.
     */
    explicit KNMusicTtpodLyrics(QObject *parent = 0);
    ~KNMusicTtpodLyrics();

    /*!
     * \brief Reimplemented from KNMusicLyricsDownloader::downloaderName().
     */
    QString downloaderName() Q_DECL_OVERRIDE;

    /*!
     * \brief Reimplemented from KNMusicLyricsDownloader::downloadLyrics().
     */
    void downloadLyrics(
            const KNMusicDetailInfo &detailInfo,
            QList<KNMusicLyricsDetails> &lyricsList) Q_DECL_OVERRIDE;
};

#endif // KNMUSICTTPODLYRICS_H
