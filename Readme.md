*This project has been created as part of the 42 curriculum by <lupayet>, <cbrice>.*


**cub3D — RayCaster with MiniLibX**


**Description**

	cub3D is a 3D maze exploration program inspired by the legendary game Wolfenstein 3D, one of the first first-person shooters in history. The goal of this project is to implement a raycaster — a rendering technique that simulates a 3D perspective from a 2D map using ray casting mathematics.

	The program reads a scene description file (.cub), parses the map and configuration, and renders a real-time 3D view using the MiniLibX graphics library. The player can navigate the maze using keyboard controls, with textured walls, colored floor and ceiling, and collision detection.


Key features:
	. Real-time 3D rendering via the DDA (Digital Differential Analysis) raycasting algorithm
	. 4 directional wall textures (North, South, East, West) loaded from .xpm files
	. Configurable floor and ceiling colors via RGB values in the scene file
	. Smooth player movement (W/A/S/D) and camera rotation (arrow keys)
	. Wall collision detection with sliding along walls
	. Minimap overlay for navigation assistance
	. Robust .cub file parsing with detailed error handling


**Instructions**

Requirements
	. GCC or Clang compiler
	. MiniLibX (included in mlx/ for Linux, mlx_mac/ for macOS)
	. X11 libraries (Linux only): libXext, libX11
	. Make

Compilation
	git clone <repository_url> cub3D
	cd cub3D
	make

	This will produce a ./bin/cub3D executable and a ./cub launcher script.

Usage
	Run the program directly:
		./bin/cub3D maps/valide/val.cub
	Or use the launcher script (searches for the map by filename in maps/):
		./cub val.cub
	The map file must have a .cub extension.

Controls
	W			Move forward
	S			Move backward
	A			Strafe left
	D			Strafe right
	<- ->		Rotate camera
	ESC or Q	Quit

Scene File Format (.cub)
	NO ./path/to/north_texture.xpm
	SO ./path/to/south_texture.xpm
	WE ./path/to/west_texture.xpm
	EA ./path/to/east_texture.xpm
	F 220,100,0
	C 50,50,50

	1111111111111
	1000000000001
	100N000000001
	1111111111111

	. NO, SO, WE, EA-paths to .xpm wall textures
	. F — floor color (R,G,B values between 0 and 255)
	. C — ceiling color (R,G,B values between 0 and 255)
	. Map characters: 1 (wall), 0 (empty), N/S/E/W (player spawn + orientation)
	. The map must be enclosed by walls on all sides


Makefile Rules
	make or make all	Compile the project
	make re				Clean and recompile
	make clean			Remove object files
	make fclean			Remove all generated files
	make run			Compile and run with default map
	make val			Run with Valgrind memory checker


**Resources**

Raycasting & 3D Graphics
	. Lode's Raycasting Tutorial — The reference tutorial used as the mathematical foundation for this project: https://lodev.org/cgtutor/raycasting.html
	. Wolfenstein 3D — The original 1992 game by id Software that pioneered raycasting in commercial games
	. MiniLibX Documentation — 42 School's graphics library documentation: https://harm-smits.github.io/42docs/libs/minilibx

DDA Algorithm
	. Wikipedia — Digital Differential Analyzer: https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)
	. Bresenham's line algorithm (related concept): https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
	. XPM Format

AI Usage
	AI assistance (Claude by Anthropic) was used during this project for the following tasks:
		. Debugging: Identifying the root causes of segmentation faults, memory corruption issues, and compilation errors — particularly a critical bug where ft_printf was corrupting memory due to unsupported format specifiers.
		. Code structure guidance: Advice on splitting functions to comply with 42 norm (max 25 lines, max 5 variables per function, max 5 functions per file), and suggestions for refactoring using helper structs.
		. Memory management: Guidance on properly freeing MLX resources (mlx_destroy_image, mlx_destroy_display) and structuring free_game / close_cube functions
		. Map parsing logic: Help designing the flood fill validation algorithm and the is_map_line detection heuristic.
		. Cross-platform compilation: Resolving differences between Linux (X11) and macOS (OpenGL/AppKit) for MiniLibX linking flags.
	AI was not used to directly write core algorithmic code (DDA raycasting, texture mapping calculations) — those were implemented based on the Lode's tutorial and our own understanding.