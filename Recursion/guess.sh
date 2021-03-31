#!/bin/bash

echo "Welcome to the Number Guessing Game!"
read -p "Enter User Name: " userName

set scoreFile "userScores_bash"

(( rando = RANDOM % 128 + 1 ))
set guess {-1}
set numGuesses 0



while (( guess != rando )); do
	numGuesses=$((numGuesses+1))
	read -p "Guess the number (0-128) $numGuesses: " guess

	if (( guess < rando )); then
		echo "Low Guess."
    elif (( guess > rando )); then
		echo "High Guess."
	fi
													   
done

echo -e "Congratualations! You guessed it in $numGuesses tries.\n"

echo $userName $numGuesses >> $scoreFile

echo "Scores"
sort -n $scoreFile
