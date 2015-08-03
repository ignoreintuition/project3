____________________________________________

Project_3: Another Generic Space Deathmatch

v. 0.5
Drunken Bunny Interactive
Last updated 06/24/03
____________________________________________

____________________________________________

I. Introduction
____________________________________________

Project_3 is the latest project being developed at Drunken Bunny (basically it's just me, but thats beside the point) which will be a very generic overhead deathmatch game.  Currently the game is in early stages of development and most of the actual gameplay hasen't been implemented yet.  Hopefully by the end of development the game will feature a sweet single player deathmatch with multiple weapons, random spawning locations, bot AI, obstructions, tilemapping, and maybe even LAN support.

____________________________________________

II. Current Development
____________________________________________

As of now the game allows you to traverse the screen with your character while various bots travel randomly around the screen.  Bots try to avoid collisions with you and with other bots.  The game currently has 12 animated sprites, can support, at the very least, 40 on screen characters without slowdown and a static background image.  It displays a somewhat functional HUD.  You can also shoot other sprites and you'll see in the HUD if another sprite is hit.  Tilemapping has been incorporated, but is currently very limited.  Multiple (Up to 100 for now) projectiles can currently be displayed on the screen now.  Intro and non-functional menu have been added and a shameless plug for my website has been tacked on to the end.

You can find a desktop icon in the res folder if you want to add AGSD to your desktop or startmenu.

____________________________________________

III. Controls
____________________________________________

The current controls are simply use the arrow keys to control your sprite, space to shoot, and alt to capture the screen (saves it in your project_3 folder as screen.bmp).  Tab can also be used to select a weapon from the HUD, but, as of now, the weapon you are using always stays the same.

____________________________________________

IV. Upcoming Changes
____________________________________________

These are the changes I am hoping to add before v. 0.4
- Increase the functionality of projectiles allowing them to have their own bitmaps, sounds (the sounds are included in the sfx directory), and velocities.
- Smart AI (possibly using A* algorithm)
- Graphics for item drops.
- Improive tile mapping engine to allow for diverse enviroments for fighting in. (You can see the tiles I will use.  They are currently stored in the gfx directory) 
- A seperate executable for developing maps.  
- Particle effects for when characters die and respawn.
- Network support (far future) for multiplay deathmatch.  Possible Implementations are Libnet, HawkNL, GNE, Raknet, BSD sockets/winsock 
- Fully functional menu that you can drop back to to start a new game should you please.
____________________________________________

V. Map Development
____________________________________________

*** All this information is not functional in the current version (0.49) of Project_3 ***

Currently the format of .p3m (project_3 map) files is pretty strait foward, but has to be followed specifically to work correctly.  Any lines with a # at the beginning will be ignored and can be used as comments.  The first, non-commented line has to be the relative directory and file name.  All the included tilesets are in the AGSD_HOME_DIR\gfx\*.bmp so the way you would write a map named mountailTS.bmp would be: 

gfx\\mountainTS.bmp

From there you can design the map.  They are 20 columns and 12 rows.  Columns are seperated by commas and rows are seperated by carriage returns.  Then just use the column and row from the original bmp file seperated by spaces to choose a particular tile.  For example:

8 7, 2 3, 4 5

Would choose those tiles represented in the bmp file by the 8th row, 7th column for the first tile followed by the 2nd row, 3rd column, etc.  Open the files in the map folder using your favorite text editor to get a better idea.

Additionally, if you want to make your own tilesets just follow the format of the any file in the gfx directory with the format *TS.bmp.  TO make things easier include your bitmaps in that same directory.  Good luck.
____________________________________________

VI. Known bugs
____________________________________________

These are all the bugs I am aware of.  If you find any not mentioned here please contact me.
- Main menu is not functional.  Just hit enter to start.
- When moving northwest your gun will not shoot.  I am not sure as to the cause of this problem yet.
- More delay is needed between keystrokes.  I am looking into other ways of handeling this.
- When you shoot while moving you'll take a couple of hits yourself.  This should be sixed soon.
- The graphics suck.
____________________________________________

VII. Contact
____________________________________________

For detailed information and other projects visit http://members.fortunecity.com/drunkenbunny
For questions, queries, or to help out on any projects e-mail or IM me (Brian) at bgreig01@aol.com.