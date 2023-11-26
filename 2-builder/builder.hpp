
/*****************************************************/
enum Side {
  NORTH,
  SOUTH,
  EAST,
  WEST,
};
class Direction {};

class Wall {
 public:
  Wall() {}
};
class Room {
 public:
  Room() {}

  void Addside(Side side, Wall* wall) {}
  void SetSide(Direction dir, Door* door) {}
};
class Door {
 public:
  Door(Room* r1, Room* r2) {}
};

class Maze {
 public:
  Maze() {}

  Room* RoomNo(int n) {}
  void AddRoom(Room* room) {}
};

class MazeBuilder {
 public:
  virtual void BuildMaze() {}
  virtual void BuildRoom(int room) {}
  virtual void BuildDoor(int room_form, int room_to) {}

  virtual Maze* GetMaze() {}

 protected:
  MazeBuilder();
};

class StandardMazeBuilder : public MazeBuilder {
 public:
  StandardMazeBuilder() {}

  virtual void BuildMaze() { current_maze_ = new Maze; }
  virtual void BuildRoom(int n) {
    if (!current_maze_->RoomNo(n)) {
      Room* room = new Room;
      current_maze_->AddRoom(room);

      room->Addside(NORTH, new Wall);
      room->Addside(NORTH, new Wall);
      room->Addside(NORTH, new Wall);
      room->Addside(NORTH, new Wall);
    }
  }
  virtual void BuildDoor(int room_form, int room_to) {
    Room* r1 = current_maze_->RoomNo(room_form);
    Room* r2 = current_maze_->RoomNo(room_to);
    Door* door = new Door(r1, r2);

    r1->SetSide(CommonWall(r1, r2), door);
  }

  virtual Maze* GetMaze() { return current_maze_; }

 private:
  Direction CommonWall(Room* r1, Room* r2);
  Maze* current_maze_{nullptr};
};
/*****************************************************/

/*****************************************************/
class MazeGame {
 public:
  MazeGame() {}

  Maze* CreateMaze(MazeBuilder& builder);
  Maze* CreateComplexMaze(MazeBuilder& builder);
};
Maze* MazeGame::CreateMaze(MazeBuilder& builder) {
  builder.BuildMaze();
  builder.BuildRoom(1);
  builder.BuildRoom(2);
  builder.BuildDoor(1, 2);

  return builder.GetMaze();
}
Maze* MazeGame::CreateComplexMaze(MazeBuilder& builder) {
  builder.BuildMaze();
  builder.BuildRoom(1);
  builder.BuildRoom(2);
  // xxx
  builder.BuildRoom(1005);

  builder.BuildDoor(1, 2);
  // xxx
  builder.BuildDoor(1, 1005);

  return builder.GetMaze();
}
/*****************************************************/

/*****************************************************/
