//Name randomiser to be used in future secret santas. Will first ask for the names of all the participants and place it into an
//array of people nodes (with if they have been paired yet and any spouses they cannot be paired with). I will then use a romdom 
//number generator to access a certain element in the array to be paired with each name. I will then print this information out in a nice
//list once it is finished for the user to easily read

//Libraries
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

//People nodes
struct person{
    string name;
    string spouseName;
    bool assignedSecretSanta;
    bool assignedAPerson;
    person *secretSanta;
    person *secretSantaOf;

    person() {}
    person(string newName, string newSpouseName){
        name = newName;
        spouseName = newSpouseName;
        secretSanta = nullptr;
        secretSantaOf = nullptr;
        assignedSecretSanta = false;
        assignedAPerson = false;
    }

};

//pairing function
void namePairer(person *membersParticipating[], int sizeOf){
    //This will go through the array and will assign secret santas.
    srand(time(NULL));
    cout << endl;
    cout << "Secret Santas List: " << endl;
    cout << endl;
    cout << "Format: SecretSanta --> Receiver" << endl;
    cout << endl;

    for(int k = 0; k < sizeOf; k++){
        //will first randomise a number
        int randPerson = rand() % sizeOf;
        //if statments to see if that person's spouse is the same
        if(membersParticipating[k]->spouseName == membersParticipating[randPerson]->name){
            //then I need a new random number for it. 
            k--;
        }
        else{
            //Now I need to check whether that person has already been assigned a secret santa
            if(membersParticipating[randPerson]->assignedSecretSanta == true){
                //So I need another random number for the person
                k--;
            }
            else if(membersParticipating[randPerson]==membersParticipating[k]){
                //So it's assigned to the same person, so need to try again
                k--;
            }
            else if(membersParticipating[randPerson]->secretSantaOf==membersParticipating[k]){
                //So it needs to be assigned to a new person to reduce errors, unless it's the last one
                int checkNum = k+1;
                if(checkNum == sizeOf){
                    //nvm, keep moving on
                    membersParticipating[k]->secretSantaOf = membersParticipating[randPerson];
                    membersParticipating[randPerson]->secretSanta = membersParticipating[k];
                    cout << "*   " << membersParticipating[k]->name << " --> " << membersParticipating[randPerson]->name << endl;
                    membersParticipating[k]->assignedAPerson = true;
                    membersParticipating[randPerson]->assignedSecretSanta = true;
                }
                else{
                    k--;
                }
            }
            else{
                //So it passed all the inital conditions. So know I'll assign them and print said assignment
                membersParticipating[k]->secretSantaOf = membersParticipating[randPerson];
                membersParticipating[randPerson]->secretSanta = membersParticipating[k];
                cout << "*   " << membersParticipating[k]->name << " --> " << membersParticipating[randPerson]->name << endl;
                membersParticipating[k]->assignedAPerson = true;
                membersParticipating[randPerson]->assignedSecretSanta = true;
            }
        }
    }
    return;
}

//main function (menu system for the user)

int main(){
    //Although before this I will ask for how many people are participating in the secret santa.
    //First I will ask the names for the persons participating within this secret santa game and if they have a spouses or not
    //I will then assign a node to the node array for each person within it.
    //Afterwards I will call the namePairer function which will print out the names that are assigned using a random number generator
    //using the following format: <SecretSanta> --> <Person to be Gifted>

    int numParticipants;
    cout << "How many will be participating? (ex: 10)" << endl;
    cout << "(Note: Must be greater than or equal to 3)" << endl;
    cin >> numParticipants;

    person** participants;
    participants = new person*[numParticipants];
    for (int j = 0; j < numParticipants; j++){
        participants[j] = nullptr;
    }

    cout << "Will now start adding to the list of participants..." << endl;
    for(int i = 0; i < numParticipants; i++){
        string personName;
        cout << "What is this person's name?" << endl;
        cin >> personName;

        string spousesName;
        cout << "Is the person married to anyone else who is participating in the same game? If not please enter 'No' or 'no'" << endl;
        cin >> spousesName;

        person* newPerson = new person;
        newPerson->name = personName;
        newPerson->spouseName = spousesName;
        newPerson->assignedAPerson = false;
        newPerson->assignedSecretSanta = false;
        newPerson->secretSanta = NULL;
        newPerson->secretSantaOf = NULL;
        participants[i] = newPerson;
    }

    //now will becalling the the namePairer function
    cout << "Will now be assigning names..." << endl;
    namePairer(participants, numParticipants);

    //Now to deconstruct the array
    for(int l = 0; l < numParticipants; l++){
        delete participants[l];
    }
    delete[] participants;

    //Now to return the function
    return 0;
}