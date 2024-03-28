cmake_minimum_required(VERSION 3.25)
project(CS213_A3_Object_Oriented_Programming)

set(CMAKE_CXX_STANDARD 23)

add_executable(Example X_O_App.cpp X_O_Board.cpp GameManager.cpp Player.cpp RandomPlayer.cpp BoardGame_Classes.hpp)
add_executable(Game3
        5x5_Tic_Tac_Toe/Tic_Tac_Toe_App.cpp
        5x5_Tic_Tac_Toe/Tic_Tac_Toe.h
        GameManager.cpp Player.cpp RandomPlayer.cpp BoardGame_Classes.hpp 5x5_Tic_Tac_Toe/Tic_Tac_Toe_Board.cpp)

add_executable(Games Pyramic_Tic_Tac_Toe.cpp Pyramic_Tic_Tac_Toe.h
        GameManager.cpp Player.cpp RandomPlayer.cpp BoardGame_Classes.hpp
        5x5_Tic_Tac_Toe/Tic_Tac_Toe.h
        5x5_Tic_Tac_Toe/Tic_Tac_Toe_Board.cpp
        A3_Task2_3_4_S3_20220106_20220198_20221217.cpp
        ConnectFourBoard.cpp
        ConnectFourPlayer.cpp
        ConnectFourRandomPlayer.cpp
        Four_in_a_row.h
        X_O_Board.cpp)
add_executable(Game1 Pyramic_Tic_Tac_Toe.h Pyramic_X_O_App.cpp Pyramic_Tic_Tac_Toe.cpp
        GameManager.cpp Player.cpp RandomPlayer.cpp BoardGame_Classes.hpp)
add_executable(Game2 Four_in_a_row.h ConnectFourBoard.cpp ConnectFourRandomPlayer.cpp
        ConnectFourPlayer.cpp GameManager.cpp Player.cpp RandomPlayer.cpp BoardGame_Classes.hpp main.cpp)