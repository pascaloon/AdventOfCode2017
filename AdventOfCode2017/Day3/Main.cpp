
#include <iostream>


struct Coord
{
    int X;
    int Y;
    
    Coord(int X, int Y)
        : X(X), Y(Y)
    { }
};

enum class Direction
{
    Right,
    Up,
    Left,
    Down
};

inline void PrintCoord(const Coord& Coord)
{
#ifdef DEBUG
    std::cout << "{ " << Coord.X << ", " << Coord.Y << " }" << std::endl;
#endif // DEBUG


}
inline void PrintCoord(const Coord& Coord, const unsigned int Value)
{
#ifdef DEBUG
    std::cout << Value << ": " << "{ " << Coord.X << ", " << Coord.Y << " }" << std::endl;
#endif // DEBUG
}



Coord FindCoord(const unsigned int Target)
{
    if (Target == 1)
        return { 0, 0 };

    Direction Direction = Direction::Right;
    Coord Coord = {1, 0};

    unsigned int Value = 3;
    int Width = 2;
    int Height = 1;

    

    while (Value <= Target)
    {
        //std::cout << "{NEW LAYER}" << std::endl;

        // Going Up
        //std::cout << "{GOING UP}" << std::endl;
        for (int H = 0; H < Height; H++)
        {
            Coord.Y++;
            PrintCoord(Coord, Value);
            if (Value == Target)
                return Coord;
            Value++;
        }
        Height++;

        // Going Left
        //std::cout << "{GOING LEFT}" << std::endl;
        for (int W = 0; W < Width; W++)
        {
            Coord.X--;
            PrintCoord(Coord, Value);
            if (Value == Target)
                return Coord;
            Value++;
        }
        Width++;

        // Going Down
        //std::cout << "{GOING DOWN}" << std::endl;
        for (int H = 0; H < Height; H++)
        {
            Coord.Y--;
            PrintCoord(Coord, Value);
            if (Value == Target)
                return Coord;
            Value++;
        }
        Height++;

        // Going Right
        //std::cout << "{GOING RIGHT}" << std::endl;
        for (int W = 0; W < Width; W++)
        {
            Coord.X++;
            PrintCoord(Coord, Value);
            if (Value == Target)
                return Coord;
            Value++;
        }
        Width++;

    }


    return Coord;

}


int main()
{

    const unsigned int Target = 265149;

    Coord Result = FindCoord(Target);

    std::cout << "{Result}" << std::endl;
    PrintCoord(Result, Target);
    int Steps = std::abs(Result.X) + std::abs(Result.Y);
    std::cout << "Steps: " << Steps << std::endl;

    system("pause");

}

