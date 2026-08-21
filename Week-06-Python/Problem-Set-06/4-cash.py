from cs50 import get_float

# Prompt the user for change owed
while True:
    dollar = get_float("Change: ")
    if dollar >= 0:
        break

cents = round(dollar * 100)
coins = 0

# Number of Quarters to give customer
while cents >= 25:
    cents -= 25
    coins += 1

# Number of Dimes to give customer
while cents >= 10:
    cents -= 10
    coins += 1

# Number of Nickels to give customer
while cents >= 5:
    cents -= 5
    coins += 1

# Number of Pennies to give customer
while cents >= 1:
    cents -= 1
    coins += 1

# Print the sum of the coins
print(coins)
