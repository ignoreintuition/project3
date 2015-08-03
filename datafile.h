/* datafile.h
 * see readme.txt and http://members.fortunecity.com/drunkenbunny/ for more details.
 *
 * created by Brian Greig using Allegro
 * special thanks to Ari Feldman for his Sprite Library and www.newbiegameprogrammers.com for their sounds and tilemaps.
 * extra special thanks to Pixelate and Paul Vanukoff for their article on sprite classes.
 *
 * Created for Drunken Bunny Interactive
 * Last updated Apr 29, 2003
 */

#ifndef DATAFILE_H
#define DATAFILE_H

/* format is N, NE, E, SE, S, SW, W, NW
 * and animation a + x cord, animation a + y cord, animation b + x cord, animation b + y cord
 */

/* astronaut 1's attributes */
int astro1[32] = 		{ 75, 72, 75, 104, 105, 72, 105, 104, 40, 72, 40, 104, 210, 72, 210, 104, 175, 72, 175, 104, 240, 72, 240, 104, 0, 72, 0, 104, 140, 72, 140, 104 };

/* astronaut 2's attributes */
int astro2[32] = 		{ 5, 140, 5, 172, 105, 140, 105, 172, 175, 140, 175, 172, 140, 140, 140, 172, 40, 140, 40, 172, 210, 140, 210, 172, 75, 140, 75, 172, 240, 140, 240, 172 };

/* astronaut 3's attributes */
int astro3[32] = 		{ 75, 208, 75, 240, 110, 208, 110, 240, 35, 208, 35, 240, 175, 208, 175, 240, 175, 72, 175, 104, 210, 208, 210, 240, 0, 208, 0, 240, 138, 208, 138, 240  };

/* astronaut woman's attributes */
int astroWoman[32] = 	{ 76, 342, 348, 342, 108, 342, 377, 342, 45, 342, 316, 342, 210, 342, 482, 342, 176, 342, 448, 342, 238, 342, 510, 342, 4, 342, 275, 342, 138, 342, 410, 342 };

/* eyeball's attributes */
int eyeball[32] = 		{ 580, 208, 580, 245, 580, 208, 580, 245, 545, 208, 545, 245, 545, 208, 545, 245, 515, 208, 515, 245, 515, 208, 515, 245, 580, 140, 580, 177, 580, 140, 580, 177 };

/* frisbee head's attributes */
int frisbeeHead[32] = 	{ 275, 72, 275, 104, 275, 72, 275, 104, 380, 72, 380, 104, 380, 72, 380, 104, 310, 72, 310, 104, 310, 72, 310, 104, 345, 72, 345, 104, 345, 72, 345, 104 };

/* scorpian's attributes */
int scorpian[32] = 		{ 415, 70, 415, 106, 415, 70, 415, 106, 445, 70, 445, 106, 445, 70, 445, 106, 545, 138, 545, 174, 545, 138, 545, 174, 480, 70, 480, 106, 480, 70, 480, 106 };

/* mutant's attributes */
int mutant[32] = 		{ 410, 276, 410, 308, 410, 276, 410, 308, 380, 276, 380, 308, 380, 276, 380, 308, 445, 276, 445, 308, 445, 276, 445, 308, 340, 276, 340, 308, 340, 276, 340, 308 };

/* clone's attributes */
int clone[32] = 		{ 514, 140, 514, 172, 514, 140, 514, 172, 446, 140, 446, 172, 446, 140, 446, 172, 412, 140, 412, 172, 412, 140, 412, 172, 482, 140, 482, 172, 482, 140, 482, 172  };

/* leader's attributes */
int leader[32] = 		{ 211, 276, 211, 308, 211, 276, 211, 308, 177, 276, 177, 308, 177, 276, 177, 308, 246, 276, 246, 308, 246, 276, 246, 308, 142, 276, 142, 308, 142, 276, 142, 308,  };

/* blobs attributes */
int blob[32] = 			{ 310, 275, 310, 310, 310, 275, 310, 310, 310, 275, 310, 310, 310, 275, 310, 310, 275, 275, 275, 310, 275, 275, 275, 310, 275, 275, 275, 310, 275, 275, 275, 310};

/* bald dude's attributes */
int baldDude[32] = 		{ 450, 208, 450, 240, 450, 208, 450, 240, 416, 208, 416, 240, 416, 208, 416, 240, 484, 208, 484, 240, 484, 208, 484, 240, 378, 208, 378, 240, 378, 208, 378, 240  };
#endif

