#include "questions.h"

Question questions[] = {
    {1, "What is the capital of England?", {"London", "Paris", "Rome", "Berlin"}, 0},
    {1, "Select the correct spelling.", {"Receve", "Receive", "Recieve", "Recive"}, 1},
    {1, "Which word is a color?", {"Apple", "Blue", "Cat", "Run"}, 1},
    {1, "Choose the correct article: ___ apple.", {"A", "An", "The", "No article"}, 1},
    {1, "What is the opposite of 'hot'?", {"Warm", "Cold", "Sunny", "Boiling"}, 1},
    {1, "Select the plural form of 'child'.", {"Childs", "Childes", "Children", "Child"}, 2},
    {1, "Fill in the blank: I ___ a book.", {"Reads", "Read", "Reading", "Have read"}, 1},
    {1, "Which word is a number?", {"Blue", "Seven", "Run", "Dog"}, 1},
    {1, "What is the past tense of 'go'?", {"Goed", "Went", "Gone", "Going"}, 1},
    {1, "Choose the correct pronoun: This is ___ book.", {"Me", "My", "I", "Mine"}, 1},
    
    {2, "Choose the synonym for 'happy'.", {"Sad", "Joyful", "Angry", "Tired"}, 1},
    {2, "What does 'bizarre' mean?", {"Normal", "Strange", "Easy", "Quick"}, 1},
    {2, "Select the correct sentence:", {"He go to school", "He goes to school", "He going to school", "He gone to school"}, 1},
    {2, "What is the comparative form of 'good'?", {"Gooder", "Better", "Best", "More good"}, 1},
    {2, "Which word is an adverb?", {"Quickly", "Quick", "Quicker", "Quickest"}, 0},
    {2, "Choose the correct preposition: I am interested ___ music.", {"on", "in", "at", "for"}, 1},
    {2, "Select the correct passive form: The book ___ by John.", {"Writes", "Was written", "Wrote", "Writing"}, 1},
    {2, "What is a synonym for 'begin'?", {"Start", "End", "Finish", "Close"}, 0},
    {2, "Choose the correct phrasal verb: She ___ up early.", {"Wakes", "Woke", "Wakes up", "Wake up"}, 3},
    {2, "What is the meaning of 'although'?", {"Because", "Despite", "However", "And"}, 2}
	};

int questions_count = sizeof(questions) / sizeof(questions[0]);
