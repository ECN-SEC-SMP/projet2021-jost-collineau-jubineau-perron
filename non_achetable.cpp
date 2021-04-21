#include "non_achetable.h"

Non_achetable::Non_achetable(string nom, int id) : Case(nom, id)
{
}

bool Non_achetable::isAchetable(){return false;}