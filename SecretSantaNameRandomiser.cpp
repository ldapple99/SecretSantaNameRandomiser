//Name randomiser to be used in future secret santas. Will first ask for the names of all the participants and place it into an
//array of people nodes (with if they have been paired yet and any spouses they cannot be paired with). Will then use a ramdom 
//number generator to access a certain element in the array to be paired with each name. Afterwards will print this information out in a neat
//list once for the user to easily read the assignments

//Libraries
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

//person struct
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

//namePairer - Takes and array of type person and it's size to assign and generate a list of paired persons
//Parameters: (person) membersParticipating[], (int) sizeOf
//Returns: NONE (void)
void namePairer(person *membersParticipating[], int sizeOf){
    //Go through the array and will assign secret santas.
    srand(time(NULL));
    cout << endl;
    cout << "Secret Santas List: " << endl;
    cout << endl;
    cout << "Format: SecretSanta --> Receiver" << endl;
    cout << endl;

    for(int k = 0; k < sizeOf; k++){
        //Randomising a number between 0 and sizeOf
        int randPerson = rand() % sizeOf;
        //Checking to see if spouse is the same as the randomised person
        if(membersParticipating[k]->spouseName == membersParticipating[randPerson]->name){
            //then I need a new random number for it. 
            k--;
        }
        else{
            //Check if said person has already been assigned a secret santa
            if(membersParticipating[randPerson]->assignedSecretSanta == true){
                //Therefore need another random number for the person
                k--;
            }
            else if(membersParticipating[randPerson]==membersParticipating[k]){
                //It is assigned to the same person, so need to re-loop
                k--;
            }
            else if(membersParticipating[randPerson]->secretSantaOf==membersParticipating[k]){
                //Neds to be assigned to a new person to reduce errors, unless it's the last one
                int checkNum = k+1;
                if(checkNum == sizeOf){
                    //Keep moving on
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
                //Passed all the inital conditions. Now assigning them and print said assignment
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
    //Asking how many will be participating
    int numParticipants;
    cout << "How many will be participating? (ex: 10)" << endl;
    cout << "(Note: Must be greater than or equal to 3)" << endl;
    cin >> numParticipants;

    //Creating the participants array of type person
    person** participants;
    participants = new person*[numParticipants];
    for (int j = 0; j < numParticipants; j++){
        participants[j] = nullptr;
    }
    
    //Adding to the participants array
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

    //Calling the namePairer() function
    cout << "Will now be assigning names..." << endl;
    namePairer(participants, numParticipants);

    //Deconstructing the array
    for(int l = 0; l < numParticipants; l++){
        delete participants[l];
    }
    delete[] participants;

    //Returning the main function
    return 0;
}
