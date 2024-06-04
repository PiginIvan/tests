#include  "include/gtest/gtest.h"
#include "../Rendering Raylib/src/Tools.cpp"
#include "raylib.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <string>
#include "raylib.h"

#define SIZE_PIXEL_MAP (240)
#define THICKNESS_MAP (10)

using tableChar = std::vector<std::string>;

class Map
{
public:
    tableChar scheme;
    std::vector<std::pair<Rectangle, char>> objects;

    Map(const std::string& filename);
    void findObjects();
    void readTextures(const std::string &filename);
    void showObjectsInWindow() const;
    void showFrame() const;
    const Color& getFillColor() const;
    const Vector2& getMazeSize() const;
    const Vector2& getWallSize() const {return wallSize; };
    const Rectangle& getFrame() const;
    const Texture2D* getTexture(char type) const;

private:
    Vector2 mazeSize; Vector2 wallSize;
    Rectangle frame;
    std::unordered_map<char, Texture2D> textures;
    std::unordered_map<char, Color> colors;
};

Map::Map(const std::string& filename) {
    std::cout << 1;
    frame.width = SIZE_PIXEL_MAP; frame.height = SIZE_PIXEL_MAP;
    frame.x = THICKNESS_MAP * 2; frame.y = THICKNESS_MAP * 2;

    std::ifstream file(filename, std::ios::in); std::string mazeLine;
    while (!file.eof()) 
    {
        file >> mazeLine;
        scheme.push_back(mazeLine);
    }
    file.close();
    mazeSize.x = scheme.front().size(); // Взять длину стенки миникарты
    mazeSize.y = scheme.size();         // Взять ширину стенки миникарты
    wallSize.x = SIZE_PIXEL_MAP / mazeSize.x;
    wallSize.y = SIZE_PIXEL_MAP / mazeSize.y;
}

const Rectangle& Map::getFrame() const
{
    return frame;
}
class MyClass
{
  std::string id;

public:
  MyClass(std::string _id) : id(_id) {}
  std::string GetId() { return id; }
};
struct MyClassTest : public testing::Test {
  Map *mc;

  void SetUp() { mc = new Map("../Rendering Raylib/resources/maze.txt"); } // аналог конструктора
  void TearDown() { delete mc; } // аналог деструктора
};

TEST(testTools, getDist2Points)
{
    Vector2 v1 = {4, 2}, v2 = {2, 10};
    EXPECT_FLOAT_EQ(getDist2Points(v1, v2), 8.24621);
}

TEST(testTools, DegToRad)
{
    EXPECT_FLOAT_EQ(DegToRad(40), 0.69813168);
}

TEST_F(MyClassTest, getWallSize)
{
  // Act
  Vector2 v1 = mc->getWallSize(), v2 = {4, 2};

  // Assert
  EXPECT_FLOAT_EQ(getDist2Points(v1, v2), 18.439089);
}


TEST(testTools, RadToDeg)
{
    EXPECT_FLOAT_EQ(RadToDeg(40), 2291.8313);
}

TEST(testTools, constrainAngle360)
{
    EXPECT_FLOAT_EQ(constrainAngle360(40), 40);
}

// int main(int argc, char **argv)
// {
//   ::testing::InitGoogleTest(&argc, argv);
  
//   return RUN_ALL_TESTS();
// }