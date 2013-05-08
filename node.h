#ifndef NODE_H
#define NODE_H
#include <cmath>
#include <iostream>
class node
{
public:
    node();
    node(int cellId, int _x, int _y);
    void setStarted(bool b_start);
    bool getStarted()const;

    void setClosed(bool b_close);
    bool getClosed()const;

    void setWalkable(bool b_walkable);
    bool getWalkable()const;

    void calculH(node endNode);

    int getH()const;
    int getX() const;
    int getY() const;

    void setFermer(bool b_ferme);

    int getCellid() const;

    void setInOpenList(bool b_inOpenList);
    bool getInOpenList()const;

    void setInClosedList(bool b_inClosedList);
    bool getInClosedList()const;

    void setParent(int p_id);
    int getParent()const;

    void setG(int value);
    int getG()const;

    void setF(int value);
    int getF()const;


private:
    int m_x;
    int m_y;
    int m_cellid;
    bool started;
    bool closed;
    bool fermer;
    bool walkable;
    int parent;
    bool n_inClosedList;
    bool n_inOpenList;
    int h,f,g;


};

#endif // NODE_H
