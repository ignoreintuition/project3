/* projectile.c
 * see readme.txt and http://members.fortunecity.com/drunkenbunny/ for more details.
 *
 * created by Brian Greig using Allegro
 * special thanks to Ari Feldman for his Sprite Library and www.newbiegameprogrammers.com for their sounds and tilemaps.
 * extra special thanks to Pixelate and Paul Vanukoff for their article on sprite classes.
 *
 * Created for Drunken Bunny Interactive
 * Last updated May 20, 2003
 */

#include "allegro.h"
#include "sprite.h"
#include "projectile.h"
#include "string.h"
#include "stddef.h"

/* initilize a projectile */
void initProjectile( projectile * proj, int dir, box source, int xSize, int ySize ){
	setProjectileDir( proj, dir );
	setProjectileVel( proj, 0, 0 );
	setProjectileBound( proj );
	proj->next = NULL;
	switch( dir ){
			case 0: // shoot north
				setProjectilePos( proj, (source.x1 - (source.x1 - source.x0)/2), source.y0 );
				break;
			case 1: // shoot northeast
				setProjectilePos( proj, source.x1, source.y0 );
				break;
			case 2: // shoot east
				setProjectilePos( proj, source.x1, (source.y1 - (source.y1 - source.y0)/2));
				break;
			case 3: // shoot southeast
				setProjectilePos( proj, source.x1, source.y1 );
				break;
			case 4: // shoot south
				setProjectilePos( proj, (source.x1 - (source.x1 - source.x0)/2), source.y1 );
				break;
			case 5: // shoot southwest
				setProjectilePos( proj, source.x0, source.y1 );
				break;
			case 6: // shoot west
				setProjectilePos( proj, source.x0, (source.y1 - (source.y1 - source.y0)/2));
				break;
			case 7: // shoot northwest
				setProjectilePos( proj, source.x0, source.y0 );
				break;
	}
	setProjectileSize( proj, xSize, ySize );
}

/* buffer the projectile to the screen */
void bufferProjectile( projectile * proj, BITMAP * buf ){
	circlefill(buf, proj->pos.x, proj->pos.y, proj->size.x, makecol(0,0,0) );
}

/* set the direction the projectile was aimed in */
void setProjectileDir( projectile * proj, int dir ){
	proj->currDir = dir;
}

/* set the velocity the projectile is traveling at */
void setProjectileVel( projectile * proj, int xVel, int yVel ){
	proj->vel.x = xVel;
	proj->vel.y = yVel;
}

/* set the size of the projectile */
void setProjectileSize( projectile * proj, int xSize, int ySize ){
	proj->size.x = xSize;
	proj->size.y = ySize;
}

/* set the projectiles position */
void setProjectilePos( projectile * proj, int xPos, int yPos ){
	proj->pos.x = xPos;
	proj->pos.y = yPos;
}

/* check collision of projectile and sprite */
int checkProjectileCollision( projectile * proj, sprite * sprt ){
	return !(sprt->bound.x1 < proj->bound.x0 || proj->bound.x1 < sprt->bound.x0 || sprt->bound.y1 < proj->bound.y0 || proj->bound.y1 < sprt->bound.y0);
}
/* move the projectile */
int moveProjectile( projectile * proj ){
	switch( proj->currDir ){
		case 0:
			proj->pos.y -= 12;
			break;
		case 1:
			proj->pos.x += 6;
			proj->pos.y -= 6;
			break;
		case 2:
			proj->pos.x += 12;
			break;
		case 3:
			proj->pos.x += 6;
			proj->pos.y += 6;
			break;
		case 4:
			proj->pos.y += 12;
			break;
		case 5:
			proj->pos.x -= 6;
			proj->pos.y += 6;
			break;
		case 6:
			proj->pos.x -= 12;
			break;
		case 7:
			proj->pos.x -= 6;
			proj->pos.y -= 6;
			break;
	}
	setProjectileBound( proj );

	if (proj->bound.x0 < 10 || proj->bound.y0 < 10 ||  proj->bound.x1 > 1015 || proj->bound.y1 > 570)
		return 1;
	else
		return 0;
}

/* set the sprites bounding rectangle */
void setProjectileBound( projectile * proj ){
	proj->bound.x0 = proj->pos.x - 1;
	proj->bound.y0 = proj->pos.y - 1;
	proj->bound.x1 = proj->pos.x + proj->size.x + 1;
	proj->bound.y1 = proj->pos.y + proj->size.y + 1;
}
