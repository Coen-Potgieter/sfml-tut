

- Gonna make space invaders

GENERAL

- Constants
    - Decided to make a separate file of constants
    - This way we can easily change things like size, max rotation, colours and etc in this file
    - I was getting, some wacky duplication declarations with this, so asked chat and they said to divide into a .h and .cpp file like ive done here

PLAYER

- best to make a collection of shapes
- Now how to make that collection?
- I am thinking of a class that manages the different shapes of the player
    - This way we can have one x&y coords and rotation to check for bounds etc....
    - Getting bounding box may be complicated though?
