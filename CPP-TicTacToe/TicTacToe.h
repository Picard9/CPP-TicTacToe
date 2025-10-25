#pragma once
#include"Game.h"
#include <iostream>
#include <conio.h>
#include <iostream>

class TicTacToe : public Game
{

public:
	char m_board[9] = { '1', '2', '3','4', '5', '6', '7', '8', '9' };
	int turn = 1;
	bool checkMarks = true;


	// This function should return true if the game is over, and false otherwise.
	virtual bool IsGameOver() const
	{

		int CheckWiner = (turn) ? 2 : 1;

		// Rows
		if ((m_board[0] == 'X' && m_board[1] == 'X' && m_board[2] == 'X') ||
			(m_board[0] == 'O' && m_board[1] == 'O' && m_board[2] == 'O')) {
			std::cout << "\nPlayer " << CheckWiner << " wins!\n\n";
			return checkMarks;
		}
		else if ((m_board[3] == 'X' && m_board[4] == 'X' && m_board[5] == 'X') ||
			(m_board[3] == 'O' && m_board[4] == 'O' && m_board[5] == 'O')) {
			std::cout << "\nPlayer " << CheckWiner << " wins!\n\n";
			return checkMarks;
		}
		else if ((m_board[6] == 'X' && m_board[7] == 'X' && m_board[8] == 'X') ||
			(m_board[6] == 'O' && m_board[7] == 'O' && m_board[8] == 'O')) {
			std::cout << "\nPlayer " << CheckWiner << " wins!\n\n";
			return checkMarks;
		}

		// Check columns
		for (int col = 0; col < 3; col++) {
			if ((m_board[col] == 'X' && m_board[col + 3] == 'X' && m_board[col + 6] == 'X') ||
				(m_board[col] == 'O' && m_board[col + 3] == 'O' && m_board[col + 6] == 'O')) {
				std::cout << "\nPlayer " << CheckWiner << " wins!\n\n";
				return checkMarks;
			}
		}

		// Check diagonals
		if ((m_board[0] == 'X' && m_board[4] == 'X' && m_board[8] == 'X') ||
			(m_board[0] == 'O' && m_board[4] == 'O' && m_board[8] == 'O')) {
			std::cout << "\nPlayer " << CheckWiner << " wins!\n\n";
			return checkMarks;
		}

		if ((m_board[2] == 'X' && m_board[4] == 'X' && m_board[6] == 'X') ||
			(m_board[2] == 'O' && m_board[4] == 'O' && m_board[6] == 'O')) {
			std::cout << "\nPlayer " << CheckWiner << " wins!\n\n";
			return checkMarks;
		}

		// Check for draw
		bool isDraw = true; // I assume it's a draw until its finds an empty cell

		//Check each cell
		for (int i = 0; i < 9; i++) {
			if (m_board[i] != 'X' && m_board[i] != 'O') {
				isDraw = false; // found an empty cell / not a draw
				break; //This breal helps me to Exit the loop once I met the condition
			}
		}

		if (isDraw)
		{
			std::cout << "\nIt's a draw!\n\n";
			return true;

		}

		return false;
	}



	// This function should display the current state of the game
	virtual void Display() const
	{
		std::cout << "\nTic-Tac-Toe Board:\n\n";

		std::cout << "-----------\n";
		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++) {
				int index = row * 3 + col;
				std::cout << " " << m_board[index] << " ";
				if (col < 2) std::cout << "|";  // vertical divider
			}
			std::cout << std::endl;
			if (row < 2) std::cout << "---+---+---" << std::endl;
		}
		std::cout << "-----------\n";
	}

	// This function should allow the current player to take their turn
	virtual void TakeTurn()
	{
		int choice = 0;
		int player = (turn) ? 1 : 2;

		if (turn)
		{
			std::cout << "\nPlayer " << player << "'s turn enter a position (1-9): ";
			std::cin >> choice;

			if ((choice < 1 || choice > 9) || (m_board[choice - 1] == 'X' || m_board[choice - 1] == 'O'))
			{
				std::cout << "\nPlayer " << player << ": enter a valid position.\n";
				return;
			}
			else m_board[choice - 1] = 'X';
		}
		else
		{
			std::cout << "\nPlayer " << player << "'s turn enter a position (1-9): ";
			std::cin >> choice;

			if ((choice < 1 || choice > 9) || (m_board[choice - 1] == 'X' || m_board[choice - 1] == 'O'))
			{
				std::cout << "\nPlayer " << player << ": enter a valid position.\n";
				return;
			}
			else m_board[choice - 1] = 'O';
		}
		turn = !turn;
		system("cls");
	}
};
