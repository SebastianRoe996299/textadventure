/*Sebastian Roe's text adventure game
save your friend from the haunted mansion*/





#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Welcome to Sebastian Roe's haunted mansion text adventure game.\n";
    cout << "Throughout this game, you will be presented with a series of riddles.\n";
    cout << "When presented with a riddle, simply type your answer and press enter.\n";
    cout << "The program will tell you if you are correct or not and then you may type again if you got it wrong.\n";
    cout << "Would you like to play the game on the hard difficulty (no hints on any questions) or easy (all questions have hints)?\n\n";
    cout << "1) Easy\n";
    cout << "2) Hard\n";
    int choice;
    cin >> choice;
    while (choice != 1 && choice != 2)
    {
        cout << "That is not a valid choice. Try again.\n";
        cin >> choice;
    }
    bool easyMode;
    if (choice == 1)
    {
        easyMode = true;
        cout << "You are playing on easy mode. That means you can type 'hint' for most questions and receive a hint.\n\n\n";
    }
    else
        easyMode = false;

    //seeding random number
    srand(static_cast<unsigned int>(time(0)));
    //declaring backpack
    vector<string> backpack;
    //printing intro
    cout << "Welcome to the haunted mansion adventure game! \n\n";
    cout << "Your friend has wandered off by themselves into a mysterious, creepy looking mansion..\n";
    cout << "Shockingly, he hasn't returned. So you start to worry deeply.\n";
    cout << "You are hesitant at first, but you realize that you have to make some sacrifices for your friends every once in a while.\n";
    cout << "So, you approach the mansion slowly only to discover the front door is locked\n";
    cout << "After doing some searching, you discover a chest with a combination lock. It requires 4 numbers to unlock.\n";
    cout << "On the chest, it reads 'What is 10 + 10?'\n";
    cout << "So.... you fiddle with the lock having that question in mind...\n";
    cout << "Enter your guess....\n";
    //setting up user to guess lock combo
    string strGuess;
    cin >> strGuess;
    while (strGuess != "0100")
    {
        if (strGuess == "hint" && easyMode)
        {
            cout << "Think like a computer.\n";
            cin >> strGuess;
        }
        else
        {
        cout << "That's wrong! Try again.\n";
        cin >> strGuess;
        }
    }
    //printing next part of adventure
    cout << "The chest opens and you take the key out and walk back over to the door and enter the mansion.\n";
    cout << "You enter to an elaborate and decrepit foyer, it just gives you the heebie jeebies.\n";
    cout << "You hear distant screams.... They could be your friend, they could be some other poor soul.\n";
    cout << "The noises appear to be coming from a door at the top of the main staircase.\n";
    cout << "You walk up the stairs and approach the door.\n";
    cout << "Right after you touch the door handle, a ghostly figure slaps your hand and blocks your path.\n";
    cout << "To get past this door, you must play my game! I'm going to think of a number between 1 and 50. You need to guess the right number to pass! No hints!\n";
    //setting up number guessing game
    int numGuess;
    cin >> numGuess;
    int correct = rand() % 50 + 1;
    while (numGuess != 51 && numGuess != correct)
    {
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You need to enter a number.\n";
        }
        else if (numGuess < correct)
        {
            cout << "That's the wrong number! My number is a little higher. Think outside the box?\n";
        }else
        {
            cout << "That's the wrong number! My number is lower! Think outside the box?\n";
        }
        cin >> numGuess;
    }
    if (numGuess == 51)
    {
        cout << "I never said the right number was a number between 1 and 50, just that I was thinking of a number between 1 and 50.\n";
        cout << "Well, I suppose I must open this door for you now. So long!\n";
        cout << "Oh! Before I go, take this deadly sword. It may be useful. Just maybe.\n\n";
        backpack.push_back("sword");
    }
    else
    {
        cout << "Oh I suppose you guessed the number I was thinking of. That's impressive enough. Alright then, through the door you go.\n";
    }
    cout << "After opening the door you enter a small room that only has another door. The door behind you slams shut on its own.\n";
    cout << "You attempt to open the next door with the key you got earlier, but it doesn't fit the lock.\n";
    cout << "A figure descends from the ceiling and tells you that you need to solve their riddle to pass.\n";
    cout << "The figure asks you, 'What is the first thing that goes through a door when you are opening it?'\n";
    cout << "You hear a faint voice say.... 'Remember that you can use a hint if you are on easy mode!!\n";
    //riddle loop
    cin >> strGuess;
    while (strGuess != "key")
    {
        if (strGuess == "hint" && easyMode)
        {
            cout << "you may have one on you...\n";
        }
        else
        {
            cout << "Not right! Try again.\n";
        }
        cin >> strGuess;
    }
    cout << "Yes, yes... You may proceed.\n";
    cout << "After walking through the door you arrive into a large room that appears to be some kind of dungeon.\n";
    cout << "You look around to see if you can find your friend anywhere, but they don't appear to be here.\n";
    cout << "You continue walking through the dungeon, looking for a way through.\n";
    cout << "After searching a while, you see a rope leading up into a hole in the ceiling.\n";
    cout << "In the same room, there is a mysterious looking chest that you decide to investigate.\n";
    cout << "On the chest there is a riddle printed, it reads: \n";
    cout << "During which month do people sleep the least? One attempt! (Remember to use a hint on easy mode!)\n";
    cin >> strGuess;
    if (strGuess == "February" || strGuess == "february")
    {
        cout << "The chest opens and inside you find a dagger. You place it inside your backpack and head for the rope.\n";
        backpack.push_back("dagger");
    }
    else if (easyMode && strGuess == "hint")
    {
        cout << "Think about which month would have the least opportunity to sleep a lot in one month!\n";
        cin >> strGuess;
        if (strGuess == "February" || strGuess == "february")
        {
            cout << "The chest opens and inside you find a dagger. You place it inside your backpack and head for the rope.\n";
            backpack.push_back("dagger");
        }
        else
        {
            cout << "After saying your guess, nothing happened, and the box magically disappeared. Oh well.\n\n";
        }
    }
    else
    {
        cout << "After saying your guess, nothing happened, and the box magically disappeared. Oh well.\n\n";
    }

    if (!easyMode){
        cout << "After climbing up the rope you find yourself in a room with nothing but a door.\n";
        cout << "You feel as if you are going to have to solve another riddle.\n";
        cout << "Once you reach get into the room the hole you climbed out of seals by itself.\n";
        cout << "In the room a ghost approaches you..\n";
        cout << "You've made it to the final room before you see your friend. You just need to solve my riddle.\n";
        cout << "What has a head and a tail, but no body?\n\n";
        cin >> strGuess;
        while (strGuess != "coin")
        {
            cout << "Incorrect! Try again!\n";
            cin >> strGuess;
        }
        cout << "You answer the riddle correctly and go through the door.";
    }
    cout << "The next room appears to be another dungeon with many cells.";
    cout << "You begin to worry that after all your troubles you may not be able to find your friend and help them escape. This place looks very dangerous.\n";
    cout << "Suddenly, you hear the voice of your friend coming from one of the cells.\n";
    cout << "You assure your friend you are both going to get out when a giant troll comes out of nowhere.\n";
    cout << "It looks like you are going to have to battle the troll to free your friend!\n";
    //setting up final battle
    int heroHP;
    int trollHP;
    int trollDmg;
    int heroDmg;
    int action;
    if (easyMode)
    {
        heroHP = 20;
        trollHP = 20;
        trollDmg = 4;
        heroDmg = 4;
    }
    else
    {
        heroHP = 30;
        trollHP = 30;
        trollDmg = 6;
        heroDmg = 5;
    }
    bool healNotUsed = true;
    //giving hero extra damage if they have a sword
    if (find(backpack.begin(), backpack.end(), "sword") != backpack.end())
    {
        heroDmg += 2;
    }
    if (find(backpack.begin(), backpack.end(), "dagger") != backpack.end())
    {
        heroDmg += 1;
    }
    //battle loop
    while (heroHP > 0 && trollHP > 0)
    {
        cout << "What will you do?\n";
        cout << "1) Attack (50% chance to hit)\n";
        cout << "2) Heal (only 1 heal avaialable)\n";
        cout << "3) Attempt to flee\n";
        cin >> action;
        if (action == 1)
        {
            if (rand()%2)           //50% chance to hit
            {
                cout << "Your attack hit the troll and did " << heroDmg << " damage points!\n";
                trollHP -= heroDmg;
                if (trollHP <= 0)
                {
                    cout << "You have defeated the troll in combat!\n";
                    break;
                }
            }else                   //miss
            {
                cout << "Your attack missed! The troll hit you for 4 damage points!\n";
                heroHP -= trollDmg;
            }
            cout << "Your HP: " << heroHP << "\nTroll's HP: " << trollHP << endl;
        }
        else if (action == 2 && healNotUsed)
        {
            heroHP += 4;                        //healing
            healNotUsed = false;
        }
        else if (action == 3)
        {
            if ((rand()%25 + 1) == 1)
            {
                cout << "You have successfully fleed! You and your friend high tail it out of there.\n";            //successful flee
                trollHP = 0;
            }else
            {
                cout << "You failed to escape!\n";
                if (rand() % 2)                                                                                     //50% chance for troll to hit if you try to flee
                {
                    cout << "The troll has hit you while you attempted to flee and dealt half damage.\n";
                    heroHP -= 2;
                    cout << "Your HP: " << heroHP << "\nTroll's HP: " << trollHP << endl;
                }
            }
        }
    }
    //hero lost
    if (heroHP <= 0)
    {
        cout << "Game over! You failed to defeat the troll, and now you must be locked away in his dungeon forever. At least you have your friend...\n";
    }else           //hero won
    {
        cout << "You successfuly make it out of the haunted mansion with your friend. The story ends.\n";
    }

    return 0;
}
