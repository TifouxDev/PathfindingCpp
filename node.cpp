#include "node.h"
#include <cmath>
#include <math.h>
node::node()
{
    started = false;
    closed = false;
    fermer = false;
}

node::node(int cellId, int _x, int _y)
{
    m_x = _x;
    m_y = _y;
    m_cellid = cellId;
}


void node::setStarted(bool b_start)
{
    started = b_start;
}

void node::setClosed(bool b_close)
{
    closed = b_close;
}

void node::setWalkable(bool b_walkable)
{
    walkable = b_walkable;
}

void node::calculH(node endNode)
{
    h = 10 * (fabs(endNode.getX() - m_x)  + fabs(endNode.getY() - m_y));
}

int node::getX() const
{
    return m_x;
}

int node::getY() const
{
    return m_y;
}

void node::setFermer(bool b_ferme)
{
    fermer = b_ferme;
}

int node::getCellid()const
{
    return m_cellid;
}
void node::setInOpenList(bool b_inOpenList)
{
    n_inOpenList = b_inOpenList;
}

bool node::getInOpenList()const
{
    return n_inOpenList;
}
void node::setInClosedList(bool b_inClosedList)
{
    n_inClosedList = b_inClosedList;
}

bool node::getInClosedList()const
{
    return n_inClosedList;
}

bool node::getStarted() const
{
    return started;
}

bool node::getClosed() const
{
    return closed;
}

void node::setParent(int p_id)
{
    parent = p_id;
}

int node::getParent()const
{
    return parent;
}

bool node::getWalkable()const
{
    return walkable;
}

void node::setG(int value)
{
    g = value;
}

int node::getG() const
{
    return g;
}

void node::setF(int value)
{
    f = value;
}

int node::getF()const
{
    return f;
}

int node::getH()const
{
    return h;
}
