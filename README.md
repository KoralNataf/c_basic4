# c_basic4
First C course -Files, Strings, Pointers to Functions, Conditional Compilation, Bits.
Running on visual studio.

In genomics, sequencing is the process of displaying information about DNA, RNA,
or protein sequences in a way that allows similarity to be identified between sequence segments in terms of their function, 
structure, or evolutionary relationship.
In this exercise, we will combine DNA, RNA, or protein sequences by using letters and spaces. 
The degree of similarity between two sequences is important when interpreting the information.

The SEQ2 sequence must always be shorter than the SEQ1 sequence.
1. Create a function that gets a text file name and builds a sequence of letters. In the file, the sequence letters are recorded one after another without gaps.

2.Create two sequences of letters SEQ1 and SEQ2 in different sizes and place n of SEQ2 from the beginning of SEQ1. The function constructs a sequence of comparison marks.
The comparison is made between all the pairs SEQ1 [n + i] and SEQ2 [i] as long as SEQ2 does not "slide" from SEQ1. The place numbering starts from 0.
The sequence of signs should be kept compressed, using a minimum amount of memory.
There are only four different comparison marks defined -- a space, an asterisk, a colon, and a dot.

3. Write a getCount function to evaluate the proximity between the two sequences. 
The function receives a sequence of comparison marks in a compressed form and returns the difference between the number of asterisks and the number of points in the sequence.

4. Write an evaluationDifference function that takes two sequences of letters SEQ1 and SEQ2 of different sizes and position n. The function returns the value of the proximity between the two sequences. 
The comparison is made between all the pairs SEQ1 [n + i] and SEQ2 [i] as long as SEQ2 does not "slide" from SEQ1. The place numbering starts from 0.
5. Write a main function that demonstrates all the functionality you developed in the previous sections.
The main gets through the parameters the names of all the required files.
Inside the main provide two running options: display sequences and symbols to the screen or not display sequences and symbols to the screen.
The execution option will be set according to the PRINT_SEQUENCES macro to be set or not set.
