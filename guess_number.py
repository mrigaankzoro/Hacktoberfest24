import random

def guess_number():
    print("Welcome to the Number Guessing Game!")
    lower_bound = int(input("Enter the lower bound of the range: "))
    upper_bound = int(input("Enter the upper bound of the range: "))
    
    number_to_guess = random.randint(lower_bound, upper_bound)  # Random number within user-defined range
    attempts = 0
    guessed = False

    print(f"I have chosen a number between {lower_bound} and {upper_bound}. Can you guess it?")

    while not guessed:
        try:
            user_guess = int(input("Enter your guess: "))
            attempts += 1

            if user_guess < lower_bound or user_guess > upper_bound:
                print(f"Please guess a number between {lower_bound} and {upper_bound}.")
            elif user_guess < number_to_guess:
                print("Too low! Try again.")
            elif user_guess > number_to_guess:
                print("Too high! Try again.")
            else:
                print(f"Congratulations! You guessed the number in {attempts} attempts.")
                guessed = True
        except ValueError:
            print("Invalid input. Please enter a valid integer.")

# Start the game
guess_number()
