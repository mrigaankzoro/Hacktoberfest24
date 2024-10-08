import random

def guess_number():
    number_to_guess = random.randint(1, 100)  # Random number between 1 and 100
    attempts = 0
    guessed = False

    print("Welcome to the Number Guessing Game!")
    print("I have chosen a number between 1 and 100. Can you guess it?")

    while not guessed:
        user_guess = int(input("Enter your guess: "))
        attempts += 1

        if user_guess < number_to_guess:
            print("Too low! Try again.")
        elif user_guess > number_to_guess:
            print("Too high! Try again.")
        else:
            print(f"Congratulations! You guessed the number in {attempts} attempts.")
            guessed = True

# Start the game
guess_number()
