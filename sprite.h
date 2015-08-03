/* sprite.h
 * see readme.txt and http://members.fortunecity.com/drunkenbunny/ for more details.
 *
 * created by Brian Greig using Allegro
 * special thanks to Ari Feldman for his Sprite Library and www.newbiegameprogrammers.com for their sounds and tilemaps.
 * extra special thanks to Pixelate and Paul Vanukoff for their article on sprite classes.
 *
 * Created for Drunken Bunny Interactive
 * Last updated Apr 29, 2003
 */


#ifndef SPRITE_H
#define SPRITE_H

typedef struct box{
	int x0;
	int y0;
	int x1;
	int y1;

} box;

typedef struct vector{
	int x;
	int y;

} vector;

typedef struct sprite{
	BITMAP * 	dataFile;	/* source file for images */
	PALETTE		pal;		/* palate for source file */
	BITMAP *	image;		/* bitmaps current image */

	vector 		pos;		/* current position on the screen */
	vector 		vel;		/* current velocity */
	vector 		srcPos;		/* position of the sprite in the datafile */
	vector 		size;		/* size of the sprite */

	box 		bound;		/* bounding rectangle */

	int 		data[32];	/* list of all possible srcPos */
	int 		currDir;	/* cardinal direction (0-7) of sprite starting from north going clockwise */
	int 		currFrame;	/* current frame of animation */
	struct sprite * nextSprite;	/* next sprite in the list */

} sprite;

/* draw the current sprite from bitmap */
void updateSprite( sprite * sprt );

/* move the sprite in current direction */
int moveSprite( sprite * sprt, int dir );

/* initilization function for sprite structure */
void initSprite( sprite * sprt, int * dat, int dir, int sx, int sy, int xPos, int yPos);

/* set the sprites current position */
void setSpritePos( sprite * sprt, int px, int py );

/* set the sprites source position */
void setSpriteSrcPos( sprite * sprt, int spx, int spy );

/* set the sprites size */
void setSpriteSize( sprite * sprt, int sx, int sy );

/* set the sprites current velocity */
void setSpriteVel( sprite * sprt, int vx, int vy );

/* write the sprites current bitmap to the buffer */
void bufferSprite( sprite * sprt, BITMAP * buf);

/* set the sprites current direction */
void setSpriteDir( sprite * sprt, int dir );

/* set the coordinates of the datafile */
void setSpriteData( sprite * sprt, int * dat );

/* animate the sprite */
void animateSprite( sprite * sprt);

/* set the sprites bounding rectangle */
void setSpriteBound( sprite * sprt );

/* check for a collision with a sprite */
int collision( sprite * sprt, sprite * sprt2 );

#endif
