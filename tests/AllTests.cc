#include  "include/gtest/gtest.h"
#include "../Rendering Raylib/src/Tools.cpp"
#include "../Rendering Raylib/include/Map.hpp"
#include "raylib.h"
#include <fstream>
Map::Map(const std::string& filename) : 
    scheme(), objects(), textures(), colors()
{
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

const Vector2& Map::getWallSize() const
{
    return wallSize;
}

//TEST(testMap, getWallSize)
//{
//   Vector2 v = {4, 2};
//    Map m("../Rendering raylib/resources/maze.txt");
//    EXPECT_FLOAT_EQ(getDist2Points(m.getWallSize(), v), 0);
//}

TEST(testTools, getDist2Points)
{
    Vector2 v1 = {4, 2}, v2 = {2, 10};
    EXPECT_FLOAT_EQ(getDist2Points(v1, v2), 8.24621);
}

TEST(testTools, DegToRad)
{
    EXPECT_FLOAT_EQ(DegToRad(40), 0.69813168);
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