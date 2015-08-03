/* icon.h
 * see readme.txt and http://members.fortunecity.com/drunkenbunny/ for more details.
 *
 * created by Brian Greig using Allegro
 * special thanks to Ari Feldman for his Sprite Library and www.newbiegameprogrammers.com for their sounds and tilemaps.
 * extra special thanks to Pixelate and Paul Vanukoff for their article on sprite classes.
 *
 * Created for Drunken Bunny Interactive
 * Last updated May 22, 2003
 */


#ifndef ICON_H
#define ICON_H

typedef struct icon{
	BITMAP * 	dataFile;	/* source file for images */
	PALETTE		pal;		/* palate for source file */
	BITMAP *	picture;	/* bitmaps image */
	BITMAP *	selected;	/* highlighted ...*/
	BITMAP *	deselected;	/* ... or not */

	int 		isSelected;	/* is the icon currently selected */
	vector 		pos;		/* current position on the screen */
	vector		size;		/* size of the icon (37) */
} icon;

/* function to intilize an icon */
void initIcon(icon * currIcon, int srcPosX, int srcPosY, int sizeX, int sizeY, int selected, int posX, int posY);

/* highlight the icon */
void selectIcon( icon * currIcon );

/* remove highlighting */
void deselectIcon( icon * currIcon );

/* buffer the icon */
void bufferIcon( icon * currIcon, BITMAP * buf );

#endif
