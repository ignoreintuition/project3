/* sprite.c
 * see readme.txt and http://members.fortunecity.com/drunkenbunny/ for more details.
 *
 * created by Brian Greig using Allegro
 * special thanks to Ari Feldman for his Sprite Library and www.newbiegameprogrammers.com for their sounds and tilemaps.
 * extra special thanks to Pixelate and Paul Vanukoff for their article on sprite classes.
 *
 * Created for Drunken Bunny Interactive
 * Last updated Apr 29, 2003
 */

#include "allegro.h"
#include "sprite.h"
#include "string.h"
#include "stddef.h"

/* initilization function for sprite structure */
void initSprite( sprite * sprt, int * dat, int dir, int sx, int sy, int xPos, int yPos){
	sprt->dataFile	= load_bitmap("gfx\\datafile.bmp", sprt->pal);
	sprt->nextSprite = NULL;
	sprt->currFrame = 0;
	setSpriteSize( sprt, sx, sy );
	setSpriteData( sprt, dat );
	setSpritePos( sprt, xPos, yPos );
	setSpriteVel( sprt, 4, 4 );
	setSpriteDir( sprt, dir );
	setSpriteSrcPos( sprt, sprt->data[sprt->currDir * 4], sprt->data[sprt->currDir * 4 + 1] );
	setSpriteBound( sprt );

}

/* draw the current sprite from bitmap */
void updateSprite( sprite * sprt){
	sprt->image 	= create_sub_bitmap(sprt->dataFile, sprt->srcPos.x, sprt->srcPos.y, sprt->size.x, sprt->size.y);
}
/* set the sprites current direction */
void setSpriteDir( sprite * sprt, int dir ){
	if ( dir > 0 && dir < 8 )
		sprt->currDir = dir;
	else
		sprt->currDir = 0;
}

/* set the sprites current position */
void setSpriteSrcPos( sprite * sprt, int spx, int spy ){
	sprt->srcPos.x 	= spx;
	sprt->srcPos.y 	= spy;
	updateSprite( sprt );
}

/* set the size of the sprite */
void setSpriteSize( sprite * sprt, int sx, int sy ){
	sprt->size.x 	= sx;
	sprt->size.y 	= sy;
}
/* set the sprites current position */
void setSpritePos( sprite * sprt, int px, int py ){
	sprt->pos.x = px;
	sprt->pos.y = py;
}

/* set the sprites current velocity */
void setSpriteVel( sprite * sprt, int vx, int vy ){
	sprt->vel.x = vx;
	sprt->vel.y = vy;
}

/* write the sprites current bitmap to the buffer */
void bufferSprite( sprite * sprt, BITMAP * buf){
	draw_sprite(buf, sprt->image, sprt->pos.x, sprt->pos.y);
	//line( buf, sprt->bound.x0, sprt->bound.y0, sprt->bound.x1, sprt->bound.y0, makecol(0,0,0));
	//line( buf, sprt->bound.x0, sprt->bound.y0, sprt->bound.x0, sprt->bound.y1, makecol(0,0,0));
	//line( buf, sprt->bound.x1, sprt->bound.y0, sprt->bound.x1, sprt->bound.y1, makecol(0,0,0));
	//line( buf, sprt->bound.x0, sprt->bound.y1, sprt->bound.x1, sprt->bound.y1, makecol(0,0,0));
}

/* moves a sprite in the direction currently assigned to sprite->currDir */
int moveSprite( sprite * sprt, int dir ){

	setSpriteDir( sprt, dir );

	switch( sprt->currDir ){
		case 0:
			sprt->pos.y -= sprt->vel.y * 2;
			break;
		case 1:
			sprt->pos.x += sprt->vel.x;
			sprt->pos.y -= sprt->vel.y;
			break;
		case 2:
			sprt->pos.x += sprt->vel.x * 2;
			break;
		case 3:
			sprt->pos.x += sprt->vel.x;
			sprt->pos.y += sprt->vel.y;
			break;
		case 4:
			sprt->pos.y += sprt->vel.y *2;
			break;
		case 5:
			sprt->pos.x -= sprt->vel.x;
			sprt->pos.y += sprt->vel.y;
			break;
		case 6:
			sprt->pos.x -= sprt->vel.x * 2;
			break;
		case 7:
			sprt->pos.x -= sprt->vel.x;
			sprt->pos.y -= sprt->vel.y;
			break;
	}
	animateSprite( sprt );
	setSpriteBound( sprt );
	return 0;
}

/* animate the sprite */
void animateSprite( sprite * sprt){
	if (sprt->currDir < 0 || sprt->currDir > 8)
		sprt->currDir = 0;

	if (sprt->currFrame == 0){
			sprt->currFrame++;
			setSpriteSrcPos( sprt, sprt->data[sprt->currDir * 4], sprt->data[(sprt->currDir * 4) + 1] );
		}
		else if (sprt->currFrame == 1){
			sprt->currFrame--;
			setSpriteSrcPos( sprt, sprt->data[(sprt->currDir * 4) + 2], sprt->data[(sprt->currDir * 4) + 3] );
		}
		else
			sprt->currFrame = 0;
}

/* set the coordinates of the datafile */
void setSpriteData( sprite * sprt, int * dat ){
	int i = 0;
	for (i = 0; i <= 32; i++)
		sprt->data[i] = dat[ i ];
}

/* remove sprite from linked list */
void removeSprite( sprite * sprt ){
	destroy_bitmap( sprt->dataFile );
	destroy_bitmap( sprt->image);
}

/* set the sprites bounding rectangle */
void setSpriteBound( sprite * sprt ){
	sprt->bound.x0 = sprt->pos.x - 1;
	sprt->bound.y0 = sprt->pos.y - 1;
	sprt->bound.x1 = sprt->pos.x + sprt->size.x + 1;
	sprt->bound.y1 = sprt->pos.y + sprt->size.y + 1;
}

/* collision detection */
int collision( sprite * sprt, sprite * sprt2 ){
	return !(sprt->bound.x1 < sprt2->bound.x0 || sprt2->bound.x1 < sprt->bound.x0 || sprt->bound.y1 < sprt2->bound.y0 || sprt2->bound.y1 < sprt->bound.y0);
}
