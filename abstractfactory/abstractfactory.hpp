

#define North "north"
#define South "south"
#define West "west"
#define East "east"

class Maze {
 public:
  Maze() {}

  void AddRoom(Room* room) {}
};
class Wall {};
class Room {
 public:
  Room(int n) {}

  void SetSide(char* location, Door* door) {}
  void SetSide(char* location, Wall* wall) {}
};
class Door {
 public:
  Door(Room* r1, Room* r2) {}
};

class MazeGame {
 public:
  MazeGame() {}

  Maze* MazeGame::CreateMaze(MazeFactory& factory);
};

class MazeFactory {
 public:
  MazeFactory() {}

  virtual Maze* MakeMaze() const { return new Maze; }
  virtual Wall* MakeWall() const { return new Wall; }
  virtual Room* MakeRoom(int n) const { return new Room(n); }
  virtual Door* MakeDoor(Room* r1, Room* r2) const { return new Door(r1, r2); }
};

Maze* MazeGame::CreateMaze(MazeFactory& factory) {
  Maze* aMaze = factory.MakeMaze();
  Room* r1 = factory.MakeRoom(1);
  Room* r2 = factory.MakeRoom(2);
  Door* aDoor = factory.MakeDoor(r1, r2);

  aMaze->AddRoom(r1);
  aMaze->AddRoom(r2);

  r1->SetSide(North, factory.MakeWall());
  r1->SetSide(South, factory.MakeWall());
  r1->SetSide(West, factory.MakeWall());
  r1->SetSide(East, aDoor);

  r2->SetSide(North, factory.MakeWall());
  r2->SetSide(South, factory.MakeWall());
  r2->SetSide(West, aDoor);
  r2->SetSide(East, factory.MakeWall());
}

// 定义各种maze抽象工厂
class EnchantedMazeFactory : public MazeFactory {
 public:
  EnchantedMazeFactory();

  virtual Room* MakeRoom(int n) const { return new EnchantedRoom(n, CastSpell()); }
  virtual Door* MakeDoor(Room* r1, Room* r2) const { return new DoorNeddingSpell(r1, r2); }

 protected:
  Spell* CastSpell() const;
};

class BoomedMazeFactory : public MazeFactory {
 public:
  BoomedMazeFactory();

  virtual Wall* MakeWall() const { return new BoomedWall; }
  virtual Room* MakeRoom(int n) const { return new RoomWithBoom(n); }
};