import random

from possible_answers import possibleAnswers
from possible_guesses import possibleGuesses
from colorama import Fore

def main():
  word = possibleAnswers[random.randint(0, len(possibleAnswers) - 1)]
  alphabet = [
      "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "a", "s", "d", "f",
      "g", "h", "j", "k", "l", "z", "x", "c", "v", "b", "n", "m"
  ]
  alphabet_status = [
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0
  ]
  for turns in range(0, 6):
    if validate(word, turns, alphabet, alphabet_status):
      break

def validate(word, turns, alphabet, alphabet_status):
  guessable = False
  correct = False

  while not guessable:
    guess = input(Fore.WHITE + "\nEnter a guess: ").lower()
    if not guess.isalpha():
      print("\nIncludes non-letters")

    elif len(guess) == 5:
      for j in range(0, len(possibleGuesses)):
        if guess == possibleGuesses[j]:
          guessable = True
          word_status, alphabet_status, alphabet = check(
              guess, word, alphabet, alphabet_status)
          display(correct, word_status, word, guess, turns, alphabet,
                  alphabet_status)
          if word_status == [2, 2, 2, 2, 2]:
            correct = True
            display(correct, word_status, word, guess, turns, alphabet,
                    alphabet_status)
            return (correct)

      if not guessable:
        print("\nNot in word list")

    else:
      print("\nNot five letters")
      
def check(guess, word, alphabet, alphabet_status):
  temp = word
  ret = [0, 0, 0, 0, 0]
  for j in range(0, 5):
    if guess[j] == temp[j]:
      ret[j] = 2
      pos_green = alphabet.index(guess[j])
      alphabet_status[pos_green] = 3
      temp = temp[:j] + "!" + temp[j + 1:]
  for j in range(0, 5):
    for k in range(0, 5):
      if j == k:
        continue
      if guess[j] == temp[k] and ret[j] != 2:
        ret[j] = 1
        pos_yellow = alphabet.index(guess[j])
        if alphabet_status[pos_yellow] < 3:
          alphabet_status[pos_yellow] = 2
        temp = temp[:k] + "!" + temp[k + 1:]
        break
      elif k == 4:
        pass
  for j in range(0, 5):
    if ret[j] == 0 and alphabet_status[alphabet.index(guess[j])] == 0:
      alphabet_status[alphabet.index(guess[j])] = 1
  return ret, alphabet_status, alphabet

def display(correct, word_status, word, guess, turns, alphabet,
            alphabet_status):
  result = ""
  keyboard = []
  if correct:
    print(Fore.WHITE + "\nGreat job, you got it in " + str(turns + 1) + "!")
  else:
    for j in range(0, 5):
      if word_status[j] == 2:
        result += (Fore.GREEN + guess[j].upper())
      elif word_status[j] == 1:
        result += (Fore.YELLOW + guess[j].upper())
      else:
        result += (Fore.WHITE + guess[j].upper())
    print(result)

    for j in range(0, 26):
      if alphabet_status[j] == 3:
        keyboard.append(Fore.GREEN + alphabet[j].upper() + " ")
      elif alphabet_status[j] == 2:
        keyboard.append(Fore.YELLOW + alphabet[j].upper() + " ")
      elif alphabet_status[j] == 1:
        keyboard.append(Fore.BLACK + alphabet[j].upper() + " ")
      else:
        keyboard.append(Fore.WHITE + alphabet[j].upper() + " ")

    print("\n" + ''.join(keyboard[0:10]))
    print(" " + ''.join(keyboard[10:19]))
    print("  " + ''.join(keyboard[19:26]))

    if turns == 5 and word_status != [2, 2, 2, 2, 2]:
      print(Fore.WHITE + "\nToo bad! The answer was " + word + ".")
main()