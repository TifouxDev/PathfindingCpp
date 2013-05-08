#ifndef PATHFINDING_H
#define PATHFINDING_H
#include <QMap>
#include <QVector>
#include "node.h"
#include "readermapborax.h"
#include "cell.h"
#include "map.h"
#include <QString>
#include <QPoint>
class pathFinding
{
public:
    pathFinding();
    QVector<int> findPath(int startId, int endId); /* Function qui va permetre de trouver notre chemin de x à  y et nous retourne la liste de cellules id. */
    node CELLPOS[560];
private:
    int MAP_WIDTH;
    int MAP_HEIGHT;
    map currentMap;
    void initializeCurrentMap();
    void findNeighboringCell(node c_node, bool diagonal); /* Function qui va nous permettre d'ajouter dans notre openList les cellules voisines par rapport a notre cellule actuel.*/
    QVector<node> openList;
    bool finish_search; /* GVarriable sert a nous indiquer si il a trouver son chemin ou pas.*/
    void sortOpenList(); /* Function qui va permetre de chercher dans notre OpenList la noeud qui à pour valeur F la plus petit par rapport au F de notre celluleId. */
    int getCellIdFromPoint(int x, int y); /* Function qui va nous permettre de convertire le x,y d'un cellule en une cellule  */
    void addCell(int cell, node c_node);
};

#endif // PATHFINDING_H
