# Chess

This is an unfinished project for the Object Oriented Programming class taught in Sofia University during the spring semester of 2018/2019.
It is a simple implementation of a not-so-simple project for the traditional game of chess. The classes are as follow.

* **Position**
  
  Position is a class for combining the two coordinates of a figure for easier access on the board.

* **Figure**

  This is an abstract class encapsulating the common functionality for the classes of the individual chess pieces.
  Each piece has:
  
    - a name (char);
  
    - a starting and a current positions (Position);
  
    - an integer, indicating the number of possible positions said piece has access to;
 
    - a dynamic Position array, containing the aforementioned positions.

  The methods in this class are the expected canonical constructors and destructors as well as getters and setters. There is also a pure virtual method `clone()`, whose return value is a pointer to newly created copy of the caller object.

* **Pawn**

  Pawn inherits the Figure class. The former means to represent the pawn pieces on the chess board.
  The class has definitions of a constructor and of the pure virtual `clone()`, declared in the parent Figure class. There is also a method checking if the piece has reached the end of the board. This information is needed for the special pawn transformation into another piece (except king) when reaching the oposite end of the board.

* **Rook**

  Rook inherits the Figure class. The former means to represent the rook pieces on the chess board.
  Apart from the constructor and `clone()`, this class also has an attribute for keeping track of the number of moves of the corresponding piece. This information is needed when validating certain moves, e.g Castling.

* **Knight**

  Knight inherits the Figurre class. The former means to represent the knight pieces on the chess board.
  The only methods in this class are the inevitable constructor and `clone()`.

* **Bishop**

  Bishop inherits the Figurre class. The former means to represent the bishop pieces on the chess board.

* **Queen**

  This class inherits the abstract Figure class. The former means to represent the queen piece on the chess board.
  It is implemented as a combination of the Bishop and the Rook classes.

* **King**

  King inherits the Figure class. The former means to represent the king piece on the chess board.
  There is an additional attribute for counting the number of moves the corresponding piece had made. The need for such attribute is the special move Castling.

* **Player**

  Player is the class representing a player in the game.
  Each player has:

    - a name (char*);
 
    - a dynamic Figure array containing the said player's pieces.

  The methods implemented for this class are the following:

    - two private helper methods for copying and for deleting a player;
 
    - a setter for the dynamic array of pieces;
 
    - a cannonic representation;
 
    - a method for writing in a file the player and his score from the game.

 * **Board**

   This class represents the board a game is being played on.
   The attributes of it are:

     - a dynamic array of pieces (Figure***) in the role of the black-and-white board. Initially, all fields are nullptr. Subsequently, the initial positions of the pieces are initialized with pointers to the objects;
       
     - two dynamic arrays - one for the black pieces and one for the white ones;
       
     - two counters for the number of elements in each pieces' array.

   
   There are the following private methods:

     - two helper methods - for copying and for deleting the board;
  
     - two helper methods for initializing the values in the pieces' arrays - one for the black ones and one for the white ones.
  
   The public methods are:

     - the canonic methods;
  
     - overloaded operator for displaying the board on the console;
  
     - getters for the board and for the two arrays of pieces (black and white ones).

* **Play**

  This is the class that encapsulates the entire hierarchy within itself.
  There are the attributes:

    - the board on which the game will be played;
 
    - two players.
 
  The private methods are:

    - a helper method for extracting a piece by given position;
 
    - a method for checking if a given position is occupied;
 
    - a method for checking if given piece is white;
 
    - a method for checking if two pieces are of the same colour (belong to the same player).
 
  The public methods are:

    - a constructor withtwo parameters - the names of the two players;
 
    - a getter for the board;
 
    - a checker if the white king is in check;
 
    - a checker if the black king is in check;
 
    - a method for capturing an opponent's piece;
 
    - a method for moving a piece by given two positions;
 
    - an En Passant checker;
 
    - a Castling checker.
