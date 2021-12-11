# SecretSantaNameRandomiser
Quick name randomiser to be used in Secret Santas. Makes sure that spouses are not paired with each other.

# How to Compile
Use the following command:
```
g++ -std=c++11 SecretSantaNameRandomiser.cpp -o SecretSantaNameRandomiser
```
# Example Output:
```
./SecretSantaNameRandomiser 
How many will be participating? (ex: 10)
(Note: Must be greater than or equal to 3)
5
Will now start adding to the list of participants...
What is this person's name?
Rowan
Is the person married to anyone else who is participating in the same game? If not please enter 'No' or 'no'
no
What is this person's name?
Edmond
Is the person married to anyone else who is participating in the same game? If not please enter 'No' or 'no'
Sara
What is this person's name?
Sara
Is the person married to anyone else who is participating in the same game? If not please enter 'No' or 'no'
Edmond
What is this person's name?
Bob
Is the person married to anyone else who is participating in the same game? If not please enter 'No' or 'no'
no
What is this person's name?
Alice
Is the person married to anyone else who is participating in the same game? If not please enter 'No' or 'no'
no
Will now be assigning names...

Secret Santas List: 

Format: SecretSanta --> Receiver

*   Rowan --> Alice
*   Edmond --> Bob
*   Sara --> Rowan
*   Bob --> Sara
*   Alice --> Edmond
```

