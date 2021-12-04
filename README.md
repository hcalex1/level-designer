# TODO: INSERT TITLE

## Definitions:
- *character*: The player's character though which he interacts with the game world
- *tile*: Any space the *character* can occupy.
- *position*: The reference system for location in 2D. It is chracterized two integers (x, y).
- *link*:  *tile*1 is *linked* to *tile*2 when the *character* can move from that *tile*1 to the *tile*2.
- *adjacent*: Two *tiles* are *adjacent* when they are at a distance of 1. This limits *adjacency* to *tiles* in cardinal directions of eachother.

## Assumptions:
1. *tiles* can only be *linked* to *adjacent tiles* 
2. *adjacent tiles* are  by default not *linked*
3. *links* will be bidirectional for simplicity.
4. a *position* can only be occupied by one *tile* during the game

## Reference system:
- 'E' is the direction of 0°.
- 'N' is the direction of 90°.
- 'W' is the direction of 180°.
- 'S' is the direction of 270°.