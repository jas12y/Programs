/*
Programmers Name: John Stubbs
      Assignment: #8
            Date: 4/26/13

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
    void SetSize(const int);
    void SetBorder(const char);
    void SetFill(const char);
    void Draw();
    void Fill(const int);
    void Summary();
};

#endif
