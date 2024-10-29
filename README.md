# Welcome to YU-CHEN and LMORAN's CUB3D

### This is our version of Cub3D, a project at 42 PARIS which consists in using raycasting and rendering to create a simple 3D game similar to Wolfenstein 3D.  
  
#### We use the MinilibX a simple X-Window programming API in C to render our game, thus it is recommended to use a MAC or LINUX machine to compile the game.  
  
#### We use the DDA method for our raycasting process, which is a simple but fast algorithm which uses square grids to calculate distances from the player to the objects (walls) in a 2D space. With this system, it is virtually impossible to have walls of different sizes, stairs, etc, but in the case of our project it made the program easy to implement.  
  
###### To access our bonuses (wall collisions, animations, and a simple minimap), compile with the bonus flag. To get the base game back, 'make re'.  

## INPUTS

WS to move FORWARD and BACK
AD to strafe LEFT and RIGHT
<- -> arrow keys to look LEFT and RIGHT  
HOLD LSHIFT to SPRINT (limited gauge that needs to replenish)
ESC to EXIT  
F in BONUS version to FIRE  

## PARSING AND MAP CREATION

Any map can be used, so long as it fits the following criteria:  
  
It MUST contain paths to textures (XPM FILES) for the walls facing each direction, such as:  
<pre>
NO path_to_texture.xpm  
SO path_to_texture.xpm  
EA path_to_texture.xpm  
WE path_to_texture.xpm  
</pre>
For the best experience, use 64x64px xpm images.  

It MUST contain the RGB values for the ceiling and floor, such as:
<pre>
F 188,106,60 (brown)
C 173,216,230 (light blue) 
</pre>
The map MUST be closed, and contain ONE player character. The player can face whatever direction is chosen by using N,S,W,E characters. Walls are '1' and empty spaces are '0', such as:  
<pre>
11111111  
10111001  
10001111  
11S01 1  
 111111  
</pre>
In this example map, the player will be facing North when the game launches. This map is valid, as the map is closed and contains a player, even if there is an inaccessible room, and an empty area inside the map.  
TABs cannot be used for spaces in the map creation, only SPACEs.  
  
Have fun!  
