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
#ifndef KNMUSICALBUMDETAIL_H
#define KNMUSICALBUMDETAIL_H

#include <QModelIndex>
#include <QWidget>

class QLabel;
class QPropertyAnimation;
class QParallelAnimationGroup;
class QSequentialAnimationGroup;
class KNMusicAlbumModel;
class KNMusicCategoryModel;
class KNMusicLibraryModel;
class KNMusicAlbumDetail : public QWidget
{
    Q_OBJECT
public:
    explicit KNMusicAlbumDetail(QWidget *parent = 0);
    void setAlbumModel(KNMusicCategoryModel *model);
    void setLibraryModel(KNMusicLibraryModel *model);
    void setAnimeParameter(const QRect &albumRect,
                           const int &iconSize);
    void displayAlbumIndex(const QModelIndex &index);

    int sizeParameter() const;
    void setSizeParameter(int sizeParameter);

signals:

public slots:
    void foldDetail();

protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void onActionAlbumArtInFinished();

private:
    void generateStep2FinalPosition(QRect &albumArtGeometry,
                                    QRect &contentGeometry);
    void updateWidgetGeometries();
    QLabel *m_albumArt;
    QWidget *m_albumContent;
    KNMusicAlbumModel *m_albumModel;
    KNMusicLibraryModel *m_libraryModel;
    QModelIndex m_currentAlbumIndex;
    QRect m_animeStartRect;
    QPropertyAnimation *m_albumArtIn1, *m_albumContentIn1,
                       *m_albumArtIn2, *m_albumContentIn2;
    QParallelAnimationGroup *m_expandStep1, *m_expandStep2;
    QSequentialAnimationGroup *m_expandAnime;

    int m_iconSize, m_sizeParameter=0;
};

#endif // KNMUSICALBUMDETAIL_H
