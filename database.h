#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);
    
    // un tas de getters pour un tas d'infos différantes
    // ...

    // un tas de setters pour un tas d'infos différantes
    // ...

    virtual void undo() = 0; // annule la dernière modification
    virtual void redo() = 0; // annule la dernière annulation

    virtual bool canUndo() = 0; // indique si on peut faire un undo
    virtual bool canRedo() = 0; // indique si on peut faire un redo
};

#endif // DATABASE_H
