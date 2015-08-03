/* workhorse.c
 * see readme.txt and http://members.fortunecity.com/drunkenbunny/ for more details.
 *
 * created by Brian Greig using Allegro
 * special thanks to Ari Feldman for his Sprite Library and www.newbiegameprogrammers.com for their sounds and tilemaps.
 * extra special thanks to Pixelate and Paul Vanukoff for their article on sprite classes.
 *
 * Created for Drunken Bunny Interactive
 * Last updated June 19, 2003
 */


#include "allegro.h"
#include "workhorse.h"
#include "stddef.h"

int init_game(){
	allegro_init();
	set_color_depth(16);

	if (install_keyboard() != 0) {
		allegro_message("Unable to install keyboard\n%s\n", allegro_error);
		return 1;
	}

	if (install_timer() != 0) {
		allegro_message("Unable to install timer\n%s\n", allegro_error);
		return 1;
	}

	if (set_gfx_mode(GFX_SAFE, screenWidth, screenHeight, 0, 0) != 0) {
   		set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
   		allegro_message("Unable to set any graphic mode\n%s\n", allegro_error);
   		return 1;
   	}
   	return 0;
}


void intro(){

	/* my pathetic intro */
	BITMAP * logo;
	PALETTE pal;
	logo =  load_bitmap("gfx\\allegro_logo.bmp", pal);
	blit(logo, screen, 0, 0, screenWidth/2 - 127, screenHeight/2 - 127, 254, 254);
	rest(3000);
	clear_to_color(screen, makecol(0,0,0));

	textout(screen, font, "No Story", SCREEN_W/2 - 10, SCREEN_H/2 - 75, makecol(255,255,255));
	rest(2000);

	textout(screen, font, "No Characters", SCREEN_W/2 - 30, SCREEN_H/2 - 25, makecol(255,255,255));
	rest(2000);

	textout(screen, font, "No Fancy Graphics", SCREEN_W/2 - 50, SCREEN_H/2 + 25, makecol(255,255,255));
	rest(2000);

	textout(screen, font, "Just Senseless Violence", SCREEN_W/2 - 70, SCREEN_H/2 + 75, makecol(255,0,0));
	rest(3000);
}

void outro(){
	clear_keybuf();
	clear_to_color(screen, makecol(0,0,0));
	textout(screen, font, "Thanks for Playing!", SCREEN_W/2 - 10, SCREEN_H/2 - 50, makecol(255,255,255));
	textout(screen, font, "For more fine Drunken Bunny games vist:", SCREEN_W/2 -85, SCREEN_H/2, makecol(255,255,255));
	textout(screen, font, "http://members.fortunecity.com/DrunkenBunny", SCREEN_W/2 - 100, SCREEN_H/2 + 50, makecol(255,255,255));
	readkey();
}

int menu(){
	int i = 0, j = 0, sel = 0;

	PALETTE pal;
	BITMAP * buf, * srcIcon, * sIcon, * dIcon, * boarder, * heading, * bg;
	srcIcon		= load_bitmap("gfx\\intro_gfx.bmp", pal);
	set_palette(pal);

	buf  		= create_bitmap(screenWidth, screenHeight);
	sIcon		= create_sub_bitmap(srcIcon, 0, 0, 199, 49);
	dIcon		= create_sub_bitmap(srcIcon, 0, 49, 199, 49);
	boarder		= create_sub_bitmap(srcIcon, 0, 100, 219, 55);
	heading 	= create_sub_bitmap(srcIcon, 0, 212, 395, 55);
	bg			= create_sub_bitmap(srcIcon, 0, 270, 50, 50);
	clear_keybuf();
	/* options menu */
	do{

		if (key[KEY_UP] && sel > 0)
			sel--;

		if (key[KEY_DOWN] && sel < 3)
			sel++;

		clear_to_color(buf, makecol(0,0,0));
		for (i = 0; i < 16; i++)
			for (j = 0; j < 21; j++)
				draw_sprite(buf, bg, j*50, i*50);

		draw_sprite(buf, heading, 100, 75);

		draw_sprite(buf, boarder, SCREEN_W/2 - 61, 272);
		if (sel == 0)
			draw_sprite(buf, sIcon, SCREEN_W/2 - 50, 275);
		else
			draw_sprite(buf, dIcon, SCREEN_W/2 - 50, 275);
		textout(buf, font, "PLAY GAME", SCREEN_W/2 - 10, 300, makecol(255,255,255));

		draw_sprite(buf, boarder, SCREEN_W/2 - 61, 372);
		if (sel == 1)
			draw_sprite(buf, sIcon, SCREEN_W/2 - 50, 375);
		else
			draw_sprite(buf, dIcon, SCREEN_W/2 - 50, 375);
		textout(buf, font, "OPTIONS", SCREEN_W/2 - 10, 400, makecol(255,255,255));

		draw_sprite(buf, boarder, SCREEN_W/2 - 61, 472);
		if (sel == 2)
			draw_sprite(buf, sIcon, SCREEN_W/2 - 50, 475);
		else
			draw_sprite(buf, dIcon, SCREEN_W/2 - 50, 475);
		textout(buf, font, "EDIT MAP", SCREEN_W/2 - 10, 500, makecol(255,255,255));

		draw_sprite(buf, boarder, SCREEN_W/2 - 61, 572);
		if (sel == 3)
			draw_sprite(buf, sIcon, SCREEN_W/2 - 50, 575);
		else
			draw_sprite(buf, dIcon, SCREEN_W/2 - 50, 575);
		textout(buf, font, "EXIT AGSD", SCREEN_W/2 - 10, 600, makecol(255,255,255));

		if (key[KEY_ESC])
			return 1;
		if (key[KEY_ENTER] && sel == 0)
			return 0;
		if (key[KEY_ENTER] && sel == 1)
			textout(buf, font, "This feature is not yet implemented", SCREEN_W/2 - 75, 200, makecol(255, 255, 255));
		if (key[KEY_ENTER] && sel == 2)
			textout(buf, font, "This feature is not yet implemented", SCREEN_W/2 - 75, 200, makecol(255, 255, 255));
		if (key[KEY_ENTER] && sel == 3)
			return 1;
		blit(buf, screen, 0, 0, 0, 0, screenWidth, screenHeight);

		rest(100);
	}while (1);
	return 0;
}
