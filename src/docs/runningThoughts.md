

- Gonna make space invaders

GENERAL

- Constants
    - Decided to make a separate file of constants
    - This way we can easily change things like size, max rotation, colours and etc in this file
    - I was getting, some wacky duplication declarations with this, so asked chat and they said to divide into a .h and .cpp file like ive done here
    - Asked Claude instead an he told me about constexpr, so now i only have a .h file for constants :)

- Bounding Box
    - If we cliukc B then hitbox for all entites are shown...

PLAYER

- best to make a collection of shapes
- Now how to make that collection?
- I am thinking of a class that manages the different shapes of the player
    - This way we can have one x&y coords and rotation to check for bounds etc....
    - Getting bounding box may be complicated though?


BULLETS

- Going to make a class that can handle both player and enemy bullets
- For Player Bullets
    - Need an array that which size muyst be determined at compile time => using `std::array`
    - Will dynamically allocate/deallocate bullets to this array
    
- This is messed up, im gonna abstract player bullets to its own class...
- Tried to have some fixed array but this won't work...
    - Im trying to populate and remove bullets from the clip with some index.
    - Firstly this won't work cause most of the time these bullets are FIFO
    - But also, they may disappear at random times. 
        - Hitting an enemy vs leaving the screen
    - therefore i need some hashmap that can hold x amount of Bullets
    - This means way more computation when it comes to searching for available spots and things...
    - Fuck this hashmap thing. Im using a vector, this makes things much easier i think...
