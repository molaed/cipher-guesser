note from Cohen who converted it to C++: "just pretend it is all C++ instructions xd"

## So what's all this about? 🖥️
Caesar is a C-library for encoding and decoding English text using the classic Caesar cipher! :sunglasses:

*Currently the library uses a 3-character shift, meaning a becomes d & so on*

Read more below for the full details...

## How does Caesar work?
As of now, the Caesar library uses:
* Casting
* Modular Arithmetic
* File I/O


## Function Descriptions
*Refer to caesar.h and caesar.c*

**char text_cipher(const char c, unsigned int shift)**
Takes an ascii character and encodes it into caesar cipher by shifting it 'shift' positions in the ascii chracter line.   
Ex. text_cipher('a', 3) returns 'd'.  
Special cases: newline '\n', space ' ' and double-quotes '\"' are not converted.

**char cipher_text(const char c, unsigned int shift)** 
Takes an ascii character (in caesar cipher) and shifts it back by 'shift' positions in the ascii line.  
Ex. cipher_text('d', 3) returns 'a'.  
Special cases: same as text_cipher

**void encode_line(char \*src, unsigned int shift)**
Takes a string of ascii characters and shifts all of them by 'shift' positions.  
Ex. "Julius Caesar" becomes "Mxolxv Fdhvdu" with a shift of 3.

**void decode_line(char \*src, unsigned int shift)**
Takes a string of caesar cipher text and shifts every character inside by 'shift' positions.  
Ex. "Mxolxv Fdhvdu" becomes "Julius Caesar" with a shift of 3.

**unsigned int encode_to_file(char \*dest, char \*src, unsigned int max_len, unsigned int shift)**
Reads lines from src and translates them into caesar cipher (shifting by 'shift' characters), assuming each line in src is no more than max_len characters long.  
Returns:
* 0: if the max_len value was less than 1.
* 1: if one of the files could not be opened (or did not exist).
* 2: if there was a malloc failure.

**unsigned int decode_to_file(char \*dest, char \*src, unsigned int max_len, unsigned int shift)**
Reads lines from src and shifts their characters back by 'shift' positions, assuming each line in src is no more than max_len characters long.  
Returns:
* 0: if the max_len value was less than 1.
* 1: if one of the files could not be opened (or did not exist).
* 2: if there was a malloc failure.

## Check it out!
Download the repo. Use the Makefile in the Terminal: run 'make main', then run './main'.  
For source file use "text.txt" and for target file use "cipher.txt".
For max no. of characters use 52, and for shift try 3.  
Enjoy! :tada:
