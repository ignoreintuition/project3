/* game.c
 * see readme.txt and http://members.fortunecity.com/drunkenbunny/ for more details.
 *
 * created by Brian Greig using Allegro
 * special thanks to Ari Feldman for his Sprite Library and www.newbiegameprogrammers.com for their sounds and tilemaps.
 * extra special thanks to Pixelate and Paul Vanukoff for their article on sprite classes.
 *
 * Created for Drunken Bunny Interactive
 * Last updated June 19, 2003
 */

#include <stdlib.h>

#include "allegro.h"

#include "stddef.h"
#include "datafile.h"

#include "sprite.h"
#include "workhorse.h"
#include "projectile.h"
#include "icon.h"

/* this is a temporary variable for the number of sprites on the screen. */
const int maxSprts = 12;
const int waitTime = 90;
const int numTiles = 240;
const int numWeapons = 8;
int numProj = 0;

int main() {

	int gameQuit = 0, gameOver = 0, i = 0, j = 0, counter = 0, seed[maxSprts - 1];

	/* our array of sprites */
	sprite * sprt[maxSprts];
	sprite * map[numTiles];
	icon * weaponIcon[numWeapons];
	projectile * proj[100];

	/* variables */
	int currWeapon = 0;
	int currTime = 0000;

	/* temporary varibles */
	int ammo = 100;
	int killed = 0;
	int frags = 0;
	int health = 100;

	/* allegro bitmaps */
	BITMAP *buffer, *background, *backgroundSrc, *currTile, *interface;
	PALETTE pal;

	/* initilize random variables for pseudo AI */
	for (i = 0; i < maxSprts - 1; i++)
		seed[i] = 0;

	/* allocate space for sprites */
	for (i = 0; i < maxSprts; i++)
		sprt[i] = (sprite *)malloc(sizeof(sprite));
	for (i = 0; i < numTiles; i++)
		map[i] = (sprite *)malloc(sizeof(sprite));
	for (i = 0; i < numWeapons; i++)
		weaponIcon[i] = (icon *)malloc(sizeof(icon));
	for (i = 0; i < 100; i++)
		proj[i] = (projectile *)malloc(sizeof(projectile));

	/* initilize for allegro */
	if (init_game() != 0) {	exit(0); }
	intro();
	if (menu() != 0) {	exit(0); }

	/* set all our bitmaps to initial positions */
	backgroundSrc	= load_bitmap("gfx\\mountainTS.bmp", pal);
	interface	= load_bitmap("gfx\\interface.bmp", pal);

	/* creating the background image */
	background	= create_bitmap(1056, 576);
	currTile = create_sub_bitmap(backgroundSrc, 206, 308, 48, 48);
	for (i = 0; i < 12; i++)
		for (j = 0; j < 22; j++)
			draw_sprite(background, currTile, j*48, i*48);


	buffer 		= create_bitmap(screenWidth, screenHeight);

	/* set all of our sprites to their initial positions */
	initSprite( sprt[0], 	astro1,	 		NORTHEAST,	swidth, sheight, 100, 275 );
	initSprite( sprt[1], 	astro2, 		WEST, 		swidth, sheight, 450, 150 );
	initSprite( sprt[2], 	baldDude, 		SOUTHEAST, 	swidth, sheight, 400, 200 );
	initSprite( sprt[3], 	scorpian, 		NORTHEAST, 	swidth, sheight, 400, 350 );
	initSprite( sprt[4], 	eyeball, 		NORTHWEST, 	swidth, sheight, 550, 300 );
	initSprite( sprt[5], 	frisbeeHead,	EAST, 		swidth, sheight, 475, 325 );
	initSprite( sprt[6], 	astro3,		 	NORTH, 		swidth, sheight, 625, 225 );
	initSprite( sprt[7], 	astroWoman,	 	SOUTHWEST,	swidth, sheight, 375, 100 );
	initSprite( sprt[8], 	clone,		 	SOUTH,		swidth, sheight, 350, 250 );
	initSprite( sprt[9], 	mutant, 	 	NORTHWEST,	swidth, sheight, 150, 250 );
	initSprite( sprt[10], 	leader, 	 	NORTH,		swidth, sheight, 325, 275 );
	initSprite( sprt[11], 	blob,	 	 	SOUTH,		swidth, sheight, 625, 375 );

	initIcon( weaponIcon[0], 1, 1,   37, 37, SELECTED,   39,  661 );
	initIcon( weaponIcon[1], 1, 40,  37, 37, DESELECTED, 90,  661 );
	initIcon( weaponIcon[2], 1, 80,  37, 37, DESELECTED, 141, 661 );
	initIcon( weaponIcon[3], 1, 120, 37, 37, DESELECTED, 192, 661 );
	initIcon( weaponIcon[4], 1, 160, 37, 37, DESELECTED, 39,  715 );
	initIcon( weaponIcon[5], 1, 200, 37, 37, DESELECTED, 90,  715 );
	initIcon( weaponIcon[6], 1, 240, 37, 37, DESELECTED, 141, 715 );
	initIcon( weaponIcon[7], 1, 280, 37, 37, DESELECTED, 192, 715 );

	/* draw inital buffer */
	draw_sprite(buffer, background, 0, 0);
	draw_sprite(buffer, interface, 0, 0);
	for (i = 0; i < maxSprts; i++)
		bufferSprite(sprt[i], buffer);

	/* blit our initial buffer */
	blit(buffer, screen, 0, 0, 0, 0, screenWidth, screenHeight);
	do{
		/* main game loop */
		do{
			clear_keybuf();

			/* take a quick screen shot */
			if (   key[KEY_ALT])
				save_bitmap("screen.bmp", buffer, pal);

			/* space is hit, gun is shoot */
			if (   key[KEY_SPACE]){
				if (ammo > 0){
					ammo--;
					initProjectile( proj[numProj], sprt[0]->currDir, sprt[0]->bound, 1, 1 );
					numProj++;
				}
			}

			/* tab switchs between weapons */
			if (	key[KEY_TAB]){
				if (currWeapon < numWeapons - 1)
					currWeapon++;
				else
					currWeapon = 0;
			}
			/* key press up */
			if (		key[KEY_UP] 	&& !key[KEY_LEFT] 	&& !key[KEY_RIGHT] 	&& !key[KEY_DOWN])
				moveSprite( sprt[0], NORTH );
			/* key press up + right */
			else if (	key[KEY_UP] 	&& key[KEY_RIGHT] 	&& !key[KEY_LEFT] 	&& !key[KEY_DOWN])
				moveSprite( sprt[0], NORTHEAST );
			/* key press right */
			else if (	key[KEY_RIGHT] 	&& !key[KEY_UP]	 	&& !key[KEY_DOWN] 	&& !key[KEY_LEFT])
				moveSprite( sprt[0], EAST );
			/* key press down + right */
			else if (	key[KEY_DOWN] 	&& key[KEY_RIGHT] 	&& !key[KEY_UP] 	&& !key[KEY_LEFT])
				moveSprite( sprt[0], SOUTHEAST );
			/* key press down */
			else if (	key[KEY_DOWN] 	&& !key[KEY_LEFT] 	&& !key[KEY_UP] 	&& !key[KEY_RIGHT])
				moveSprite( sprt[0], SOUTH );
			/* key press down + left */
			else if (	key[KEY_DOWN] 	&& key[KEY_LEFT] 	&& !key[KEY_UP] 	&& !key[KEY_RIGHT])
				moveSprite( sprt[0], SOUTHWEST );
			/* key press left */
			else if (	key[KEY_LEFT]	&& !key[KEY_UP] 	&& !key[KEY_DOWN] 	&& !key[KEY_RIGHT])
				moveSprite( sprt[0], WEST );
			/* key press up + left */
			else if (	key[KEY_UP] 	&& key[KEY_LEFT] 	&& !key[KEY_DOWN] 	&& !key[KEY_RIGHT])
				moveSprite( sprt[0], NORTHWEST );
			/* no keypress */
			else
				updateSprite( sprt[0] );

			/* pseudo AI */
			counter++;
			if (counter == 10){
				counter = 0;
				for (i = 0; i < maxSprts - 1; i++)
					seed[i] = rand() % 8;			/* set seed to a random position between 0 - 7 */
			}
			for (i = 1; i < maxSprts; i++){
				for (j = 0; j < maxSprts; j++)
					if (i != j)
						if (collision(sprt[i], sprt[j]))
							seed[i - 1] = (seed[i - 1] + 4) % 8; /* send them moving in the opposite direction */
			}
			for (i = 1; i < maxSprts; i++)
				moveSprite( sprt[i], seed[i - 1] );	/* move sprite in random direction from seed */
			/* end pseudo AI */

			/* check for collision with projectile */
			for (i = 0; i < maxSprts; i++)
				for (j = 0; j < numProj; j++)
					if(checkProjectileCollision(proj[j], sprt[i]))
						textout(screen, font, "You got him!", 500, 600, makecol(255,255,255));
			for (i = 0; i < numProj; i++)
				moveProjectile(proj[i]);

			/* check for collisions with interface */
			for (i = 0; i < maxSprts; i++){
				if( sprt[i]->bound.x0 < 10 || sprt[i]->bound.y0 < 10 ||  sprt[i]->bound.x1 > 1015 || sprt[i]->bound.y1 > 570){
					moveSprite (sprt[i], (sprt[i]->currDir + 4) % 8);
					if (i > 0)
						seed[i - 1] = (seed[i - 1] + 4) % 8; // necessary for AI.
				}
			}

			/* buffer this frame */
			draw_sprite(buffer, background, 0, 0);
			draw_sprite(buffer, interface, 0, 0);
			textprintf(buffer, font, 712, 651, makecol(255,255,255), "%d", health);
			textprintf(buffer, font, 912, 651, makecol(255,255,255), "%d", killed);
			textprintf(buffer, font, 712, 691, makecol(255,255,255), "%d", currTime);
			textprintf(buffer, font, 912, 691, makecol(255,255,255), "%d", frags);
			textprintf(buffer, font, 712, 725, makecol(255,255,255), "%d", ammo);
			textprintf(buffer, font, 912, 725, makecol(255,255,255), "%d", maxSprts - 1);
			for (i = 0; i < numProj; i++)
				bufferProjectile(proj[i], buffer);

			for (i = 0; i < maxSprts; i++)
				bufferSprite(sprt[i], buffer);

			for (i = 0; i < numWeapons; i++){
				if (i == currWeapon)
					selectIcon(weaponIcon[i]);
				else
					deselectIcon(weaponIcon[i]);
				bufferIcon(weaponIcon[i], buffer);
			}

			/* blit this frame to the screen.  Nice. */
			blit(buffer, screen, 0, 0, 0, 0, screenWidth, screenHeight);

			rest(waitTime);

			/* Esc to quit */
			if (key[KEY_ESC]){
				gameOver = 1;
			}

		/* loop until game is over */
		}while(gameOver == 0);

	/* This doesn't really work */
	gameQuit = 1;
	}while(gameQuit == 0);

	/* clean up before returing */
	for (i = 0; i < maxSprts; i++){
		removeSprite(sprt[i]);
		free(sprt[i]);
	}

	for (i = 0; i < 8; i++)
		free(weaponIcon[i]);
	outro();

	allegro_exit();

   	return 0;
}

/* thats it!  done */
END_OF_MAIN();
