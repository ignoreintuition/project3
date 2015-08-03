CC = gcc

agsd.exe : game.o workhorse.o sprite.o projectile.o icon.o
	$(CC) game.o workhorse.o sprite.o projectile.o icon.o -o agsd.exe -lalleg	

icon.o : icon.c
	$(CC) icon.c -c -o icon.o
	
projectile.o : projectile.c
	$(CC) projectile.c -c -o projectile.o

sprite.o : sprite.c
	$(CC) sprite.c -c -o sprite.o    

workhorse.o : workhorse.c
	$(CC) workhorse.c -c -o workhorse.o
	
game.o : game.c
	$(CC) game.c  -c  -o game.o 

clean :
	@del agsd.exe 
	@del *.o
	@del screen.bmp
	@echo Done!
