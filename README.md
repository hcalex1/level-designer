# INF1015 Projet - Jeu Deadly Rooms

## Definitions:
- *character*: The player's character though which he interacts with the game world
- *tile*: Any space the *character* can occupy.
- *position*: The reference system for location in 2D. It is chracterized two integers (x, y).
- *link*:  *tile*1 is *linked* to *tile*2 when the *character* can move from that *tile*1 to the *tile*2.
- *adjacent*: Two *tiles* are *adjacent* when they are at a distance of 1. This limits *adjacency* to *tiles* in cardinal directions of eachother.
- *room*: The object occupying a *tile* with which a *character* can interact.

## Assumptions:
1. *tiles* can only be *linked* to *adjacent tiles* 
2. *adjacent tiles* are  by default not *linked*
3. *links* will be bidirectional for simplicity.
4. a *position* can only be occupied by one *tile* during the game

## Reference system:
- *positions* are represented by two integers and are used as `std::pair<int, int>`.
- NORTH is the direction represented by the vector ( 0, 1)
- EAST  is the direction represented by the vector ( 1, 0)
- SOUTH is the direction represented by the vector ( 0,-1)
- WEST  is the direction represented by the vector (-1, 0)

## Structure
Level creation and loading will be seperate from the game. All the optimisation and rule/assumption enforcement and validation should be completed during level creation and loading. This allows for faster navigation and room loading. For the mapping system, we can think of `Map` as a specialized 2D container, of `Navigator` as the iterator for this 2D container and `Tile` as a node in the container.

### The Tile class
The `Tile` contains all the information necessary to navigate the *map*. This information is quickly accessible and does not require much computation.

This information includes:
- pointers to *adjacent tiles* (`weak_ptr` to avoid circular referencing)
- wether or not the *tile* are *linked*

Link are tracked in a bitmap.

### The Map class
The `Map` allows the level designer to set *adjacency* in a consistent manner respecting assumptions above. It stores all the *tiles* by their *position*. Therefore, it facilitates destruction of the *tiles* to free up memory when changing levels.
 
### The Navigator class
The `Navigator` is used to move through the *tiles*. It holds the current *position* and interprets the information in *tile* to only allow movement between *linked tiles*.

### The Game class
The `Game` interprets the player's commands, modifies the `Tile`s and `Navigator` accordingly and gives feedback to the player.

### The Lookable class
The `Lookable` class is an abstract class from which all classes with information viewable to the user will be derrived.

### The Room class
The `Room` class is the object with which the player interacts. I contains information about the *room* viewable by the *character*. More functionality can be added to this class.