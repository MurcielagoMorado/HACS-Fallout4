# This code is meant to assist with Fallout 3 and 4's hacking minigame.

# the minigame works as follows:
- a random word is chosen as the correct keyword, with its difficulty affecting the length of the word.
- a list of words with equal length are generated, shuffled along with the keyword, and presented to the player.
- the player has 4 attempts to select the correct keyword.
- after selecting a word as a guess, a "likeness" score is given. This represents how many letters in the guessed word are shared with the keyword in the same position.
- for example, if "LOAN" is the keyword, and the word "BOON" is guessed, the likeness score will be 2, as the second and fourth letters of each word are the same.
- by contrast, "LOAN" and "COAL" will have a likeness of 2 as well. Although both words share O, A, and L, L is not in the same position, and thus not alike.
- the game is won if the player selects the correct keyword, and is lost if the player fails to do so in 4 tries.

# HACS has no online functionality.
Any suggestion otherwise is intended only to provide appropriate theming to the game's universe.

# the flow of the program (HACS) is as follows:
- user is prompted for the list of generated words.
- HACS will analyze the list for each position's most common letter, and produce an "optimal string".
- HACS will then choose the word which best matches the optimal string and output it as its suggested guess.

# TO-DO:
- after suggesting the best guess, prompt user for likeness score and eliminate words that *cannot* be the keyword before repeating the process of finding the optimal string.
- implement tie resolution.
- optimize space usage.
- improve readability.
- visual polish and finishing touches.

# KNOWN ISSUES:
- the order in which the initial list is given has *heavy* impact on optimal string generation and therefore best guess.
- possibility for space and time optimizations.
- does not account for fallout 4's "dud removal" trick.
