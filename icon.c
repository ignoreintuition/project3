/* icon.c
 * see readme.txt and http://members.fortunecity.com/drunkenbunny/ for more details.
 *
 * created by Brian Greig using Allegro
 * special thanks to Ari Feldman for his Sprite Library and www.newbiegameprogrammers.com for their sounds and tilemaps.
 * extra special thanks to Pixelate and Paul Vanukoff for their article on sprite classes.
 *
 * Created for Drunken Bunny Interactive
 * Last updated May 24, 2003
 */


/* function to intilize an icon */
#include "allegro.h"
#include "sprite.h"
#include "string.h"
#include "stddef.h"
#include "icon.h"

void initIcon(icon * currIcon, int srcPosX, int srcPosY, int sizeX, int sizeY, int selected, int posX, int posY){
	currIcon->dataFile		= load_bitmap("gfx\\weapons.bmp", currIcon->pal);
	currIcon->selected		= create_sub_bitmap(currIcon->dataFile, 1, 320, 37, 37);
	currIcon->deselected 	= create_sub_bitmap(currIcon->dataFile, 1, 360, 37, 37);
	currIcon->isSelected	= selected;
	currIcon->size.x		= sizeX;
	currIcon->size.y		= sizeY;
	currIcon->picture		= create_sub_bitmap(currIcon->dataFile, srcPosX, srcPosY, sizeX, sizeY);
	currIcon->pos.x			= posX;
	currIcon->pos.y			= posY;
}

/* highlight the icon */
void selectIcon( icon * currIcon ){
	currIcon->isSelected = 1;
}

/* remove highlighting */
void deselectIcon( icon * currIcon ){
	currIcon->isSelected = 0;
}

/* buffer the icon */
void bufferIcon( icon * currIcon, BITMAP * buf ){
	if (currIcon->isSelected == 1)
		draw_sprite(buf, currIcon->selected, currIcon->pos.x, currIcon->pos.y);
	else if (currIcon->isSelected == 0)
		draw_sprite(buf, currIcon->deselected, currIcon->pos.x, currIcon->pos.y);

	draw_sprite(buf, currIcon->picture, currIcon->pos.x, currIcon->pos.y);

}
/*bel is an angel and needs a lot of patience to love brian and his family.*/
