import random

#complete this function to generate a random number between 1 and 100 
def getRandomNumber():
    return random.randrange(1,100)


def runGuess():
    secretNumber = getRandomNumber()
    print("The number is", secretNumber)


if __name__ == '__main__':
    runGuess()