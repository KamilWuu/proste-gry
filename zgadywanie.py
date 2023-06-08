import random

print("Hello")

random_number =random.randint(0,  100)
i = 0
while True:
    i +=1
    liczba = int(input("Wylosowalem liczbe od 0 do 100: zgadnij liczbe>>>     "))
    if liczba < random_number:
        print("Moja liczba jest wieksza")
    if liczba > random_number:
        print("Moja liczba jest mniejsza")
    if liczba == random_number:
        print("Zgadles liczbe w", i, "probie!")
        break

