# Assignment 8.2

For this assignment, you are to write a program garble that introduces transposition errors that are just frequent enough to be annoying into an input provided on stdin, sending the results to stdout.

Your program should process the characters in the input in order. When it encounters two consecutive characters that are (a) both lowercase and (b) have numerical ASCII encodings that have the same remainders mod 7, it should swap these characters. All other characters should be passed through intact.

Rule (b) means that most lowercase characters will not be swapped. For example, all of the characters abcde have different remainders mod 7, so for an input

1. a
2. ab
3. abc
4. abcd
5. abcde

the corresponding output should be

1. a
2. ab
3. abc
4. abcd
5. abcde

On the other hand, 'a' (ASCII code 97) and 'h' (ASCII code 104) have the same remainder 6 when divided by 7. So on input

1. a
2. ah
3. aha
4. ahah
5. ahaha

the output should be

a
ha
haa
haha
hahaa
Note that once a pair of characters has been swapped, those characters don’t participate in further swaps.

Non-letters and letters that are not lowercase are never swapped, and separate otherwise-swappable pairs. So

Haha, thou knave, I say haha!
becomes

Hhaa, tohu knvae, I say ahah!
One check to see if you are applying the rules correctly is that running an input through your program twice should restore the original input.