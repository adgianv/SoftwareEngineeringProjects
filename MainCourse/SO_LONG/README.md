# SO LONG

To compile the program, use `make re` in your command line.

### Running the Program

Start the game with the pacman classic map:
```bash
./main  map/pacman-classic.ber
```

You should collect all the collectibles avoiding the enemy to enable the winning portal and win the game.

Press `esc` to exit the game.

You can change the map and choose from the available ones in the `map` folder when running the program.

---

**_Note:_**  The enemy has speed set for the `pacman-classic`, for smaller maps it might be too fast.
Adjust the speed increasing or decreasing the value in the first `if` condition within the function `put_map` in the `sources/put_images.c` file.
Increasing the value from 3 to 6 will decrease the speed in half.

<img width="309" alt="Screenshot 2024-04-07 alle 14 19 24" src="https://github.com/adgianv/42CodingSchool/assets/137940937/49d40947-efda-4ebb-8cd7-bb15fe48184c">

Remember to run `make re` in your command line again.






