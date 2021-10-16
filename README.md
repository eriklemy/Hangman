# Hangman 
- Erick Lemmy dos Santos Oliveira 
- Programação Imperativa (2020)

Hangman is a game in which the player has to guess which word is proposed, having as a hint the number of letters and the theme linked to the word. For each wrong letter, a part of the body is erased until it is hanged.

# Example 
<pre>
|--------------HANGMAN--------------|
|            [1] - play             |
|            [2] - exit             |
|-----------------------------------|
Choice: 1

|------------|                       [score: 0 / 11]
|            |                       [lifes: 6]     
|            0
|           /|\
|           / \
|
|    _ _ _ _ _ _ _ _ _ _ _
Used Letters:
keyword: COMIDA

Type a letter: A

|------------|                       [score: 4 / 11]
|            |                       [lifes: 6]     
|            0
|           /|\
|           / \
|
|    _ A _ A _ _ _ _ A _ A
Used Letters:  A
keyword: COMIDA

Type a letter:

|------------|                       [score: 10 / 11]
|            |                       [lifes: 3]      
|            0
|            |\
|
|   M A C A R R O N A _ A
Used Letters:  M  A  S  X  I  C  R  O  N
keyword: COMIDA

Type a letter:  d
</pre>

---
# Win 
<pre>
         CONGRATS YOU WON!!
         Answer: MACARRONADA

|------------|                       [score: 11 / 11]|            |                       [lifes: 3]      
|            0
|            |\
|             
|
|
Right answer: MACARRONADA
</pre>
--- 
# Lose 
<pre>
|------------|                       [score: 4 / 7]
|            |                       [lifes: 0]    
|           \0/
|
| YOU LOST!!

Right answer: LARANJA
</pre>