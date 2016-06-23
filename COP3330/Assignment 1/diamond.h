/*
Programmers Name: John Stubbs
      Assignment: #1
            Date: 1/18/13

This file defines the class Diamond
*/
# ifndef DIAMOND_H
# define DIAMOND_H

class Diamond
{
private:
    int Dsize;
    char Dborder;
    char Dfill;
    
public:
    Diamond();
    Diamond(const int, const char b = '#', const char f = '*');
    int GetSize();
    int Perimeter();
    double Area();
    void Grow();
    void Shrink();
    void SetBorder(const char);
    void SetFill(const char);
    void Draw();
    void Fill(const int);
    void Summary();
};

#endif
