#include "pathfinding.h"

pathFinding::pathFinding()
{
    MAP_WIDTH = 14;
    MAP_HEIGHT = 20;
    finish_search = false;
}



QVector<int> pathFinding::findPath(int startId, int endId)
{
    initializeCurrentMap();
    int loc_1 = 0;
    int loc_2 = 0;
    int loc_3 = 0;
    int loc_4 = 0;
    int loc_5 = 0;
    while(loc_5 < MAP_HEIGHT) /*  on actualize tout les noeud avec leur vrais valeur x,y */
    {
        loc_4 = 0;
        while(loc_4 < MAP_WIDTH)
        {
            CELLPOS[loc_3] = node(loc_3, loc_1 + loc_4, loc_2 + loc_4);
            loc_3++;
            loc_4++;
        }
        loc_1++;
        loc_4 = 0;
        while(loc_4 < MAP_WIDTH)
        {
            CELLPOS[loc_3] = node(loc_3, loc_1 + loc_4, loc_2 + loc_4);
            loc_3++;
            loc_4++;
        }
        loc_2 = loc_2 - 1;
        loc_5++;
    }

    /* on initialize tous les information des cellules Id*/
    for (int i =0; i <560; i++)
    {
        bool appli = false;
        Cell currentCell = currentMap.getCellId(i);
        if (i == startId)
        {
            appli = true;
            CELLPOS[i].setClosed(false);
            CELLPOS[i].setStarted(true);
            CELLPOS[i].setWalkable(currentCell.getMov());
        }

        if (i == endId)
        {
            appli = true;
            CELLPOS[i].setClosed(true);
            CELLPOS[i].setStarted(false);
            CELLPOS[i].setWalkable(currentCell.getMov());
        }
        if (appli == false)
        {
            CELLPOS[i].setClosed(false);
            CELLPOS[i].setStarted(false);
        }
        CELLPOS[i].setWalkable(currentCell.getMov());
        CELLPOS[i].calculH(CELLPOS[endId]);;
    }
    node currentNode = CELLPOS[startId];

    while (finish_search == false) /* on créé une boucle jusqu'a qu'il trouve son chemin jusqu'a sa destination*/
    {
        findNeighboringCell(currentNode, false); /* on cherche les cellules voisines par rapport à noeud actuel.  */

        currentNode = openList[0]; /* on remplace la noeud actuel par la première de la openList don celle qui a le plus petit F a notre noeud actuel*/
        currentNode.setInClosedList(true);
        currentNode.setInOpenList(false);
        openList.remove(0);
    }

    node currentCell = CELLPOS[endId];
    QVector<int> cells;
    while(currentCell.getCellid() != CELLPOS[startId].getCellid())
    {
        cells.push_back(currentCell.getCellid());
        currentCell = CELLPOS[currentCell.getParent()];
    }
    cells.push_back(startId);
    QVector<int> chemin;
    for(int reverse = cells.size() -1; reverse > -1; reverse--)
    {
        chemin.push_back(cells[reverse]);
    }

    return chemin;
}

void pathFinding::initializeCurrentMap()
{
    readerMapBorax reader;
    currentMap = reader.getMapId(84674062);
}


void pathFinding::findNeighboringCell(node c_node, bool diagonal = false)
{
    addCell(getCellIdFromPoint(c_node.getX(),  c_node.getY() + 1), c_node);

    addCell(getCellIdFromPoint(c_node.getX() - 1,  c_node.getY()), c_node);

    addCell(getCellIdFromPoint(c_node.getX() + 1, c_node.getY()), c_node);

    addCell(getCellIdFromPoint(c_node.getX(), c_node.getY() - 1), c_node);


    if (diagonal)
    {
        addCell(getCellIdFromPoint(c_node.getX() - 1, c_node.getY() + 1), c_node);

        addCell(getCellIdFromPoint(c_node.getX() + 1, c_node.getY() + 1), c_node);

        addCell(getCellIdFromPoint(c_node.getX() + 1, c_node.getY() - 1), c_node);

        addCell(getCellIdFromPoint(c_node.getX() - 1, c_node.getY() - 1), c_node);

    }
    sortOpenList();
}

void pathFinding::addCell(int cell, node c_node)
{
    if (CELLPOS[cell].getWalkable() == true)
    {
        if(CELLPOS[cell].getClosed() == true)
        {
            CELLPOS[cell].setParent(c_node.getCellid());
            finish_search = true;
            return;
        }

        if (CELLPOS[cell].getInOpenList() == false && CELLPOS[cell].getInClosedList() == false)
        {
            CELLPOS[cell].setParent(c_node.getCellid());
            CELLPOS[cell].setInOpenList(true);
            CELLPOS[cell].setG(c_node.getG() + 10);
            CELLPOS[cell].setF(CELLPOS[cell].getG() + CELLPOS[cell].getH());
            openList.push_back(CELLPOS[cell]);
        }
    }
}

int pathFinding::getCellIdFromPoint(int x, int y)
{
    return (x - y) * MAP_WIDTH + y + (x - y) / 2;
}

void pathFinding::sortOpenList()
{
    bool ok = false;
    while(ok == false)
    {
        ok = true;
        node temp;

        for (int i = 0; i < openList.size() - 1 ; i++) /* on fait regarde tous les noeud qui son dans l'openList puis on regarde qui a le plus petit F */
        {
            if (openList[i].getF() > openList[i + 1].getF())
            {
                temp = openList[i];
                openList[i] = openList[i+1];
                openList[i+1] = temp;
                ok = false;
            }
        }
    }
}
