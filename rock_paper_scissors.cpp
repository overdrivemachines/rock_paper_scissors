#include <iostream>

using namespace std;

int translateInputToInt(char input);

int main(int argc, char const *argv[]) {
  const int ROCK = 0, PAPER = 1, SCISSORS = 2;
  char opponent_choice, outcome;
  int my_choice_int;
  int total_score = 0;
  // A = Rock       - 1 Point
  // B = Paper      - 2 Points
  // C = Scissors   - 3 Points

  int choice[3] = {1, 2, 3};

  // Rock 0
  // Paper 1
  // Scissors 2
  int defeats[3], wins[3];

  defeats[ROCK] = SCISSORS;
  defeats[PAPER] = ROCK;
  defeats[SCISSORS] = PAPER;

  wins[SCISSORS] = ROCK;
  wins[ROCK] = PAPER;
  wins[PAPER] = SCISSORS;

  // Lost - 0 Points
  // Draw - 3 Points
  // Won  - 6 Points

  int points_matrix[3][3] = {
      // rock, paper, scissors
      {1, 1, 1},  // rock
      {2, 2, 2},  // paper
      {3, 3, 3}   // scissors
  };

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      points_matrix[i][j] = choice[i];
      if (i == j) {
        // Tie
        points_matrix[i][j] += 3;
      } else {
        if (defeats[i] == j) {
          // won 6 points
          points_matrix[i][j] += 6;

        } else if (defeats[j] == i) {
          // lost 0 points
        }
      }
    }
  }

  // read input
  while (!cin.eof()) {
    cin >> opponent_choice;
    cin >> outcome;

    // calculate my input based on what the outcome should be
    switch (outcome) {
      case 'X':
        // I need to lose
        my_choice_int = defeats[translateInputToInt(opponent_choice)];
        break;
      case 'Y':
        // I need to end the round in a draw
        my_choice_int = translateInputToInt(opponent_choice);
        break;
      case 'Z':
        // I need to win
        my_choice_int = wins[translateInputToInt(opponent_choice)];
        break;
      default:
        cout << "Invalid Outcome" << endl;
        exit(0);
    }

    // cout << my_choice_int << " - " << opponent_choice << " - " << outcome << endl;

    total_score += points_matrix[my_choice_int][translateInputToInt(opponent_choice)];

    cin.get();   // reads in the new line character \n after the input (on the same line)
    cin.peek();  // reads first character of the next line
  }

  cout << total_score << endl;

  return 0;
}

int translateInputToInt(char input) {
  switch (input) {
    case 'A':
      return 0;
      break;
    case 'B':
      return 1;
      break;
    case 'C':
      return 2;
      break;
    default:
      return 3;
  }
}
