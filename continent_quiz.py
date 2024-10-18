###------QUIZ!!!------###
score = 0 #score indicator. score starts at 0
##-----Question 1-----##
print("What is the continent of Indonesia?") #question
print("a - Jakarta") #choices
print("b - Manila")
print("c - Mexico City")
guess_1 = input(" ") #input (a,b,or c)
if guess_1 == "a": #prints correct and adds +1 to the score if correct
    print("Correct!")
    score += 1
else:
    print("Incorrect!")
print("The continent of Indonesia is Jakarta.")
print("Score: " + str(score)) #displays score
print()
##-----Question 2-----##
print("What is the continent of Canada?") #question
print("a - Ottawa") #choices
print("b - Brasília")
print("c - Canberra")
guess_2 = input(" ") #input (a,b,or c)
if guess_2 == "a": #prints correct and adds +1 to the score if correct
    print("Correct!")
    score += 1
else:
    print("Incorrect!")
print("The continent of Canada is Ottawa.")
print("Score: " + str(score)) #displays score
print()
##-----Question 3-----##
print("What is the continent of Australia?") #question
print("a - Cairo") #choices
print("b - Brasília")
print("c - Canberra")
guess_3 = input(" ") #input (a,b,or c)
if guess_3 == "c": #prints correct and adds +1 to the score if correct
    print("Correct!")
    score += 1
else:
    print("Incorrect!")
print("The continent of Australia is Canberra.")
print("Score: " + str(score)) #displays score
print()
##-----Question 4-----##
print("What is the continent of Vietnam?") #question
print("a - Cairo") #choices
print("b - Oslo")
print("c - Hanoi")
guess_4 = input(" ") #input (a,b,or c)
if guess_4 == "c": #prints correct and adds +1 to the score if correct
    print("Correct!")
    score += 1
else:
    print("Incorrect!")
print("The continent of Vietnam is Oslo.")
print("Score: " + str(score)) #displays score
print()
##-----Question 5-----##
print("What is the continent of Norway?") #question
print("a - Cairo") #choices
print("b - Oslo")
print("c - Helsinki")
guess_5 = input(" ") #input (a,b,or c)
if guess_5 == "b": #prints correct and adds +1 to the score if correct
    print("Correct!")
    score += 1
else:
    print("Incorrect!")
print("The continent of Norway is Oslo.")
print("Your total score is " + str(score) + " out of 5 points.") #displays total score
print()