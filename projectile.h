/* projectile.h
 * see readme.txt and http://members.fortunecity.com/drunkenbunny/ for more details.
 *
 * created by Brian Greig using Allegro
 * special thanks to Ari Feldman for his Sprite Library and www.newbiegameprogrammers.com for their sounds and tilemaps.
 * extra special thanks to Pixelate and Paul Vanukoff for their article on sprite classes.
 *
 * Created for Drunken Bunny Interactive
 * Last updated Apr 29, 2003
 */



#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "string.h"

typedef struct projectile {
	vector 		pos;		/* current position on the screen */
	vector		vel;		/* current velocity */
	vector		size;		/* size of the sprite */

	box 		bound;		/* bounding rectangle */

	int 		currDir;	/* cardinal direction (0-7) of sprite starting from north going clockwise */

	struct projectile *next; /* next projectile in the linked list */
} projectile;

/* initilize a projectile */
void initProjectile( projectile * proj, int dir, box source, int xSize, int ySize );

/* buffer the projectile to the screen */
void bufferProjectile( projectile * proj, BITMAP * buf );

/* set the direction the projectile was aimed in */
void setProjectileDir( projectile * proj, int dir );

/* set the velocity the projectile is traveling at */
void setProjectileVel( projectile * proj, int xVel, int yVel );

/* set the size of the projectile */
void setProjectileSize( projectile * proj, int xSize, int ySize );

/* set the projectiles position */
void setProjectilePos( projectile * proj, int xPos, int yPos );

/* set projectiles bounding rectangle */
void setProjectileBound( projectile * proj );

/* move the projectile */
int moveProjectile( projectile * proj );

/* check collision of projectile and sprite */
int checkProjectileCollision( projectile * proj, sprite * sprt );

#endif
