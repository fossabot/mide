/****************************************************************
Copyright (c) 1998 Sandro Sigala <ssigala@globalnet.it>.
All rights reserved.

Permission to use, copy, modify, and distribute this software
and its documentation for any purpose and without fee is hereby
granted, provided that the above copyright notice appear in all
copies and that both that the copyright notice and this
permission notice and warranty disclaimer appear in supporting
documentation, and that the name of the author not be used in
advertising or publicity pertaining to distribution of the
software without specific, written prior permission.

The author disclaim all warranties with regard to this
software, including all implied warranties of merchantability
and fitness.  In no event shall the author be liable for any
special, indirect or consequential damages or any damages
whatsoever resulting from loss of use, data or profits, whether
in an action of contract, negligence or other tortious action,
arising out of or in connection with the use or performance of
this software.
****************************************************************/

#include "config.h"

#include <qframe.h>
#include <qpainter.h>
#include <qpixmap.h>

#include "ksmiletris.h"
#include "npiecewidget.h"

NextPieceWidget::NextPieceWidget(QPixmap *s, bool *game, bool *pause,
				 QWidget *parent, const char *name)
	: QFrame(parent, name)
{
	in_game = game;
	in_pause = pause;
	sprites = s;
	setFrameStyle(QFrame::Box | QFrame::Raised);
	setLineWidth(2);
	setMidLineWidth(1);
	resize(2 * sprite_width + 10, 2 * sprite_height + 10);
}

void NextPieceWidget::drawContents(QPainter *p)
{
	QRect r = contentsRect();

	if (!*in_game) {
		p->fillRect(r, black);
		return;
	}

	p->drawPixmap(r.x(), r.y(),
		      sprites[next_piece_sprites[0]]);
	p->drawPixmap(r.x()+sprite_width, r.y(),
		      sprites[next_piece_sprites[1]]);
	p->drawPixmap(r.x(), r.y()+sprite_height,
		      sprites[next_piece_sprites[2]]);
	p->drawPixmap(r.x()+sprite_width, r.y()+sprite_height,
		      sprites[next_piece_sprites[3]]);
}
